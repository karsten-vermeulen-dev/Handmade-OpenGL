#version 460

in vec3 vertexIn;  
in vec4 colorIn;
in vec2 textureIn;

out vec3 vertexOut;
out vec4 colorOut;
out vec2 textureOut;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void)
{
	colorOut = colorIn;
	textureOut = textureIn;
	gl_PointSize = 15.0f;
	gl_Position = projection * view * model * vec4(vertexIn, 1.0f);
}