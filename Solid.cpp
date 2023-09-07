#include "Solid.hpp"
#include "Sphere.hpp"
#include "Engine.hpp"
// Default constructor
Solid::Solid() 
    : _pos(0, 0), _dir(0, 0), _mass(1), _rho(1), _a(0)
{
}

// Parameterized constructor
Solid::Solid(glm::vec2 pos, glm::vec2 dir, float a, float mass, float rho) 
    : _pos(pos), _dir(dir), _mass(mass), _rho(rho), _a(a)
{
}

// Copy constructor
Solid::Solid(const Solid &s) 
    : _pos(s._pos), _dir(s._dir), _mass(s._mass), _rho(s._rho), _a(s._a) 
{
}

// Destructor
Solid::~Solid()
{
    std::cout << "Solid destroyed" << std::endl;
}


sf::Vector2f toSFMLCoordinates(const glm::vec2& pos) {
    return sf::Vector2f(pos.x, WINDOW_HEIGHT - pos.y);
}


void Solid::setPosition(glm::vec2 pos)
{
	this->getShape().setPosition((sf::Vector2f){pos.x, pos.y});	
}


void Solid::updatePosition(float dt)
{
    _dir.y += g * dt;  

    _pos.x += _dir.x * dt;
    _pos.y += _dir.y * dt + 0.5 * g * dt * dt; 
    setPosition(_pos);
}
