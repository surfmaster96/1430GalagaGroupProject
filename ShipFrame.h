//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef ShipFrame_H
#define ShipFrame_H
#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"
#include "Bullet.h"
#include <cmath>

using namespace std;

class ShipFrame{
private:
    Color color[2500];
    Point location[2500];
    Point center;
    Point start;
    int count;
    double radius;
    bool bugsfall = false;
    
public:
    //************************************************************
    // description: Constructs a ShipFrame in default setting    *
    // return: nothing to return                                 *
    // precondition: ShipFrame must be in the correct environment*
    // postcondition: A ShipFrame is constructed with default    *
    //  values                                                   *
    //************************************************************
    int midNum;
    
    ShipFrame();
    
    void setCount(int);
    
    int getCount() const;
    
    void setCenter(Point);
    
    Point getCenter() const;
    
    void setStart(Point c);
    
    Point getStart() const;
    
    void setBugRadius(double c);

    double getBugRadius() const;
    
    void setbugsfall(bool flag);
    
    bool getbugsfall() const;
    
    //************************************************************
    // description: sets the ShipFrame's color                   *
    // return: nothing to return                                 *
    // precondition: x and c are all valid                       *
    // postcondition: sets ship's color at a specified point     *
    //************************************************************
    void setColor(int, Color);
    //************************************************************
    // description: gets the ShipFrame's color at certain        *
    //  locations                                                *
    // return: Color                                             *
    // precondition: x is valid                                  *
    // postcondition: returns the ShipFrame's color at a location*
    //************************************************************
    Color getColor(int) const;
    
    //************************************************************
    // description: sets the ShipFrame's location                *
    // return: nothing to return                                 *
    // precondition: x, y, and myPoint are all valid             *
    // postcondition: sets enemy location to specified point     *
    //************************************************************
    void setLocation(int, Point);
    //************************************************************
    // description: gets the ShipFrame's location                *
    // return: Point                                             *
    // precondition: x is valid                                  *
    // postcondition: returns the ShipFrame's location           *
    //************************************************************
    Point getLocation(int) const;
    
    //************************************************************
    // description: displays the ShipFrame on the screen         *
    // return: nothing to return                                 *
    // precondition: g, move, x, X, Y, and myFrame must be valid *
    //  and in the right environment.                            *
    // postcondition: ShipFrame is displayed on screen           *
    //************************************************************
    void displayFrame(int MoveSpeed, SDL_Plotter& g);
    
    void drawFrame(int MoveSpeed, SDL_Plotter& g);
    
    void displayBugs(double moveX_Speed, double moveY_Speed, SDL_Plotter& g, bool& fall);
    
    void drawBugs(double moveX, double moveY, SDL_Plotter& g, ShipFrame boom);
    //opposite bool from drawBugs
    void drawPower(double moveX, double moveY, SDL_Plotter& g, ShipFrame boom);
    
    void drawPowerBugs(double moveX, double moveY, SDL_Plotter& g, ShipFrame& power, ShipFrame boom);
    
    void findPower(ShipFrame &shield, ShipFrame &Maxwell, bool &Xshield, bool& XMaxwell);
    
    //detect the bullet
    bool findBullet(Bullet b[],int n);
    
    void displayFire(SDL_Plotter& g, Point location);
    
    void displayPowerUp(SDL_Plotter& g, Point start);
    //************************************************************
    // description: erases the ShipFrame from view               *
    // return: nothing to return                                 *
    // precondition: g, move, x, and myFrame must be valid and in*
    //  the right environment.                                   *
    // postcondition: ShipFrame is not displayed on screen       *
    //************************************************************
    void eraseFrame(int, int move, ShipFrame, SDL_Plotter& g);
};

#endif /* ShipFrame_H */
