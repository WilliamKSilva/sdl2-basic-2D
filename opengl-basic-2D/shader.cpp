#include "shader.h"
#include "stdlib.h"
#include "glad/glad.h"
#include "iostream"

ShaderProgram::ShaderProgram()
{
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int compileStatus;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileStatus);

	if (compileStatus == GL_FALSE)
	{
		std::cout << "ERROR::VERTEX_SHADER_COMPILATION" << std::endl;
		exit(-1);
	}

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileStatus);

	if (compileStatus == GL_FALSE)
	{
		std::cout << "ERROR::FRAGMENT_SHADER_COMPILATION" << std::endl;
		exit(-1);
	}

	unsigned int shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int linkStatus;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkStatus);
	
	if (linkStatus == GL_FALSE) {
		std::cout << "ERROR::SHADER_LINKING" << std::endl;
		exit(-1);
	}

	ID = shaderProgram;

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void ShaderProgram::Use()
{
	glUseProgram(ID);
}
