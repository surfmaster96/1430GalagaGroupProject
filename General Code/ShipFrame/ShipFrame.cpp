//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "ShipFrame.h"

// ## Begin Constructor ##
ShipFrame::ShipFrame()
{
    for(int i = 0; i <= 2500;i++)
    {
        location[i].X = location[i].Y = 200;
        color[i].R = 0;
        color[i].B = 255;
        color[i].G = 255;
    }
}

// ## Begin Color ##
void ShipFrame::setColor(int x, Color c)
{
    color[x] = c;
}

Color ShipFrame::getColor(int x) const
{
    return color[x];
}

// ## Begin Location ##
void ShipFrame::setLocation(int x, Point p)
{
    location[x] = p;
}

Point ShipFrame::getLocation(int x) const
{
    return location[x];
}

// ## Begin Display / Erase ##
void ShipFrame::displayFrame(int x ,int move, ShipFrame myFrame, SDL_Plotter& g, double& X, double& Y)
{
    double m, n;
    
    for(int i = 0; i < x; i++)
    {
        m = location[i].X;
        m += move;
        n = location[i].Y;
        // Update X and Y for bullet's new location.
        X = location[x/3].X;
        X += move;
        Y = location[x/3].Y;
        g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
    }
}

void ShipFrame::eraseFrame(int x, int move, ShipFrame myFrame, SDL_Plotter& g)
{
    double m, n;
    
    for(int i = 0; i < x; i++)
    {
        m = location[i].X;
        m += move;
        n = location[i].Y;
        g.plotPixel(m, n, 255, 255, 255);
    }
}

