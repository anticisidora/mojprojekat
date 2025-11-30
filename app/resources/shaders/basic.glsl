//#shader vertex
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    TexCoords = aTexCoords;
    gl_Position = projection * view * vec4(FragPos, 1.0);
}

//#shader fragment
#version 330 core

out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

uniform float lightIntensity;

uniform sampler2D texture_diffuse1;
uniform vec3 viewPos;


struct DirLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform DirLight dirLight;


struct PointLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};
uniform PointLight pointLight;


void main()
{
    vec3 texColor = texture(texture_diffuse1, TexCoords).rgb;

    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);


    vec3 lightDir = normalize(-dirLight.direction);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);

    vec3 ambD  = dirLight.ambient  * texColor * 1.3;
    vec3 diffD = dirLight.diffuse  * diff * texColor;
    vec3 specD = dirLight.specular * spec;

    vec3 dirResult = (ambD + diffD + specD) * lightIntensity;


    vec3 lightDirP = normalize(pointLight.position - FragPos);

    float diffP = max(dot(norm, lightDirP), 0.0);
    vec3 reflectDirP = reflect(-lightDirP, norm);
    float specP = pow(max(dot(viewDir, reflectDirP), 0.0), 8.0);

    float distance = length(pointLight.position - FragPos);
    float attenuation = 1.0 /
    (pointLight.constant +
    pointLight.linear * distance +
    pointLight.quadratic * distance * distance);

    vec3 ambP  = pointLight.ambient  * texColor;
    vec3 diffP2 = pointLight.diffuse  * diffP * texColor;
    vec3 specP2 = pointLight.specular * specP;

    vec3 pointResult = ((ambP + diffP2 + specP2) * attenuation) * lightIntensity;


    vec3 finalColor = dirResult + pointResult;

    FragColor = vec4(finalColor, 1.0);
}
