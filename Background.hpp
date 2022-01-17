#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class Background {
    private:
        //x Offset für die Landschaft
        double xOffset;
    
        SVG *view;
        Image backgroundPaper;
        Image backgroundLandscape1;
        Image backgroundLandscape2;
        
        //Wird bei Positionsänderungen aufgerufen
        void updateImagePos() {
            //Halbe Größe addieren, da Image position im Center und nicht oben links hat
            this->backgroundLandscape1.moveTo(this->xOffset, this->view->getHeight() / 2);
            this->backgroundLandscape2.moveTo(this->xOffset + this->view->getWidth(), this->view->getHeight() / 2);
        }
    
    public:
        //Konstruktor
        Background(string spritePath, SVG *view) {
            this->view = view;
            this->backgroundPaper = Image("sprites/background/paper.png", 0, 0, this->view->getWidth(), this->view->getHeight(), view);
            this->backgroundLandscape1 = Image("sprites/background/landscape.png", 0, 0, this->view->getWidth(), this->view->getHeight(), view);
            this->backgroundLandscape2 = Image("sprites/background/landscape.png", 0, 0, this->view->getWidth(), this->view->getHeight(), view);
            this->updateImagePos();
        }
        //Set-Methode
        void moveBackground(double dx) {
            this->xOffset = (this->xOffset - dx + this->view->getWidth()) % this->view->getWidth();
            this->updateImagePos();
        }

        //Get-Methode
        double getXOffset() {
            return this->xOffset;
        }
};