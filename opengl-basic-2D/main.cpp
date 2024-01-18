#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstdlib>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "renderer.h"
#include "input.h"
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
  SDLRenderer sdlRenderer = SDLRenderer("Basic 2D stuff :P", SCREEN_WIDTH, SCREEN_HEIGHT);
  Input input = Input();

  bool windowShouldClose = false;

  /* Main Loop */
	while (!windowShouldClose) {
    /* Input */
    input.Process(sdlRenderer.renderer, &windowShouldClose);
    /* Render stuff */
    sdlRenderer.Render();
	}

  /* Quit game */
  SDL_DestroyRenderer(sdlRenderer.renderer);
  SDL_DestroyWindow(sdlRenderer.window);
	SDL_Quit();
	std::cout << "Quit..." << std::endl;

	return 0;
}
