#include "VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size) {

	glGenBuffers(1, &ID);
	start();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	stop();
}

void VBO::start() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::stop() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::cleanUp() {
	glDeleteBuffers(1, &ID);
}