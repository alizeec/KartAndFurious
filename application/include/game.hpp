#pragma once
#include "Map.hpp"
#include "Kart.hpp"

void detectionZonesRallentissantes(Map map,Kart* kartDuJoueur);
void detectionCheckpoints(Kart *kartDuJoueur, Map* map);

class Game{
    bool isOver;
public:
    Game(){}
    ~Game(){}
    void initIsOver();
    void setTrueIsOver();
};
