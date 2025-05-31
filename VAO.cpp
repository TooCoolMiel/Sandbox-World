#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

void VAO::addVBO(VBO& vbo, GLuint layout, GLuint size, GLenum type, GLuint stride, void* offset) {
	vbo.start();
	glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vbo.stop();
	attrib_count++;
}

// Binds the VAO
void VAO::start()
{
	glBindVertexArray(ID);
}

// Unbinds the VAO
void VAO::stop()
{
	glBindVertexArray(0);
}

// Deletes the VAO
void VAO::cleanUp()
{
	while (attrib_count--) {
		glDisableVertexAttribArray(attrib_count);
	}
	glDeleteVertexArrays(1, &ID);
}