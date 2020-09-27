//
//  GameSystem.h
//  TestASCII
//
//  Created by Carlos Rivas on 9/20/15.
//  Copyright (c) 2015 Carlos Rivas. All rights reserved.
//

#ifndef __TestASCII__GameSystem__
#define __TestASCII__GameSystem__

#include "Level.h"
#include <stdio.h>
#include "Player.h"



class gameSystem
{
public:
    bool isDone = true;
    
    gameSystem();
    void playGame();
    void Menu();
    char Begininput;
    char udInput;
    char enterInput;
    
private:
    Level _Level;
    Player _Player;
};




#endif /* defined(__TestASCII__GameSystem__) */
