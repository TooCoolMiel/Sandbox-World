#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

using std::runtime_error;

/*
* Our window struct.
* Please remember to only make one.
*/
struct Window
{
	
	// Our window handle
	GLFWwindow* window_handle;

	int width;
	int height;
	const char* title;

	// Creates a window using parameters as settings
	Window(const char* title, int width, int height);

	// Updates the window by clear the color buffer and polling events
	void update();

	/*
	* Swaps the windows buffers
	* Reminder to render BEFORE this
	*/ 
	void swapBuffers();

	// Returns whether the window should close
	bool shoudWindowClose();

	// Destroys the window and terminates GLFW
	void cleanUp();
};

