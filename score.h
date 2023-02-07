#ifndef ARKANOID_SCORE_H
#define ARKANOID_SCORE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Score {
    sf::Text text;
    sf::Font font;
    std::string scoree;
    int score;
public:
    Score();
    sf::Text show();
    void scoreChange(int s);
};


#endif //ARKANOID_SCORE_H
