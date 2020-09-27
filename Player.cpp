//
//  Player.cpp
//  TestASCII
//
//  Created by Carlos Rivas on 9/20/15.
//  Copyright (c) 2015 Carlos Rivas. All rights reserved.
//

#include "Player.h"
#include <iostream>

using namespace std;


Player::Player()
{
    _x = 0;
    _y = 0;
    _attack = 10;
    _health = 100;
    _xp = 1;
}

void Player::getPosition(int &x, int &y)
{
    x = _x;
    y = _y;
}

void Player::getLevel(int &level)
{
    level = _xp;
}

void Player::setPosition(int x, int y)
{
    _y = y;
    _x = x;
}

void Player::getHA(int &health, int &attack)
{
    health = _health;
    attack = _attack;
}

void Player::setHA(int health, int attack)
{
    _health = health;
    _attack = attack;
}
int Player::playerAttack(int index, vector<Enemy> &enemies)
{
    int Eattack;
    int Ehealth;
    int Exp;
    
    enemies[index].getHAX(Ehealth, Eattack, Exp);
    
    
    Ehealth = Ehealth - _attack;
    
    if (Ehealth <= 0)
    {
        _xp = _xp + Exp;
        _attack = _attack * 2;
        
        return 1;
    }
    else
    {
        enemies[index].setHAX(Ehealth, Eattack, Exp);
    }
    
    return 0;
}






