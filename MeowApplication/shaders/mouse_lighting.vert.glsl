#version 450 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 colors;

uniform mat4 u_proj_mat = mat4(1.0f);
uniform mat4 u_model_mat = mat4(1.0f);

out vec4 pos;
out vec4 color;

void main()
{
    gl_Position = u_proj_mat * u_model_mat * position;
    //gl_Position = u_proj_mat * position;
    pos = position;
    color = colors;
}