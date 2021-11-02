#version 330 core

in vec2 TexCoord;
out vec4 FragColour;

uniform sampler2D texture1;

void main()
{
    FragColour = texture(texture1, TexCoord);
}