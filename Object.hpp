#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class Object {
    private:
        double x;
        double y;
        int w;
        int h;
        //x,y Offset für Kollisionen
        double cxOffset;
        double cyOffset;
        //Kollisionsbreite & höhe
        double cw;
        double ch;
    
        SVG *view;
        Image objectImage;
        
        //Wird bei Positionsänderungen aufgerufen
        void updateImagePos() {
            //Halbe Größe addieren, da Image Position im Center und nicht oben links hat
            this->objectImage.moveTo(this->x + this->w / 2, this->y + this->h / 2);
        }
    
    public:
        //Konstruktor
        Object(double x, double y,int w, int h, string spritePath, SVG *view) {
            this->setBoundingBox(x, y, w, h);
            this->setCollisionBoundingBox(0, 0, w, h);
            this->view = view;
            this->objectImage = Image(spritePath, x, y, w, h, view);
        }
    
        //Set-Methoden
        void setPos(double x,double y) {
            this->x = x;
            this->y = y;
            updateImagePos();
        }
        void setSize(int w, int h) {
            this->w = w;
            this->h = h;
            this->objectImage.setSize(w, h);
            updateImagePos();
        }
        void setBoundingBox(double x, double y, int w, int h) {
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
            this->objectImage.setSize(w, h);
            updateImagePos();
        }
        void setSprite(string path) {
            //Setzt die Textur über das href Attribut
            this->objectImage.setAttribute("href", path);
        }
    
        //Set-Methoden für Kollisionen
        void setCollisionOffset(double cxOffset, double cyOffset) {
            this->cxOffset = cxOffset;
            this->cyOffset = cyOffset;
        }
        void setCollisionSize(int cw, int ch) {
            this->cw = cw;
            this->ch = ch;
        }
        void setCollisionBoundingBox(double cxOffset, double cyOffset, double cw, double ch) {
            this->setCollisionOffset(cxOffset, cyOffset);
            this->setCollisionSize(cw, ch);
        }

        //Get-Methoden
        double getX() {
            return this->x;
        }
        double getY() {
            return this->y;
        }
        int getW() {
            return this->w;
        }
        int getH() {
            return this->h;
        }
        SVG *getView() {
            return this->view;
        }
        
        //Get-Methoden für Kollisionen
        double getCxMin() {
            return this->x + this->cxOffset;
        }
        double getCyMin() {
            return this->y + this->cyOffset;
        }
        double getCxMax() {
            return this->getCxMin() + this->cw;
        }
        double getCyMax() {
            return this->getCyMin() + this->ch;
        }
        bool isColliding(Object *that) {
            return this->getCxMin() < that->getCxMax() && this->getCxMax() > that->getCxMin() && this->getCyMin() < that->getCyMax() && this->getCyMax() > that->getCyMin();

        }
};