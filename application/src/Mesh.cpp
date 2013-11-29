#include "Mesh.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <ShaderProgram.hpp>

Mesh::Mesh()
{
  //en attendant les vrais modèles 3D (qui seront chargés par loadFromFile), un simple cube
  //(dessine à la main)
  vertices[0].position = glm::vec3(-0.5f, -0.5f, 0.5f);
  vertices[1].position = glm::vec3(0.5f, -0.5f, 0.5f);
  vertices[2].position = glm::vec3(-0.5f, 0.5f, 0.5f);
  vertices[3].position = glm::vec3(0.5f, 0.5f, 0.5f);
  vertices[4].position = glm::vec3(-0.5f, -0.5f, -0.5f);
  vertices[5].position = glm::vec3(0.5f, -0.5f, -0.5f);
  vertices[6].position = glm::vec3(-0.5f, 0.5f, -0.5f);
  vertices[7].position = glm::vec3(0.5f, 0.5f, -0.5f);

  indices[0] = 0; indices[1] = 1;
  indices[2] = 2; indices[3] = 3;
  indices[4] = 7; indices[5] = 1;
  indices[6] = 5; indices[7] = 4;
  indices[8] = 7; indices[9] = 6;
  indices[10] = 2; indices[11] = 4;
  indices[12] = 0; indices[13] = 1;

  modelMatrix = glm::mat4(1.);
  const GLsizeiptr verticesSize = 8 * sizeof(glimac::Vertex3D);
  vbo.setBufferData((const GLvoid* ) glm::value_ptr(vertices[0].position), verticesSize, GL_STATIC_DRAW);

  vao.enableVertexAttribArray(0);
  vao.vertexAttribPointer(vbo, 0, 3, GL_FLOAT, GL_TRUE, sizeof(glimac::Vertex3D), (const GLvoid* ) offsetof(glimac::Vertex3D, position));
}

void Mesh::loadFromFile(const std::string& cheminFichier)
{
  //Lolilol pour l'instant je fais rien mais plus tard j'utiliserai ASSIMP
}

void Mesh::mettreAJour()
{

}

void Mesh::afficher(const glimac::ShaderProgram& shaderProgram) const
{
  //Activer les bons shaders, et afficher l'objet comme il faut en fonction de la caméra
  //(peut etre que cette méthode aura des paramètres)

  GLint modelMatrixIndex = shaderProgram.getUniformIndex("model");
  shaderProgram.setUniform(modelMatrixIndex, modelMatrix);
  vao.bind();
  glDrawElements(GL_TRIANGLE_STRIP, GLsizei(14), GL_UNSIGNED_SHORT, (const GLvoid*) indices);
  vao.unbind();
}

void Mesh::setPositionEtOrientation(const glm::vec3& position, const glm::quat& orientation)
{
  //On met à jour la matrice modèle pour prendre en compte la nouvelle position et orientation
  modelMatrix = glm::translate(glm::mat4(1.f), position) * glm::toMat4(orientation);
}


