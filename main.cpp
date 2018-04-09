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
#include "ship.h"
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
    
    //****************Andy, we need change the handleShipUI function because it is not
    //****************reusable now. and I put the definition here to build the program first.
    string junkLine;
    Ship mainChar;
    Point shipX(200, 600);
    int readR = 0, readC = 0;
    char colorChar;
    bool one = false, two = false, three = false;
    
    //**********************
    
    // ## Begin Ship Display ##
    int count1 = 0, column = 50;
    Point location;
    
    // ## Begin Ship Display Array ##
    ShipFrame frame1;
    Color color1;
    int move = 0;
    char key;
    double bulletX =200, bulletY = 680;
    
    // ## Background(Stars in progessing) ##
    Ship background;
    
    //**  Bugs **
    ShipFrame bugs;
    int count2 = 0;
    int iku = 20;
    Color color2;
    Ship mainChar2;
    Point bugX(200,150), location2;
    double bug_x, bug_y;
    ifstream readbug;
    
    // ## Begin Bullet ##
    Bullet bullet1[20], bullet2[20];
    Point bullet_1,bullet_2;
    bool bulletOne[20] = {false};
    int bulletSpeed[20] = {0};
    bool xChange = false;
    int bulletNum = 0, temp = 0;
    
    handleShipUI(readIn, location, color1, count1, frame1, column);
    
    //Processing************************************************* NUM 2.
    
    readbug.open("enemy.txt");
    if(!readbug)
    {
        cout << "Error: Reading failed."<<endl;
    }
    getline(readbug, junkLine);
    while(readbug >> colorChar){
        //************************************************************Location
        location2 = Point(bugX.X+readC, bugX.Y+readR);
        
        /*
         If you need more colors, just simply copy the if statement and change
         color1's value to make a new color.
         */
        
        if(colorChar == 'R') // if it's R
        { // we set to red
            color1 = Color(255,0,60);
            mainChar2.setLocation(readR, readC, location2);
            mainChar2.setColor(readR, readC, color1);
            one = true;
        }
        if(colorChar == 'W') // if it's W
        { // we set to white
            color1 = Color(255,255,255);
            mainChar2.setLocation(readR, readC, location2);
            mainChar2.setColor(readR, readC, color1);
            two = true;
        }
        if(colorChar == 'B') // if it's B
        { // we set to blue
            color1 = Color(0,120,255);
            mainChar2.setLocation(readR, readC, location2);
            mainChar2.setColor(readR, readC, color1);
            three = true;
        }
        
        // !! Bullet Related !!
        if(one||two||three) // If One, Two or Three are true
        { // set frame1 to a new location and new color and iterate count1.
            bugs.setLocation(count2, location2);
            bugs.setColor(count2, color1);
            count2++;
            /*
             We take divisor of count1, then we can get some Point of
             the "fire" Point, which can be used for creating bullet.
             */
        }
        
        readC++;
        //Need The Matirx Information!!!
        if(readC % column == 0){
            readR++;
            readC = 0;
        }
        
        one = two = three = false;
    }
    readIn.close();
    cout << "Successfully Reading File, \n converting..." << endl;
    cout << count2 << endl;
    
    
    // ## Begin SDL Display Stuff ##
    while(!g.getQuit())
    {
        background.draw(g);
        frame1.displayFrame(count1, move, frame1, g, bulletX, bulletY);
        bugs.displayFrame(count2, iku+=1, bugs, g, bug_x, bug_y);
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
                        bullet_2.X = bulletX - 20;
                        xChange = false;
                    }
                    bullet_1.Y = bulletY -20;
                    bullet_2.Y = bulletY -20;
                    bullet1[bulletNum].setShot(bullet_1);
                    bullet2[bulletNum].setShot(bullet_2);
                    if(temp == 6)
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
        
        // ## Begin Bullet ##
        //Need Move Ship to get coordinate for bullet. ***FIXED***
        //Need change Bullet to arrary style to make anothor shot--Partilly FIXED
        if(bulletOne[1]){
            //bullet1[1].eraseFlash(bulletSpeed[1], bullet1[1],g);
            bulletSpeed[1] += 2;//Bullte Speed***********
            
            bullet1[1].displayBullet(bulletSpeed[1], bullet1[1], g);
            bullet2[1].displayBullet(bulletSpeed[1], bullet2[1], g);
            
            if((bulletSpeed[1]) >= 600){
                //bullet1[1].eraseFlash(bulletSpeed[1], bullet1[1],g);
                bulletOne[1] = false;
                bulletSpeed[1] = 0;
            }
        }
        if(bulletOne[2]){
            //bullet1[2].eraseFlash(bulletSpeed[2], bullet1[2],g);
            bulletSpeed[2] += 2;//Bullte Speed***********
            
            bullet1[2].displayBullet(bulletSpeed[2], bullet1[2], g);
            bullet2[2].displayBullet(bulletSpeed[2], bullet2[2], g);
            
            if((bulletSpeed[2]) >= 600){
                //bullet1[2].eraseFlash(bulletSpeed[2], bullet1[2],g);
                bulletOne[2] = false;
                bulletSpeed[2] = 0;
            }
        }
        if(bulletOne[3]){
            //bullet1[3].eraseFlash(bulletSpeed[3], bullet1[3],g);
            bulletSpeed[3] += 2;//Bullte Speed***********
            
            bullet1[3].displayBullet(bulletSpeed[3], bullet1[3], g);
            bullet2[3].displayBullet(bulletSpeed[3], bullet2[3], g);
            if((bulletSpeed[3]) >= 600){
                //bullet1[3].eraseFlash(bulletSpeed[3], bullet1[3],g);
                bulletOne[3] = false;
                bulletSpeed[3] = 0;
            }
        }
        if(bulletOne[4]){
            //bullet1[4].eraseFlash(bulletSpeed[4], bullet1[4],g);
            bulletSpeed[4] += 2;//Bullte Speed***********
            
            bullet1[4].displayBullet(bulletSpeed[4], bullet1[4], g);
            bullet2[4].displayBullet(bulletSpeed[4], bullet2[4], g);
            
            if((bulletSpeed[4]) >= 600){
                //bullet1[4].eraseFlash(bulletSpeed[4], bullet1[4],g);
                bulletOne[4] = false;
                bulletSpeed[4] = 0;
            }
        }
        if(bulletOne[0]){
            //bullet1[0].eraseFlash(bulletSpeed[0], bullet1[0],g);
            bulletSpeed[0] += 2;//Bullte Speed***********
            
            bullet1[0].displayBullet(bulletSpeed[0], bullet1[0], g);
            bullet2[0].displayBullet(bulletSpeed[0], bullet2[0], g);
            
            if((bulletSpeed[0]) >= 600){
                //bullet1[0].eraseFlash(bulletSpeed[0], bullet1[0],g);
                bulletOne[0] = false;
                bulletSpeed[0] = 0;
            }
        }
        if(bulletOne[5]){
            //bullet1[4].eraseFlash(bulletSpeed[4], bullet1[4],g);
            bulletSpeed[5] += 2;//Bullte Speed***********
            
            bullet1[5].displayBullet(bulletSpeed[5], bullet1[5], g);
            bullet2[5].displayBullet(bulletSpeed[5], bullet2[5], g);
            
            if((bulletSpeed[5]) >= 600){
                //bullet1[5].eraseFlash(bulletSpeed[5], bullet1[5],g);
                bulletOne[5] = false;
                bulletSpeed[5] = 0;
            }
        }
        
        g.update();
    }
    
    return 0;
}

