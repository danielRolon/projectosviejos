#version 330 core

in vec4 v_Color;
in vec2 v_TexCoord;
in float v_TexIndex;

uniform sampler2D u_Textures[2];

void main()
{
    vec4 dColor = vec4(1);

    int index = int(v_TexIndex);

    switch(index)
    {
        case -1:
            dColor = v_Color;
            break;
        
        default:
            dColor = texture(u_Textures[index], v_TexCoord) * v_Color;
            break;

    }

    gl_FragColor = dColor;
}