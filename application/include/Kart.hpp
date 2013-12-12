#ifndef KART_HPP
#define KART_HPP

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

/**
 * @brief The Kart class
 * Pour ne pas avoir un Kart qui saccade quand on le controle au clavier :
 * il faut que quand on *appuie* sur la touche ça ne fasse rien directement mais
 * modifie sa vitesse "d'avancement" ou sa vitesse de "tournage" pour qu'elle soit différente de 0.
 * Ensuite c'est la méthode mettreAJour qui va modifier concrètement en fonction de ces deux paramètre la position
 * du Kart.
 * ATTENTION c'est vraiment une base, il faut rajouter la gestion du temps (un peu comme en TD) pour avoir
 * un déplacement qui dépend pas de la vitesse de votre processeur.
 */
class Kart
{
public:
  Kart();
  Kart(glm::vec3 position, glm::quat direction, float speed);
  virtual ~Kart();

  //Met à jour le Kart en fonction de sa vitesse, sa vitesse angulaire
  //sa position actuelle et son orientation actuelle
  void mettreAJour(sf::Time elapsedTimeInSecond);

  //Donne les ordres au Kart.
  //Modifient *vitesse* :
  void avance();
  void recule();

  //Modifient vitesseAngulaire:
  void tourneAGauche();
  void tourneADroite();

  //Met à zéro vitesse
  void stopAvancer();

  //Met à zéro vitesseAngulaire
  void stopTourner();

  const glm::vec3& getPosition() const;
  const glm::quat& getOrientation() const;

private:
  glm::vec3 position;
  glm::quat orientation;
  float angleDirection;
  float vitesse;
  float vitesseAngulaire;
  sf::Time lastmove;
};

#endif
