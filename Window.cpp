#include "Window.h"

Window::Window(const char* title, int width, int height) :
	title(title), width(width), height(height)
{
	// Check for GLFW initialization errors
	if (!glfwInit()) {
		throw runtime_error("Couldn't intialize GLFW!\n");
	}

	// Set up window hints
	glfwDefaultWindowHints();
	// Set the window so it is unresizeable and not visible
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	// Set the OpenGL version and profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create the window with the settings
	window_handle = glfwCreateWindow(width, height, title, nullptr, nullptr);

	// Check if window creation was successful
	if (window_handle == NULL) {
		throw runtime_error("Couldn't create Window!\n");
	}

	// Make the context current to the thread
	glfwMakeContextCurrent(window_handle);

	// Load glad GL functions and check for errors
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw runtime_error("Failed to load GLAD!\n");
	}

	// Configure GL settings
	glViewport(0, 0, width, height);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	// Configure GLFW settings
	glfwSwapInterval(1);

	// Center Window
	const GLFWvidmode* screen = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window_handle, (screen->width - width) / 2, (screen->height - height) / 2);

	// Show the window
	glfwShowWindow(window_handle);
}

void Window::update() {
	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// Poll events
	glfwPollEvents();
}

void Window::swapBuffers() {
	glfwSwapBuffers(window_handle);
}

bool Window::shoudWindowClose() {
	return glfwWindowShouldClose(window_handle);
}

Window::~Window() {
	glfwDestroyWindow(window_handle);
	glfwTerminate();
}