#pragma once

#include <glad/glad.h>

struct EBO
{

	GLuint ID;

	EBO(GLuint* indices, GLsizeiptr size);
	void start();
	void stop();
	void cleanUp();
};

