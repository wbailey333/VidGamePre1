#pragma once

#include <string>
#include <GL/glew.h>

class GLSProgram
{
public:
	GLSProgram();
	~GLSProgram();

	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

	void linkShader();

private:
	GLuint _programID;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;

};

