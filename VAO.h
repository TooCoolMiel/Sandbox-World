#pragma once

#include <glad/glad.h>
#include "VBO.h"

/*
	Vertex Array Object. Contains information like positions, and texture coordinates.

*/
struct VAO
{
	GLuint ID;
	GLuint attrib_count = 0;

	VAO();
	void addVBO(VBO& vbo, GLuint layout, GLuint size, GLenum type, GLuint stride, void* offset);
	void start();
	void stop();
	void cleanUp();
};

