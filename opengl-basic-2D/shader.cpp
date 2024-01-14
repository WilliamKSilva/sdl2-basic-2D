#include "shader.h"
#include "stdlib.h"
#include "glad/glad.h"
#include "iostream"

ShaderProgram::ShaderProgram()
{
	ID = glCreateProgram();

	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int compileStatus;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileStatus);

	if (compileStatus == GL_FALSE)
	{
		std::cout << "ERROR::VERTEX_SHADER_COMPILATION" << std::endl;
		exit(-1);
	}

	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileStatus);

	if (compileStatus == GL_FALSE)
	{
		std::cout << "ERROR::FRAGMENT_SHADER_COMPILATION" << std::endl;
		exit(-1);
	}

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	glLinkProgram(ID);

	int linkStatus;
	glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);
	
	if (linkStatus == GL_FALSE) {
		std::cout << "ERROR::SHADER_LINK" << std::endl;
		exit(-1);
	}
}

void ShaderProgram::Use()
{
	glUseProgram(ID);
}
