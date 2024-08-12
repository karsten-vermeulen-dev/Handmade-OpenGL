#version 460

in vec4 colorIn;
in vec3 vertexIn;  
in vec3 normalIn;
in vec2 textureIn;

out vec4 colorOut;
out vec3 vertexOut;
out vec3 normalOut;
out vec2 textureOut;

uniform mat4 view;
uniform mat4 model;
uniform mat3 normal;
uniform mat4 projection;

void main(void)
{
	colorOut = colorIn;
	textureOut = textureIn;
	normalOut = normalize(normal * normalIn);
	vertexOut = (model * vec4(vertexIn, 1.0)).xyz;
	gl_Position = projection * view * model * vec4(vertexIn, 1.0f);
}