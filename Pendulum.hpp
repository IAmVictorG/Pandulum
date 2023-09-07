#ifndef Pendulum_HPP
#define Pendulum_HPP


#include "Line.hpp"
#include "Sphere.hpp"
#include "Solid.hpp"

class Pendulum
{
	private:
		Line *l;
		Sphere *s;
		float length;
		float angle;
		glm::vec2 fix_p;
		float angular_velocity = 0;

	public:
		Pendulum(glm::vec2 fix_p, float length, float angle);
		~Pendulum();
		sf::Shape& getShapeSphere() { return s->getShape(); }
		sf::Shape& getShapeLine() { return l->getShape(); }
		void updatePosition(float dt);
};


#endif