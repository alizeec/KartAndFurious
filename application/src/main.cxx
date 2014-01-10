#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <GL/glew.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <sstream>

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
#include "Program.hpp"
#include "Vertex2DUV.hpp"
#include "Matrix2D.hpp"


#include <glm/gtc/matrix_transform.hpp>

int main() {
  const size_t WINDOW_WIDTH = 1024;
  const size_t WINDOW_HEIGHT = 768;
  bool PointX = false;
  bool PointZ = false;
  bool intro = true;
  bool choixMap = true;
  bool choixKart = true;
  bool commandes = true;
  std::string nomMap;
  std::string nomKartJoueur;
  std::string nomKartIA;
  std::string nomKartIA2;

  bool demandeAQuitter = false;

  //------------- INITIALISATION ---------------------
  //Création de la fenetre et initialisation de GLEW
  sf::RenderWindow window;
  window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Kart and Furious");
  GLenum glewCode = glewInit();
  if(GLEW_OK != glewCode) {
    std::cerr << "Unable to initialize GLEW : " << glewGetErrorString(glewCode) << std::endl;
    return EXIT_FAILURE;
  }

   sf::Image image;
    if (!image.loadFromFile("application/data/intro.png"))
    {
        std::cout << "error" <<std::endl;
    }
    GLuint texture;
    glGenTextures(1,  &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D( GL_TEXTURE_2D , 0,GL_RGBA, image.getSize().x,  image.getSize().y,  0,  GL_RGBA,  GL_UNSIGNED_BYTE,  image.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);


    glimac::Program program = glimac::loadProgram("application/shaders/tex2dTP8.vs.glsl", "application/shaders/tex2dTP8.fs.glsl");
    program.use();


    GLuint idProg3 = program.getGLId();
    GLint location3= glGetUniformLocation(idProg3, "uTexture");

  glimac::LowLevelVBO vbo;
    vbo.bind(); // bindage


    glimac::Vertex2DUV vertices[] = {
	{ 1, -1, 1, 1 },	
	{ -1, -1, 0, 1 },        
        { -1, 1, 0 ,0},
        { 1, 1, 1, 0 }
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW ); // envoi des données
    glBindBuffer(GL_ARRAY_BUFFER,0);

    glimac::VAO vao;
    vao.bind();
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    vbo.bind(); // bindage
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE, sizeof(glimac::Vertex2DUV),(const void*) offsetof(glimac::Vertex2DUV, x)  );
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(glimac::Vertex2DUV),(const void*) offsetof(glimac::Vertex2DUV, u) );



    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    while (intro == true)
    {

	if(demandeAQuitter == true){
		intro = false;
	}

        // Rendering code goes here
        glClear(GL_COLOR_BUFFER_BIT);

         vao.bind();
        glBindTexture(GL_TEXTURE_2D, texture);

       glUniform1i(location3, 0);
        glDrawArrays(GL_QUADS,0,4);




        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);


        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.type == sf::Event::MouseButtonPressed)
	   {
		    if (event.mouseButton.button == sf::Mouse::Left)
		    {
			if(event.mouseButton.x >0 && 	event.mouseButton.x<750 && event.mouseButton.y >470 && event.mouseButton.y < 530){			
				intro = false;
			}	
		    }
	   } 
	   if (event.type == sf::Event::Closed){
                window.close();
                demandeAQuitter = true;
	   }
        }

        window.display();
    }

    glDeleteTextures(1,&texture);

    sf::Image image2;
    if (!image2.loadFromFile("application/data/choix_circuit.png"))
    {
        std::cout << "error" <<std::endl;
    }
    GLuint texture2;
    glGenTextures(1,  &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexImage2D( GL_TEXTURE_2D , 0,GL_RGBA, image2.getSize().x,  image2.getSize().y,  0,  GL_RGBA,  GL_UNSIGNED_BYTE,  image2.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);


    vbo.bind(); // bindage

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW ); // envoi des données
    glBindBuffer(GL_ARRAY_BUFFER,0);

    vao.bind();
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    vbo.bind(); // bindage
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE, sizeof(glimac::Vertex2DUV),(const void*) offsetof(glimac::Vertex2DUV, x)  );
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(glimac::Vertex2DUV),(const void*) offsetof(glimac::Vertex2DUV, u) );



    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    while (choixMap == true)
    {



        // Rendering code goes here
        glClear(GL_COLOR_BUFFER_BIT);

         vao.bind();
        glBindTexture(GL_TEXTURE_2D, texture2);

       glUniform1i(location3, 0);
        glDrawArrays(GL_QUADS,0,4);




        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);


        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.type == sf::Event::MouseButtonPressed)
	   {
		    if (event.mouseButton.button == sf::Mouse::Left)
		    {
			//std::cout << "the right button was pressed" << std::endl;
			if(event.mouseButton.x >640 && 	event.mouseButton.x<930 && event.mouseButton.y >247 && event.mouseButton.y < 484){			
				nomMap = "application/KAF/map.KAF";
				choixMap = false;
			}else if(event.mouseButton.x >373 && 	event.mouseButton.x<688 && event.mouseButton.y >468 && event.mouseButton.y < 702){
				nomMap = "application/KAF/map.KAF";
				choixMap = false;
			}	
		    }
	   } 
	   if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

    glDeleteTextures(1,&texture);

    sf::Image image3;
    if (!image3.loadFromFile("application/data/choix_voiture.png"))
    {
        std::cout << "error" <<std::endl;
    }
    GLuint texture3;
    glGenTextures(1,  &texture3);
    glBindTexture(GL_TEXTURE_2D, texture3);
    glTexImage2D( GL_TEXTURE_2D , 0,GL_RGBA, image3.getSize().x,  image3.getSize().y,  0,  GL_RGBA,  GL_UNSIGNED_BYTE,  image3.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    vbo.bind(); // bindage

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW ); // envoi des données
    glBindBuffer(GL_ARRAY_BUFFER,0);

    //glimac::VAO vao;
    vao.bind();
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    vbo.bind(); // bindage
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE, sizeof(glimac::Vertex2DUV),(const void*) offsetof(glimac::Vertex2DUV, x)  );
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(glimac::Vertex2DUV),(const void*) offsetof(glimac::Vertex2DUV, u) );



    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    while (choixKart == true)
    {



        // Rendering code goes here
        glClear(GL_COLOR_BUFFER_BIT);

         vao.bind();
        glBindTexture(GL_TEXTURE_2D, texture3);

       glUniform1i(location3, 0);
        glDrawArrays(GL_QUADS,0,4);




        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);


        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.type == sf::Event::MouseButtonPressed)
	   {
		    if (event.mouseButton.button == sf::Mouse::Left)
		    {
			//std::cout << "the right button was pressed" << std::endl;
			std::cout<< "x : " << event.mouseButton.x << std::endl; 
			std::cout<< "y : " << event.mouseButton.y << std::endl; 
			if(event.mouseButton.x >660 && 	event.mouseButton.x<1010 && event.mouseButton.y >220 && event.mouseButton.y < 460){			
				nomKartJoueur = "application/KAF/kart2.KAF";
				nomKartIA = "application/KAF/kart3.KAF";
				nomKartIA2 = "application/KAF/kart1.KAF";
				choixKart = false;
			}else if(event.mouseButton.x >680 && 	event.mouseButton.x<1010 && event.mouseButton.y >490 && event.mouseButton.y < 740){
				nomKartJoueur = "application/KAF/kart1.KAF";
				nomKartIA = "application/KAF/kart2.KAF";
				nomKartIA2 = "application/KAF/kart3.KAF";
				choixKart = false;
			}else if(event.mouseButton.x >300 && 	event.mouseButton.x<670 && event.mouseButton.y >490 && event.mouseButton.y < 740){
				nomKartJoueur = "application/KAF/kart3.KAF";
				nomKartIA = "application/KAF/kart1.KAF";
				nomKartIA2 = "application/KAF/kart2.KAF";
				choixKart = false;
			}	
		    }
	   } 
	   if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

    glDeleteTextures(1,&texture);

