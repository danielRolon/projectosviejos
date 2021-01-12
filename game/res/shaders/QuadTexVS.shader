#version 330 core
layout (location = 0) in vec4 a_Coord;
layout (location = 1) in vec4 a_Color;
layout (location = 2) in vec2 a_TexCoord;
layout (location = 3) in float a_TexIndex;

out vec4 v_Color;
out vec2 v_TexCoord;
out float v_TexIndex;

uniform mat4 v_ProjectionView;

void main()
{
    gl_Position = v_ProjectionView * a_Coord;

    v_Color    = a_Color;
    v_TexCoord = a_TexCoord;
    v_TexIndex = a_TexIndex;
}