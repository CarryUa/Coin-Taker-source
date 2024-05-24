#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<user/structs.h>
#include<user/defines.h>
#include<SDL2/SDL_ttf.h>
App Init(App app) {

    IMG_Init(IMG_INIT_PNG || IMG_INIT_JPG);
    app.window = SDL_CreateWindow("game v0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FOREIGN);
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_EVENTS) != 0)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Video initialization error ", SDL_GetError());
    if (TTF_Init() != 0)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Font initialization error ", TTF_GetError());
    app.font = TTF_OpenFont("src/fonts/Arial.ttf", 24);

    return app;
}