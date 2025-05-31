#include <iostream>
#include "Window.h"
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

int main() {

	/*
	* TODO: Please move this stuff to a game class or something for organization
	*/

	Window game_window("Sandbox World", 1000, 900);
	Shader default_shader("default.vert", "default.frag");

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	GLuint indices[] = {
		0,1,2,
		2,3,0
	};

	VAO vao;
	vao.start();
	VBO vbo(vertices, sizeof(vertices));
	EBO ebo(indices, sizeof(indices));
	vao.addVBO(vbo, 0);
	vao.stop();
	vbo.stop();
	ebo.stop();


	while (!game_window.shoudWindowClose()) {
		game_window.update();

		default_shader.start();
		vao.start();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		vao.stop();
		default_shader.stop();

		game_window.swapBuffers();
	}

	vao.cleanUp();
	vbo.cleanUp();
	ebo.cleanUp();

	default_shader.cleanUp();
	game_window.cleanUp();

	return 0;
}