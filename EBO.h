#pragma once

#include <glad/glad.h>

/*
	Index array object store VAO indices allowing for more efficent VAOs.
*/
struct EBO
{

	GLuint ID;

	EBO(GLuint* indices, GLsizeiptr size);
	void start();
	void stop();
	void cleanUp();
};

