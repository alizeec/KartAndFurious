#version 330
in vec4 FragColor;
in vec2 oTexCoord;

out vec4 oFragColor;
out vec3 fFragColor;

uniform sampler2D uTexture;


void main(void)
{
  oFragColor = FragColor;
  fFragColor = vec3(texture2D(uTexture, oTexCoord));

}
