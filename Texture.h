#pragma once

#include <glad/glad.h>
#include <stb/stb_image.h>
#include "Shader.h"

struct Texture
{
	GLuint ID;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void start();
	// Unbinds a texture
	void stop();
	// Deletes a texture
	void cleanUp();
};

