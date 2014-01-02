#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<SFML/System.hpp>

#include <GL/glew.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Mesh.hpp"
#include "Kart.hpp"
#include "Map.hpp"
#include "Texture.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "initGraphique.hpp"
#include "LoadKAF.hpp"


#include <glm/gtc/matrix_transform.hpp>

int main() {
  const size_t WINDOW_WIDTH = 1024;
  const size_t WINDOW_HEIGHT = 768;
  bool PointX = false;
  bool PointZ = false;

  //------------- INITIALISATION ---------------------
  //Création de la fenetre et initialisation de GLEW
  sf::RenderWindow window;
  window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Fat and Furious");
  GLenum glewCode = glewInit();
  if(GLEW_OK != glewCode) {
    std::cerr << "Unable to initialize GLEW : " << glewGetErrorString(glewCode) << std::endl;
    return EXIT_FAILURE;
  }
  //On active le test de profondeur dans OpenGL
  glEnable(GL_DEPTH_TEST);

  //-----------------------------------------------------

  //chargement de la texture
    /*glimac::Texture texture(GL_TEXTURE_2D);
    texture.loadTexture2D("data/fond-bois.jpg");*/







  //Création du Kart "logique" qui va contenir le code de déplacement
  Kart kartDuJoueur;
  kartDuJoueur.updatePosition(glm::vec3(26.f,0.f,78.f));
  kartDuJoueur.updateOrientation(70.f);

  LoadKAFKart(&kartDuJoueur,"KAF/kart1.KAF");





  Map map;
  LoadKAFMap(&map,"KAF/map1.KAF");
  LoadKAFCollision(&map,"KAF/test.KAF");

  Point3D current_point = map.trajet[0];

  //Création des kart des autres joueurs (IA)
  Kart IA1;
  IA1.updatePosition(glm::vec3(-5.5f,0.f,-27.f));
  IA1.updateOrientation(70.f);

  //initialisation du world3D, qui contiendra tous les Mesh
  worldGraphique world3D;
   world3D.initGraphisme(kartDuJoueur);

 // création du shader de base.Ne gère pas les textures
 glimac::ShaderProgram shaderProgram;
 shaderProgram.loadProgram("shaders/Simple3DVS.glsl","shaders/SimpleFS.glsl");
 shaderProgram.use();


  //GLint locationtex = shaderProgram.getUniformIndex("uTexture");

  const glm::vec3 initialDirection=glm::vec3(0.f,0.f,3.f);

  sf::Clock clock;



  //--------- BOUCLE DE JEU ---------------
  bool demandeAQuitter = false;
  do
  {
    //-----------------RENDU 3D-----------------------
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    //On affiche le circuit
    world3D.listeMesh[0]->afficher(shaderProgram);


    //On met à jour la position et l'orientation des modèle 3D du kart du joueur et des IA
    //par rapport aux Karts "logiques" qui gèrent le déplacement
    world3D.updatePositionKarts(kartDuJoueur, IA1);


    //Enfin on affiche le Kart 3D du joueur et les IA
    //C'est lui qui se charge d'envoyer la bonne matrice modele au shaderProgram
    world3D.listeMesh[1]->afficher(shaderProgram);
    world3D.listeMesh[2]->afficher(shaderProgram);



    // gestion de la caméra
    glm::vec3 cameraPosition = kartDuJoueur.getPosition()+ glm::vec3(0.f,4.f,0.f)+ glm::toMat3(kartDuJoueur.getOrientation())* initialDirection;
    glm::vec3 cameraDirection= kartDuJoueur.getPosition() ;

    glm::mat4 camera = glm::lookAt(cameraPosition,cameraDirection, glm::vec3(0.f,1.f, 0.f));

    //Le projeté 2D de la caméra (matrice de projection)
    glm::mat4 cameraProjetee =  glm::perspective(90.f, WINDOW_WIDTH / (float) WINDOW_HEIGHT, 0.1f, 1000.f) * camera;

    //On balance ça au shader !
    GLint viewProjectionIndex = shaderProgram.getUniformIndex("viewProjection");
    shaderProgram.setUniform(viewProjectionIndex, cameraProjetee);




    //-------------- CODE "APPLICATIF"(la logique du jeu quoi, + gestion des évènements) ----------

    //On met à jour le Kart "logique" du joueur par rapport aux évènements claviers
    //std::cout << IA1.getPosition().x - current_point.x << "\n";
   /* if(IA1.getPosition().x - current_point.x < 0.001){
	//std::cout<<"TOURNER \n";
	if(IA1.getPosition().x < current_point.x){
    		IA1.tourneAGauche();
		//IA1.avance();
	}else{
		IA1.tourneADroite();
		//IA1.avance();
	}
    }else{
	//std::cout<<"STOOOOOOOP TOURNER \n";
	PointX = true;
	IA1.stopTourner();
    } 
    if(IA1.getPosition().z - current_point.z > -0.001){
	//std::cout<<"AVANCER \n";
	if(IA1.getPosition().z < current_point.z){
    		IA1.avance();
	}else{
		IA1.avance();
	}
    }else{
	//std::cout<<"STOOOOOOOP AVANCER \n";

	PointZ = true;
	IA1.stopAvancer();
    }

    if(PointX == true){
	std::cout<<"x:"<<IA1.getPosition().x << "\n";
	//std::cout<<"z:"<<IA1.getPosition().z << "\n";
	std::cout<<"STOOOOOOOP \n";
demandeAQuitter = true;
    }
    //std::cout << "z : " <<IA1.getPosition().z << "\n";
    //std::cout << "z : " <<IA1.getPosition().x << "\n";
    */
    sf::Time elapsed = clock.restart();
    kartDuJoueur.mettreAJour(elapsed);
    IA1.mettreAJour(elapsed);

    int size = map.ralentissement.getRallentissementCoord().size();
    std::vector <Point3D> positionfriction = map.ralentissement.getRallentissementCoord();
    std::vector <Point3D> sizefriction = map.ralentissement.getRallentissementSize();

const glm::vec3& currentpositionkart = kartDuJoueur.getPosition();
   bool friction=false;
    for (int i=0;i<size; ++i){
        if (currentpositionkart[0]>(positionfriction[i].x-sizefriction[i].x/2) && currentpositionkart[0]<(positionfriction[i].x+sizefriction[i].x/2) && currentpositionkart[1]>(positionfriction[i].y-sizefriction[i].y/2) && currentpositionkart[1]<(positionfriction[i].y+sizefriction[i].y/2)) {
            friction=true;
            }
        }
    if(friction==true){
        kartDuJoueur.freiner();
    }
   else if(friction==false){
        kartDuJoueur.stopFreiner();
    }


    //Gestion du clavier
    sf::Event e;
    while (window.pollEvent(e))
    {
      switch(e.type)
      {
        case sf::Event::Closed :
                window.close();
                demandeAQuitter = true;
        break;

        case sf::Event::KeyPressed:
            if (e.key.code == sf::Keyboard::Down)
                kartDuJoueur.recule();

            if (e.key.code == sf::Keyboard::Up){
                kartDuJoueur.avance();
            }

            if (e.key.code == sf::Keyboard::Space){
              kartDuJoueur.freiner();
            }

            if (e.key.code == sf::Keyboard::Left)
                kartDuJoueur.tourneAGauche();

            if (e.key.code == sf::Keyboard::Right)
                kartDuJoueur.tourneADroite();



            break;
        case sf::Event::KeyReleased:
            if (e.key.code == sf::Keyboard::Down)
                kartDuJoueur.stopAvancer();

            else if (e.key.code == sf::Keyboard::Up)
                kartDuJoueur.stopAvancer();

            else if (e.key.code == sf::Keyboard::Left)
                kartDuJoueur.stopTourner();

            else if (e.key.code == sf::Keyboard::Right)
                kartDuJoueur.stopTourner();


            else if (e.key.code == sf::Keyboard::Space)
                kartDuJoueur.stopFreiner();


            break;
        default:
          break;


      }
    }
    //Equivalent du swapBuffer de la SDL
    window.display();
  } while (!demandeAQuitter);

  world3D.deleteGraphique();
	return EXIT_SUCCESS;
}
