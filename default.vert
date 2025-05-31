#version 330 core

layout(location = 0)in vec3 apos;
layout(location = 1)in vec2 a_texCoords;

out vec2 out_texCoords;

void main() {
	gl_Position = vec4(apos, 1.0);
	out_texCoords = a_texCoords;
}