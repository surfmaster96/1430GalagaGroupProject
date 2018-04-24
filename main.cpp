//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Jiahao Xu
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 ****************            Read me          *****************
 How to print an (.txt) picture on screen
 (the picture should looks like this
 012345678901234567890123456789
 ....R...RR.......RRR....W...R.
 ....R..RRRRRRRRRRR.RRR..RR..R.
 ....RR.RRWWRRR.RRRRWWWRRRR.W..
 .....RRRRRWWRRRRRWWWRRRR..WW..
 ..RRRRRRWWWWRRRRRWRR..R.WWW...
 .RRRRRRRRRRRRRR.RRR.RRRRWRW...
 ...RR.RRR..RRRRRRRRRRR..RR....
 ..RR.RRRWRRRRRRRRRRRRR..RRWW..
 ..R.RR.WWRRR.RWWRR.RWWRRRRWWR.
 ...RRRRRRW...RWWWRRWWWWRRRR.R.
 ...RRWRRWW....RRRRWRRRRRR...R.
 .RRRRWWRR.....RRRWWWRRRR....R.
 .............RRRRRWWRRR.......
 ............RR.RRRRR..........
 .............R...R............
 )
 1.ShipFrame name;
 2.handleShipUI(string filename, Point start, ShipFrame& name);
 
 then in while(!getQuit()) loop you got 2 choices between spaceship and bugs.
 3. spaceship: name.displayFrame(int moveSpeed, SDL_Plotter& g);
 bugs: name.displayBugs(double moveX_Speed, double moveY_Speed, SDL_Plotter& g, bool& fall);
 */

#include <iostream>
#include <fstream>
#include "Time.h"
#include <ctime>
#include "SDL_Plotter.h"
#include "ship.h"
#include "Point.h"
#include "ShipFrame.h"
#include "Bullet.h"
#include "TrivialFunctions.h"

using namespace std;

//******************
const int SCREEN_FPS = 45;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;
const int SCREEN_WIDTH = 700;
const int SCREEN_DEEP = 700;


//******************
void handleBullet(bool[], Bullet[], int[], SDL_Plotter&);
void handlePlotter();

