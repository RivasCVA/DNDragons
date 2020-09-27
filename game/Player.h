//
//  Player.h
//  TestASCII
//
//  Created by Carlos Rivas on 9/20/15.
//  Copyright (c) 2015 Carlos Rivas. All rights reserved.
//

#ifndef __TestASCII__Player__
#define __TestASCII__Player__

#include <stdio.h>
#include "Enemy.h"
#include "vector"

class Player
{
public:
    Player();
    
    void getPosition(int &x, int &y);
    void setPosition(int x, int y);
    int playerAttack(int index, vector<Enemy> &enemies);
    void getHA(int &health, int &attack);
    void setHA(int health, int attack);
    void getLevel(int &level);

private:
    int _x;
    int _y;
    
    int _attack;
    int _health;
    int _xp;
    
};

#endif /* defined(__TestASCII__Player__) */
