
#version 330


layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexTexCoord;

out vec2 vFragPosition;
out vec2 vFragTexCoord;

uniform mat3 uModelMatrix;



void main() {
   vFragPosition = aVertexPosition;
   vFragTexCoord = aVertexTexCoord;

    gl_Position = vec4(aVertexPosition, 0, 1);

};

