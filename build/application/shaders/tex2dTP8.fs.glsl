
#version 330


in vec2 vFragPosition;
in vec2 vFragTexCoord;
uniform sampler2D uTexture;




out vec3 fFragColor;

void main() {

   fFragColor = vec3(texture2D(uTexture, vFragTexCoord));
};
