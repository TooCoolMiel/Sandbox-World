#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

using std::string;

struct Shader
{
	GLuint ID;

	Shader(const char* vertex_path, const char* fragment_path);
	void start();
	void stop();
	~Shader();
};

