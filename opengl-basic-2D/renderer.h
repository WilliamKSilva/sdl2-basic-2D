#include <SDL2/SDL_render.h>

class SDLRenderer
{
  public:
    SDLRenderer(char* windowTitle, int windowWidth, int windowHeight);
    SDL_Window* window;
    SDL_Renderer* renderer;

    void DrawRect();
    void Render();
};
