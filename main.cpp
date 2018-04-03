#include <iostream>
#include <ostream>
#include <fstream>


#include "SDL_Plotter.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "ship.h"
#include "displayArray.h"
#include "Bullet.h"

using namespace std;



int main(int argc, char** argv)
{
    bool stopped = false;
    bool One, Two, Three;
    One = Two = Three = false;
    int count1 = 0, columen;
    SDL_Plotter g(700,700);
    Ship ship1;
    Point shipX, location;
    shipX.x = 200;
    shipX.y = 600;
    //*************************************************DisplayArray
    shipframe frame1;
    Color color1;
    int Move = 0;
    char key;
    double bulletX =200, bulletY = 700;
    //*************************************************Bullet
    flash bullet1[20];
    Point bullet_1;
    bool bulletOne[20] = {false};
    int bulletSpeed[20] = {0};
    bool Xchange = false;
    int bulletNum = 0,TempNum = 0;
    
    
    
    //**************************************************
    char n;
    //**************************************************
    int ReadC = 0, ReadR = 0;
    string junkline;
    ifstream Reading;
    //cin >> junkline;
    //cin >> columen;
    columen = 50;
    
    //Processing.
    
    Reading.open("Shape2.txt");
    if(!Reading){
        cout << "Error: Reading failed."<<endl;
    }
    getline(Reading,junkline);
    while(Reading >> n){
        //************************************************************Location
        location = Point(shipX.x+ReadC,shipX.y+ReadR);
        
        
        /*
        If you need more colors, just simply copy the if statement and change 
        color1's value to make a new color.
        */
        if(n == 'R'){
            color1 = Color(255,0,0);
            
            ship1.setL(ReadR, ReadC, location);
            ship1.setColor(ReadR, ReadC, color1);
            One = true;
        }
        if(n == 'W'){
            color1 = Color(0,255,255);
            ship1.setL(ReadR, ReadC, location);
            ship1.setColor(ReadR, ReadC, color1);
            Two = true;
        }
        if(n == 'B'){
            color1 = Color(0,0,255);
            ship1.setL(ReadR, ReadC, location);
            ship1.setColor(ReadR, ReadC, color1);
            Three = true;
        }
        
        if(One||Two||Three){
            frame1.setLone(count1, location);
            frame1.setColor(count1, color1);
            count1 ++;
            /*
             We take divisor of count1, then we can get some Point of
             the "fire" Point, which can be used for creating bullet.
             */
        }
        
        
        
        
        ReadC++;
        //Need The Matirx Information!!!  "columen"
        if(ReadC % columen == 0){
            ReadR++;
            ReadC = 0;
        }
        
        One = Two = Three = false;
    }
    Reading.close();
    cout <<"Successfully Reading File, \n converting..."<<endl;
    cout <<count1<<endl;
    
    while(!g.getQuit()){
        
        
        if(!stopped){
            frame1.displayframe(count1, Move, frame1, g,bulletX,bulletY);
            if(g.kbhit()){
                key = g.getKey();
                switch(key){
                    case ' ':
                        for(int bulletNum1 = 0; bulletNum1 <20; bulletNum1 ++){
                            bullet1[bulletNum1].eraseflash(bulletSpeed[bulletNum1], bullet1[bulletNum1], g);
                            if(bulletNum1 == 20){
                                bulletNum1 = 0;
                            }
                        }
                        
                        bulletNum = TempNum;
                        bulletOne[bulletNum] = true;
                        TempNum++;
                        Xchange = true;
                        if(Xchange){
                            bullet_1.x = bulletX;
                            Xchange = false;
                        }
                        bullet_1.y = bulletY;
                        bullet1[bulletNum].setShot(bullet_1);
                        if(TempNum == 20){
                            TempNum = 0;
                        }
                        break;
                    case RIGHT_ARROW: frame1.eraseframe(count1, Move, frame1, g);
                        Move += 20;
                        break;
                    case LEFT_ARROW: frame1.eraseframe(count1, Move, frame1, g);
                        Move -= 20;
                        break;
                    
//**************************************CONTINUED
                }
            }
            
            //*************************************************Bullet
            //Need Move Ship to get coordinate for bullet. ***FIXED***
            //Need change Bullet to arrary style to make anothor shot--FIXED.
            for(int bulletNum1 = 0; bulletNum1 <20; bulletNum1 ++){
                if(bulletOne[bulletNum1]){
                    bullet1[bulletNum1].eraseflash(bulletSpeed[bulletNum1], bullet1[bulletNum1],g);
                    bulletSpeed[bulletNum1] += 5;//*****Bullte Speed***********
                    
                    bullet1[bulletNum1].displayflash(bulletSpeed[bulletNum1], bullet1[bulletNum1], g);
                    if((bulletSpeed[bulletNum1]) >= 600){
                        bullet1[bulletNum1].eraseflash(bulletSpeed[bulletNum1], bullet1[bulletNum1],g);
                        bulletOne[bulletNum1] = false;
                        bulletSpeed[bulletNum1] = 0;
                    }
                    if(bulletNum1 == 20){
                        bulletNum1 = 0;
                    }
                    
                }
            }
            g.update();
        }
        //cin.get();
        
        //g.Sleep(10);
    }
    
    
    
    
    
    
    
    
    
    return 0;
    
    
    /*
    
    //those just lecture notes, ignore them, lol
     Point p1;
     
     //    p1.color.r = 220;
     
     SDL_Plotter g(500,500);
     
     
     
     p1.x = 50;
     p1.y = 50;
     p1.draw(cout);
     p1.draw(g);
     *************************************************
     
    bool stopped = false;
    int x, y;
    SDL_Plotter g(900,900);
    Line myLine;
    myLine.setP1(Point(0,0));
    myLine.setP2(Point(100,400));
    
    myLine.draw(cout);
    
    Circle myCircle;
    
    //myCircle.draw(g);
    
    **************************************************
    while(!g.getQuit()){
        if(!stopped){
            myLine.setP1(Point(rand()%850+10,rand()%850+10));
            myLine.setP2(Point(rand()%850+10,rand()%850+10));
            myLine.setColor(Color(rand()%256,rand()%256,rand()%256));
            myLine.draw(g);
            
            
            myCircle.setCenter(Point(rand()%800+50,rand()%800+50));
            myCircle.setColor(Color(rand()%256,rand()%256,rand()%256));
            //myCircle.draw(g);
        }
        
        if(g.kbhit()){
            g.getKey();
            stopped = !stopped;
        }
        g.update();
        g.Sleep(10);
    }
    */
    
    
}


