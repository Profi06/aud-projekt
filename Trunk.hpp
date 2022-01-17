#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class Trunk : public Obstacle {
    public:
        Trunk(double x, double y, SVG *view, Obstacle *next) : Obstacle(x, y, 42, 160, "sprites/trunk.png", view, next){
            this->setCollisionBoundingBox(5, 5, 34, 150);
        }
        void update(double deltaTime) {
            this->setPos(this->getX() - 70 * deltaTime, this->getY());
        }
};