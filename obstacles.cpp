#include "obstacles.h"

Obstacles::Obstacles()
{
    for(int i=0; i<36; i++)
    {
        obstacles[i].setFillColor(sf::Color::Green);
        obstacles[i].setSize(sf::Vector2f(80,40));
    }
}

sf::Vector2f Obstacles::getpos(int i)
{
    return obstacles[i].getPosition();
}

sf::Vector2f Obstacles::setpos(int i, int x, int y)
{
    obstacles[i].setPosition(x,y);
}

sf::Vector2f Obstacles::blank(int i)
{
    obstacles[i].setFillColor(sf::Color::Black);
}

sf::RectangleShape Obstacles::show(int i)
{
    return obstacles[i];
}