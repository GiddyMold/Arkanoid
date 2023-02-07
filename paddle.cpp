#include "paddle.h"

Paddle::Paddle()
{
    paddle.setFillColor(sf::Color::White);
    paddle.setPosition(450,900);
    paddle.setSize(sf::Vector2f(100,10));
}

sf::Vector2f Paddle::getpos()
{
    return paddle.getPosition();
}

sf::RectangleShape Paddle::show()
{
    return paddle;
}

sf::Vector2f Paddle::setpos(int x, int y)
{
    paddle.setPosition(x,y);
}
