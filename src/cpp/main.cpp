#include<SDL2/SDL.h>
#include<SDL2/SDL_main.h>
#include<user/defines.h>
#include<user/structs.h>
#include<user/init.h>
#include<user/draw.h>
int main(int argc, char* argv[]) {
    RGBA backgroundColor = { 0, 226, 255, 1 };
    App app;
    app = Init(app);
    Entity player({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, { 32,32 }, 3, loadTexture("src/textures/logo_icon_248042.png", app));
    while (true) {
        processScene(app, backgroundColor);
        SDL_Delay(16);
        draw(player, app);
        player.getInput();
        presentScene(app);
    }
    SDL_Quit();
    return 0;

}
