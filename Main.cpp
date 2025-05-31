#include <iostream>
#include "Window.h"
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"

int main() {

	/*
	* TODO: Please move this stuff to a game class or something for organization
	*/

	Window game_window("Sandbox World", 1000, 900);
	Shader default_shader("default.vert", "default.frag");

	GLfloat vertices[] = {
		// Positions		 |	TexCoords
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f
	};

	GLuint indices[] = {
		0, 2, 1, // Upper triangle
		0, 3, 2 // Lower triangle
	};

	VAO vao;
	vao.start();
	VBO vbo(vertices, sizeof(vertices));
	EBO ebo(indices, sizeof(indices));
	vao.addVBO(vbo, 0, 3, GL_FLOAT, 5 * sizeof(GLfloat), (void*)0);
	vao.addVBO(vbo, 1, 2, GL_FLOAT, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	vao.stop();
	vbo.stop();
	ebo.stop();

	Texture my_texture("apple.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	my_texture.texUnit(default_shader, "tex", 0);


	default_shader.start();
	vao.start();
	my_texture.start();

	while (!game_window.shoudWindowClose()) {
		game_window.update();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		game_window.swapBuffers();
	}
	vao.stop();
	my_texture.stop();
	default_shader.stop();

	vao.cleanUp();
	vbo.cleanUp();
	ebo.cleanUp();

	default_shader.cleanUp();
	game_window.cleanUp();

	return 0;
}