#ifndef SHADER_H
#define SHADER_H

class ShaderProgram {
public:
	ShaderProgram();
	unsigned int ID;

	/* I think that is bad to save shaders like this */
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
			"   gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";

	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";

	void Use();
};
#endif