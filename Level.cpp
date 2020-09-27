//
//  Level.cpp
//  TestASCII
//
//  Created by Carlos Rivas on 9/20/15.
//  Copyright (c) 2015 Carlos Rivas. All rights reserved.
//

#include "Level.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <ctime>

using namespace std;


Level::Level()
{
    
}

void Level::loadLevel(string FileName)
{
    ifstream file;
    file.open(FileName);
    if (file.fail())
    {
        perror(FileName.c_str());
    }
    
    string line;
    
    while (getline (file, line))
    {
        _Leveldata.push_back(line);
    }
}

void Level::printLevel(Player &player)
{
    int health;
    int attack;
    int level;
    int Eattack = 0;
    int Ehealth = 0;
    
    switch (_cenemyTile)
    {
        case 'S':
            Ehealth = 50;
            Eattack = 10;
            break;
        case 'D':
            Ehealth = 900;
            Eattack = 100;
            break;
        case 'G':
            Ehealth = 100;
            Eattack = 30;
            break;
    }
    
    player.getLevel(level);
    player.getHA(health, attack);
    
    for (int i = 0; i < _Leveldata.size(); i++)
    {
        if (i == 3 || i == 5 || i == 7 || i == 9)
        {
        cout << _Leveldata[i];
        }
        else
        {
        cout << _Leveldata[i] << endl;
        }
        
        if (i == 3)
        {
            cout << "     " << "Level: " << level << endl;
        }
        
        if (i == 5)
        {
            cout << "     " << "Attack: " << attack << endl;
        }
        
        if (i == 7)
        {
            cout << "     " << "Health: " << health << endl;
        }
        
        if (i == 9)
        {
            if (_cenemyName != "n" && _cenemyTile != 'n')
            {
                cout << "      " << "Closest enemy: " << _cenemyName << "(" << _cenemyTile << ")" << endl;
                i++;
                cout << _Leveldata[i];
                cout << "                     " << _cenemyName << "(" << _cenemyTile << ")" << "Attack: " << Eattack << endl;
                i++;
                cout << _Leveldata[i];
                cout << "                     " << _cenemyName << "(" << _cenemyTile << ")" << "Health: " << Ehealth << endl;

            }
            else
            {
                cout << endl;
            }
        }
        
    }
}

void Level::playerMove(Player &player)
{
    char input;
    int playerX;
    int playerY;
    
    player.getPosition(playerX, playerY);
    
    cout << "W/A/S/D";
    
    input = getCh();
    
    switch (input)
    {
        case 'w':
        case 'W':
            tryMove(playerX, playerY - 1, player);
            break;
        case 'a':
        case 'A':
            tryMove(playerX - 1, playerY, player);
            break;
        case 's':
        case 'S':
            tryMove(playerX, playerY + 1, player);
            break;
        case 'd':
        case 'D':
            tryMove(playerX + 1, playerY, player);
            break;
        default:
            cout << "Bad input!";
    }
    
}

void Level::processLevel(Player &player)
{
    char tile;
    for (int i = 0; i < _Leveldata.size(); i++)
    {
        for (int j = 0; j < _Leveldata[i].size(); j++)
        {
            tile = _Leveldata[i][j];
            
            switch (tile)
            {
                case '@':
                    player.setPosition(j, i);
                    break;
                case 'S':
                    _Enemies.push_back(Enemy("Snake", tile, 50, 10, 1, j, i));
                    break;
                case 'D':
                    _Enemies.push_back(Enemy("Dragon", tile, 900, 100, 7,  j, i));
                    break;
                case 'G':
                    _Enemies.push_back(Enemy("Goblin", tile, 100, 30, 2, j, i));
                    break;
                case '#':
                    break;
            }
        }
    }
    
    
}

void Level::tryMove(int newplayerX, int newplayerY, Player &player)
{
    char tile;
    tile = _Leveldata[newplayerY][newplayerX];
        switch (tile)
    {
        case '.':
            movePlayer(newplayerX, newplayerY, player);
            break;
        case '#':
            break;
        default:
            enemyBattle(newplayerX, newplayerY, player);
            break;
    }
}

void Level::movePlayer(int newplayerX, int newplayerY, Player &player)
{
    int oldX;
    int oldY;
    
    player.getPosition(oldX, oldY);
    
    _Leveldata[oldY][oldX] = '.';
    _Leveldata[newplayerY][newplayerX] = '@';
    player.setPosition(newplayerX, newplayerY);
}

void Level::die()
{
    cout << endl << "You died!!!";
    
    exit(0);
}

void Level::enemyBattle(int playerX, int playerY, Player &player)
{
    int enemyX;
    int enemyY;
    int PattackResult;
    int EattackResult;
    
    for (int i = 0; i < _Enemies.size(); i++)
    {

        _Enemies[i].getPosition(enemyX, enemyY);
        
        if (playerX == enemyX && playerY == enemyY)
        {
            
            PattackResult = player.playerAttack(i, _Enemies);
            
            
            if (PattackResult == 1)
            {
                enemyKill(i);
            }
            
            if (PattackResult != 1)
            {
            EattackResult = enemyAttack(player, i, _Enemies);
            
            if (EattackResult == 1)
            {
                playerKill(player);
            }
            }
            
        }
    }
}

