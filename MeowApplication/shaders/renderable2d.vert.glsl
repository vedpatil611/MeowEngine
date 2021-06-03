#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 colors;
layout(location = 2) in vec2 texcoords;

uniform mat4 u_proj_mat = mat4(1.0f);
uniform mat4 u_view_mat = mat4(1.0f);
uniform mat4 u_model_mat = mat4(1.0f);

out vec4 color;

void main()
{
    gl_Position = u_proj_mat * u_view_mat * u_model_mat * vec4(position, 1.0f);
    //gl_Position = u_proj_mat * position;
    color = colors;
}