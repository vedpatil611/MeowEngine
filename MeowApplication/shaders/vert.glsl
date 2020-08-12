#version 330 core

layout(location = 0) in vec3 position;
uniform mat4 pr_mat;

void main()
{
    gl_Position = pr_mat * vec4(position, 1.0);
}