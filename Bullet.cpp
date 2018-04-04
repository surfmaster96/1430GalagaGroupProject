//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "Bullet.h"


flash::flash()
{
    for(int i = 0; i<100; i++)
    {
        int j = 0;
        Shot[i].X = Shot[i].Y = 0;
        Shot[i].X +=i;
        Shot[i].Y +=j;
        if(i%10 == 0){
            j++;
        }
        color[i].R = 255;
        color[i].G = 50;
        color[i].B = 120;
    }
}

void flash::setColor(int x,Color c)
{
    color[x]=c;
}

void flash::setShot(Point p)
{
    int m = 0, n = 0, x = 100;
    for(int i = 0; i<x; i++){
        Shot[i].X = p.X+m;
        Shot[i].Y = p.Y+n;
        m++;
        //***m%5, 5 is the wigth of bullet.
        if((m%5) == 0){
            n++;
            m = 0;
        }
    }
}

Color flash::getColor(int x) const
{
    return color[x];
}

Point flash::getShot(int x) const
{
    return Shot[x];
}

void flash::displayFlash(int BulletSpeed, flash, SDL_Plotter& g)
{
    int x = 100;
    double m, n;
    for(int i = 0; i < x; i++)
    {
        m = Shot[i].X;
        n = Shot[i].Y;
        n -= BulletSpeed;
        g.plotPixel(m, n, 100, 50, 120);
    }
}

void flash::eraseFlash(int BulletSpeed, flash, SDL_Plotter& g)
{
    double m, n;
    int x = 100;
    for(int i = 0; i < x; i++)
    {
        m = Shot[i].X;
        n = Shot[i].Y;
        n -= BulletSpeed;
        g.plotPixel(m, n, 255, 255, 255);
    }
}
