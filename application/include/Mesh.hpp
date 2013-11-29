#ifndef MESH_HPP
#define MESH_HPP

#include <VAO.hpp>
#include <VBO.hpp>
#include <Vertex3D.hpp>
#include <string>
#include <ShaderProgram.hpp>
#include <glm/gtc/quaternion.hpp>

class Mesh
{
public:
  Mesh();
  void loadFromFile(const std::string& cheminFichier);

  void mettreAJour();
  void afficher(const glimac::ShaderProgram& shaderProgram) const;

  void setPositionEtOrientation(const glm::vec3& position, const glm::quat& orientation);

private:
  //Tableau fixe pour le cube mais faudra faire autrement pour un vrai modèle 3D
  //dont on ne connait pas la taille à l'avance
  glimac::Vertex3D vertices[8];

  GLushort indices[14];
  glimac::LowLevelVBO vbo;
  glimac::VAO vao;

  glm::mat4 modelMatrix;
  //Stocker aussi la texture si besoin...
};

#endif // MESH_HPP
