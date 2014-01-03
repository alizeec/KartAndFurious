#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "Mesh.hpp"
#include "initGraphique.hpp"

void worldGraphique::initGraphisme(Kart kart, Map map){


    //Chargement des données 3D
    Mesh* circuit3D=new(Mesh);
    circuit3D->loadFromFile(map.getChemin());
    this->listeMesh.push_back(circuit3D);


    Mesh* kart3D=new(Mesh);
    kart3D->loadFromFile(kart.specifications.nomduModele);
    this->listeMesh.push_back(kart3D);


    Mesh* kart3D_IA1=new(Mesh);
    kart3D_IA1->loadFromFile(map.getIA());
    this->listeMesh.push_back(kart3D_IA1);


}

void worldGraphique::deleteGraphique(){
    for (unsigned int i=0; i<this->listeMesh.size(); ++i){
        delete this->listeMesh[i];
    }
}


void worldGraphique::updatePositionKarts(Kart kartDuJoueur, Kart IA1){
        //On met à jour la position et l'orientation du modèle 3D
        //par rapport au Kart "logique" qui gère le déplacement
        this->listeMesh[1]->setPositionEtOrientation(kartDuJoueur.getPosition(), kartDuJoueur.getOrientation());
        this->listeMesh[2]->setPositionEtOrientation(IA1.getPosition(), IA1.getOrientation());
}
