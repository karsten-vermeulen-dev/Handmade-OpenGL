#version 460

in vec3 vertexOut;
in vec4 colorOut;
in vec2 textureOut;
out vec4 pixelColor;

uniform sampler2D textureImage;

void main(void)
{
	vec2 uv;
	uv.x = textureOut.x;
	uv.y = 1 - textureOut.y;
	pixelColor = colorOut * texture(textureImage, textureOut).r;
}