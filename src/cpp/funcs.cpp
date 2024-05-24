#include<user/structs.h>
#include<user/draw.h>
#include<string>
#include<vector>
bool isTouching(Entity entity1, Entity entity2)
{
    bool isHightOk = (entity1.getPossition().y + entity1.getSize().h / 2 >= entity2.getPossition().y - entity2.getSize().h / 2 && entity1.getPossition().y - entity1.getSize().h / 2 <= entity2.getPossition().y + entity2.getSize().h / 2);
    bool isWidthOk = (entity1.getPossition().x + entity1.getSize().w / 2 >= entity2.getPossition().x - entity2.getSize().w / 2 && entity1.getPossition().x - entity1.getSize().w / 2 <= entity2.getPossition().x + entity2.getSize().w / 2);
    if (isHightOk && isWidthOk)
        return true;
    else
        return false;
}
bool isTouching(Entity entity1, Entity* entity2)
{
    bool isHightOk = (entity1.getPossition().y + entity1.getSize().h / 2 >= entity2->getPossition().y - entity2->getSize().h / 2 && entity1.getPossition().y - entity1.getSize().h / 2 <= entity2->getPossition().y + entity2->getSize().h / 2);
    bool isWidthOk = (entity1.getPossition().x + entity1.getSize().w / 2 >= entity2->getPossition().x - entity2->getSize().w / 2 && entity1.getPossition().x - entity1.getSize().w / 2 <= entity2->getPossition().x + entity2->getSize().w / 2);
    if (isHightOk && isWidthOk)
        return true;
    else
        return false;
}
const char* intToChar(int value) {
    const char* ch = std::to_string(value).c_str();
    return ch;
}
App setText(const char* text, App app) {
    app.textSurface = TTF_RenderText_Solid(app.font, text, { 255,255,255,255 });
    app.textTexture = SDL_CreateTextureFromSurface(app.renderer, app.textSurface);
    return app;
}
Enemy* processEnemyVector(Enemy* enemy, Player& player, Coin& coin, App& app) {
    draw(enemy, app);
    enemy->processDirection(player);
    enemy->processMovement();
    if (isTouching(player, enemy))
    {
        player.setHP(player.getHP() - 1);
        SDL_Delay(1000);
        enemy->setPossition({ 0,0 });
        player.setPossition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
        coin.randomizePossition();
    }
    return enemy;
}
