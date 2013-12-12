#include "Kart.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>

Kart::Kart()
    : position(0.f, 0.f, 0.f), orientation(glm::angleAxis(0.f, glm::vec3(0.f, 1.f, 0.f))),
      angleDirection(0.f), vitesse(0.f), vitesseAngulaireCourante(0.f), accelerationCourante(0.f), accelerationStatut(NE_BOUGE_PAS)
{
}

Kart::Kart(glm::vec3 position, glm::quat orientation, float speed)
  : position(position), orientation(orientation), vitesse(speed)
{
}

Kart::~Kart()
{
}

void Kart::mettreAJour(sf::Time elapsedTime)
{
  //Calcul de la nouvelle direction en fonction de l'angularSpeed
  if (vitesse != 0.f)
  {
    angleDirection += vitesseAngulaireCourante * (elapsedTime.asSeconds()); //en degres/secondes
  }
  orientation = glm::angleAxis(angleDirection, glm::vec3(0.f, 1.f, 0.f));

  //La direction initiale de l'objet 3D, avant toute modification : par convention il est tourné vers -z
  // !!! => ça veut dire qu'il faut modéliser nos objets en respectant cette convention !
  const glm::vec3 directionInitiale = glm::vec3(0.f, 0.f, -1.f);
  glm::vec3 direction = glm::normalize(glm::toMat3(orientation) * directionInitiale);

  //Tentative d'implémentation d'une base de physique : http://www.onversity.net/cgi-bin/progactu/actu_aff.cgi?Eudo=bgteob&P=00000551
  float distanceParcourue = 0.f;

  if (accelerationStatut == VITESSE_MAX_ATTEINTE)
  {
    distanceParcourue = vitesse * elapsedTime.asSeconds();
  }
  else
  {
   distanceParcourue = vitesse * elapsedTime.asSeconds() + accelerationCourante * (elapsedTime.asSeconds() * elapsedTime.asSeconds()) / 2.f;
  }

  /* Si on est en phase de deceleration et qu'on bouge pas c'est qu'on
   * a fini la phase de deceleration et qu'on est a l'arret, il faut donc
   * empecher le kart de repartir dans l'autre sens !
   */
  float nouvelleVitesseSupposee = distanceParcourue / elapsedTime.asSeconds();
  if ( (abs(vitesse - 0.f) <= 0.000001f || nouvelleVitesseSupposee / vitesse < 0.f) && accelerationStatut == DECELERE)
  {
    accelerationCourante = 0.f;
    distanceParcourue = 0.f;
    vitesse = 0.f;
    accelerationStatut = NE_BOUGE_PAS;
  }
  else
  {
    //Update speed for next calculation ! (speed = initialSpeed)
    vitesse = nouvelleVitesseSupposee;
    if (abs(vitesse) >= specifications.vitesseMax && accelerationStatut != VITESSE_MAX_ATTEINTE)
    {
      accelerationStatut = VITESSE_MAX_ATTEINTE;
      if (vitesse > 0.f)
        vitesse = specifications.vitesseMax;
      else vitesse = - specifications.vitesseMax;
    }
  }
  position += direction * distanceParcourue;//en uniteOGL/seconde
}

//Les valeurs dans les méthodes qui suivent sont là pour les tests
void Kart::avance(){
  //uniteOpenGL / seconde
  accelerationCourante = specifications.acceleration;
  accelerationStatut = ACCELERE;
}

void Kart::recule(){
  //uniteOpenGL / seconde
  accelerationCourante = - specifications.acceleration;
  accelerationStatut = ACCELERE;
}

void Kart::tourneAGauche(){
  vitesseAngulaireCourante = specifications.vitesseAngulaire;
}

void Kart::tourneADroite(){
  vitesseAngulaireCourante = -specifications.vitesseAngulaire;
}

void Kart::stopAvancer()
{
  //Si on est deja en train de decelerer, rien a faire
  if (accelerationStatut == DECELERE)
    return;
  accelerationCourante = -accelerationCourante;
  accelerationStatut = DECELERE;
}

void Kart::stopTourner()
{
  vitesseAngulaireCourante = 0.f;
}

//Le freinage est juste une deceleration plus puissante pour l'instant
void Kart::freiner()
{
  //Si on est deja en train de decelerer il faut juste augmenter l'acceleration courante
  if (accelerationStatut == DECELERE)
  {
    accelerationCourante = specifications.coefficientFreinage * accelerationCourante;
  }
  //Sinon il faut carrement prendre son oppose
  else
  {
    accelerationStatut = DECELERE;
    accelerationCourante = - specifications.coefficientFreinage * accelerationCourante;
  }
}

const glm::vec3& Kart::getPosition() const
  {return position;}

const glm::quat& Kart::getOrientation() const
  {return orientation;}

