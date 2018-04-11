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

// ## Begin Constructor ##
Bullet::Bullet()
{
    for(int i = 0; i<100; i++)
    {
        int j = 0;
        Shot[i].X = Shot[i].Y = 0;
        Shot[i].X += i;
        Shot[i].Y += j;
        if(i % 10 == 0)
        {
            j++;
        }
        color[i].R = 255;
        color[i].G = 50;
        color[i].B = 120;
    }
}

// ## Begin Color ##
void Bullet::setColor(int x, Color c)
{
    color[x] = c;
}

Color Bullet::getColor(int x) const
{
    return color[x];
}

// ## Begin Shot ##
void Bullet::setShot(Point p)
{
    int m = 0, n = 0, x = 100;
    for(int i = 0; i < x; i++)
    {
        Shot[i].X = p.X + m;
        Shot[i].Y = p.Y + n;
        m++;
        // Wait time for Bullet is M % 5
        if((m % 5) == 0)
        {
            n++;
            m = 0;
        }
    }
}

Point Bullet::getShot(int x) const
{
    return Shot[x];
}

// ## Begin Display / Erase ##
void Bullet::displayBullet(int BulletSpeed, Bullet myBullet, SDL_Plotter& g)
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

void Bullet::eraseBullet(int BulletSpeed, Bullet myBullet, SDL_Plotter& g)
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
