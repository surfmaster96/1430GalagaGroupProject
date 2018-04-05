//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
 This function is using to reading the .txt file, and the deafult dimension I set is 50x50;
which means it can hold 2500 objects.
Because there are a lot of waste space if you draw 50X50 everytime, I created another function named
displayArray, which is simply an object to hold "valid" points, for example, in "Shape2.txt", only 947
points have colors. Hence, draw displayArray will increase the efficient. (I think this can hold BUGS too)

Some tips:
since the dimention is 50x50, we can change it if you want hold some bigger guy, remember change all related
value, like in displayArray, 2500 = 50 x 50;
by reading .txt files, in main.cpp, the value of columen is associated with how many columns your .txt have.
btw, please use "." or some nonsense "char" to make sure each row have same columens.

*/

#ifndef Ship_H
#define Ship_H

#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"

class Ship
{
    private:
        Color color[50][50];
        Point location[50][50];
    
    public:
        //************************************************************
        // description: Constructs a Ship in default setting         *
        // return: nothing to return                                 *
        // precondition: Ship must be in the correct environment     *
        // postcondition: A Ship is constructed with default values  *
        //************************************************************
        Ship();
    
        //************************************************************
        // description: sets the ship's color                        *
        // return: nothing to return                                 *
        // precondition: x, y, and c are all valid                   *
        // postcondition: sets ship's color at a specified point     *
        //************************************************************
        void setColor(int, int, Color);
        //************************************************************
        // description: gets the ship's color at certain locations   *
        // return: Color                                             *
        // precondition: x and y are valid                           *
        // postcondition: returns the ship's color at a location     *
        //************************************************************
        Color getColor(int, int) const;
    
        //************************************************************
        // description: sets the ship's location                     *
        // return: nothing to return                                 *
        // precondition: x, y, and p are all valid                   *
        // postcondition: sets ship's location to specified point    *
        //************************************************************
        void setLocation(int, int, Point);
        //************************************************************
        // description: gets the ship's location                    *
        // return: Point                                             *
        // precondition: x and y are valid                           *
        // postcondition: returns the ship's location               *
        //************************************************************
        Point getLocation(int x, int y) const;
    
        void setCenter(Point);
        Point getCenter() const;
    
        //************************************************************
        // description: draws the ship on the screen                 *
        // return: nothing to return                                 *
        // precondition: g must be valid, enemy must be setup        *
        // postcondition: ship is drawn to screen                    *
        //************************************************************
        void draw(SDL_Plotter&);
        //************************************************************
        // description: displays the ship on the screen              *
        // return: nothing to return                                 *
        // precondition: g must be valid, enemy must be setup        *
        // postcondition: ship is displayed on screen                *
        //************************************************************
        void display(SDL_Plotter&);
};

#endif /* Ship_H */
