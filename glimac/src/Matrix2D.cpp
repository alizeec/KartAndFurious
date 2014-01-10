#include <math.h>
#include <GL/glew.h>

#include"../include/Matrix2D.hpp"

Matrix2D translate(GLfloat tx, GLfloat ty){
    Matrix2D result;
    result.values[0]=1.;
    result.values[1]=0.;
    result.values[2]=0.;

    result.values[3]=0;
    result.values[4]=1;
    result.values[5]=0;

    result.values[6]=tx;
    result.values[7]=ty;
    result.values[8]=1;

    return result;
}
Matrix2D scale(GLfloat sx,GLfloat sy){
    Matrix2D result;
    result.values[0]=sx;
    result.values[1]=0;
    result.values[2]=0;

    result.values[3]=0;
    result.values[4]=sy;
    result.values[5]=0;

    result.values[6]=0;
    result.values[7]=0;
    result.values[8]=1;
    return result;
}
Matrix2D rotate(GLfloat a){
    float radian =(a*3.14)/180;
    Matrix2D result;
    result.values[0]=cos(radian);
    result.values[1]=sin(radian);
    result.values[2]=0;

    result.values[3]=-sin(radian);
    result.values[4]=cos(radian);
    result.values[5]=0;

    result.values[6]=0;
    result.values[7]=0;
    result.values[8]=1;
    return result;
}


