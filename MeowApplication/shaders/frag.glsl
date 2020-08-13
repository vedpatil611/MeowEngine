#version 330 core

out vec4 outColor;

uniform vec4 u_Color = vec4(1.0, 0.0, 0.0, 1.0);
uniform vec2 u_LightPos;
uniform float u_LightSize = 100;

in vec4 pos;

void main()
{
    float intensity = u_LightSize / length(pos.xy - u_LightPos);
    outColor = u_Color * intensity;
}