#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<SFML/System.hpp>
#include <SFML/Audio.hpp>
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
#include "game.hpp"


#include <glm/gtc/matrix_transform.hpp>

int main() {
  const size_t WINDOW_WIDTH = 1024;
  const size_t WINDOW_HEIGHT = 768;
  bool PointX = false;
  bool PointZ = false;

  //------------- INITIALISATION ---------------------
  //Création de la fenetre et initialisation de GLEW
  sf::RenderWindow window;
  window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Kart and Furious");
  GLenum glewCode = glewInit();
  if(GLEW_OK != glewCode) {
    std::cerr << "Unable to initialize GLEW : " << glewGetErrorString(glewCode) << std::endl;
    return EXIT_FAILURE;
  }
  //On active le test de profondeur dans OpenGL
  glEnable(GL_DEPTH_TEST);

  //-----------------------------------------------------




  /* initialisation de la map */
  Map map;

  LoadKAFMap(&map,"KAF/map.KAF");
  LoadKAFCollision(&map,"KAF/test.KAF");
  LoadKAFCheckpoint(&map, "KAF/mapCheckpoint.KAF");
std::cout<< map.getChemin()<<std::endl;
  int numPoint = 0;
  Point3D current_point = map.trajet[0];


  //Création du Kart "logique" qui va contenir le code de déplacement
  Kart kartDuJoueur;
  kartDuJoueur.etatFreinage = false;
  kartDuJoueur.updatePosition(map.getLigneDepartPosition());
  kartDuJoueur.updateOrientation(map.getLigneDepartAngle());
  LoadKAFKart(&kartDuJoueur,"KAF/kart2.KAF");

  //Création des kart des autres joueurs (IA)
  IA IA1;
  IA1.updatePosition(map.getLigneDepartPosition()+glm::vec3(0.f,0.f,2.f));
  IA1.updateOrientation(map.getLigneDepartAngle());

  float current_angle = IA1.angleDirection;
  glm::vec3 current_position = IA1.getPosition();

  //initialisation du world3D, qui contiendra tous les Mesh
  worldGraphique world3D;
   world3D.initGraphisme(kartDuJoueur, map);

 // création du shader de base
 glimac::ShaderProgram shaderProgram;
 shaderProgram.loadProgram("shaders/Simple3DVS.glsl","shaders/SimpleFS.glsl");
 shaderProgram.use();

   //pour la camera

   glm::vec3 currentCamera=glm::vec3(0.f,0.f,2.f);

  sf::Clock clock;

  sf::Music music; if (!music.openFromFile("music/1.ogg")) return -1;


  //music.play();


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
    world3D.listeMesh[3]->afficher(shaderProgram);



    // gestion de la caméra
    glm::vec3 cameraPosition = kartDuJoueur.getPosition()+ glm::vec3(0.f,2.f,0.f)+ glm::toMat3(kartDuJoueur.getOrientation())* currentCamera;
    glm::vec3 cameraDirection= kartDuJoueur.getPosition() ;

   glm::mat4 camera = glm::lookAt(cameraPosition,cameraDirection, glm::vec3(0.f,1.f, 0.f));


    //Le projeté 2D de la caméra (matrice de projection)
    glm::mat4 cameraProjetee =  glm::perspective(90.f, WINDOW_WIDTH / (float) WINDOW_HEIGHT, 0.1f, 1000.f) * camera;

    //On balance ça au shader !
    GLint viewProjectionIndex = shaderProgram.getUniformIndex("viewProjection");
    shaderProgram.setUniform(viewProjectionIndex, cameraProjetee);
    //Pour le soleil
    GLint viewIndex = shaderProgram.getUniformIndex("view");
    shaderProgram.setUniform(viewIndex, camera);


    //-------------- CODE "APPLICATIF"(la logique du jeu quoi, + gestion des évènements) ----------


    sf::Time elapsed = clock.restart();
    kartDuJoueur.mettreAJour(elapsed);
    //IA1.mettreAJour(elapsed);


    IA1.setPositionIA(elapsed, map);



    detectionZonesRallentissantes(map,&kartDuJoueur);


    detectionCheckpoints(kartDuJoueur, &map);



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

          if (e.key.code == sf::Keyboard::Space){
            kartDuJoueur.freiner();
          }
           else if (e.key.code == sf::Keyboard::Down){
                kartDuJoueur.recule();
            }

            else if (e.key.code == sf::Keyboard::Up){
                kartDuJoueur.avance();
            }


            else if (e.key.code == sf::Keyboard::Right){
                kartDuJoueur.tourneADroite();
            }

            else if (e.key.code == sf::Keyboard::Left){
                kartDuJoueur.tourneAGauche();
            }

          else if (e.key.code == sf::Keyboard::B){
              currentCamera[2]=2.f;
          }

          else if (e.key.code == sf::Keyboard::F){

              currentCamera[2]=-2.f;
          }

          else if (e.key.code== sf::Keyboard::A){
              std::cout<<"kartdujouer"<<kartDuJoueur.getPosition()[0]<<","<<kartDuJoueur.getPosition()[2]<<std::endl;
          }








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
  music.stop();
	return EXIT_SUCCESS;
}
