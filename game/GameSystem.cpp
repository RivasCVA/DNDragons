//
//  GameSystem.cpp
//  TestASCII
//
//  Created by Carlos Rivas on 9/20/15.
//  Copyright (c) 2015 Carlos Rivas. All rights reserved.
//

#include "GameSystem.h"
#include <iostream>

using namespace std;

gameSystem::gameSystem()
{
    _Level.loadLevel("theLevel.txt");
    _Level.processLevel(_Player);
}

void gameSystem::playGame()
{
    cout << string(50, '\n');
    cout << "Press 'w' or 's' to move selection | Press 'l' to choose" << endl << endl;
    cout << "Start" << "<---" << endl;
    cout << "Exit" << endl;
    
    while (true)
    {
    while (isDone == true)
    {
        Menu();
    }
    
    cout << "Loading...";
    
    while (isDone == false)
    {
        cout << string(50, '\n');
        _Level.printLevel(_Player);
        _Level.playerMove(_Player);
        _Level.enemyMove(_Player);
        _Level.checkForW(isDone, _Player);
        
    }
    
    _Level.printLevel(_Player);
    }
    
}
void gameSystem::Menu()
{
    udInput = 'w';
    Begininput = _Level.getCh();
    
    if (Begininput == 'w' || Begininput == 's')
    {
        udInput = Begininput;
    }
    
    if (Begininput == 'l')
    {
        enterInput = 'l';
    }
    
    if (udInput == 'w')
    {
        cout << string(50, '\n');
        cout << "Press 'w' or 's' to move selection | Press 'l' to choose" << endl << endl;
        cout << "Start" << "<---" << endl;
        cout << "Exit" << endl;
    }
    
    if (udInput == 's')
    {
        cout << string(50, '\n');
        cout << "Press 'w' or 's' to move selection | Press 'l' to choose" << endl << endl;
        cout << "Start" << endl;
        cout << "Exit" << "<---" << endl;
    }
    
    if (enterInput == 'l')
    {
        if (udInput == 'w')
        {
            isDone = false;
            enterInput = 'p';
        }
        if (udInput == 's')
        {
            cout << endl << "Thanks for playing!" << endl;
            enterInput = 'p';
            exit(0);
        }
    }
}









