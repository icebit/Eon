#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;

out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = proj * view * model * vec4(position, 1.0f);
    texCoord = vec2(uv.x, 1.0 - uv.y);
}
