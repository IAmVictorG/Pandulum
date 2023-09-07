#include "Engine.hpp"

Engine::Engine()
{
}

Engine::~Engine()
{
    delete(window);
}

void Engine::createWindow(int w, int h, const std::string name)
{
    window = new sf::RenderWindow(sf::VideoMode(w, h), name);
}

void Engine::startSimulation()
{
    sf::Clock clock;  // Initialize the clock

    while (window->isOpen())
    {
        float dt = clock.restart().asSeconds();  // Get elapsed time since last frame

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

        // Draw each Solid's shape
        for (auto& solid : solids)
        {
            window->draw(solid->getShape());
        }
        for (auto& p : Pendulums)
        {
            window->draw(p->getShapeSphere());
            window->draw(p->getShapeLine());
        }
        
        window->display();
        update(dt);
    }
}


void Engine::update(float dt)
{
    for (auto &p : Pendulums)
    {
        p->updatePosition(dt);
    }
}



void Engine::addSphere(Sphere &sphere)
{
    solids.push_back(std::make_shared<Sphere>(sphere));
}

void Engine::addPendulum(Pendulum &p)
{
    Pendulums.push_back(std::make_shared<Pendulum>(p));
}
