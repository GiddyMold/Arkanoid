#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "orb.h"
#include "paddle.h"
#include "obstacles.h"
#include "menu.h"
#include "start.h"
#include "score.h"
#include "scoreboard.h"


float movement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return -10;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return 10;
    return 0;
}

void edgeCollide(Orb &orb, sf::RenderWindow &window, Scoreboard &scoreboard, int &score)
{
    orb.steer();
    sf::Vector2f Bpos = orb.getpos();
    if(Bpos.x>985 || Bpos.x<0)
        orb.changeX();
    if(Bpos.y>985 || Bpos.y<0)
        orb.changeY();
    if(Bpos.y>985)
        lost(window,scoreboard, score);
}

void setObstacles(Obstacles &obstacles, sf::RenderWindow &window)
{
    int x=0;
    for (int i = 50; i < 900; i += 100) {
        for (int j = 50; j < 400; j += 100) {
            obstacles.setpos(x,i,j);
            window.draw(obstacles.show(x));
            x++;
        }
    }
}

void obstacleCollide(Obstacles &obstacles, Orb &orb, bool flag[], sf::Vector2f &Bpos, int &score)
{
    for(int i=0; i<36; i++)
    {
        sf::Vector2f Opos = obstacles.getpos(i);
        if(Bpos.x+15>Opos.x && Bpos.x+15<Opos.x + 80 && Bpos.y+15>Opos.y && Bpos.y+15<Opos.y + 40 && flag[i]==false)
        {
            obstacles.blank(i);
            orb.changeY();
            flag[i]=true;
            score++;
        }
    }
}

void paddleCollide(Paddle &paddle, sf::Vector2f &Bpos, Orb &orb)
{
    sf::Vector2f Ppos = paddle.getpos();
    paddle.setpos(Ppos.x + movement(), Ppos.y);
    if(Ppos.y==Bpos.y+25 && Bpos.x > Ppos.x && Bpos.x+15 < Ppos.x+100)
        orb.changeY();
}

int start(sf::RenderWindow &window)
{
    Start menu;
    sf::Text text[4];


    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for(int i=0; i<4; i++)
        {
            text[i]=menu.show(i);
        }

        for(int i=0; i<4; i++)
        {
            window.draw(text[i]);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            menu.Up();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            menu.Down();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            if(menu.flag==true)
                exit(0);
            else
                return 0;
        }

        window.display();
    }
    return 0;
}


sf::Text showScore(Score &scoree, int &score)
{
    scoree.scoreChange(score);
    return scoree.show();
}


void game(Orb &orb, Paddle &paddle, Obstacles &obstacles, Score &scoree, sf::RenderWindow &window, bool flag[], int &score, Scoreboard &scoreboard)
{
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        setObstacles(obstacles,window);
        edgeCollide(orb,window, scoreboard, score);
        sf::Vector2f Bpos = orb.getpos();
        obstacleCollide(obstacles,orb,flag,Bpos,score);
        paddleCollide(paddle,Bpos,orb);
        checkwin(score, scoreboard, window);

        window.draw(showScore(scoree,score));
        window.draw(orb.show());
        window.draw(paddle.show());
        window.display();
    }
}

void won(sf::RenderWindow &window, Scoreboard &scoreboard, int &score)
{
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);

        for(int i=0; i<4 ; i++)
        {
            window.draw(scoreboard.winScenario(i,score));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            exit(0);

        window.display();
    }
}

void lost(sf::RenderWindow &window, Scoreboard &scoreboard, int &score)
{
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);

        for(int i=0; i<4 ; i++)
        {
            window.draw(scoreboard.loseScenario(i,score));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            exit(0);

        window.display();
    }
}

void checkwin(int &score, Scoreboard &scoreboard, sf::RenderWindow &window)
{
    if(score>35)
        won(window,scoreboard, score);
}