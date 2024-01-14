#ifndef SHADER_H
#define SHADER_H
#include "glad/glad.h"

class ShaderProgram {
public:
	ShaderProgram();
	unsigned int ID;

	/* I think that is bad to save shaders like this */
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"layout (location = 1) in vec4 vertexColor;\n"
		"out ve4 VertexColor;\n"
		"void main()\n"
		"{\n"
			"   gl_Position = vec4(position, 1.0);\n"
			"   VertexColor = vertexColor;\n"
		"}\0";

	const char* fragmentShaderSource = "#version 330 core\n"
		"in vec4 VertexColor;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
			"   FragColor = VertexColor\n"
		"}\0";

	void Use();
};
#endif