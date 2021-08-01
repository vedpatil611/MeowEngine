#version 450 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 colour;
layout(location = 2) in vec2 texcoords;
layout(location = 3) in float tex_id;

uniform mat4 u_proj_mat = mat4(1.0f);
uniform mat4 u_view_mat = mat4(1.0f);
uniform mat4 u_model_mat = mat4(1.0f);

out DATA {
	vec4 colour;
	vec2 uv;
	float tid;
} vs_data;

void main()
{
	gl_Position = u_proj_mat * u_view_mat * u_model_mat * position;
	vs_data.colour = colour;
	vs_data.uv = texcoords;
	vs_data.tid = tex_id;
}
