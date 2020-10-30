#version 450 core

layout(location = 0) out vec4 color;

uniform sampler2D u_Texture;
uniform vec2 u_LightPos;
uniform float u_LightSize = 10;
uniform vec4 multColour = vec4(1, 1, 1, 1);

in vec2 texCoords;
in vec4 pos;

void main()
{
	float intensity = u_LightSize / length(pos.xy - u_LightPos);
	color = texture(u_Texture, texCoords) * intensity;
	//color = multColour * texture(u_Texture, texCoords) * intensity;
}