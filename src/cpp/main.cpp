#include<SDL2/SDL.h>
#include<user/defines.h>
#include<user/structs.h>
#include<user/init.h>
#include<user/draw.h>
int main(int argc, char* argv[]) {
    App app;
    RGBA backgroundColor = { 0, 226, 255, 1 };
    app = Init(app);
    while (true) {
        processScene(app, backgroundColor);
        SDL_Delay(16);
        presentScene(app);
    }
    return 0;
}