void Level::playerKill(Player player)
{
    int playerX;
    int playerY;
    
    player.getPosition(playerX, playerY);
    
    _Leveldata[playerY][playerX] = 'X';
    
    cout << endl << "YOU DIED!!!" << endl << endl << endl;
    
    exit(0);
}

void Level::enemyKill(int index)
{
    int Ex;
    int Ey;
    
    _Enemies[index].getPosition(Ex, Ey);
    _Leveldata[Ey][Ex] = '.';
    
    if (_Enemies.size() > 1)
    {
    _Enemies[index] = _Enemies.back();
    _Enemies.pop_back();
    }
    else
    {
        _Enemies.pop_back();
    }
}

int Level::enemyAttack(Player &player, int index, vector<Enemy> enemies)
{
    int Pattack;
    int Phealth;
    int Eattack;
    int Ehealth;
    int Exp;
    
    player.getHA(Phealth, Pattack);
    enemies[index].getHAX(Ehealth, Eattack, Exp);
    
    Phealth = Phealth - Eattack;
    
    if (Phealth <= 0)
    {
        return 1;
    }
    else
    {
        player.setHA(Phealth, Pattack);
        return 0;
    }
    
    return 0;
}

char Level::enemyAI(Player &player, int index)
{
    int enemyX;
    int enemyY;
    int playerX;
    int playerY;
    int number;
    string enemyName;
    char enemyTile;
    
    int Dx;
    int Dy;
    int diffX;
    int diffY;
    
    player.getPosition(playerX, playerY);
    _Enemies[index].getPosition(enemyX, enemyY);
        
        Dx = abs(playerX - enemyX);
        Dy = abs(playerY - enemyY);
        diffX = playerX - enemyX;
        diffY = playerY - enemyY;
        
        if (Dx < 5 && Dy < 4)
        {
            if (Dx <= 3 && Dy <= 1)
            {
                _Enemies[index].getName(enemyName);
                _Enemies[index].getTile(enemyTile);
                
                _cenemyName = enemyName;
                _cenemyTile = enemyTile;
                
            }
            else
            {
                _cenemyName = "n";
                _cenemyTile = 'n';
            }
            
            if (diffX < 0)
            {
                return 'a';
            }
            
            else if (diffX > 0)
            {
                return 'd';
            }
            
            else if (diffY > 0)
            {
                return 's';
            }
            
            else if (diffY < 0)
            {
                return 'w';
            }
            
        }
    
    random(number);
    
    switch (number)
    {
        case 1:
            return 's';
            break;
        case 2:
            return 'a';
            break;
            
        case 3:
            return 'w';
            break;
        case 4:
            return 'd';
            break;
    }
    
    
    
    return 'p';
    
}

void Level::enemyMove(Player &player)
{
    char input;
    int Ex;
    int Ey;
    char tile;
    char newMove;
    
    for (int i = 0; i < _Enemies.size(); i++)
    {
        
    input = enemyAI(player, i);
        
    _Enemies[i].getTile(tile);
    switch (input)
    {
        case 'w':
        case 'W':
            _Enemies[i].getPosition(Ex, Ey);
            newMove = _Leveldata[Ey - 1][Ex];
            
            if (newMove == '.')
            {
            _Leveldata[Ey][Ex] = '.';
            _Leveldata[Ey - 1][Ex] = tile;
            _Enemies[i].setPosition(Ex, Ey - 1);
            }
            break;
        case 'a':
        case 'A':
            _Enemies[i].getPosition(Ex, Ey);
            newMove = _Leveldata[Ey][Ex - 1];
            
            if (newMove == '.')
            {
            _Leveldata[Ey][Ex] = '.';
            _Leveldata[Ey][Ex - 1] = tile;
            _Enemies[i].setPosition(Ex - 1, Ey);
            }
            break;
        case 's':
        case 'S':
            _Enemies[i].getPosition(Ex, Ey);
            newMove = _Leveldata[Ey + 1][Ex];
            
            if (newMove == '.')
            {
            _Leveldata[Ey][Ex] = '.';
            _Leveldata[Ey + 1][Ex] = tile;
            _Enemies[i].setPosition(Ex, Ey + 1);
            }
            break;
        case 'd':
        case 'D':
            _Enemies[i].getPosition(Ex , Ey);
            newMove = _Leveldata[Ey][Ex + 1];
            
            if (newMove == '.')
            {
            _Leveldata[Ey][Ex] = '.';
            _Leveldata[Ey][Ex + 1] = tile;
            _Enemies[i].setPosition(Ex + 1, Ey);
            }
            break;
    }
    }
}

void Level::random(int &number)
{
    num = num + 1;
    default_random_engine randomEngine(num);
    uniform_int_distribution<int> randNumber(1, 5);
    
    number = randNumber(randomEngine);
}

void Level::checkForW(bool &isDone, Player &player)
{
    if (_Enemies.size() < 1)
    {
        string (50, '\n');
        printLevel(player);
        cout << "YOU WIN!!" << endl;
        isDone = true;
    }
    
}

char Level::getCh()
{
    char ch;
    
    system("stty raw");
    
    ch = getchar();
    
    system("stty cooked");
    
    return ch;
}




