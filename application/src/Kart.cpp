#include "Kart.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>

Kart::Kart()
    : position(0.f, 0.f, 0.f), orientation(glm::angleAxis(0.f, glm::vec3(0.f, 1.f, 0.f))),
      angleDirection(0.f), vitesse(0.f), vitesseAngulaire(0.f)
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
    angleDirection += vitesseAngulaire * (elapsedTime.asSeconds()); //en degres/secondes
  }
  orientation = glm::angleAxis(angleDirection, glm::vec3(0.f, 1.f, 0.f));

  //La direction initiale de l'objet 3D, avant toute modification : par convention il est tourné vers -z
  // !!! => ça veut dire qu'il faut modéliser nos objets en respectant cette convention !
  const glm::vec3 directionInitiale = glm::vec3(0.f, 0.f, -1.f);
  glm::vec3 direction = glm::normalize(glm::toMat3(orientation) * directionInitiale);

  //Calcul de la nouvelle position en fonction de la speed et de la direction
  position += direction * vitesse * elapsedTime.asSeconds();//ajouter gestion temps

}

//Les valeurs dans les méthodes qui suivent sont là pour les tests
void Kart::avance(){
  vitesse = 5.f;
}

void Kart::recule(){
  vitesse = -5.f;
}

void Kart::tourneAGauche(){
  vitesseAngulaire = 90.f;
}

void Kart::tourneADroite(){
  vitesseAngulaire = -90.f;
}

void Kart::stopAvancer()
{
  vitesse = 0.f;
}

void Kart::stopTourner()
{
  vitesseAngulaire = 0.f;
}

const glm::vec3& Kart::getPosition() const
  {return position;}

const glm::quat& Kart::getOrientation() const
  {return orientation;}

