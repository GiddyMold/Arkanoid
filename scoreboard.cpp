#include "scoreboard.h"

Scoreboard::Scoreboard()
{
    font.loadFromFile("RetroM54.ttf");
    for(int i=0; i<10; i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(100);
        text[i].setFillColor(sf::Color::Black);
    }
}

sf::Text Scoreboard::loseScenario(int i, int s)
{
    text[0].setCharacterSize(129);
    text[0].setString("GAME OVER");
    text[0].setPosition(000,000);
    text[1].setCharacterSize(60);
    text[1].setString("Total score");
    text[1].setPosition(220,300);
    text[2].setCharacterSize(60);
    scoree=std::to_string(s);
    text[2].setString(scoree);
    text[2].setPosition(440,400);
    text[3].setCharacterSize(33);
    text[3].setString("Press ESC to quit");
    text[3].setPosition(5,950);

    return text[i];
}

sf::Text Scoreboard::winScenario(int i, int s)
{
    text[0].setCharacterSize(152);
    text[0].setString("YOU WON");
    text[0].setPosition(000,000);
    text[1].setCharacterSize(60);
    text[1].setString("Total score");
    text[1].setPosition(220,400);
    text[2].setCharacterSize(60);
    scoree=std::to_string(s);
    text[2].setString(scoree);
    text[2].setPosition(440,500);
    text[3].setCharacterSize(33);
    text[3].setString("Press ESC to quit");
    text[3].setPosition(5,950);

    return text[i];
}