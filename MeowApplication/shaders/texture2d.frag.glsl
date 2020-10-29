#version 450 core

out vec4 fragColor;

uniform sampler2D u_Texture;

in vec2 texCoords;
in vec4 outColor;

void main()
{
	vec4 texColor = texture(u_Texture, texCoords);
	fragColor = texColor;
	//gl_FragColor = color;
	//fragColor = outColor;
}