#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Sphere.hpp"
#include "Pendulum.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <glm/glm.hpp>


#define WINDOW_HEIGHT 400
#define WINDOW_WIDTH 800

class Engine
{
    private:
        sf::RenderWindow *window;
        std::vector<std::shared_ptr<Solid>> solids;
        std::vector<std::shared_ptr<Pendulum>> Pendulums; 
    public:
        Engine();
        ~Engine();
        
        void createWindow(int width, int height, const std::string name);
        void startSimulation();
        void update(float dt);
        
        void addSphere(Sphere &sphere);
        void addPendulum(Pendulum &p);
};

#endif
