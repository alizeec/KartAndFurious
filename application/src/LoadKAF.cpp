#include "Kart.hpp"
#include "LoadKAF.hpp"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

bool LoadFileKAF(Kart* kart,const std::string&  chemin){
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
                  }

                if(type.compare("map")==0){
                // code de lecture de la map
                }

                 file.close();
            }
            else  // sinon
                    cerr << "Impossible d'ouvrir le fichier !" << endl;







            /*std::string keyword;

            file = fopen(chemin.c_str(),"r");
            if(file == NULL) return false;

            char type [10];
            int k;
            for (k=0; k<10;k++){
                    type[k]= 0;
            }

            int i;
            for (i=0; i< 4; i++){
                    fscanf(file,"%c \n",type+i);
            }

                    if (strcmp(type,"map")!= 0 && strcmp(type,"kart")!=0 ){
                            fprintf(stderr, "Fichier incompatible\n");
                            return false;
                    }

                    if (strcmp(type,"kart")==0){

                        float type2;


                                fscanf(file,"%f \n",type2);

                        kart->specifications.setAcceleration(type2);

                    }*/

                    return true;
}
