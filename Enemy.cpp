//
//  Enemy.cpp
//  TestASCII
//
//  Created by Carlos Rivas on 9/22/15.
//  Copyright (c) 2015 Carlos Rivas. All rights reserved.
//

#include "Enemy.h"
#include "iostream"


Enemy::Enemy(string name, char tile, int health, int attack, int xp, int x, int y)
{
    _name = name;
    _tile = tile;
    _health = health;
    _attack = attack;
    _xp = xp;
    _x = x;
    _y = y;

}

void Enemy::getTile(char &tile)
{
    tile = _tile;
}

void Enemy::getName(string &name)
{
    name = _name;
}

void Enemy::getPosition(int &x, int &y)
{
    x = _x;
    y = _y;
}

void Enemy::setPosition(int x, int y)
{
    _y = y;
    _x = x;
}

void Enemy::getHAX(int &health, int &attack, int &xp)
{
    health = _health;
    attack = _attack;
    xp = _xp;
}

void Enemy::setHAX(int health, int attack, int xp)
{
    _health = health;
    _attack = attack;
    _xp = xp;
}