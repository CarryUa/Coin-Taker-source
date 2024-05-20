#include<SDL2/SDL.h>
#include<user/defines.h>
#include<user/structs.h>
#include<user/init.h>
int main(int argc, char* argv[]) {
    App app;
    app = Init;
    while (true) {
        SDL_Delay(16);
    }
    return 0;
}