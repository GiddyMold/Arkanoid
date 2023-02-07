#ifndef ARKANOID_ORB_H
#define ARKANOID_ORB_H

#include <SFML/Graphics.hpp>


class Orb{
    sf::CircleShape ball;
    int velY;
    int velX;
public:
    Orb();
    int getY();
    int getX();
    void changeX();
    void changeY();
    sf::Vector2f getpos();
    void steer();
    sf::CircleShape show();
};


#endif //ARKANOID_ORB_H
