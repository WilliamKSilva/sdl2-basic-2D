#ifndef GL_H
#define GL_H
#include "SDL2/SDL_video.h"
#include <vector>
#include "shader.h"

class GL {
public:
	GL(const char* windowName, int windowWidth, int windowHeight);
	static void ProcessEvents();
	static void ProcessKeyboardEvent(SDL_Keysym key);
	void SetupVertexArrayObject();
	void Render();
private:
	SDL_Window* window;
	ShaderProgram* shaderProgram = NULL;
	SDL_GLContext glContext;
	unsigned int VAO;
	unsigned int VBO;
	std::vector <float> rectangleVertices;
	void BindVertexArrayObject(int VAO);
};
#endif
