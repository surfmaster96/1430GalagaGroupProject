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

#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"
#include "Ship.h"


class Bullet
{
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
        Bullet();
    
        //************************************************************
        // description: sets the bullet's color                      *
        // return: nothing to return                                 *
        // precondition: x and c are all valid                       *
        // postcondition: sets bullet's color at a specified point   *
        //************************************************************
        void setColor(int, Color);
        //************************************************************
        // description: gets the bullet's color at certain locations *
        // return: Color                                             *
        // precondition: x is valid                                  *
        // postcondition: returns the ship's color at a location     *
        //************************************************************
        Color getColor(int) const;
    
        //************************************************************
        // description: sets the bullet's tragectory location        *
        // return: nothing to return                                 *
        // precondition: p is valid                                  *
        // postcondition: sets bullet's location for movement        *
        //************************************************************
        void setShot(Point);
        //************************************************************
        // description: gets the bullet's current location           *
        // return: Int                                               *
        // precondition: x is valid                                  *
        // postcondition: returns the ship's color at a location     *
        //************************************************************
        Point getShot(int) const;
    
        //************************************************************
        // description: displays the Bullet on the screen            *
        // return: nothing to return                                 *
        // precondition: g, move, and myBullet must be valid and in  *
        //  the right environment.                                   *
        // postcondition: Bullet is displayed on screen              *
        //************************************************************
        void displayBullet(int Move, Bullet, SDL_Plotter& g);
        //************************************************************
        // description: erases the Bullet from view                  *
        // return: nothing to return                                 *
        // precondition: g, move, x, and my bullet must be valid and *
        //  in the right environment.                                *
        // postcondition: Bullet is not displayed on screen          *
        //************************************************************
        void eraseBullet(int Move, Bullet, SDL_Plotter& g);
};

#endif /* Bullet_h */
