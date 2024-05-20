#include<SDL2/SDL.h>
#include<user/defines.h>
#include<user/structs.h>
#include<user/init.h>
int main(int argc, char* argv[]) {
    App app;
    int i = 0;
    app = Init(app);
    while (true) {
        i++;
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "i = %d", i);
        SDL_Delay(16);
    }
    return 0;
}