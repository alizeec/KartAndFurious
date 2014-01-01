#include "Map.hpp"
#include "Point3D.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>

Map::Map()
    : chemin(""), nbPoints(0)
{
}
Map::Map(std::string cheminMap ="", int size = 0)
{
}

Map::~Map()
{
}

const std::string Map::getChemin() const
  {return chemin;}

const int Map::getNbPoints() const
  {return nbPoints;}


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
