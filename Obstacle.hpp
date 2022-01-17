#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class Obstacle : public Object {
    private:
        Obstacle *next;
    public:
        Obstacle(double x, double y, int w, int h, string spritePath, SVG *view, Obstacle *next) : Object(x, y, w, h, spritePath, view){
            this->next = next;
        }
        
        /*
         * virtual sorgt dafür dass update in 
         * Unterklassen überschrieben wird
         */
        virtual void update(double deltaTime) {}
    
        void setNext(Obstacle *next) {
            this->next = next;
        }
    
        Obstacle *getNext() {
            return next;
        }
        bool isOnScreen() {
            return this->getX() + this->getW() > 0 && this->getX() < this->getView()->getWidth() && this->getY() + this->getH() > 0 && this->getY() < this->getView()->getHeight();
        }
};