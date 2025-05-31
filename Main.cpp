#include <iostream>
#include "Window.h"
#include "Shader.h"

int main() {

	/*
	* TODO: Please move this stuff to a game class or something for organization
	*/

	Window* game_window = new Window("Sandbox World", 1000, 900);
	Shader* default_shader = new Shader("default.vert", "default.frag");

	while (!game_window->shoudWindowClose()) {
		game_window->update();
		default_shader->start();

		default_shader->stop();
		game_window->swapBuffers();
	}

	delete default_shader;
	delete game_window;

	return 0;
}