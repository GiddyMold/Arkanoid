#ifndef ARKANOID_MENU_H
#define ARKANOID_MENU_H

#include <SFML/Graphics.hpp>
#include "score.h"
#include "scoreboard.h"


float movement();

void edgeCollide(Orb &orb, sf::RenderWindow &window, Scoreboard &scoreboard, int &score);

void setObstacles(Obstacles &obstacles, sf::RenderWindow &window);

void obstacleCollide(Obstacles &obstacles, Orb &orb, bool flag[], sf::Vector2f &Bpos, int &score);

void paddleCollide(Paddle &paddle, sf::Vector2f &Bpos, Orb &orb);

int start(sf::RenderWindow &window);

sf::Text showScore(Score &scoree, int &score);

void game(Orb &orb, Paddle &paddle, Obstacles &obstacles, Score &scoree, sf::RenderWindow &window, bool flag[], int &score, Scoreboard &scoreboard);

void lost(sf::RenderWindow &window, Scoreboard &scoreboard, int &score);

void won(sf::RenderWindow &window, Scoreboard &scoreboard, int &score);

void checkwin(int &score, Scoreboard &scoreboard, sf::RenderWindow &window);


#endif //ARKANOID_MENU_H
