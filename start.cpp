#include "start.h"
#include <iostream>

Start::Start()
{
    font.loadFromFile("RetroM54.ttf");
    for(int i=0; i<4; i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(40);
        text[i].setFillColor(sf::Color::White);
    }
    text[0].setCharacterSize(55);
    text[0].setString("Welcome to Arkanoid");
    text[0].setPosition(50,50);
    text[1].setString("Play");
    text[1].setPosition(420,400);
    text[2].setString("Exit");
    text[2].setPosition(420,600);
    text[3].setCharacterSize(22);
    text[3].setString("Use arrows to move and ENTER to accept");
    text[3].setPosition(300,950);
}

sf::Text Start::show(int i)
{
    return text[i];
}

void Start::Up()
{
    text[1].setColor(sf::Color::Red);
    text[2].setColor(sf::Color::White);
    flag=false;
}

void Start::Down()
{
    text[1].setColor(sf::Color::White);
    text[2].setColor(sf::Color::Red);
    flag=true;
}