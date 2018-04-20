#include <iostream>

#include "SDL_Plotter.h"
#include "Bullet.h"
#include "Color.h"
#include "drawShape.h"
#include "Point.h"
#include "Ship.h"
#include "ShipFrame.h"
#include "TrivialStaff.h"

#include "Constants.h"

using namespace std;

using namespace std;

void handleBullet(bool[], Bullet[], int[], SDL_Plotter&);
void handlePlotter();

int main(int argc, char ** argv)
{

    // ## Main Stuff ##
    ifstream readIn;
    SDL_Plotter g(700,700);
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

    bool fall[5] = {false};
    Point Start(0,0);


    //**  Bugs **
    ShipFrame bugs[2];
    int iku = 20; //(use for testing).
    Point bugX[2];
    Point tempPoint;
    bugX[0].setPoint(100, 100);
    bugX[1].setPoint(150, 150);
    int moveX = 1;

    // ## Begin Bullet ##
    Bullet bullet1[20], bullet2[20];
    Point bullet_1,bullet_2;
    bool bulletOne[20] = {false};
    int bulletSpeed[20] = {0};
    bool xChange = false;
    int bulletNum = 0, temp = 0;
    // Loading all the shapes.

    handleShipUI("fireshape.txt", Start, fire);
    handleShipUI("Shape2.txt", shipX, frame1);
    handleShipUI("enemy.txt", bugX[0], bugs[0]);
    handleShipUI("enemy.txt", bugX[1], bugs[1]);

    // ## Begin SDL Display Stuff ##


    while (!g.getQuit())
    {
        background.draw(g);
        frame1.displayFrame(move, g);
        bugs[1].displayBugs(iku += moveX, 0, g, fall[1]);
        //.....................
        if(bugs[1].getCenter().X >= 640){
            moveX = -1;
        }
        if(bugs[1].getCenter().X <= 5){
            moveX = 1;
        }
        bugs[0].displayBugs(iku += moveX, 0, g, fall[0]);
        //.....................
        if(bugs[0].getCenter().X >= 640){
            moveX = -1;
        }
        if(bugs[0].getCenter().X <= 5){
            moveX = 1;
        }
        //.....................
        //cout<<"This is Bugs: "<<bugs.getCenter().X<<": "<<bugs.getCenter().Y<<endl;



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
                        bullet_1.X = frame1.getCenter().X;
                        bullet_2.X = frame1.getCenter().X - 20;
                        xChange = false;
                    }
                    bullet_1.Y = frame1.getCenter().Y - 20;
                    bullet_2.Y = frame1.getCenter().Y - 20;
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
            bulletSpeed[2] += 2;//Bullte Speed***********

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
            bulletSpeed[3] += 2;//Bullte Speed***********

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
            bulletSpeed[4] += 2;//Bullte Speed***********

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
            bulletSpeed[0] += 2;//Bullte Speed***********

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
            bulletSpeed[5] += 2;//Bullte Speed***********

            bullet1[5].displayBullet(bulletSpeed[5], g);
            bullet2[5].displayBullet(bulletSpeed[5], g);
            //attack(Target, bullet1[5], 15, fire, g, fall);
            if((bulletSpeed[5]) >= 600){
                //bullet1[5].eraseFlash(bulletSpeed[5], bullet1[5],g);
                bulletOne[5] = false;
                bulletSpeed[5] = 0;
            }
        }

		g.update();
    }
}



void handleBullet(bool bulletOne[], Bullet bullet1[], Bullet bullet2[], int bulletSpeed[], SDL_Plotter& g)
{

}

void handlePlotter(SDL_Plotter& g)
{

}
