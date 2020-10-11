#version 450 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texcoords;

//uniform vec4 u_BlendColor;
uniform mat4 u_MVP;

out vec2 texCoords;

void main()
{
	gl_Position = u_MVP * position;
	texCoords = texcoords;
}
