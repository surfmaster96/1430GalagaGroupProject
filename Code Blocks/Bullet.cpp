//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman, Jiahao Xu
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
        if(i == 2){
            location = Shot[i];
        }
        m++;
        // Wait time for Bullet is M % 5
        if((m % 3) == 0)
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

void Bullet::setLocation(Point p, double speed){
    p.Y -= speed;
    location = p;
}

Point Bullet::getLocation() const{
    return location;
}





// ## Begin Display / Erase ##
void Bullet::displayBullet(int BulletSpeed, SDL_Plotter& g)
{
    
    //Calculation
    //1   2   3   4   5;
    //6   7   8   9   10;
    //11  12  13  14  15;
    //5 6-10 11-15 16-20 21-25 26-30
    int x = 38;
    double m, n;
    for(int i = 0; i <= x; i++)
    {
        if(i  < 15){
            m = Shot[i].X;
            n = Shot[i].Y;
            n -= BulletSpeed;
            if(i == 2){
                location.Y = n;
            }
            g.plotPixel(m, n, 213, 123, 204);
        }
        else{
            m = Shot[i].X;
            n = Shot[i].Y;
            n -= BulletSpeed;
            g.plotPixel(m, n, 255, 255, 150);
        }
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
