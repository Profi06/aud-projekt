#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class DangerZone : public Obstacle {
    public:
        DangerZone(SVG *view, Obstacle *next) : Obstacle(-view->getWidth(), 0, view->getWidth(), view->getHeight(), "sprites/dangerZone.png", view, next){
            this->setCollisionBoundingBox(0, 0, view->getWidth(), view->getHeight());
        }
        void update(double deltaTime) {
            this->setPos(this->getX() + 7 * deltaTime, this->getY());
        }
        void pushBack(double dx) {
            /*
             * Darf nicht komplett aus dem Spielfeld gestoßen werden da 
             * sie sonst vom Obstacle Manager gelöscht werden würde
             */
            this->setPos(fmax(-399,this->getX() - dx), this->getY());
        }
};