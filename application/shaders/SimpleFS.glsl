#version 330
struct Material
{
  vec4 ambient;
  vec4 diffuse;
  vec4 specular;
};

in vec4 FragColor;
in vec4 NormalViewSpace;

out vec4 oFragColor;

const vec4 diffuseLightDirection = vec4(2,5,0,0);
const vec4 diffuseLightIntensity = vec4(1.0, 1.0,1.0,1.0);
const vec4 ambientLightIntensity = vec4 (0.4,0.4,0.4,1.0);
uniform Material material;

vec4 ADS()
{
  float fDotProduct = max(0.0, dot(NormalViewSpace, diffuseLightDirection));
  vec4 vDiffuseColor = material.diffuse * diffuseLightIntensity * fDotProduct;
  vec4 vAmbientColor = material.ambient * ambientLightIntensity;
 return vAmbientColor + vDiffuseColor;
}


void main(void)
{
  oFragColor = ADS(); //FragColor;
}

