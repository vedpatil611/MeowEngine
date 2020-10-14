#version 450 core

layout(location = 0) out vec4 color;

uniform sampler2D u_Texture;

in vec2 texCoords;
in vec4 outColor;

void main()
{
	vec4 texColor = texture(u_Texture, texCoords);
	color = texColor;
	//color = outColor;
}