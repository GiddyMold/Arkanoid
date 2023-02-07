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

int main()
{
    srand(time(NULL));
    int width=1000, height=1000, score=0;
    bool flag[36] = {0};
    sf::RenderWindow window(sf::VideoMode(width,height), "Arkanoid");
    window.setFramerateLimit(60);
    Orb orb;
    Paddle paddle;
    Obstacles obstacles;
    Score scoree;
    Scoreboard scoreboard;

    start(window);
    game(orb, paddle, obstacles, scoree, window, flag, score, scoreboard);
}
