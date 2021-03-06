#include "Kart.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>
#include <math.h>
#include<glm/gtx/vector_angle.hpp>

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

void Kart::updatePosition(glm::vec3 nouvellePosition){
    this->position=nouvellePosition;
}

void Kart::updateOrientation(float nouvelleDirection){
    this->angleDirection=nouvelleDirection;
}





void Kart::mettreAJour(sf::Time elapsedTime)
{
  //Calcul de la nouvelle direction en fonction de l'angularSpeed
  if (vitesse != 0.f)
  {
    angleDirection +=  vitesseAngulaireCourante * (elapsedTime.asSeconds()); //en degres/secondes
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

  // Freinage  :
  if (etatFreinage==true){
      if (statutsens==AVANCE){
     vitesse=specifications.coefficientFreinage;}
      else if (statutsens==RECULE){
          vitesse=-specifications.coefficientFreinage;}

  }

  position += direction * distanceParcourue;//en uniteOGL/seconde
}





void Kart::avance(){
  //uniteOpenGL / seconde
  accelerationCourante = specifications.acceleration;
  accelerationStatut = ACCELERE;
  statutsens = AVANCE;
}

void Kart::recule(){
  //uniteOpenGL / seconde
  accelerationCourante = - specifications.acceleration;
  accelerationStatut = ACCELERE;
  statutsens = RECULE;
}

void Kart::tourneAGauche(){
  vitesseAngulaireCourante =  specifications.vitesseAngulaire;
}

void Kart::tourneADroite(){
  vitesseAngulaireCourante = -specifications.vitesseAngulaire;
}

void Kart::stopAvancer()
{
  //Si on est deja en train de decelerer, rien a faire
  if (accelerationStatut == DECELERE)
    return;
  accelerationCourante = -70*accelerationCourante;
  accelerationStatut = DECELERE;

}


void Kart::stopTourner()
{
  vitesseAngulaireCourante = 0.f;
}


void Kart::freiner()
{
etatFreinage=true;
}

void Kart::stopFreiner(){
    etatFreinage=false;
}


const glm::vec3& Kart::getPosition() const
  {return position;}

const glm::quat& Kart::getOrientation() const
  {return orientation;}






/********************************* IA ********************************************************/
void IA::setTrueTargetCalculate(){
    this->targetCalculate=true;
}

void IA::setFalseTargetCalculate(){
    this->targetCalculate=false;
}

void IA::setAngle(float newangle){
    this->angleIA = newangle;
}

void IA::incrementCursor(){
    this->Cursor ++;
}
int IA::getCursor(){
    return this->Cursor;
}

void IA::initCursor(){
    this->Cursor=0;
}




int IA::setPositionIA(sf::Time elapsedTimeInSecond, Map map){

    const glm::vec3 directionInitiale = glm::vec3(0.f, 0.f, -1.f);


    glm::vec3 vecdirecteur= glm::normalize(glm::toMat3(orientation)*directionInitiale);
    float x= map.trajet[getCursor()].x-(this->getPosition()[0]);
    float y= map.trajet[getCursor()].y-(this->getPosition()[1]);
    float z= map.trajet[getCursor()].z-(this->getPosition()[2]);
    int nb_noeud=map.getNbPoints();



   glm::vec3 kartToCheckpoint=glm::vec3(x,y,z);


   glm::vec2 kartToCheckpoint2 = glm::vec2(kartToCheckpoint.x, kartToCheckpoint.z);
   float angle = glm::orientedAngle(glm::normalize(kartToCheckpoint2), glm::normalize(glm::vec2(0.0f,-1.0f)));


   angleDirection = angle;

    mettreAJour(elapsedTimeInSecond);
    if (fabs(this->getPosition()[0]-map.trajet[getCursor()].x)<4.f && fabs(this->getPosition()[2]-map.trajet[getCursor()].z)<4.f){
        incrementCursor();
        setFalseTargetCalculate();
        if(getCursor()==nb_noeud-1){
            stopAvancer();
            arived=true;
        }
    }else{
        avance();
    }

}

