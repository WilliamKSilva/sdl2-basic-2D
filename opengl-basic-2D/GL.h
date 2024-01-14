#ifndef GL_H
#define GL_H
#include "SDL2/SDL_video.h"
#include "shader.h"

class GL {
public:
	GL(const char* windowName, int windowWidth, int windowHeight);
	static void ProcessEvents();
	static void ProcessKeyboardEvent(SDL_Keysym key);
	void Render();
private:
	SDL_Window* window;
	SDL_GLContext glContext;
	ShaderProgram shaderProgram = ShaderProgram();
};
#endif
