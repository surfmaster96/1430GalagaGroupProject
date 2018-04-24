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

void ShipFrame::setStart(Point c){
    start = c;
}

Point ShipFrame::getStart() const{
    return start;
}

void ShipFrame::setBugRadius(double c){
    radius = c;
}

double ShipFrame::getBugRadius() const{
    return radius;
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


void ShipFrame::setbugsfall(bool flag){
    bugsfall = flag;
}

bool ShipFrame::getbugsfall() const{
    return bugsfall;
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
/*
 my old version
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
 */

void ShipFrame::displayFrame(int MoveSpeed, SDL_Plotter& g){
    int m, n;
    int x = count;
    for(int i = 0; i < x; i++)
    {
        m = location[i].X;
        m += MoveSpeed;
        n = location[i].Y;
        // Update X and Y for bullet's new location.
        if(i == midNum){
            center.X = m % 700;
            center.Y = n % 700;
        }
        if(i == 0){
            start.X = m % 700;
            start.Y = n % 700;
        }
        g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
    }
}
/*
void ShipFrame::displayBugs(double moveX, double moveY, SDL_Plotter& g, bool& fall)
{
    if(!fall){
        int m, n;
        for(int i = 0; i < count; i++)
        {
            m = location[i].X;
            m += moveX;
            n = location[i].Y;
            n += moveY;
            
            if(i == midNum){
                center.X = m % 700;
                center.Y = n % 700;
            }
            // Update X and Y for bullet's new location.
            g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
        }
    }
}
 */
//********working...finished
void ShipFrame::drawBugs(double moveX, double moveY, SDL_Plotter& g, ShipFrame boom)
{   Point C;
    int m, n;
    radius = 25;
    if(!bugsfall){
        for(int i = 0; i < count; i++)
        {
            m = location[i].X;
            m += moveX;
            n = location[i].Y;
            n += moveY;
            if(i == midNum){
                center.X = m % 700;
                center.Y = n % 700;
            }
            // Update X and Y for bullet's new location.
            g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
        }
        //center = location[midNum];
        //cout <<center.X<<"   ";
    }
    else{
        boom.displayFire(g, center);
    }
}
void ShipFrame::drawPower(double moveX, double moveY, SDL_Plotter& g, ShipFrame boom)
{   Point C;
    int m, n;
    radius = 25;
    if(bugsfall){
        for(int i = 0; i < count; i++)
        {
            m = location[i].X;
            m += moveX;
            n = location[i].Y;
            n += moveY;
            if(i == midNum){
                center.X = m % 700;
                center.Y = n % 700;
            }
            // Update X and Y for bullet's new location.
            g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
        }
        //center = location[midNum];
        //cout <<center.X<<"   ";
    }
    else{
        boom.displayFire(g, center);
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

//************sort
bool ShipFrame::findBullet(Bullet b[],int n){
    bool flag = false;
    if(!bugsfall){
        double distance;
        for(int i = 0; i<= n; i++){
            if(b[i].getBfire()){
                distance = sqrt(pow((center.X - b[i].getLocation().X),2)+pow((center.Y - b[i].getLocation().Y),2));
                //cout <<"R: "<<radius<<endl;
                //cout <<"D: "<<distance<<endl;
                if(distance < radius){
                    flag = true;
                    bugsfall = flag;
                    b[i].setBfire(false);
                }
            }
        }
    }
    return flag;
}

void ShipFrame::findPower(ShipFrame &shield, ShipFrame &Maxwell, bool &Xshield, bool& XMaxwell){
    double distance;
    Point S;
    Point M;
    radius = 30;
    if(shield.getbugsfall()){
        S = shield.getCenter();
        distance = sqrt(pow((center.X - S.X),2)+pow((center.Y - S.Y),2));
        if(distance < radius){
            Xshield = true;
            shield.setbugsfall(false);
        }
        else if(S.Y >= 700){
            shield.setbugsfall(false);
        }
        //cout <<distance<<" "<<radius<<endl;
    }
    if(Maxwell.getbugsfall()){
        M = Maxwell.getCenter();
        distance = sqrt(pow((center.X - M.X),2)+pow((center.Y - M.Y),2));
        if(distance < radius){
            XMaxwell = true;
            Maxwell.setbugsfall(false);
        }
        else if(S.Y >= 700){
            Maxwell.setbugsfall(false);
        }
    }
}


void ShipFrame::drawPowerBugs(double moveX, double moveY, SDL_Plotter& g, ShipFrame& power, ShipFrame boom)
{   Point C;
    int m, n;
    radius = 25;
    if(!bugsfall){
        for(int i = 0; i < count; i++)
        {
            m = location[i].X;
            m += moveX;
            n = location[i].Y;
            n += moveY;
            if(i == midNum){
                center.X = m % 700;
                center.Y = n % 700;
            }
            // Update X and Y for bullet's new location.
            g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
        }
    }
    else{
        boom.displayFire(g, center);
        power.setbugsfall(true); //inverse of fall*********!!
        power.setCenter(center);
        //power.displayFire(g, center);
    }
}

//*********************************** For firing
void ShipFrame::displayFire(SDL_Plotter& g, Point start){
    double m, n;
    int x = count /2;
    for(int i = 0; i < count; i++)
    {
        if(i < x){
            m = start.X - location[i].X;
            n = start.Y - location[i].Y;
        }
        else{
            m = start.X + location[i].X;
            n = start.Y + location[i].Y;
        }
        g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
    }
}

void ShipFrame::displayPowerUp(SDL_Plotter& g, Point start){
    double m, n;
    int x = count;
    for(int i = 0; i < x; i++)
    {
        m = start.X - location[i].X;
        n = start.Y - location[i].Y;
        g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
    }
    
}
