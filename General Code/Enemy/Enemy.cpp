//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Andrew Zimmerman
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "Enemy.h"

// ## Begin Constructor ##
Enemy::Enemy()
{
    lives = 1; // This will be mutable based on enemy type.
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            color[i][j].R = 0;
            color[i][j].B = 255;
            color[i][j].G = 255;
            
            location[i][j].X = 400+i;
            location[i][j].Y = 400+j;
        }
    }
}

// ## Begin Location ##
void Enemy::setLocation(int x, int y, Point myPoint)
{
    location[x][y] = myPoint;
}

Point Enemy::getLocation(int x, int y) const
{
    return location[x][y];
}

// ## Begin Color ##
void Enemy::setColor(int x, int y, Color myColor)
{
    color[x][y] = myColor;
}

Color Enemy::getColor(int x, int y) const
{
    return color[x][y];
}

/*  Work in progress
void setCenter(Point myPoint)
{
    
}

Point getCenter() const
{
    
}
 */

// ## Begin Drawing / Displaying ##
void Enemy::draw(SDL_Plotter& g)
{
    for(int j = 0; j < 50; j++){
        for(int i = 0;i <50; i++){
            g.plotPixel(location[i][j].X, location[i][j].Y, color[i][j].R, color[i][j].G, color[i][j].B);
        }
    }
}

void Enemy::display(SDL_Plotter& g)
{
    for(int j = 0; j < 500; j++){
        g.plotPixel(location[j][j].X, location[j][j].Y, color[j][j].R, color[j][j].G, color[j][j].B);
    }
}
