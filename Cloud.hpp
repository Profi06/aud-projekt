#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class Cloud : public Obstacle {
    public:
        Cloud(double x, double y, SVG *view, Obstacle *next) : Obstacle(x, y, 80, 80, "sprites/cloud.png", view, next){
            this->setCollisionBoundingBox(1, 1, 78, 78);
        }
        void update(double deltaTime) {
            this->setPos(this->getX() - 70 * deltaTime, this->getY());
        }
};