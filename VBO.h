#pragma once

#include <glad/glad.h>

/*
	VBO stores data like positions or texture coordinates.
*/
struct VBO
{
	GLuint ID;

	VBO(GLfloat* vertices, GLsizeiptr size);
	void start();
	void stop();
	void cleanUp();

};

