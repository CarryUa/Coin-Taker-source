#include <SDL2/SDL.h>
typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} App;
typedef struct {
    int r;
    int g;
    int b;
    int a;
} RGBA;