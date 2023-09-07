#include <iostream>
#include "Engine.hpp"
#include <list>

int main()
{

    
    Engine *e = new Engine();
    e->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Engine");

    Pendulum *p1 = new Pendulum((glm::vec2) {600, 50}, 100, 45);    
    e->addPendulum(*p1);


    Pendulum *p2 = new Pendulum((glm::vec2) {250, 50}, 300, 45);    
    e->addPendulum(*p2);

    e->startSimulation();

    delete(e);
    delete(p1);
    delete(p2);
    return 0;
}