sf::Image image4;
    if (!image4.loadFromFile("application/data/commandes.png"))
    {
        std::cout << "error" <<std::endl;
    }
    GLuint texture4;
    glGenTextures(1,  &texture4);
    glBindTexture(GL_TEXTURE_2D, texture4);
    glTexImage2D( GL_TEXTURE_2D , 0,GL_RGBA, image4.getSize().x,  image4.getSize().y,  0,  GL_RGBA,  GL_UNSIGNED_BYTE,  image4.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    vbo.bind(); // bindage

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW ); // envoi des données
    glBindBuffer(GL_ARRAY_BUFFER,0);

    //glimac::VAO vao;
    vao.bind();
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);


    vbo.bind(); // bindage
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE, sizeof(glimac::Vertex2DUV),(const void*) offsetof(glimac::Vertex2DUV, x)  );
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(glimac::Vertex2DUV),(const void*) offsetof(glimac::Vertex2DUV, u) );



    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    while (commandes == true)
    {



        // Rendering code goes here
        glClear(GL_COLOR_BUFFER_BIT);

         vao.bind();
        glBindTexture(GL_TEXTURE_2D, texture4);

       glUniform1i(location3, 0);
        glDrawArrays(GL_QUADS,0,4);




        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);


        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.type == sf::Event::MouseButtonPressed)
	   {
		    if (event.mouseButton.button == sf::Mouse::Left)
		    {
			if(event.mouseButton.x >660 && 	event.mouseButton.x<1010 && event.mouseButton.y >220 && event.mouseButton.y < 460){			
				commandes = false;
			}	
		    }
	   } 
	   if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

    glDeleteTextures(1,&texture);
  //On active le test de profondeur dans OpenGL
  glEnable(GL_DEPTH_TEST);

  //-----------------------------------------------------
  // Initialisation du generateur de nbre aleatoire
  srand(time(nullptr));

  // Random entre 1 et 5
  int rand_music = (rand() % 5) + 1;

  // Creation variables pour chemin du fichier
  std::string way_start = "application/music/";
  std::string way_end = ".ogg";
  std::string way_access;

  std::stringstream sstm;
  sstm << way_start << rand_music << way_end;
  way_access = sstm.str();

  // Open music
  sf::Music music;
  if (!music.openFromFile(way_access)) return -1;



  /* initialisation de la map */
  Map map;

  LoadKAFMap(&map,nomMap);
  LoadKAFCollision(&map,"application/KAF/mapFriction.KAF");
  LoadKAFCheckpoint(&map, "application/KAF/mapCheckpoint.KAF");
std::cout<< map.getChemin()<<std::endl;
  int numPoint = 0;
  Point3D current_point = map.trajet[0];


  //Création du Kart "logique" qui va contenir le code de déplacement
  Kart kartDuJoueur;
  kartDuJoueur.etatFreinage = false;
  kartDuJoueur.updatePosition(map.getLigneDepartPosition());
  kartDuJoueur.updateOrientation(map.getLigneDepartAngle());
  LoadKAFKart(&kartDuJoueur,nomKartJoueur);

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
 shaderProgram.loadProgram("application/shaders/Simple3DVS.glsl","application/shaders/SimpleFS.glsl");
 shaderProgram.use();

   //pour la camera

   glm::vec3 currentCamera=glm::vec3(0.f,0.f,2.f);

  sf::Clock clock;


  music.play();


  //--------- BOUCLE DE JEU ---------------
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
