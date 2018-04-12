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
#include "TrivialStaff.h"
using namespace std;

void handleBullet(bool[], Bullet[], int[], SDL_Plotter&);
void handlePlotter();

int main(int argc, const char * argv[]) {
    // ## Main Stuff ##
    ifstream readIn;
    SDL_Plotter g(700,700);
    
    Point Target;
    
    //****************Andy, we need change the handleShipUI function because it is not
    //****************reusable now. and I put the definition here to build the program first.
    string junkLine;
    Ship mainChar;
    Point shipX(200, 600);
    
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
    ShipFrame fire;
    bool fall = false;
    Point Start(0,0);
    int count3 = 0; // Need to fix it(we can store count into ShipFrame)
    handleShipUI("fireshape.txt", Start, count3, fire, 30);
    fire.setCount(count3);
    
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
    
    handleShipUI("Shape2.txt", shipX, count1, frame1, 50);
    //Processing************************************************* NUM 2.
    handleShipUI("enemy.txt", bugX, count2, bugs, 50);
    
    
    // ## Begin SDL Display Stuff ##
    while(!g.getQuit())
    {
        background.draw(g);
        frame1.displayFrame(count1, move, frame1, g, bulletX, bulletY);
        if(!fall){
            bugs.displayFrame(count2, iku+=0, bugs, g, bug_x, bug_y);
        }
        Target.X = bug_x;
        Target.Y = bug_y;
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
                case RIGHT_ARROW: //frame1.eraseFrame(count1, move, frame1, g);
                    move += 20;
                    break;
                case LEFT_ARROW: //frame1.eraseFrame(count1, move, frame1, g);
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
            attack(Target, bullet1[1], 15, fire, g, fall);
            //cout << bullet1[1].getLocation().Y <<endl;
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
            attack(Target, bullet1[2], 15, fire, g, fall);
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
            attack(Target, bullet1[3], 15, fire, g, fall);
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
            attack(Target, bullet1[4], 15, fire, g, fall);
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
            if(!fall){
                attack(Target, bullet1[0], 50, fire, g, fall);
                g.Sleep(10);
            }
            
            
            if((bulletSpeed[0]) >= 600||fall){
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
            attack(Target, bullet1[5], 15, fire, g, fall);
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



void handleBullet(bool bulletOne[], Bullet bullet1[], Bullet bullet2[], int bulletSpeed[], SDL_Plotter& g)
{
    
}

void handlePlotter(SDL_Plotter& g)
{
    
}
