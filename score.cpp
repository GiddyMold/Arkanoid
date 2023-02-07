#include "score.h"

Score::Score()
{
    font.loadFromFile("RetroM54.ttf");
    text.setFont(font);
    text.setCharacterSize(200);
    text.setFillColor(sf::Color(100,100,100));
    text.setPosition(400,600);
    text.setString("test");
    score=0;
}

sf::Text Score::show()
{
    return text;
}

void Score::scoreChange(int s)
{
    score = s;
    scoree=std::to_string(score);
    text.setString(scoree);
}