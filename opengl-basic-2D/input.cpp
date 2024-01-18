#include "input.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_shape.h>
#include <SDL2/SDL_video.h>
#include <iostream>

void Input::Process(SDL_Renderer* renderer, bool* windowShouldClose)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (*windowShouldClose == true)
    {
      break;
    }

    if (event.type == SDL_KEYDOWN)
    {
      ProcessKeyboard(event.key.keysym);
      continue;
    }

    if (event.type == SDL_WINDOWEVENT)
    {
      ProcessWindow((SDL_WindowEventID)event.window.event, renderer, windowShouldClose);
      continue;
    }
  }
}

void Input::ProcessKeyboard(SDL_Keysym keyID)
{
  if (keyID.sym == SDLK_w)
  {
    std::cout << "Pressed W!" << std::endl;
  }
}

void Input::ProcessWindow(SDL_WindowEventID eventID, SDL_Renderer* renderer, bool* windowShouldClose)
{
  if (eventID == SDL_WINDOWEVENT_CLOSE)
  {
    *windowShouldClose = true;
    return;
  }
}
