#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

class Input
{
  public:
    static void Process(SDL_Renderer* renderer, bool* windowShouldClose);
    static void ProcessKeyboard(SDL_Keysym keyID);
    static void ProcessWindow(SDL_WindowEventID eventID, SDL_Renderer* renderer, bool* windowShouldClose);
};
