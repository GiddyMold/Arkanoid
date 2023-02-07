#ifndef ARKANOID_PADDLE_H
#define ARKANOID_PADDLE_H

#include <SFML/Graphics.hpp>


class Paddle{
    sf::RectangleShape paddle;
public:
    Paddle();
    sf::Vector2f getpos();
    sf::Vector2f setpos(int x, int y);
    sf::RectangleShape show();
};


#endif //ARKANOID_PADDLE_H
