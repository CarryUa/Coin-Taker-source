#ifndef funcs_h
#define funcs_h
#include<vector>
bool isTouching(Entity entity1, Entity entity2);
bool isTouching(Entity entity1, Entity* entity2);
const char* intToChar(int value);
Enemy* processEnemyVector(Enemy* enemy, Player& player, Coin& coin, App& app);
App setText(const char* text, App app);

#endif