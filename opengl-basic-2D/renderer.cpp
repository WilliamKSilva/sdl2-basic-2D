#include "renderer.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

SDLRenderer::SDLRenderer(char* windowTitle, int windowWidth, int windowHeight)
{
  window = SDL_CreateWindow(windowTitle, 0, 0, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void SDLRenderer::DrawRect()
{
  SDL_Rect rect;
  rect.x = 50;
  rect.x = 50;
  rect.w = 400;
  rect.y = 400;
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
  SDL_RenderDrawRect(renderer, &rect);
  SDL_RenderPresent(renderer);
}

void SDLRenderer::Render()
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  DrawRect();
}
