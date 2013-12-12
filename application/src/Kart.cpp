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

void Kart::mettreAJour(sf::Time elapsed)
{
  //Calcul de la nouvelle direction en fonction de l'angularSpeed
  angleDirection += vitesseAngulaire*elapsed.asSeconds(); //ajouter gestion temps
  //std::cout << vitesseAngulaire/elapsed.asSeconds() << std::endl;
  // création d'un quaternion (matrice de rotation mais en mieux) avec l'angle en fonction de l'axe y
  orientation = glm::angleAxis(angleDirection, glm::vec3(0.f, 1.f, 0.f));
  // récupération de la position initiale,à faire gaffe quand on importera des mesh
  const glm::vec3 initialDirection = glm::vec3(0.f, 0.f, -1.f);
  // transformation du quaternion en matrice, multiplication par la direction initiale pour avoir la nouvelle direction
  glm::vec3 direction = glm::normalize(glm::toMat3(orientation) * initialDirection);

  //Calcul de la nouvelle position en fonction de la speed et de la direction
  position += direction * vitesse*elapsed.asSeconds();//ajouter gestion temps

}

//Les valeurs dans les méthodes qui suivent sont là pour les tests
void Kart::avance(){
  vitesse = 5.f;
}

void Kart::recule(){
  vitesse = -5.f;
}

void Kart::tourneAGauche(){
  vitesseAngulaire = 10.f;
}

void Kart::tourneADroite(){
  vitesseAngulaire = -10.f;
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

