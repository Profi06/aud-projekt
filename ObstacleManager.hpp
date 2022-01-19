#include <stdlib.h>
#include <algoviz/SVG.hpp>

using namespace std;

class ObstacleManager {
    private:
        Obstacle *first;
        Obstacle *current;
        SVG *view;

    public:
        //Konstruktor
        ObstacleManager(SVG *view, Obstacle *first) {
            this->view = view;
            this->first = first;
            this->current = this->first;
        }

        //Listen Methoden
        void next() {
            this->current = this->current->getNext();
        }
        void front() {
            this->current = this->first;
        }
        void deleteNext() {
            Obstacle *deleteThis = this->current->getNext();
            this->current->setNext(deleteThis->getNext());
            delete deleteThis;
        }
        /**
         * Fügt am Listenanfang einen Baumstamm ein
         * @param cx x-Koordinate
         * @param cy y-Koordinate
         */
        void addTrunk() {
            this->first = new Trunk(this->view->getWidth(), 20 + rand()%(this->view->getHeight() - 180), this->view, this->first);
        }
        /**
         * Fügt am Listenanfang eine Krähe ein
         * @param cx x-Koordinate
         * @param cy y-Koordinate
         */
        void addCrow() {
            this->first = new Crow(20 + rand()%(this->view->getWidth() - 40), 20 + rand()%(this->view->getHeight() - 40), this->view, this->first);
        }
        /**
         * Führt update(deltaTime) für alle Objekte aus
         * @param deltaTime
         */
        void updateAll(double deltaTime) {
            //Am Listenanfang anfangen
            this->front();
            while(getCurrentPointingAtObject()) {
                this->current->update(deltaTime);
                //Nächstes Element entfernen falls es den Bildschirm verlassen hat
                if (this->current->getNext() != nullptr && !this->current->getNext()->isOnScreen()) {
                    this->deleteNext();
                }
                this->next();
            }
        }
        //Überprüft, ob Listeneinträge mit dem Objekt kollidieren
        bool hasCollidingObject(Object *checkCollision) {
            bool returnValue = false;
            //Am Listenanfang anfangen
            this->front();
            //Frühzeitiges Ende durch Kollision
            while(getCurrentPointingAtObject()&&!returnValue) {
                returnValue = this->current->isColliding(checkCollision);
                this->next();
            }
            return returnValue;
        }

        //Set Methoden
        void setFirst(Obstacle *first) {
            this->first = first;
        }
        void setCurrent(Obstacle *current) {
            this->current = current;
        }

        //Get Methoden
        Obstacle *getFirst() {
            return this->first;
        }
        Obstacle *getCurrent() {
            return this->current;
        }
        SVG *getView() {
            return this->view;
        }
        bool getCurrentPointingAtObject() {
            return this->current != nullptr;
        }
};