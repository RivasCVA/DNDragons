//
//  Enemy.h
//  TestASCII
//
//  Created by Carlos Rivas on 9/22/15.
//  Copyright (c) 2015 Carlos Rivas. All rights reserved.
//

#ifndef __TestASCII__Enemy__
#define __TestASCII__Enemy__

#include <stdio.h>
#include <string>

using namespace std;

class Enemy
{
public:
    Enemy(string name, char tile, int health, int attack, int xp, int x, int y);
    void getPosition(int &x, int &y);
    void setPosition(int x, int y);
    void getHAX(int &health, int &attack, int &xp);
    void setHAX(int health, int attack, int xp);
    void getTile(char &tile);
    void getName(string &name);
    
private:
    string _name;
    char _tile;
    int _health;
    int _attack;
    int _xp;
    int _x;
    int _y;
    
};

#endif /* defined(__TestASCII__Enemy__) */
