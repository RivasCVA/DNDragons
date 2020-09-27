//
//  Level.h
//  TestASCII
//
//  Created by Carlos Rivas on 9/20/15.
//  Copyright (c) 2015 Carlos Rivas. All rights reserved.
//

#ifndef __TestASCII__Level__
#define __TestASCII__Level__

#include <stdio.h>
#include <string>
#include <vector>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Level
{
public:
    Level();
    void loadLevel(string FileName);
    void printLevel(Player &player);
    char getCh();
    void processLevel(Player &player);
    void playerMove(Player &player);
    void tryMove(int playerX, int playerY, Player &player);
    void movePlayer(int newplayerX, int newplayerY, Player &player);
    void die();
    void enemyBattle(int playerX, int playerY, Player &player);
    int enemyAttack(Player &player, int index, vector<Enemy> enemies);
    void playerKill(Player player);
    void enemyKill(int index);
    char enemyAI(Player &player, int index);
    void enemyMove(Player &player);
    void random(int &number);
    void checkForW(bool &isDone, Player &player);
    void getPlayerKill(bool &playerKill);
    
    bool playerDie = false;
private:
    vector<string> _Leveldata;
    vector<Enemy> _Enemies;
    int num;
    string _cenemyName = "n";
    char _cenemyTile = 'n';
    
};

#endif /* defined(__TestASCII__Level__) */
