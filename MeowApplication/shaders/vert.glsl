#version 330 core

layout(location = 0) in vec4 position;
uniform mat4 u_pr_mat;

out vec4 pos;

void main()
{
    gl_Position = u_pr_mat * position;
    pos = position;
}