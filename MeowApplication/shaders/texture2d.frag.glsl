#version 450 core

layout(location = 0) out vec4 color;

uniform sampler2D u_Texture;

in vec4 texCoords;

void main()
{
	color = texture(u_Texture, texCoords);
}