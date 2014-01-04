#include "Kart.hpp"
#include "Map.hpp"
#include "LoadKAF.hpp"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

bool LoadKAFKart(Kart* kart,const std::string&  chemin){
    /* On ouvre le fichier */

        ifstream file(chemin, ios::in);  // on ouvre le fichier en lecture

            if(file)  // si l'ouverture a réussi
            {
                string type;

                file >> type;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

                if(type.compare("kart")==0){
                    float accelerationRead;
                    float vitesseMaxRead;
                    float vitesseAngulaireRead;
                    float coeffFreinageRead;
                    string name;

                    file>> accelerationRead >>vitesseMaxRead >> vitesseAngulaireRead >> coeffFreinageRead >> name;
                    kart->specifications.setAcceleration(accelerationRead);
                    kart->specifications.setVitesseMax(vitesseMaxRead);
                    kart->specifications.setVitesseAngulaire(vitesseAngulaireRead);
                    kart->specifications.setCoefficientFreinage(coeffFreinageRead);
                    kart->specifications.setModeleName(name);
                  }else{
			cerr << "Ceci n'est pas un Kart" << endl;
		  }

                 file.close();
            }
            else  {
                    cerr << "Impossible d'ouvrir le fichier !" << endl;
                    return false;
            }

                    return true;
}

bool LoadKAFMap(Map* map,const std::string&  cheminMap){
    /* On ouvre le fichier */

  ifstream file(cheminMap, ios::in);  // on ouvre le fichier en lecture

  if(file)  // si l'ouverture a réussi
  {
    string type;

    file >> type; /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

    if(type.compare("map")==0){
      string nom;
      string chemin;
      string nomIA;
      float StartCoordx, StartCoordy, StartCoordz, StartAngle;
      int nbPoints;
      file>>chemin>>nomIA>>StartCoordx>>StartCoordy>>StartCoordz>>StartAngle>>nbPoints;
      map->setChemin(chemin);
      map->setIA(nomIA);
      map->setLigneDepart(StartCoordx,StartCoordy,StartCoordz,StartAngle);


      /*Récupération des coordonnées*/
      float tab[nbPoints * 3];
      int cpt = 0;
      int coord;
      while (file >> coord){
        tab[cpt] = coord;
        cpt++;
      }
      for(int i=0; i<cpt;i+=3){
        std::cout << "i " << i << std::endl;
        Point3D p;
        p.x = tab[i];
        p.y = tab[i+1];
        p.z = tab[i+2];
        map->trajet.push_back(p);

      }

    }else{
      cerr << "Ceci n'est pas une Map" << endl;
    }

    file.close();
  }
  else {
    cerr << "Impossible d'ouvrir le fichier Map!" << endl;
    return false;
  }

return true;
}

bool LoadKAFCollision(Map* map,const std::string&  collision){
  ifstream file(collision, ios::in);  // on ouvre le fichier en lecture

  if(file)  // si l'ouverture a réussi
  {
    string Type,Type2,typeInfo;
    float coordx,coordy,coordz,sizex,sizey,sizez;
    std::vector<Point3D> coord;
    std::vector<Point3D> size;

    while (file >> Type>>Type2>>typeInfo >> coordx>> coordy>> coordz>> typeInfo>> sizex>>sizey>>sizez
           ){


      Point3D pcoord;
      pcoord.x = coordx;
      pcoord.y = coordy;
      pcoord.z = coordz;

      Point3D psize;
      psize.x = sizex;
      psize.y = sizey;
      psize.z = sizez;

      map->ralentissement.setRallentissement(pcoord,psize);

    }

    file.close();

  }
  else{
    cerr << "Impossible d'ouvrir le fichier Collision!" << endl;
    return false;
  }
  return true;
}




bool LoadKAFCheckpoint(Map* map,const std::string&  checkpoint){
  ifstream file(checkpoint, ios::in);  // on ouvre le fichier en lecture

  if(file)  // si l'ouverture a réussi
  {
    string Type,Type2,typeInfo;
    float coordx,coordy,coordz,radius;


    while (file >> Type>>Type2>>typeInfo >> coordx>> coordy>> coordz>> typeInfo>>radius){


      Point3D pcoord;
      pcoord.x = coordx;
      pcoord.y = coordy;
      pcoord.z = coordz;

      map->checkpoint.setCheckpoint(pcoord,radius);

    }

    file.close();

  }
  else{
    cerr << "Impossible d'ouvrir le fichier Checkpoint!" << endl;
    return false;
  }
  return true;
}
