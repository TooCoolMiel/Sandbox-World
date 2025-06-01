#version 330 core

layout(location = 0)in vec3 apos;
layout(location = 1)in vec2 a_texCoords;

out vec2 out_texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
	gl_Position = proj * view * model * vec4(apos, 1.0);
	out_texCoords = a_texCoords;
}