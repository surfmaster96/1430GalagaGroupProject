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
    count = 2500;
    for(int i = 0; i <= count;i++)
    {
        location[i].X = location[i].Y = 200;
        color[i].R = 0;
        color[i].B = 255;
        color[i].G = 255;
    }
    
}

//## count ##

void ShipFrame::setCount(int c){
    count = c;
}


int ShipFrame::getCount() const{
    return count;
}

void ShipFrame::setCenter(Point c){
    center = c;
}

Point ShipFrame::getCenter() const{
    return center;
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
void ShipFrame::displayFrame(int moveSpeed, SDL_Plotter& g)
{
    double m, n;
    int x = count;
    Point C;
    for(int i = 0; i < x; i++)
    {
        m = location[i].X;
        m += moveSpeed;
        n = location[i].Y;
        // Update X and Y for bullet's new location.
        if(i == (x-5)){
            C.X = location[x/3].X;
            C.X += moveSpeed;
            C.Y = location[x/3].Y;
        }
        setCenter(C);
        g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
    }
}

void ShipFrame::displayBugs(double moveX, double moveY, SDL_Plotter& g, bool& fall)
{
    if(!fall){
        Point C;
        double m, n;
        for(int i = 0; i < count; i++)
        {
            m = location[i].X;
            m += moveX;
            n = location[i].Y;
            n += moveY;
            
            if(i == 100){
                
                C.X = m;
                C.Y = n;
                setCenter(C);
            }
            // Update X and Y for bullet's new location.
            g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
        }
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


//*********************************** For firing
void ShipFrame::displayFire(SDL_Plotter& g, Point start){
    double m, n;
    for(int i = 0; i < count; i++)
    {
        m = start.X + location[i].X;
        n = start.Y + location[i].Y;
        g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
    }
}
