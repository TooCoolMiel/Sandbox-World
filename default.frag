#version 330 core

in vec2 out_texCoords;

out vec4 FragColor;

uniform sampler2D tex;

void main() {
	FragColor = texture(tex, out_texCoords);
}