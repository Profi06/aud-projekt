#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class Storm : public Obstacle {
    public:
        Storm(SVG *view, Obstacle *next) : Obstacle(-200, 0, 200, 400, "sprites/cloud.png", view, next){
            this->setCollisionBoundingBox(0, 0, 199, 400);
        }
        void update(double deltaTime) {
            this->setPos(this->getX() + 1 * deltaTime, this->getY());
        }
};