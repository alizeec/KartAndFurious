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
uniform mat4 view = mat4(1);

const vec4 sunLightDirection = vec4(2,5,0,0);
const vec4 sunLightDiffuseIntensity = vec4(1.0, 1.0,1.0,1.0);
const vec4 sunLightSpecularIntensity = vec4(0.2, 0.2, 0.2,1.0);
const vec4 ambientLightIntensity = vec4 (0.1,0.1,0.1,1.0);
const float shininess = 500.0;

uniform Material material;

vec4 ADS()
{
  vec4 sunLightDirInViewSpace = view * sunLightDirection;
  float fDotProduct = max(0.0, dot(NormalViewSpace, sunLightDirInViewSpace));
  vec4 vDiffuseColor = material.diffuse * sunLightDiffuseIntensity * fDotProduct;
  vec4 vAmbientColor = material.ambient * ambientLightIntensity;

  /*
  vec4 vReflection = reflect(-sunLightDirInViewSpace, NormalViewSpace);
  float spec = max(0.0, dot(normalize(NormalViewSpace), vReflection));
  float fSpec = pow(spec, shininess);
  vec4 vSpecularColor = sunLightSpecularIntensity * material.specular * fSpec;
*/
  return vAmbientColor + vDiffuseColor ;//+ vSpecularColor;
}


void main(void)
{
  oFragColor = ADS(); //FragColor;
}

