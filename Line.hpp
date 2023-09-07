#ifndef LINE_HPP
#define LINE_HPP

#include "Solid.hpp"

class Line : public Solid
{
	private:
		glm::vec2 _end_pos;
		sf::RectangleShape shape;

	public:
		Line();
		Line(glm::vec2 pos, float length, float angle);
		~Line();

		virtual sf::Shape& getShape() override { return shape; }
		bool collidesWith(const Solid& other) const {(void) other; return false; }
		void setPosition(float angle);

};


#endif