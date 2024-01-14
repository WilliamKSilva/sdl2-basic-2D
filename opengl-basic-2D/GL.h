#include "SDL2/SDL_video.h"

class GL {
private:
	SDL_Window* window;
	SDL_GLContext glContext;

public:
	GL(const char* windowName, int windowWidth, int windowHeight);
	static void ProcessEvents();
	static void ProcessKeyboardEvent(SDL_Keysym key);
	void Render();
};
