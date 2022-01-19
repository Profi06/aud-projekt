#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class ScrollingImage {
    private:
        //Offset für den Hintergrund
        double xOffset;
        double yImagePos;
    
        SVG *view;
        Image scrollingImage1;
        Image scrollingImage2;
        
        //Wird bei Positionsänderungen aufgerufen
        void updateImagePos() {
            //Halbe Größe addieren, da Image Position im Center und nicht links hat
            double xPos = this->xOffset + this->view->getWidth() / 2;
            this->scrollingImage1.moveTo(xPos, this->yImagePos);
            this->scrollingImage2.moveTo(xPos - this->view->getWidth(), this->yImagePos);
        }
    
    public:
        //Konstruktor
        ScrollingImage(string spritePath, double yOffset, int imageHeight, SVG *view) {
            this->xOffset = 0;
            //Halbe Größe addieren, da Image Position im Center und nicht oben hat
            this->yImagePos = yOffset + imageHeight / 2;
            
            this->view = view;
            this->scrollingImage1 = Image(spritePath, 0, 0, this->view->getWidth(), imageHeight, view);
            this->scrollingImage2 = Image(spritePath, 0, 0, this->view->getWidth(), imageHeight, view);
            this->updateImagePos();
        }
        //Set-Methode
        void move(double dx) {
            this->xOffset = fmod(this->xOffset + dx + this->view->getWidth(), this->view->getWidth());
            this->updateImagePos();
        }

        //Get-Methode
        double getXOffset() {
            return this->xOffset;
        }
};