void handleShipUI(ifstream& readIn, Point& location, Color& color1, int& count1, ShipFrame& frame1, int& column)
{
    string junkLine;
    Ship mainChar;
    Point shipX(200, 600);
    int readR = 0, readC = 0;
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
        location = Point(shipX.X + readC, shipX.Y+readR);
        
        /*
         If you need more colors, just simply copy the if statement and change
         color1's value to make a new color.
         */
        
        if(colorChar == 'R') // if it's R
        { // we set to red
            color1 = Color(255,0,60);
            
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            one = true;
        }
        if(colorChar == 'W') // if it's W
        { // we set to white
            color1 = Color(255,255,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            two = true;
        }
        if(colorChar == 'B') // if it's B
        { // we set to blue
            color1 = Color(0,120,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
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
        
        readC++;
        //Need The Matirx Information!!!
        if(readC % column == 0)
        {
            readR++;
            readC = 0;
        }
        
        one = two = three = false;
    }
    readIn.close(); // close our open file.
    cout << "Successfully Reading File, \n converting..." << endl;
    cout << count1 << endl;
}

void handleBullet(bool bulletOne[], Bullet bullet1[], Bullet bullet2[], int bulletSpeed[], SDL_Plotter& g)
{
    
}

void handlePlotter(SDL_Plotter& g)
{
    
}
