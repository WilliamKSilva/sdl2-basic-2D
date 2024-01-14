#define SDL_MAIN_HANDLED
#include "SDL2/SDL.H"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_video.h"
#include "GL.h"
#include "iostream"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1920;

int bpp = 0;
int flags = 0;

int main() {
	int sdlInit = SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER );

	if (sdlInit < 0)
	{
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	
	const char* windowName = "Basic 2D stuff :P";
	GL* gl = new GL(windowName, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	bool quitApplication = false;

	// Main game loop
	while (!quitApplication) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_Quit();
				exit(0);
				break;
			}
		}
	}

	SDL_Quit();
	std::cout << "Quit..." << std::endl;

	return 0;
}