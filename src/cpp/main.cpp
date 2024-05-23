#include<SDL2/SDL.h>
#include<SDL2/SDL_main.h>
#include<user/defines.h>
#include<user/structs.h>
#include<user/init.h>
#include<user/draw.h>
#include<user/funcs.h>

int main(int argc, char* argv[]) {
    RGBA backgroundColor = { 0, 226, 255, 1 };
    int score = 0;
    App app;
    app = Init(app);
    Coin coin({ SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 + 100 }, { 32,32 }, { false, false, false, false }, loadTexture("src/textures/logo_icon_248042.png", app));
    Player player({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, { 32,32 }, { false, false, false, false }, loadTexture("src/textures/logo_icon_248042.png", app));
    while (true) {
        processScene(app, backgroundColor);
        SDL_Delay(16);
        draw(player, app);
        draw(coin, app);
        player.processMovement();
        player.getInput();
        if (isTouching(player, coin))
        {
            coin.randomizePossition();
            score++;
        }
        SDL_
            presentScene(app);

        SDL_Delay(0);
    }
    SDL_Quit();
    return 0;

}
