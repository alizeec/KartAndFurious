#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Point3D.hpp"

#include <vector>

class Map
{
public:
  //Structure qui empacte les caractéristiques de la Map
  
  Map();
  Map(std::string cheminMap, int size);
  virtual ~Map();

	
  const std::string getChemin() const;
  const int getNbPoints() const;
  //const Point3D* getTrajet() const;

    void setChemin(std::string chem){
        this->chemin=chem;
    }
  void setNbPoints(float nb){
        this->nbPoints=nb;
    }

std::vector<Point3D> trajet;
private:
  std::string chemin;
  int nbPoints;
    
};

#endif
