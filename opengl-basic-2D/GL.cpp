#include "SDL2/SDL.h" 
#include "glad/glad.h"
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
        windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);

	if (window == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(-1);
	}

	glContext = SDL_GL_CreateContext(window);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}

	int makeContextCurrent = SDL_GL_MakeCurrent(window, glContext);

	if (makeContextCurrent < 0)
	{
		std::cout << "Failed to make OpenGL context current" << std::endl;
		exit(-1);
	}

}

void GL::Render()
{
	glClearColor(255, 255, 255, 255);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
}

void GL::ProcessEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.key.type == SDL_KEYDOWN)
		{
			ProcessKeyboardEvent(event.key.keysym);
		}
	}
}

void GL::ProcessKeyboardEvent(SDL_Keysym key)
{
	if (key.scancode == SDL_SCANCODE_W)
	{
		std::cout << "Pressed the W key" << std::endl;
	}
}
