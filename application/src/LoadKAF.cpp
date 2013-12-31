#include "Kart.hpp"
#include "LoadKAF.hpp"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

bool LoadFileKAFkart(Kart* kart,const std::string&  chemin){
    /* On ouvre le fichier */

        ifstream file(chemin, ios::in);  // on ouvre le fichier en lecture

            if(file)  // si l'ouverture a réussi
            {
                string type;

                file >> type;  /*on lit jusqu'au retour chariot et on stocke ce qui est lu dans la variable indiquée */

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
                else{
                    cout<<"erreur de fichier: ce n'est pas un fichier de Kart"<<endl;
                    return false;
                }

                 file.close();
            }
            else  // sinon
                    cerr << "Impossible d'ouvrir le fichier !" << endl;
                    return false;

             return true;
}
