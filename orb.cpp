#include "orb.h"
#include <time.h>
#include <cstdlib>

Orb::Orb()
{
    srand(time(NULL));
    velX=-8;
    velY=-5;
    ball.setRadius(15);
    ball.setFillColor(sf::Color::Yellow);
    ball.setPosition(rand()%800+100,800);
}

int Orb::getX()
{
    return velX;
}

int Orb::getY()
{
    return velY;
}

void Orb::changeX()
{
    velX=-velX;
}

void Orb::changeY()
{
    velY=-velY;
}

sf::Vector2f Orb::getpos()
{
    return ball.getPosition();
}

void Orb::steer()
{
    ball.move(velX,velY);
}

sf::CircleShape Orb::show()
{
    return ball;
}