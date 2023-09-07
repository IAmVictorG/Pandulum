NAME = engine

SRC = main.cpp Solid.cpp Engine.cpp Sphere.cpp Line.cpp Pendulum.cpp

OBJS := $(SRC:%.cpp=%.o)

CPPFLAGS = 

all: $(NAME)

$(NAME): $(OBJS)
	c++ -fsanitize=address $(CPPFLAGS) $(OBJS) -o $@ -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all