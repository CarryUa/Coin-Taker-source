#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <user/structs.h>
void processScene(App app, RGBA bgColor) {
    SDL_SetRenderDrawColor(app.renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a); //sets background color
    SDL_RenderClear(app.renderer);
}
void presentScene(App app) {
    SDL_RenderPresent(app.renderer);
}
SDL_Texture*