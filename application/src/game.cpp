#include <iostream>
#include <math.h>
#include "game.hpp"
#include "Kart.hpp"
#include "Map.hpp"

void detectionZonesRallentissantes(Map map, Kart *kartDuJoueur){
int sizeTabRallentissement = map.ralentissement.getRallentissementCoord().size();
std::vector <Point3D> positionfriction = map.ralentissement.getRallentissementCoord();
std::vector <Point3D> sizefriction = map.ralentissement.getRallentissementSize();
const glm::vec3& currentpositionkart = kartDuJoueur->getPosition();
std::cout<< currentpositionkart[0]<<","<<currentpositionkart[2]<<std::endl;
   bool friction=false;
    for (int i=0;i<sizeTabRallentissement; ++i){

       if (currentpositionkart[0]>=(positionfriction[i].x-fabs(sizefriction[i].x)/2) && currentpositionkart[0]<=(positionfriction[i].x+fabs(sizefriction[i].x)/2) && currentpositionkart[2]>=(positionfriction[i].z-fabs(sizefriction[i].z)/2) && currentpositionkart[2]<=(positionfriction[i].z+fabs(sizefriction[i].z)/2)) {
           friction=true;
            }
        }
    /* si on est dans une zone */
   if(friction==true){
        kartDuJoueur->stopFreiner();
	std::cout << "fegdfhr" << std::endl;
    }
    /* si on y est pas encore ou qu'on en sort*/
  else if(friction==false){
        kartDuJoueur->freiner();
    }
}


void detectionCheckpoints(Kart kartDuJoueur, Map* map){
int sizeTabCheckpoint = map->checkpoint.getCheckpointCoord().size();
std::vector <Point3D> positionCheckpoint = map->checkpoint.getCheckpointCoord();
std::vector <float> sizeCheckpoint = map->checkpoint.getCheckpointRadius();
std::vector<bool> listeCheckpoint = map->checkpoint.getIsValidated();
const glm::vec3& currentpositionkart = kartDuJoueur.getPosition();



if(currentpositionkart[0]>=(positionCheckpoint[0].x-(sizeCheckpoint[0]/2)) && currentpositionkart[0]<=(positionCheckpoint[0].x+(sizeCheckpoint[0]/2)) && currentpositionkart[2]>=(positionCheckpoint[0].z-(sizeCheckpoint[0]/2)) && currentpositionkart[2]<=(positionCheckpoint[0].z+(sizeCheckpoint[0]/2)) && listeCheckpoint[1]==true && listeCheckpoint[2]==true && listeCheckpoint[3]==true && listeCheckpoint[4]==true){
    map->checkpoint.setTrue(0);
 }

    for (int i=1;i<sizeTabCheckpoint; ++i){
        if (currentpositionkart[0]>=(positionCheckpoint[i].x-(sizeCheckpoint[i]/2)) && currentpositionkart[0]<=(positionCheckpoint[i].x+(sizeCheckpoint[i]/2)) && currentpositionkart[2]>=(positionCheckpoint[i].z-(sizeCheckpoint[i]/2)) && currentpositionkart[2]<=(positionCheckpoint[i].z+(sizeCheckpoint[i]/2))) {
            map->checkpoint.setTrue(i);

            }
        }
}
