#include "Shader.h"

// Reads a text file and outputs a string with everything in the text file
string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertex_path, const char* fragment_path) {
	string vertex_file = get_file_contents(vertex_path);
	string fragment_file = get_file_contents(fragment_path);

	const char* vertex_source = vertex_file.c_str();
	const char* fragment_source = fragment_file.c_str();

	ID = glCreateProgram();

	GLuint vertex_ID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_ID, 1, &vertex_source, NULL);
	glCompileShader(vertex_ID);
	
	GLint vertex_compile_success;
	glGetShaderiv(vertex_ID, GL_COMPILE_STATUS, &vertex_compile_success);
	if (!vertex_compile_success) {
		throw runtime_error("Error Compiling Vertex Shader!\n");
	}

	GLuint fragment_ID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_ID, 1, &fragment_source, NULL);
	glCompileShader(fragment_ID);

	GLint fragment_compile_success;
	glGetShaderiv(fragment_ID, GL_COMPILE_STATUS, &fragment_compile_success);
	if (!fragment_compile_success) {
		throw runtime_error("Error Compiling Fragment Shader\n");
	}

	glAttachShader(ID, vertex_ID);
	glAttachShader(ID, fragment_ID);
	
	glLinkProgram(ID);

	glDetachShader(ID, vertex_ID);
	glDetachShader(ID, fragment_ID);

	glDeleteShader(vertex_ID);
	glDeleteShader(fragment_ID);
}

void Shader::start() {
	glUseProgram(ID);
}

void Shader::stop() {
	glUseProgram(0);
}

void Shader::cleanUp() {
	stop();
	glDeleteProgram(ID);
}