#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "GL.h"
#include "iostream"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main() {
	int sdlInit = SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER );

	if (sdlInit < 0)
	{
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	const char* windowName = "Basic 2D stuff :P";
	GL* gl = new GL(windowName, SCREEN_WIDTH, SCREEN_HEIGHT);
	gl->SetupVertexArrayObject();

	bool quitApplication = false;

	// Main loop
	while (!quitApplication) {
		gl->ProcessEvents();

		gl->Render();
	}

	SDL_Quit();
	std::cout << "Quit..." << std::endl;

	return 0;
}
