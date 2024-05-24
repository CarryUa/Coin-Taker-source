#include<SDL2/SDL.h>
#include<SDL2/SDL_main.h>
#include<SDL2/SDL_ttf.h>
#include<user/defines.h>
#include<user/structs.h>
#include<user/init.h>
#include<user/draw.h>
#include<user/funcs.h>
int main(int argc, char* argv[]) {
    srand(time(NULL));
    RGBA backgroundColor = { 0, 226, 255, 1 };
    int score = 0;
    App app;
    app = Init(app);
    Coin coin({ 0,0 }, { 32,32 }, { false, false, false, false }, 0, loadTexture("src/textures/coin.png", app));
    Enemy enemy({ 0,0 }, { 32,32 }, { false, false, false, false }, 2, loadTexture("src/textures/coin.png", app));
    Player player({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, { 32,32 }, { false, false, false, false }, 4, loadTexture("src/textures/hero.png", app));
    coin.randomizePossition();
    while (true) {
        processScene(app, backgroundColor);
        SDL_Delay(16);
        draw(player, app);
        draw(coin, app);
        draw(enemy, app);
        player.getInput();
        player.processMovement();

        enemy.processDirection(player);
        enemy.processMovement();
        if (isTouching(player, coin))
        {
            coin.randomizePossition();
            score++;
        }
        app = setText(intToChar(score), app);
        drawTextBox({ 100,60 }, { 50, 60 }, { 128, 128, 128, 255 }, app);
        app = setText("hp", app);
        drawText({ 100,24 }, { 50, 82 }, app);
        presentScene(app);
    }
    SDL_Quit();
    return 0;

}
