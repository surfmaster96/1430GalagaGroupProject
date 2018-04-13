//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "ship.h"

// ## Begin Constructor ##
Ship::Ship()
{
    for(int i = 0; i < 50;i++)
    {
        for(int j = 0; j < 50; j++)
        {
            color[i][j].R = 0;
            color[i][j].B = 255;
            color[i][j].G = 255;
            location[i][j].X = 400+i;
            location[i][j].Y = 400+j;
        }
    }
}

// ## Begin Color ##
void Ship::setColor(int x, int y, Color c)
{
    color[x][y] = c;
}

Color Ship::getColor(int x, int y) const
{
    return color[x][y];
}

// ## Begin Location ##
void Ship::setLocation(int x, int y, Point p)
{
    location[x][y] = p;
}

Point Ship::getLocation(int x, int y) const
{
    return location[x][y];
}

//*******Do not use draw or display, because it waste too many RAM and GPU.
//Using Displayframe function instead.
//Do not using srand(time(0))!!!
void Ship::draw(SDL_Plotter& g)
{
    static bool sky = true;
    for(int j = 0; j < 700; j++)
    {
        int a, b;
        for(int i = 0; i <700; i++)
        {
            g.plotPixel(i,j,0,0,0);
            
        }
        //This is the Shine-shine code.
        if(j % 53 == 0){
            a = 20 + rand()%680;
            b = 20 + rand()%680;
            ////g.plotPixel(a, b, 255, rand()%255, rand()%255);
            //g.plotPixel(a+1, b, 155, rand()%255, rand()%255);
            g.plotPixel(a-1, b, 255, rand()%255, rand()%255);
            //g.plotPixel(a, b+1, 55, rand()%255, rand()%255);
            //g.plotPixel(a, b-1, 255, rand()%255, rand()%255);
        }
        
    }
    
}

void Ship::display(SDL_Plotter& g)
{
    for(int j = 0; j < 500; j++)
    {
        g.plotPixel(location[j][j].X, location[j][j].Y, color[j][j].R, color[j][j].G, color[j][j].B);
    }
}

