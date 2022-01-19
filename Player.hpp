#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class Player : public Object {
    private:
        double dx;
        double dy;
        
        double moveCooldown;
    public:
        Player(double x, double y, SVG *view) : Object(x, y, 40, 40, "sprites/player.png", view){
            this->setCollisionBoundingBox(2, 21, 34, 11.5);
            this->dx = 0;
            this->dy = 0;
            this->moveCooldown = 0;
        }
        
        void update(string button, double deltaTime) {
            if (moveCooldown <= 0) {
                if(button == "ArrowLeft") {
                    this->dx-= 60;
                    moveCooldown = 0.25;
                } else if(button == "ArrowRight") {
                    this->dx+= 50;
                    moveCooldown = 0.2;
                } else if(button == "ArrowUp") {
                    this->dy-= 25;
                    moveCooldown = 0.1;
                } else if(button == "ArrowDown") {
                    this->dy+= 25;
                    moveCooldown = 0.1;
                }
            } else {
                moveCooldown -= deltaTime;
            }
            this->dx = (-40 * deltaTime + this->dx) / 2;
            this->dy = (0 * deltaTime + this->dy) / 2;
            this->setPos(this->getX() + this->dx, this->getY() + this->dy);
        }
};