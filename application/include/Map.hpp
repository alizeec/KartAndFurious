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
  Map(std::string cheminMap,std::string IA, glm::vec3 LigneDepartPosition,float LigneDepartAngle , int size);
  virtual ~Map();

	
  const std::string getChemin() const;
  const std::string getIA() const;
  const glm::vec3 getLigneDepartPosition() const;
  const float getLigneDepartAngle()const;
  const int getNbPoints() const;
  //const Point3D* getTrajet() const;

  void setChemin(std::string chem);
  void setIA(std::string nomIA);
  void setLigneDepart(float x, float y, float z, float angle);
  void setNbPoints(float nb);

  struct Ralentissement{
  private:
      std::vector<Point3D> coord;
      std::vector<Point3D> size;

  public:
      void setRallentissement(const Point3D, const Point3D);
      std::vector<Point3D> getRallentissementCoord();
      std::vector<Point3D> getRallentissementSize();
  };

  Ralentissement ralentissement;



std::vector<Point3D> trajet;
private:
  std::string chemin;
  std::string IA;
  glm::vec3 LigneDepartPosition;
  float LigneDepartAngle;
  int nbPoints;
    


};

#endif
