#include "SDL2/SDL_video.h"

class GL {
private:
	SDL_Window* window;
	SDL_GLContext glContext;

public:
	GL(const char* windowName, int windowWidth, int windowHeight);
};
