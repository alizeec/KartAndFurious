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


