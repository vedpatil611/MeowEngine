#version 450 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 colors;

uniform mat4 u_proj_mat;
uniform mat4 u_model_mat;

out vec4 pos;
out vec4 color;

void main()
{
    gl_Position = u_proj_mat * u_model_mat * position;
    pos = position;
    color = colors;
}