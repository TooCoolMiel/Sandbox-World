#include "Texture.h"
#include <iostream>

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
	type = texType;

	int width, height, channels;

	stbi_set_flip_vertically_on_load(true);

	unsigned char* image_data = stbi_load(image, &width, &height, &channels, 4);
	if (image_data == NULL) {
		std::cout << "Failed to load image: " << stbi_failure_reason() << '\n';
		throw runtime_error("");
	}

	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(texType, ID);

	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(texType, 0, GL_RGBA, width, height, 0, format, pixelType, image_data);
	glGenerateMipmap(texType);

	stbi_image_free(image_data);

	glBindTexture(texType, 0);

}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit) {
	GLuint texLoc = glGetUniformLocation(shader.ID, uniform);
	shader.start();
	glUniform1i(texLoc, unit);
}

void Texture::start() {
	glBindTexture(type, ID);
}

void Texture::stop() {
	glBindTexture(type, 0);
}

void Texture::cleanUp() {
	glDeleteTextures(1, &ID);
}