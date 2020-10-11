#version 450 core

layout(location = 0) out vec4 color;

uniform sampler2D u_Texture;
uniform vec4 multColour = vec4(1, 1, 1, 1);

in vec2 texCoords;

void main()
{
	color = multColour * texture(u_Texture, texCoords);
}