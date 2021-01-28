#version 450 core

layout(location = 0) out vec4 fragColor;

uniform sampler2D u_Texture;
uniform int spritesCountX;
uniform int spritesCountY;
uniform int currentIndex;

in vec2 texCoords;
//in vec4 outColor;

void main()
{
	int y = currentIndex / spritesCountX;
	int x = currentIndex % spritesCountX;
	float xDiff = float(1) / spritesCountX;
	float yDiff = float(1) / spritesCountY;
	vec2 uv = vec2(xDiff * (texCoords.x + x), yDiff * (texCoords.y + y));
	vec4 texColor = texture(u_Texture, uv);
	fragColor = texColor;
}