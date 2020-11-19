#version 450 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texcoords;

uniform mat4 u_proj_mat = mat4(1.0f);
uniform mat4 u_view_mat = mat4(1.0f);
uniform mat4 u_model_mat = mat4(1.0f);

out vec2 texCoords;
out vec4 pos;

void main()
{
	gl_Position = u_model_mat * u_view_mat * u_proj_mat * position;
	pos = position;
	texCoords = texcoords;
}
