#pragma once
#include <GL/glew.h>


struct Matrix2D{
    GLfloat values[9];

};

Matrix2D translate(GLfloat tx, GLfloat ty);
Matrix2D scale(GLfloat sx, GLfloat sy);
Matrix2D rotate(GLfloat a);

inline Matrix2D operator *(const Matrix2D& lhs, const Matrix2D& rhs) {
    Matrix2D result;
    for(int j = 0; j < 3; ++j) {
        for(int i = 0; i < 3; ++i) {
            int idx = i + j * 3;
            result.values[idx] = 0.f;
            for(int k = 0; k < 3; ++k) {
                result.values[idx] += lhs.values[i + k * 3] * rhs.values[k + j * 3];
            }
        }
    }
    return result;
}
