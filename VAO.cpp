#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

void VAO::addVBO(VBO& vbo, GLuint layout) {
	vbo.start();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
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