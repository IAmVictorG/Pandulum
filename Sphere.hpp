#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Solid.hpp"

class Sphere : public Solid
{
private:
    float _radius;
    sf::CircleShape shape;  // Direct object, not a pointer
public:
    Sphere();
    Sphere(float radius);
    Sphere(float radius, glm::vec2 pos);
    Sphere(glm::vec2 pos, glm::vec2 dir, float a, float mass, float rho, float radius);
    ~Sphere();

    virtual sf::Shape& getShape() override { return shape; }
    bool checkAndResolveCollision() override;
    void resolveCollision(Sphere& other);
    bool collidesWith(const Solid& other) const;
    void setPosition(glm::vec2 pos);

};


#endif
