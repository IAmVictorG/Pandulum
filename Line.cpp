#include "Line.hpp"

Line::Line(glm::vec2 pos, float length, float angle) : Solid(pos, (glm::vec2) {0,0}, 0, 0, 0)
{
    shape =	sf::RectangleShape(sf::Vector2f(length, 2));
    shape.rotate(angle);
    shape.setPosition(_pos.x, _pos.y);
    std::cout << "Create Line" << std::endl;
}


Line::~Line(){}

void Line::setPosition(float angle)
{
	shape.rotate(angle * 180 / M_PI);
}
