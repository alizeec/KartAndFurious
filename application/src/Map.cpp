#include "Map.hpp"
#include "Point3D.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>

Map::Map()
    : chemin(""), nbPoints(0)
{
}
Map::Map(std::string cheminMap ="", std::string IA="", glm::vec3 LigneDepartPosition=glm::vec3(0.f,1.f,0.f), float LigneDepartAngle = 0.f, int size = 0)
{
}

Map::~Map()
{
}

const std::string Map::getChemin() const
  {return chemin;}

const std::string Map::getIA() const
  {return IA;}

const glm::vec3 Map::getLigneDepartPosition() const
    {return LigneDepartPosition;}

const float Map::getLigneDepartAngle()const
    {return LigneDepartAngle;}

const int Map::getNbPoints() const
  {return nbPoints;}

void Map::setChemin(std::string chem){
    this->chemin=chem;
}

void Map::setIA(std::string nomIA){
    this->IA=nomIA;
}

  void Map::setLigneDepart(float x, float y, float z, float angle){
      this->LigneDepartPosition= glm::vec3(x,y,z);
      this->LigneDepartAngle=angle;
  }

void Map::setNbPoints(float nb){
    this->nbPoints=nb;
}

void Map::Ralentissement::setRallentissement(const Point3D coordonnees,const Point3D taille){
    this->coord.push_back(coordonnees);
    this->size.push_back(taille);
}

std::vector<Point3D> Map::Ralentissement::getRallentissementCoord(){
    return this->coord;
}


std::vector<Point3D> Map::Ralentissement::getRallentissementSize(){
    return this->size;
}
