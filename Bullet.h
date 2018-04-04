//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef Bullet_h
#define Bullet_h

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"
#include "Ship.h"


class flash{
    private:
        Point Shot[100];
        Color color[100];
    
    public:
        //************************************************************
        // description: Constructs a Bullet in default setting       *
        // return: nothing to return                                 *
        // precondition: Ship must be in the correct environment     *
        // postcondition: A Ship is constructed with default values  *
        //************************************************************
        flash();
    
        void setColor(int,Color);
        Color getColor(int) const;
    
        void setShot(Point);
        Point getShot(int) const;
    
        void displayFlash(int Move, flash, SDL_Plotter& g);
        void eraseFlash(int Move, flash, SDL_Plotter& g);
};




#endif /* Bullet_h */
