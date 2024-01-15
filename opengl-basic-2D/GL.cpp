#include "SDL2/SDL.h" 
#include "glad/glad.h"
#include "GL.h"
#include "shader.h"
#include <stdlib.h>
#include <iostream>

GL::GL(const char* windowName, int windowWidth, int windowHeight)
{
	/* 
		This makes our buffer swap syncronized with the monitor's vertical refresh
		Vsync =	SDL_GL_SetSwapInterval(1);
	*/

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	window = SDL_CreateWindow(windowName, 0, 0,
        windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(-1);
	}

	glContext = SDL_GL_CreateContext(window);

	int makeContextCurrent = SDL_GL_MakeCurrent(window, glContext);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}

	if (makeContextCurrent < 0)
	{
		std::cout << "Failed to make OpenGL context current" << std::endl;
		exit(-1);
	}

	glViewport(0, 0, 1920, 1080);

	shaderProgram = new ShaderProgram();
}

void GL::Render()
{

	/* Initialize shader */
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	shaderProgram->Use();
	BindVertexArrayObject(this->VAO);

	glDrawArrays(GL_TRIANGLES, 0, 3);

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

void GL::SetupVertexArrayObject()
{
	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	this->VAO = VAO;
	this->VAO = VBO;

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	/* Triangle */
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/* Position Attribute */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/* Color Attribute */
}

void GL::BindVertexArrayObject(int VAO)
{
	glBindVertexArray(VAO);
}
