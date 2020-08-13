#version 450 core

out vec4 outColor;

in vec4 pos;
in vec4 color;

void main()
{
    
    outColor = color;
}