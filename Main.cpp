#include <iostream>
#include "Window.h"
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main() {

	/*
	* TODO: Please move this stuff to a game class or something for organization
	*/

	Window game_window("Sandbox World", 1000, 900);
	Shader default_shader("default.vert", "default.frag");

	GLfloat vertices[] = {
		//     COORDINATES   /   TexCoord  //
		-0.5f, 0.0f,  0.5f,   	0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,   	5.0f, 0.0f,
		 0.5f, 0.0f, -0.5f,   	0.0f, 0.0f,
		 0.5f, 0.0f,  0.5f,		5.0f, 0.0f,
		 0.0f, 0.8f,  0.0f,		2.5f, 5.0f
	};

	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3,
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4
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

	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	default_shader.start();
	vao.start();
	my_texture.start();

	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
	proj = glm::perspective(glm::radians(45.0f), (float)game_window.width / (float)game_window.height, 0.1f, 100.0f);

	int modelLoc = glGetUniformLocation(default_shader.ID, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	int viewLoc = glGetUniformLocation(default_shader.ID, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	int projLoc = glGetUniformLocation(default_shader.ID, "proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
	
	while (!game_window.shoudWindowClose()) {
		game_window.update();

		double currTime = glfwGetTime();
		if (currTime - prevTime >= 1 / 60) {
			rotation += 1.5;
			prevTime = currTime;
		}

		model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(GLuint), GL_UNSIGNED_INT, nullptr);

		game_window.swapBuffers();
	}
	vao.stop();
	my_texture.stop();
	default_shader.stop();

	vao.cleanUp();
	vbo.cleanUp();
	ebo.cleanUp();

	my_texture.cleanUp();

	default_shader.cleanUp();
	game_window.cleanUp();

	return 0;
}