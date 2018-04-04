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

void handleShipUI();
void handlePlotter();

int main(int argc, const char * argv[]) {
    
    bool One, Two, Three;
    One = Two = Three = false;
    int count1 = 0, column;
    SDL_Plotter g(700,700);
    Ship mainChar;
    Point shipX(200, 600), location;
    
    // ## Begin Ship Display Array ##
    ShipFrame frame1;
    Color color1;
    int move = 0;
    char key;
    double bulletX =200, bulletY = 680;
    
    // ## Begin Bullet ##
    flash bullet1[20];
    Point bullet_1;
    bool bulletOne[20] = {false};
    int bulletSpeed[20] = {0};
    bool xChange = false;
    int bulletNum = 0, temp = 0;
    
    // ## Begin Ship Display ##
    char colorChar;
    
    int readC = 0, readR = 0;
    string junkline;
    ifstream readIn;
    column = 50;
    
    //Processing.
    
    readIn.open("Shape2.txt");
    if(!readIn)
    {
        cout << "Error: Reading failed."<<endl;
    }
    getline(readIn, junkline);
    while(readIn >> colorChar){
        //************************************************************Location
        location = Point(shipX.X+readC, shipX.Y+readR);
        
        /*
         If you need more colors, just simply copy the if statement and change
         color1's value to make a new color.
         */
        
        if(colorChar == 'R') // if it's R
        { // we set to red
            color1 = Color(255,0,0);
            
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            One = true;
        }
        if(colorChar == 'W') // if it's W
        { // we set to white
            color1 = Color(0,255,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            Two = true;
        }
        if(colorChar == 'B') // if it's B
        { // we set to blue
            color1 = Color(0,0,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            Three = true;
        }
        
        // !! Bullet Related !!
        if(One||Two||Three) // If One, Two or Three are true
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
        if(readC % column == 0){
            readR++;
            readC = 0;
        }
        
        One = Two = Three = false;
    }
    readIn.close();
    cout << "Successfully Reading File, \n converting..." << endl;
    cout << count1 << endl;
    
    // ## Begin SDL Display Stuff ##
    while(!g.getQuit()){
        frame1.displayFrame(count1, move, frame1, g,bulletX,bulletY);
        if(g.kbhit()){
            key = g.getKey();
            switch(key){
                case ' ':
                    /*
                     for(int bulletNum1 = 0; bulletNum1 <=20; bulletNum1 ++){
                     cout <<bulletNum1<<endl;
                     bullet1[bulletNum1].eraseflash(bulletSpeed[bulletNum1], bullet1[bulletNum1], g);
                     if(bulletNum1 > 20){
                     bulletNum1 = 0;
                     }
                     cout <<bulletNum1<<endl;
                     }
                     */
                    bulletNum = temp;
                    bulletOne[bulletNum] = true;
                    temp++;
                    xChange = true;
                    if(xChange){
                        bullet_1.X = bulletX;
                        xChange = false;
                    }
                    bullet_1.Y = bulletY;
                    bullet1[bulletNum].setShot(bullet_1);
                    if(temp == 5){
                        temp = 0;
                    }
                    //******************************
                    
                    
                    
                    //**************************
                    break;
                case RIGHT_ARROW: frame1.eraseFrame(count1, move, frame1, g);
                    move += 20;
                    break;
                case LEFT_ARROW: frame1.eraseFrame(count1, move, frame1, g);
                    move -= 20;
                    break;
                    
                    //**************************************CONTINUED
            }
        }
        
        //*************************************************Bullet
        //Need Move Ship to get coordinate for bullet. ***FIXED***
        //Need change Bullet to arrary style to make anothor shot--Partilly FIXED
        if(bulletOne[1]){
            bullet1[1].eraseFlash(bulletSpeed[1], bullet1[1],g);
            bulletSpeed[1] += 5;//Bullte Speed***********
            
            bullet1[1].displayFlash(bulletSpeed[1], bullet1[1], g);
            if((bulletSpeed[1]) >= 600){
                bullet1[1].eraseFlash(bulletSpeed[1], bullet1[1],g);
                bulletOne[1] = false;
                bulletSpeed[1] = 0;
            }
        }
        if(bulletOne[2]){
            bullet1[2].eraseFlash(bulletSpeed[2], bullet1[2],g);
            bulletSpeed[2] += 5;//Bullte Speed***********
            
            bullet1[2].displayFlash(bulletSpeed[2], bullet1[2], g);
            if((bulletSpeed[2]) >= 600){
                bullet1[2].eraseFlash(bulletSpeed[2], bullet1[2],g);
                bulletOne[2] = false;
                bulletSpeed[2] = 0;
            }
        }
        if(bulletOne[3]){
            bullet1[3].eraseFlash(bulletSpeed[3], bullet1[3],g);
            bulletSpeed[3] += 5;//Bullte Speed***********
            
            bullet1[3].displayFlash(bulletSpeed[3], bullet1[3], g);
            if((bulletSpeed[3]) >= 600){
                bullet1[3].eraseFlash(bulletSpeed[3], bullet1[3],g);
                bulletOne[3] = false;
                bulletSpeed[3] = 0;
            }
        }
        if(bulletOne[4]){
            bullet1[4].eraseFlash(bulletSpeed[4], bullet1[4],g);
            bulletSpeed[4] += 5;//Bullte Speed***********
            
            bullet1[4].displayFlash(bulletSpeed[4], bullet1[4], g);
            if((bulletSpeed[4]) >= 600){
                bullet1[4].eraseFlash(bulletSpeed[4], bullet1[4],g);
                bulletOne[4] = false;
                bulletSpeed[4] = 0;
            }
        }
        if(bulletOne[0]){
            bullet1[0].eraseFlash(bulletSpeed[0], bullet1[0],g);
            bulletSpeed[0] += 5;//Bullte Speed***********
            
            bullet1[0].displayFlash(bulletSpeed[0], bullet1[0], g);
            if((bulletSpeed[0]) >= 600){
                bullet1[0].eraseFlash(bulletSpeed[0], bullet1[0],g);
                bulletOne[0] = false;
                bulletSpeed[0] = 0;
            }
        }
        //***********************************************************
        g.update();
        //cin.get();
        
        //g.Sleep(10);
    }
    
    return 0;
}
/* CODE WILL BE MOVED INTO FUNCTIONS SOON
void handleShipUI(ifstream& readIn, int readCol, int readRow)
{
    // Data Abstraction
    string junkline;
    char colorChar; // May be a param...
    
    // Process
    readIn.open("Shape2.txt");
    if(!readIn)
    {
        cout << "Error: Reading of Ship Shape failed." << endl;
    }
    
    getline(readIn, junkline);
    
    while(readIn >> colorChar)
    {
        
    }
    readIn.close(); // close our open file.
    cout << "Successfully Reading File, \n converting..." << endl;
    // cout << count1 << endl; - Unsure...
}

void handlePlotter(SDL_Plotter& g)
{
    
}
*/
