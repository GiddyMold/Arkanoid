#ifndef ARKANOID_OBSTACLES_H
#define ARKANOID_OBSTACLES_H

#include <SFML/Graphics.hpp>

class Obstacles {
    sf::RectangleShape obstacles[36];
public:
    Obstacles();
    sf::Vector2f getpos(int i);
    sf::Vector2f setpos(int i, int x, int y);
    sf::Vector2f blank(int i);
    sf::RectangleShape show(int i);
};


#endif //ARKANOID_OBSTACLES_H
