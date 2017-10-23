#version 330 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float transparency;

void main()
{
   color = mix(texture(texture1, TexCoord), texture(texture2, vec2(TexCoord.x*(-1.0f),TexCoord.y)), transparency);
}