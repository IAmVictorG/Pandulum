#include "Pendulum.hpp"

Pendulum::Pendulum(glm::vec2 fix_p, float length, float angle) : length(length), angle(angle * M_PI / 180), fix_p(fix_p)
{
	l = new Line(fix_p, length, angle);
	float s_radius = 15;
	glm::vec2 sphere_center;
	sphere_center.x = fix_p.x + length * std::cos(angle * M_PI / 180) - s_radius; 
	sphere_center.y = fix_p.y + length * std::sin(angle * M_PI / 180) - s_radius;


	std::cout << "Sphere center " << sphere_center.x << ", " << sphere_center.y << std::endl;
	s = new Sphere(s_radius, sphere_center);
}

Pendulum::~Pendulum(){}

void Pendulum::updatePosition(float dt)
{
	float angular_acceleration = - (g / length * 100) * sin(angle);

	angular_velocity = (angular_velocity + angular_acceleration * dt);

	angle += angular_velocity * dt;

	glm::vec2 sphere_center;
	sphere_center.x = fix_p.x + length * -std::cos(angle + M_PI_2);
	sphere_center.y = fix_p.y + length * std::sin(angle + M_PI_2);  


	s->setPosition(sphere_center);

	l->setPosition(-angular_velocity * dt);
}