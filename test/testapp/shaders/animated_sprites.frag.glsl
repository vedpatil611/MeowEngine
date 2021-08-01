#version 450 core

layout(location = 0) out vec4 fragColor;

uniform sampler2D u_Texture[32];
uniform int spritesCountX;
uniform int spritesCountY;
uniform int currentIndex;

in DATA {
	vec4 colour;
	vec2 uv;
	float tid;
} fs_data;

void main()
{
	vec4 texColour = fs_data.colour;

	int y = currentIndex / spritesCountX;
	int x = currentIndex % spritesCountX;
	float xDiff = float(1) / spritesCountX;
	float yDiff = float(1) / spritesCountY;
	vec2 uv = vec2(xDiff * (fs_data.uv.x + x), yDiff * (fs_data.uv.y + y));
	
	int tid = int(fs_data.tid + 0.5);
	if (tid >= 0)
	{
		texColour = texture(u_Texture[tid], uv);
	}

	fragColor = texColour;


}