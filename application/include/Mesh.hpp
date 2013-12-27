#ifndef MESH_HPP
#define MESH_HPP

#include <VBO.hpp>
#include <VAO.hpp>
#include <vector>
#include <glm/glm.hpp>
#include <string>
#include <ShaderProgram.hpp>
#include <glm/gtx/quaternion.hpp>

class Mesh
{
public:
  //Une structure interne à Mesh pour se simplifier la gestion des Materials
  struct Material
  {
    glm::vec4 ambientColor;
    glm::vec4 diffuseColor;
    glm::vec4 specularColor;
  };

  Mesh();
  ~Mesh();
  void loadFromFile(const std::string& cheminFichier);


  void mettreAJour();
  void afficher(const glimac::ShaderProgram& shaderProgram) const;

  void setPositionEtOrientation(const glm::vec3& position, const glm::quat& orientation);

private:
  glm::mat4 modelMatrix;
  /* Implémentation basique :
   * pour un VBO à l'indice 'i' correspond un VAO et un material à l'indice 'i'.
   * A voir plus tard si faut pas faire un truc plus proche, pour l'instant je me suis
   * concentré sur le résultat...
   * Utilisation des pointeurs parce que l'allocation des VBO/VAO est chiante
   * à gérer.
   */
  std::vector<glimac::LowLevelVBO* > meshVBOs;
  std::vector<glimac::VAO *> meshVAOs;
  std::vector<Material> materials;

  std::vector<std::vector<unsigned int>> indices;

};

#endif // MESH_HPP
