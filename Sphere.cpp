#include "Sphere.hpp"
#include "Engine.hpp"

// Default constructor
Sphere::Sphere() 
    : Solid(), _radius(1), shape(_radius)  // Initialize the shape directly
{
	shape.setPosition((sf::Vector2f) {_pos.x, _pos.y});
    shape.setOrigin(_pos.x, _pos.y);
    std::cout << "Create Sphere" << std::endl;
}

// Constructor with radius
Sphere::Sphere(float radius) 
    : Solid(), _radius(radius), shape(_radius)  // Initialize the shape directly
{
	shape.setPosition((sf::Vector2f) {_pos.x, _pos.y});
    shape.setOrigin(_pos.x, _pos.y);
    std::cout << "Create Sphere" << std::endl;
}

Sphere::Sphere(float radius, glm::vec2 pos) 
    : Solid(pos, (glm::vec2) {0,0}, 0, 0, 0), _radius(radius), shape(_radius)  // Initialize the shape directly
{
	shape.setPosition((sf::Vector2f) {_pos.x, _pos.y});
    //shape.setOrigin(pos.x, pos.y);
    std::cout << "Create Sphere, Origine (" << shape.getPosition().x << ", " << shape.getPosition().y << ")" << std::endl;
}

// Parameterized constructor
Sphere::Sphere(glm::vec2 pos, glm::vec2 dir, float a, float mass, float rho, float radius) 
    : Solid(pos, dir, a, mass, rho), _radius(radius), shape(_radius)  // Initialize the shape directly
{
	shape.setPosition((sf::Vector2f) {_pos.x, _pos.y});
    shape.setOrigin(pos.x, pos.y);
    std::cout << "Create Sphere" << std::endl;
}

// Destructor
Sphere::~Sphere()
{
    std::cout << "Sphere destroyed" << std::endl;
    // No need to delete shape; it'll be destroyed automatically
}

bool Sphere::collidesWith(const Solid& other) const {
    const Sphere* otherSphere = dynamic_cast<const Sphere*>(&other);
    if (!otherSphere) return false; // if other is not a sphere

    float distanceSquared = glm::length(_pos - otherSphere->_pos);
    float radiusSum = _radius + otherSphere->_radius;
    return distanceSquared <= (radiusSum * radiusSum);
}


void Sphere::setPosition(glm::vec2 pos)
{
    shape.setPosition(pos.x - _radius, pos.y - _radius);
}

void Sphere::resolveCollision(Sphere& other) {
    float restitution = 0.99f; 

    float radiusSum = _radius + other._radius;
    float distanceSquared = glm::length(_pos - other._pos);

    glm::vec2 collisionNormal = glm::normalize(_pos - other._pos);
    glm::vec2 relativeVelocity = _dir - other._dir;
    float velocityAlongNormal = glm::dot(relativeVelocity, collisionNormal);

    if (velocityAlongNormal > 0) return;

    float impulseScalar = -(1 + restitution) * velocityAlongNormal;
    impulseScalar /= (1/_mass + 1/other._mass);

    glm::vec2 impulse = collisionNormal * impulseScalar;

    _dir += impulse * (1 / _mass);
    other._dir -= impulse * (1 / other._mass);

    glm::vec2 offset = collisionNormal * (0.5f * (radiusSum - std::sqrt(distanceSquared)));
    _pos += offset;
    other._pos -= offset;
}




bool Sphere::checkAndResolveCollision()
{
    float restitution = 0.99f; // Restitution coefficient (you can adjust this value)
    bool collided = false;
	float d = 2*_radius;

    // Bottom collision
    if (_pos.y + d >= WINDOW_HEIGHT) {
        _pos.y = WINDOW_HEIGHT - d;
        if (_dir.y > 0) 
            _dir.y = -_dir.y * restitution;
        collided = true;
    }

    // Top collision
    if (_pos.y <= 0) {
        _pos.y = 0;
        if (_dir.y < 0) 
            _dir.y = -_dir.y * restitution;
        collided = true;
    }

    // Right side collision
    if (_pos.x + d >= WINDOW_WIDTH) {
        _pos.x = WINDOW_WIDTH - d;
        if (_dir.x > 0)
            _dir.x = -_dir.x * restitution;
        collided = true;
    }

    // Left side collision
    if (_pos.x <= 0) {
        _pos.x = 0;
        if (_dir.x < 0) 
            _dir.x = -_dir.x * restitution;
        collided = true;
    }

    return collided;
}



