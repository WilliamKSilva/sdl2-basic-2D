#include "SDL2/SDL.h" 
#include "GL.h"
#include <stdlib.h>
#include <iostream>

GL::GL(const char* windowName, int windowWidth, int windowHeight)
{
	/* 
		This makes our buffer swap syncronized with the monitor's vertical refresh
		Vsync =	SDL_GL_SetSwapInterval(1);
	*/

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(-1);
	}

	glContext = SDL_GL_CreateContext(window);
}