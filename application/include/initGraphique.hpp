#ifndef INITGRAPHIQUE_HPP
#define INITGRAPHIQUE_HPP
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "Mesh.hpp"
#include "Kart.hpp"
#include "Map.hpp"

class worldGraphique{
public:
void initGraphisme(Kart kart, Map map);
void deleteGraphique();
void updatePositionKarts(Kart, Kart);

std::vector<Mesh*> listeMesh;
};
#endif
