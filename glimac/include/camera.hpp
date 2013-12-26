#pragma once

#include <GL/glew.h>


namespace glimac {


struct Camera {
public:
    Camera(): Distance(5.f), AngleX(0.f), AngleY(0.f) {
    }

    void moveFront(float delta) {
        Distance -= delta;
        Distance = glm::max(0.1f, Distance);
    }

    void rotateLeft(float degrees) {
        AngleY += degrees;
    }

    void rotateUp(float degrees) {
        AngleX += degrees;
    }

    glm::mat4 getViewMatrix() const {
        glm::mat4 V = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -Distance));
        V = glm::rotate(V, AngleX, glm::vec3(1, 0, 0));
        V = glm::rotate(V, AngleY, glm::vec3(0, 1, 0));
        return V;
    }

private:
    float Distance;
    float AngleX, AngleY;
};

}
