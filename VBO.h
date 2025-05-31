#pragma once

#include <glad/glad.h>

struct VBO
{
	GLuint ID;

	VBO(GLfloat* vertices, GLsizeiptr size);
	void start();
	void stop();
	void cleanUp();

};

