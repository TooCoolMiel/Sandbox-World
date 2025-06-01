#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

using std::string;
using std::runtime_error;

/*
	A struct containing shader information like program ID and binding functions
*/
struct Shader
{
	GLuint ID;

	Shader(const char* vertex_path, const char* fragment_path);
	void start();
	void stop();
	void cleanUp();
};

