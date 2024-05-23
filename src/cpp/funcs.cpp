#include<user/structs.h>
bool isTouching(Entity entity1, Entity entity2)
{
    bool isHightOk = (entity1.getPossition().y + entity1.getSize().h / 2 >= entity2.getPossition().y - entity2.getSize().h / 2 && entity1.getPossition().y - entity1.getSize().h / 2 <= entity2.getPossition().y + entity2.getSize().h / 2);
    bool isWidthOk = (entity1.getPossition().x + entity1.getSize().w / 2 >= entity2.getPossition().x - entity2.getSize().w / 2 && entity1.getPossition().x - entity1.getSize().w / 2 <= entity2.getPossition().x + entity2.getSize().w / 2);
    if (isHightOk && isWidthOk)
        return true;
    else
        return false;
}