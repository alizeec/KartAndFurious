#ifndef LOAD_HPP
#define LOAD_HPP
#include "Kart.hpp"
#include "Map.hpp"
#include <string>


bool LoadKAFKart(Kart* kart,const std::string&  chemin);
bool LoadKAFMap(Map* map,const std::string&  chemin);

#endif
