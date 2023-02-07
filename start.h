#ifndef ARKANOID_START_H
#define ARKANOID_START_H

#include <SFML/Graphics.hpp>

class Start {
    sf::RectangleShape option1;
    sf::RectangleShape option2;
    sf::Text text[4];
    sf::Font font;
public:
    bool flag=0;
    Start();
    void Up();
    void Down();
    sf::Text show(int i);
};


#endif //ARKANOID_START_H
