#pragma once

#include <glad/glad.h>
#include "VBO.h"

struct VAO
{
	GLuint ID;
	GLuint attrib_count = 0;

	VAO();
	void addVBO(VBO& vbo, GLuint layout);
	void start();
	void stop();
	void cleanUp();
};

