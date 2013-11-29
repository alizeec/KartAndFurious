#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Mesh.hpp"
#include "Kart.hpp"
#include <glm/gtc/matrix_transform.hpp>

int main() {
  const size_t WINDOW_WIDTH = 800;
  const size_t WINDOW_HEIGHT = 600;

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


  //Chargement des données 3D (pour l'instant ça marche pas, vos Mesh sont tous des cubes de taille 1)
  Mesh circuit3D;
  circuit3D.loadFromFile("...");
  Mesh kart3D;
  kart3D.loadFromFile("...");

  //Création du Kart "logique" qui va contenir le code de déplacement
  Kart kartDuJoueur;

  //On créé les ShaderProgram de base (le code des shaders est a regarder et devra etre modifie plus
  // tard pour la gestion des textures entre autres)
  glimac::ShaderProgram shaderProgram;
  std::string logInfo;
  shaderProgram.addShader(GL_VERTEX_SHADER, "shaders/Simple3DVS.glsl");
  shaderProgram.addShader(GL_FRAGMENT_SHADER, "shaders/SimpleFS.glsl");
  if (!shaderProgram.compileAndLinkShaders(logInfo))
  {
    std::cerr << logInfo << std::endl;
    return EXIT_FAILURE;
  }
  shaderProgram.use();

  sf::Clock clock;


  //--------- BOUCLE DE JEU ---------------
  bool demandeAQuitter = false;
  do
  {
    //-----------------RENDU 3D-----------------------
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //On affiche le circuit (pas encore parce que c'est pas pret)
    //circuit3D.afficher(shaderProgram);

    //On met à jour la position et l'orientation du modèle 3D
    //par rapport au Kart "logique" qui gère le déplacement
    kart3D.setPositionEtOrientation(kartDuJoueur.getPosition(), kartDuJoueur.getOrientation());
;
    //Enfin on affiche le Kart 3D (un cube pour l'instant)
    //C'est lui qui se charge d'envoyer la bonne matrice modele au shaderProgram
    kart3D.afficher(shaderProgram);

    //La caméra est pour l'instant fixe
    glm::mat4 camera =  glm::lookAt(glm::vec3(0.f, 2.f, 1.f), glm::vec3(0.f,0.f,0.f), glm::vec3(0.f, 1.f, 0.f));
    //Le projeté 2D de la caméra (matrice de projection)
    glm::mat4 cameraProjetee =  glm::perspective(90.f, WINDOW_WIDTH / (float) WINDOW_HEIGHT, 0.1f, 1000.f) * camera;

    //On balance ça au shader !
    GLint viewProjectionIndex = shaderProgram.getUniformIndex("viewProjection");
    shaderProgram.setUniform(viewProjectionIndex, cameraProjetee);


    //-------------- CODE "APPLICATIF"(la logique du jeu quoi, + gestion des évènements) ----------

    //On met à jour le Kart "logique" du joueur par rapport aux évènements claviers
    //(faudrait que je demande à Laurent mais c'est bizarre de mettre ça avant la gestion des évènements)
    //parce que du coup là on a un tour de boucle de retard...)

    sf::Time elapsed = clock.restart();
    kartDuJoueur.mettreAJour(elapsed);


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

            else if (e.key.code == sf::Keyboard::Up)
                kartDuJoueur.avance();

            else if (e.key.code == sf::Keyboard::Left)
                kartDuJoueur.tourneAGauche();

            else if (e.key.code == sf::Keyboard::Right)
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
            break;
        default:
          break;
      }
    }
    //Equivalent du swapBuffer de la SDL
    window.display();
  } while (!demandeAQuitter);

	return EXIT_SUCCESS;
}