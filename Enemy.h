//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Andrew Zimmerman
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/3/2018
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef Enemy_h
#define Enemy_h

#include "SDL_Plotter.h"
#include "Color.h"
#include "Point.h"

class Enemy{
    private:
        Color color[50][50];
        Point location[50][50];
    
    public:
        //************************************************************
        // description: Constructs an enemy in default setting       *
        // return: nothing to return                                 *
        // precondition: Enemy must be in the correct environment    *
        // postcondition: An enemy is constructed with default values*
        //************************************************************
        Enemy();
    
        //************************************************************
        // description: sets the enemy's locaiton                    *
        // return: nothing to return                                 *
        // precondition: x, y, and myPoint are all valid             *
        // postcondition: sets enemy location to specified point     *
        //************************************************************
        void setLocation(int, int, Point);
        //************************************************************
        // description: gets the enemy's location                    *
        // return: Point                                             *
        // precondition: x and y are valid                           *
        // postcondition: returns the enemy's location               *
        //************************************************************
        Point getLocation(int x, int y) const;
    
        //************************************************************
        // description: sets the enemy's color                       *
        // return: nothing to return                                 *
        // precondition: x, y, and myColor are all valid             *
        // postcondition: sets enemy's color at a specified point    *
        //************************************************************
        void setColor(int, int, Color);
        //************************************************************
        // description: gets the enemy's color at certain locations  *
        // return: Color                                             *
        // precondition: x and y are valid                           *
        // postcondition: returns the enemy's color at a location    *
        //************************************************************
        Color getColor(int, int) const;
    
        void setCenter(Point);
        Point getCenter() const;
    
        //************************************************************
        // description: draws the enemy on the screen                *
        // return: nothing to return                                 *
        // precondition: g must be valid, enemy must be setup        *
        // postcondition: enemy is drawn to screen                   *
        //************************************************************
        void draw(SDL_Plotter&);
        //************************************************************
        // description: displays the enemy on the screen             *
        // return: nothing to return                                 *
        // precondition: g must be valid, enemy must be setup        *
        // postcondition: enemy is displayed on screen               *
        //************************************************************
        void display(SDL_Plotter&);
};

#endif /* Enemy_h */
