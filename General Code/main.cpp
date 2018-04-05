//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <fstream>
#include "SDL_Plotter.h"
#include "Ship.h"
#include "Point.h"
#include "ShipFrame.h"
#include "Bullet.h"

using namespace std;

void handleShipUI(ifstream&, Point&, Color&, int&, ShipFrame&, int&);
void handleBullet(bool[], Bullet[], int[], SDL_Plotter&);
void handlePlotter();

int main(int argc, const char * argv[]) {
    // ## Main Stuff ##
    ifstream readIn;
    SDL_Plotter g(700,700);
    
    // ## Begin Ship Display ##
    int count1 = 0, column = 50;
    Point location;
    
    // ## Begin Ship Display Array ##
    ShipFrame frame1;
    Color color1;
    int move = 0;
    char key;
    double bulletX =200, bulletY = 680;
    
    // ## Begin Bullet ##
    Bullet bullet1[20];
    Point bullet_1;
    bool bulletOne[20] = {false};
    int bulletSpeed[20] = {0};
    bool xChange = false;
    int bulletNum = 0, temp = 0;
    
    handleShipUI(readIn, location, color1, count1, frame1, column);
    
    // ## Begin SDL Display Stuff ##
    while(!g.getQuit())
    {
        frame1.displayFrame(count1, move, frame1, g, bulletX, bulletY);
        if(g.kbhit())
        {
            key = g.getKey();
            switch(key)
            {
                case ' ':
                    bulletNum = temp;
                    bulletOne[bulletNum] = true;
                    temp++;
                    xChange = true;
                    if(xChange)
                    {
                        bullet_1.X = bulletX;
                        xChange = false;
                    }
                    bullet_1.Y = bulletY;
                    bullet1[bulletNum].setShot(bullet_1);
                    if(temp == 5)
                    {
                        temp = 0;
                    }
                    break;
                case RIGHT_ARROW: frame1.eraseFrame(count1, move, frame1, g);
                    move += 20;
                    break;
                case LEFT_ARROW: frame1.eraseFrame(count1, move, frame1, g);
                    move -= 20;
                    break;
            }
        }
        
        handleBullet(bulletOne, bullet1, bulletSpeed, g);
        
        g.update();
    }
    
    return 0;
}

void handleShipUI(ifstream& readIn, Point& location, Color& color1, int& count1, ShipFrame& frame1, int& column)
{
    string junkLine;
    Ship mainChar;
    Point shipX(200, 600);
    int readRow = 0, readCol = 0;
    char colorChar;
    bool one = false, two = false, three = false;
    
    // ## Begin Read of Design ##
    readIn.open("Shape2.txt");
    if(!readIn)
    {
        cout << "Error: Reading of Ship Shape failed." << endl;
    }
    
    getline(readIn, junkLine);
    
    while(readIn >> colorChar)
    {
        // Ship's Location
        location = Point(shipX.X + readCol, shipX.Y+readRow);
        
        /*
         If you need more colors, just simply copy the if statement and change
         color1's value to make a new color.
         */
        
        if(colorChar == 'R') // if it's R
        { // we set to red
            color1 = Color(255,0,0);
            
            mainChar.setLocation(readRow, readCol, location);
            mainChar.setColor(readRow, readCol, color1);
            one = true;
        }
        if(colorChar == 'W') // if it's W
        { // we set to white
            color1 = Color(0,255,255);
            mainChar.setLocation(readRow, readCol, location);
            mainChar.setColor(readRow, readCol, color1);
            two = true;
        }
        if(colorChar == 'B') // if it's B
        { // we set to blue
            color1 = Color(0,0,255);
            mainChar.setLocation(readRow, readCol, location);
            mainChar.setColor(readRow, readCol, color1);
            three = true;
        }
        
        // ## Bullet Related ##
        if(one||two||three) // If One, Two or Three are true
        { // set frame1 to a new location and new color and iterate count1.
            frame1.setLocation(count1, location);
            frame1.setColor(count1, color1);
            count1++;
            /*
             We take divisor of count1, then we can get some Point of
             the "fire" Point, which can be used for creating bullet.
             */
        }
        
        readCol++;
        //Need The Matirx Information!!!
        if(readCol % column == 0)
        {
            readRow++;
            readCol = 0;
        }
        
        one = two = three = false;
    }
    readIn.close(); // close our open file.
    cout << "Successfully Reading File, \n converting..." << endl;
    cout << count1 << endl;
}

void handleBullet(bool bulletOne[], Bullet bullet1[], int bulletSpeed[], SDL_Plotter& g)
{
    // ## Begin Bullet ##
    //Need Move Ship to get coordinate for bullet. ***FIXED***
    //Need change Bullet to arrary style to make anothor shot--Partilly FIXED
    if(bulletOne[1]){
        bullet1[1].eraseBullet(bulletSpeed[1], bullet1[1], g);
        bulletSpeed[1] += 5;//Bullet speed
        
        bullet1[1].displayBullet(bulletSpeed[1], bullet1[1], g);
        if((bulletSpeed[1]) >= 600){
            bullet1[1].eraseBullet(bulletSpeed[1], bullet1[1], g);
            bulletOne[1] = false;
            bulletSpeed[1] = 0;
        }
    }
    if(bulletOne[2]){
        bullet1[2].eraseBullet(bulletSpeed[2], bullet1[2], g);
        bulletSpeed[2] += 5;// Bullet speed
        
        bullet1[2].displayBullet(bulletSpeed[2], bullet1[2], g);
        if((bulletSpeed[2]) >= 600){
            bullet1[2].eraseBullet(bulletSpeed[2], bullet1[2], g);
            bulletOne[2] = false;
            bulletSpeed[2] = 0;
        }
    }
    if(bulletOne[3]){
        bullet1[3].eraseBullet(bulletSpeed[3], bullet1[3], g);
        bulletSpeed[3] += 5;// Bullet speed
        
        bullet1[3].displayBullet(bulletSpeed[3], bullet1[3], g);
        if((bulletSpeed[3]) >= 600){
            bullet1[3].eraseBullet(bulletSpeed[3], bullet1[3], g);
            bulletOne[3] = false;
            bulletSpeed[3] = 0;
        }
    }
    if(bulletOne[4]){
        bullet1[4].eraseBullet(bulletSpeed[4], bullet1[4], g);
        bulletSpeed[4] += 5;//Bullet speed
        
        bullet1[4].displayBullet(bulletSpeed[4], bullet1[4], g);
        if((bulletSpeed[4]) >= 600){
            bullet1[4].eraseBullet(bulletSpeed[4], bullet1[4], g);
            bulletOne[4] = false;
            bulletSpeed[4] = 0;
        }
    }
    if(bulletOne[0]){
        bullet1[0].eraseBullet(bulletSpeed[0], bullet1[0], g);
        bulletSpeed[0] += 5;//Bullet speed
        
        bullet1[0].displayBullet(bulletSpeed[0], bullet1[0], g);
        if((bulletSpeed[0]) >= 600){
            bullet1[0].eraseBullet(bulletSpeed[0], bullet1[0],g);
            bulletOne[0] = false;
            bulletSpeed[0] = 0;
        }
    }
}

void handlePlotter(SDL_Plotter& g)
{
    
}