int main(int argc, const char * argv[]) {
    //Time ....
    int Tcount = 0;
    
    // ## Main Stuff ##
    ifstream readIn;
    SDL_Plotter g(SCREEN_DEEP, SCREEN_WIDTH);
    char key;
    
    // ## Begin Ship Display ##
    Point location;
    
    // ## Begin Ship Display Array ##
    ShipFrame frame1;
    Point shipX(200, 600);
    int move = 0;
    
    // ## Background(Stars in progessing) ##
    Ship background;
    ShipFrame fire;
    
    Point Start(0,0);
    
    
    //**  Bugs ** and power************
    ShipFrame bugs[5];
    int iku = 20; //(use for testing).
    int Yiku = 0;
    int Ykuru = 0;
    int kiku[5]={0};
    int Ykiku[5]={0};
    Ykiku[1]=2;
    Point bugX[5];
    Point tempPoint;
    bugX[0].setPoint(100, 100);
    bugX[1].setPoint(150, 150);
    bugX[2].setPoint(250, 150);
    bugX[3].setPoint(200, 150);
    bugX[4].setPoint(300, 100);
    int moveX = 3;
    int moveY = 1;
    
    // ## Begin Bullet ##
    Bullet bullet1[20], bullet2[20];
    Point bullet_1,bullet_2;
    int BuSPEEDA = 10;
    bool xChange = false;
    int bulletNum = 0, temp = 0;
    
    // ## play music
    g.initSound("shoot.wav");
    g.initSound("bb2.wav");
    g.Sleep(120);
    g.playSound("bb2.wav");
    //
    bool Xshield = false;
    bool XMaxwell = false;
    ShipFrame shield, shieldUp, Maxwell;
    
    
    // Loading all the shapes.
    
    
    handleShipUI("fireshape.txt", Start, fire);
    handleShipUI("shieldUp.txt", Start, shieldUp);
    handleShipUI("Shape2.txt", shipX, frame1);
    for(int z = 0; z<= 2; z++){
        handleShipUI("enemy.txt", bugX[z], bugs[z]);
        //cout <<bugs[z].midNum<<endl;
    }
    handleShipUI("EnemyB8.txt" , bugX[3], bugs[3]);
    handleShipUI("EnemyC7.txt" , bugX[4], bugs[4]);
    // ## Begin SDL Display Stuff ##
    //*****************Time**********
    //The frames per second timer
    LTimer fpsTimer;
    
    //The frames per second cap timer
    LTimer capTimer;
    
    //In memory text stream
    std::stringstream timeText;
    
    //Start counting frames per second
    int countedFrames = 0;
    fpsTimer.start();
    //********************************
    while(!g.getQuit()){
        //Start cap timer
        capTimer.start();
        
        //Calculate and correct fps
        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
        if( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }
        
        //*************************
        background.draw(g);
        //shield.displayFrame(0, g);
        //*****************************
        if(!frame1.getbugsfall()){
            frame1.displayFrame(move, g);
            for(int i = 0; i<= 4; i++){
                catchShip(bugs[i], frame1);
            }
            if(Xshield){
                
            }
        }
        //****************************
        //bugs[1].displayBugs(iku += moveX, 0, g, fall[1]);
        iku += moveX;
        Yiku += moveY;
        //Testing bugs[0] as a power bringer.
        if(!bugs[0].getbugsfall()){
            bugs[0].findBullet(bullet1, 16);
            bugs[0].findBullet(bullet2, 16);
            bugs[0].drawPowerBugs(iku, Yiku, g, shield, fire);
            if(bugs[0].getbugsfall()){
                Point FallPoint = shield.getCenter();
                handleShipUI("shield.txt", FallPoint, shield);
                shieldUp.displayPowerUp(g, FallPoint);
            }
        }
        else if(shield.getbugsfall()){
            frame1.findPower(shield, Maxwell, Xshield, XMaxwell);
            shield.drawPower(0, Ykuru +=1, g, shieldUp);
            if(Xshield){
                //Give up on this part, we just change the
                // ships color.
                changeImage("Shape2S2.txt", frame1);
            }
        }
        
        /*
         if(!bugs[0].getbugsfall()){
         bugs[0].findBullet(bullet1, 16);
         bugs[0].findBullet(bullet2, 16);
         bugs[0].drawBugs(iku, Yiku, g, fire);
         }
         else{
         //Make a reborn of  bugs
         if(clock()%6000>=5000){
         handleShipUI("shield1.txt", bugX[0], bugs[0]);
         bugs[0].setbugsfall(false);
         }
         }
         */
        
        
        if(!bugs[1].getbugsfall()){
            bugs[1].findBullet(bullet1, 16);
            bugs[1].findBullet(bullet2, 16);
            bugs[1].drawBugs(iku, Yiku, g, fire);
        }
        if(!bugs[2].getbugsfall()){
            bugs[2].findBullet(bullet1, 16);
            bugs[2].findBullet(bullet2, 16);
            bugs[2].drawBugs(kiku[0]+=kiku[1], Ykiku[0]+=Ykiku[1], g, fire);
        }
        else{
            if(Tcount == 0){
                //setStart(bugX[1],bugs[2]);
                Tcount++;
                bugs[2].setbugsfall(false);
                kiku[0]=0;
                Ykiku[0]=0;
                kiku[0]=4;
                Ykiku[0]=2;
            }
        }
        if(!bugs[3].getbugsfall()){
            bugs[3].findBullet(bullet1, 16);
            bugs[3].findBullet(bullet2, 16);
            bugs[3].drawBugs(iku, Yiku, g, fire);
        }
        if(!bugs[4].getbugsfall()){
            bugs[4].findBullet(bullet1, 16);
            bugs[4].findBullet(bullet2, 16);
            bugs[4].drawBugs(iku+1, Yiku+1, g, fire);
        }
        
        //.....................
        for(int z = 0; z <=4; z++){
            if(bugs[z].getCenter().X >= 640){
                moveX = -1;
            }
            if(bugs[z].getCenter().X <= 5){
                moveX = 1;
            }
            if(bugs[z].getCenter().Y >= 700){
                moveY = -50;
                moveX = bugs[z].getCenter().X % 5 +1;
            }
            if(bugs[z].getCenter().Y <= 10){
                moveY += 3;
                moveX = -bugs[z].getCenter().Y % 5;
            }
        }
        
        
        //bugs[0].displayBugs(iku += moveX, 0, g, fall[0]);
        //.....................
        //cout<<"This is Bugs: "<<bugs.getCenter().X<<": "<<bugs.getCenter().Y<<endl;
        if(g.kbhit())
        {
            key = g.getKey();
            switch(key)
            {
                case ' ':
                    bulletNum = temp;
                    bullet1[bulletNum].setBfire(true);
                    bullet2[bulletNum].setBfire(true);
                    bullet1[bulletNum].setSpeed(0);
                    bullet2[bulletNum].setSpeed(0);
                    temp++;
                    xChange = true;
                    if(xChange)
                    {
                        bullet_1.X = frame1.getCenter().X-13;
                        bullet_2.X = frame1.getCenter().X+12;
                        xChange = false;
                    }
                    bullet_1.Y = frame1.getCenter().Y+6;
                    bullet_2.Y = frame1.getCenter().Y+6;
                    bullet1[bulletNum].setShot(bullet_1);
                    bullet2[bulletNum].setShot(bullet_2);
                    if(temp >= 15)
                    {
                        temp = 0;
                    }
                    //play music for shooting
                    g.playSound("shoot.wav");
                    break;
                    
                    
                case RIGHT_ARROW: //frame1.eraseFrame(count1, move, frame1, g);
                    move += 20;
                    break;
                case LEFT_ARROW: //frame1.eraseFrame(count1, move, frame1, g);
                    move -= 20;
                    break;
            }
        }
        
        
        
        
        // ## Begin Bullet ##     BuSPEEDA;
        //Need Move Ship to get coordinate for bullet. ***FIXED***
        //Need change Bullet to arrary style to make anothor shot--Partilly FIXED
        /*
         bullet1[0].displayBullet(BuSPEEDA,  g);
         bullet1[1].displayBullet(BuSPEEDA,  g);
         bullet1[2].displayBullet(BuSPEEDA,  g);
         bullet1[3].displayBullet(BuSPEEDA,  g);
         bullet1[4].displayBullet(BuSPEEDA,  g);
         bullet1[5].displayBullet(BuSPEEDA,  g);
         bullet1[6].displayBullet(BuSPEEDA,  g);
         bullet1[7].displayBullet(BuSPEEDA,  g);
         bullet1[8].displayBullet(BuSPEEDA,  g);
         bullet1[9].displayBullet(BuSPEEDA,  g);
         bullet1[10].displayBullet(BuSPEEDA, g);
         bullet1[11].displayBullet(BuSPEEDA, g);
         bullet1[12].displayBullet(BuSPEEDA, g);
         bullet1[13].displayBullet(BuSPEEDA, g);
         bullet1[14].displayBullet(BuSPEEDA, g);
         bullet1[15].displayBullet(BuSPEEDA, g);
         */
        
        for(int i = 0; i <= 15; i++){
            bullet1[i].displayBullet(BuSPEEDA, g);
            bullet2[i].displayBullet(BuSPEEDA, g);
        }
        /*
         if(bulletOne[1]){
         //bullet1[1].eraseFlash(bulletSpeed[1], bullet1[1],g);
         bulletSpeed[1] += BuSPEEDA;//Bullte Speed***********
         
         bullet1[1].displayBullet(bulletSpeed[1], g);
         bullet2[1].displayBullet(bulletSpeed[1], g);
         //attack(Target, bullet1[1], 15, fire, g, fall);
         //cout << bullet1[1].getLocation().Y <<endl;
         if((bulletSpeed[1]) >= 600){
         //bullet1[1].eraseFlash(bulletSpeed[1], bullet1[1],g);
         bulletOne[1] = false;
         bulletSpeed[1] = 0;
         }
         }
         if(bulletOne[2]){
         //bullet1[2].eraseFlash(bulletSpeed[2], bullet1[2],g);
         bulletSpeed[2] += BuSPEEDA;//Bullte Speed***********
         
         bullet1[2].displayBullet(bulletSpeed[2], g);
         bullet2[2].displayBullet(bulletSpeed[2], g);
         //attack(Target, bullet1[2], 15, fire, g, fall);
         if((bulletSpeed[2]) >= 600){
         //bullet1[2].eraseFlash(bulletSpeed[2], bullet1[2],g);
         bulletOne[2] = false;
         bulletSpeed[2] = 0;
         }
         }
         if(bulletOne[3]){
         //bullet1[3].eraseFlash(bulletSpeed[3], bullet1[3],g);
         bulletSpeed[3] += BuSPEEDA;//Bullte Speed***********
         
         bullet1[3].displayBullet(bulletSpeed[3], g);
         bullet2[3].displayBullet(bulletSpeed[3], g);
         //attack(Target, bullet1[3], 15, fire, g, fall);
         if((bulletSpeed[3]) >= 600){
         //bullet1[3].eraseFlash(bulletSpeed[3], bullet1[3],g);
         bulletOne[3] = false;
         bulletSpeed[3] = 0;
         }
         }
         if(bulletOne[4]){
         //bullet1[4].eraseFlash(bulletSpeed[4], bullet1[4],g);
         bulletSpeed[4] += BuSPEEDA;//Bullte Speed***********
         
         bullet1[4].displayBullet(bulletSpeed[4], g);
         bullet2[4].displayBullet(bulletSpeed[4], g);
         //attack(Target, bullet1[4], 15, fire, g, fall);
         if((bulletSpeed[4]) >= 600){
         //bullet1[4].eraseFlash(bulletSpeed[4], bullet1[4],g);
         bulletOne[4] = false;
         bulletSpeed[4] = 0;
         }
         }
         if(bulletOne[0]){
         //bullet1[0].eraseFlash(bulletSpeed[0], bullet1[0],g);
         bulletSpeed[0] += BuSPEEDA;//Bullte Speed***********
         
         bullet1[0].displayBullet(bulletSpeed[0], g);
         bullet2[0].displayBullet(bulletSpeed[0], g);
         attack(bugs[0].getCenter(), bullet1[0], 50, fire, g, fall[0]);
         if((bulletSpeed[0]) >= 600 ||fall[0]){
         //bullet1[0].eraseFlash(bulletSpeed[0], bullet1[0],g);
         bulletOne[0] = false;
         //test = true;
         bulletSpeed[0] = 0;
         }
         }
         if(bulletOne[5]){
         //bullet1[4].eraseFlash(bulletSpeed[4], bullet1[4],g);
         bulletSpeed[5] += BuSPEEDA;//Bullte Speed***********
         
         bullet1[5].displayBullet(bulletSpeed[5], g);
         bullet2[5].displayBullet(bulletSpeed[5], g);
         //attack(Target, bullet1[5], 15, fire, g, fall);
         if((bulletSpeed[5]) >= 600){
         //bullet1[5].eraseFlash(bulletSpeed[5], bullet1[5],g);
         bulletOne[5] = false;
         bulletSpeed[5] = 0;
         }
         }
         */
        g.update();
        
        //
        ++countedFrames;
        //If frame finished early
        int frameTicks = capTimer.getTicks();
        if( frameTicks < SCREEN_TICK_PER_FRAME )
        {
            //Wait remaining time
            SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
        }
        
        
    }
    
    
    return 0;
}

