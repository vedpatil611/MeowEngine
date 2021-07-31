#version 450 core

layout(location = 0) out vec4 fragColor;

uniform sampler2D u_Texture[32];

in DATA {
	vec4 colour;
	vec2 uv;
	float tid;
} fs_data;

void main()
{
	vec4 texColour = fs_data.colour;

	int tid = int(fs_data.tid + 0.5);
	if (tid >= 0)
	{
		texColour = texture(u_Texture[tid], fs_data.uv);
	}

	fragColor = texColour;
}
