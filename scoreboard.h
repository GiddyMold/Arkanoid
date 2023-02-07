#ifndef ARKANOID_SCOREBOARD_H
#define ARKANOID_SCOREBOARD_H

#include <SFML/Graphics.hpp>

class Scoreboard {
    sf::Text text[10];
    sf::Font font;
    std::string scoree;
public:
    Scoreboard();
    sf::Text loseScenario(int i, int s);
    sf::Text winScenario(int i, int s);

};


#endif //ARKANOID_SCOREBOARD_H
