#include <stdlib.h>
#include <algoviz/SVG.hpp>
#define PI 3.14159265

using namespace std;

class Crow : public Obstacle {
    private:
        Image crowImage;
        Circle shadowCircle;
        double currentRotation;
        bool activeHitbox;
    public:
        Crow(double x, double y, SVG *view, Obstacle *next) : Obstacle(x, y, 0, 0, "sprites/player.png", view, next){
            this->setCollisionBoundingBox(-1000, -1000, 0, 0);
            this->activeHitbox = false;
            
            this->currentRotation = 180;
            
            this->shadowCircle = Circle(x, y, 0 , view);
            this->crowImage = Image("sprites/crow.png", x, y, 80, 80, view);
            
            this->shadowCircle.setStrokeWidth(0);
            this->shadowCircle.setFill(0, 0, 0, 0.4);
        }
        
        
        void update(double deltaTime) {
            this->currentRotation += 40 * deltaTime;
            
            //Schatten bewegt sich in einer horizontalen Linie
            this->shadowCircle.moveTo(this->getX() + this->getY() / 10 * cos(this->currentRotation * PI / 180.0), this->getY());
            
            //Schatten wird größer je tiefer die Krähe ist
            this->shadowCircle.setRadius(-30 * sin(this->currentRotation * PI / 180.0));
            
            //Krähe bewegt sich ellipsenförmig
            this->crowImage.moveTo(this->getX() + this->getY() / 3 * cos(this->currentRotation * PI / 180.0), -(this->getY() + 40) * sin(this->currentRotation * PI / 180.0) - 40);
            
            //Überprüfen ob Hitbox aktiv sein soll
            if (this->activeHitbox && this->currentRotation >= 275) {
                this->setCollisionBoundingBox(-1000, -1000, 0, 0);
                this->activeHitbox = false;
            } else if (fmin(fmax(260, this->currentRotation), 280) == this->currentRotation) {
                double collisionRange = -25 * sin(this->currentRotation * PI / 180.0);
                this->setCollisionBoundingBox(-collisionRange, -collisionRange, 2 * collisionRange, 2 * collisionRange);
                this->activeHitbox = true;
            }
            
            if (this->currentRotation > 360) {
                //ObstacleManager löscht Objekt
                this->setPos(-100, 0);
            }
        }
};
