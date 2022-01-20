#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class Bread : public Object {
    private:
        double spawnTimer;
        DangerZone *pushBack;
        Player *player;
    public:
        Bread(DangerZone *pushBack, Player *player, SVG *view) : Object(-100, -100, 20, 20, "sprites/bread.png", view){
            this->spawnTimer = 5;
            this->pushBack = pushBack;
            this->player = player;
        }
        void update(double deltaTime) {
            this->setPos(this->getX() - 50 * deltaTime, this->getY());
            if (!this->isOnScreen())  {
                //Nach 5 Sekunden erscheint das Brot wieder
                if (spawnTimer < 0) {
                    this->spawnTimer = 5;
                    this->setPos(this->getView()->getWidth(), 50 + rand()%(this->getView()->getHeight() - 120));
                } else {
                    this->spawnTimer -= deltaTime;
                }
            }
            if (this->isColliding(player)) {
                pushBack->pushBack(80);
                this->spawnTimer = 5;
                this->setPos(-100, -100);
            }
        }
        bool isOnScreen() {
            return this->getX() + this->getW() > 0 && this->getX() < this->getView()->getWidth() && this->getY() + this->getH() > 0 && this->getY() < this->getView()->getHeight();
        }
};