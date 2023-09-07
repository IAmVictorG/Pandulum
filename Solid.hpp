#ifndef SOLID_HPP
#define SOLID_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

const float g = 9.81f;

class Solid
{
    protected:
        glm::vec2 _pos;
        glm::vec2 _dir;
        float _mass;
        float _rho;
        float _a;
        void setPosition(glm::vec2 pos);
    public:
        Solid();
        Solid(glm::vec2 pos, glm::vec2 dir, float a, float mass, float rho);
        Solid(const Solid &s);
        virtual ~Solid();


        virtual bool collidesWith(const Solid& other) const = 0;
        virtual sf::Shape& getShape() = 0;


        virtual bool checkAndResolveCollision() { return false; }

        void updatePosition(float dt);
};

#endif
