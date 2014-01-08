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
 */
class Kart
{
public:
  //Indique si le Kart est actuellement en phase d'acceleration ou de deceleration
  enum StatutAcceleration
  {
    ACCELERE,
    DECELERE,
    VITESSE_MAX_ATTEINTE,
       FREINE,
    NE_BOUGE_PAS,
  };

  enum StatutSens{
      AVANCE,
      RECULE,
  };

  //Structure qui empacte les caractéristiques du Kart
  struct Specifications
  {
      public:

    Specifications()
        : acceleration(8.f), vitesseMax(20.f), vitesseAngulaire(90.f), coefficientFreinage(0.5f),nomduModele() {}

    void setAcceleration(float accel){
        this->acceleration=accel;
    }

    void setVitesseMax(float vM){
        this->vitesseMax=vM;
    }

    void setVitesseAngulaire(float vA){
        this->vitesseAngulaire=vA;
    }

    void setCoefficientFreinage(float coeff){
        this->coefficientFreinage=coeff;
    }

    void setModeleName(std::string name){
        this->nomduModele=name;
    }

    ///Doit etre positive
    float acceleration;
    ///Doit etre positive
    float vitesseMax;
    ///Doit etre positive
    float vitesseAngulaire;
    ///Doit etre positif
    float coefficientFreinage;

    std::string nomduModele;

  };


  Kart();
  Kart(glm::vec3 position, glm::quat direction, float speed);
  virtual ~Kart();
  void updatePosition(glm::vec3 nouvellePosition);
  void updateOrientation(float nouvelleDirection);
  bool etatFreinage;



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

  void freiner();
  void stopFreiner();

  const glm::vec3& getPosition() const;
  const glm::quat& getOrientation() const;
  Specifications specifications;


//private:
  glm::vec3 position;
  glm::quat orientation;
  float angleDirection;
  float vitesse;
  float vitesseAngulaireCourante;
  float accelerationCourante;

  StatutAcceleration accelerationStatut;
  StatutSens statutsens;
};

#endif
