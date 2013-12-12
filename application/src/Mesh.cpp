#include "Mesh.hpp"
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>
#include <Vertex3D.hpp>
#include <cstddef>
#include <sstream>
#include <glm/gtx/quaternion.hpp>

Mesh::Mesh()
  : modelMatrix(1.f)
{
  for (glimac::LowLevelVBO*& vbo : meshVBOs)
    vbo = nullptr;
  for (glimac::VAO*& vao : meshVAOs)
    vao = nullptr;
}

Mesh::~Mesh()
{
  for (glimac::LowLevelVBO*& vbo : meshVBOs)
    delete vbo;
  for (glimac::VAO*& vao : meshVAOs)
    delete vao;
}

void Mesh::loadFromFile(const std::string& cheminFichier)
{
  Assimp::Importer importer;

  const aiScene* scene = importer.ReadFile( cheminFichier, aiProcess_PreTransformVertices);

  if (!scene)
  {
    std::ostringstream errorMessage;
    errorMessage << "Impossible de trouver le fichier de modele 3D : " << cheminFichier << "." << std::endl;
    throw std::runtime_error(errorMessage.str());
  }

  //On prépare les vector pour qu'ils aient direct la bonne taille (mini optim)
  meshVBOs.resize(scene->mNumMeshes);
  meshVAOs.resize(scene->mNumMeshes);
  materials.resize(scene->mNumMeshes);
  indices.resize(scene->mNumMeshes);

  for (unsigned int i = 0; i < scene->mNumMeshes; ++i)
  {
    //On récupère le mesh courant
    const aiMesh* const mesh = scene->mMeshes[i];
    //On regarde quel material est lié au mesh courant
    const aiMaterial* const material = scene->mMaterials[mesh->mMaterialIndex];

    //On récupère les couleurs (par type de lumière) du material courant
    aiColor3D ambient;
    aiColor3D diffuse;
    aiColor3D specular;
    material->Get(AI_MATKEY_COLOR_AMBIENT, ambient);
    material->Get(AI_MATKEY_COLOR_DIFFUSE, diffuse);
    material->Get(AI_MATKEY_COLOR_SPECULAR, specular);
    materials[i].ambientColor = glm::vec4(ambient.r, ambient.g, ambient.b, 1.f);
    materials[i].diffuseColor = glm::vec4(diffuse.r, diffuse.g, diffuse.b, 1.f);
    materials[i].specularColor = glm::vec4(specular.r, specular.g, specular.b, 1.f);

    //On instancie le VBO et VAO qui va contenir les vertices et données d'organisation
    //(les vectors stockent des pointeurs)
    meshVBOs[i] = new glimac::LowLevelVBO();
    meshVAOs[i] = new glimac::VAO();

    //Ce vector ne dure que le temps de la fonctions, car ces vertices vont tout de suite après
    //etre envoyées à la carte graphique et n'auront pas besoin d'etre gardées en RAM
    std::vector<glimac::Vertex3D> vertices;
    vertices.reserve(mesh->mNumVertices);

    //On stocke un a un chaque vertices dans le vector (traduction assimp format => FatAndFurious format)
    //Note: On stocke les coordonnées de texture mais pour l'instant elles ne sont pas exploitées (à venir)
    for (unsigned int j = 0; j < mesh->mNumVertices; ++j)
    {
      glimac::Vertex3D current;
      current.position = glm::vec3(mesh->mVertices[j].x, mesh->mVertices[j].y, mesh->mVertices[j].z);
      current.normal = glm::vec3(mesh->mNormals[j].x, mesh->mNormals[j].y, mesh->mNormals[j].z);
      current.textureCoordinates = mesh->HasTextureCoords(0) ? glm::vec2(mesh->mTextureCoords[0][j].x, mesh->mTextureCoords[0][j].y) : glm::vec2(0.f, 0.f);
      vertices.push_back(current);
    }
    //On charge les indices pour dessiner : en effet Assimp stocke ses données de manière indéxées
    for (unsigned int j = 0; j < mesh->mNumFaces; ++j)
    {
      const aiFace& face = mesh->mFaces[j];
      for (unsigned int k = 0; k < face.mNumIndices; ++k)
      {
        indices[i].push_back(face.mIndices[k]);
      }
    }

    //On envoie les vertices à la carte graphique
    meshVBOs[i]->setBufferData((const GLvoid*) &vertices[0], vertices.size() * sizeof(glimac::Vertex3D), GL_STATIC_DRAW);

    //On dit à OpenGL comment on a organisé nos données
    meshVAOs[i]->vertexAttribPointer(*meshVBOs[i], 0, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::Vertex3D), (const GLvoid*) offsetof(glimac::Vertex3D, position));
    meshVAOs[i]->vertexAttribPointer(*meshVBOs[i], 1, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::Vertex3D), (const GLvoid*) offsetof(glimac::Vertex3D, textureCoordinates));
    meshVAOs[i]->vertexAttribPointer(*meshVBOs[i], 2, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::Vertex3D), (const GLvoid*) offsetof(glimac::Vertex3D, normal));

    //On active nos trois attributs (position, coordonnées de texture, normale)
    meshVAOs[i]->enableVertexAttribArray(0);
    meshVAOs[i]->enableVertexAttribArray(1);
    meshVAOs[i]->enableVertexAttribArray(2);

  }
}

void Mesh::mettreAJour()
{

}

void Mesh::afficher(const glimac::ShaderProgram& shaderProgram) const
{
  //Activer les bons shaders, et afficher l'objet comme il faut en fonction de la caméra
  //(peut etre que cette méthode aura des paramètres)

  GLint modelIndex = shaderProgram.getUniformIndex("model");
  shaderProgram.setUniform(modelIndex, modelMatrix);
  GLint diffuseIndex = shaderProgram.getUniformIndex("material.diffuse");
  GLint ambientIndex = shaderProgram.getUniformIndex("material.ambient");
  GLint specularIndex = shaderProgram.getUniformIndex("material.specular");

  for (unsigned int i = 0; i < meshVAOs.size(); ++i)
  {
    shaderProgram.setUniform(diffuseIndex, materials[i].diffuseColor);
    shaderProgram.setUniform(ambientIndex, materials[i].ambientColor);
    shaderProgram.setUniform(specularIndex, materials[i].specularColor);

    meshVAOs[i]->bind();
    glDrawElements(GL_TRIANGLES, indices[i].size(), GL_UNSIGNED_INT, &(indices[i][0]));
    meshVAOs[i]->unbind();
  }
}

void Mesh::setPositionEtOrientation(const glm::vec3& position, const glm::quat& orientation)
{
  //On met à jour la matrice modèle pour prendre en compte la nouvelle position et orientation
  modelMatrix = glm::scale(glm::mat4(1.f), glm::vec3(0.5f));
  modelMatrix = glm::toMat4(orientation) * modelMatrix;
  modelMatrix = glm::translate(glm::mat4(1.f), position) * modelMatrix;
}


