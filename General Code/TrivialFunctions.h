#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include "SDL_Plotter.h"
#include "ship.h"
#include "Point.h"
#include "ShipFrame.h"
#include "Bullet.h"

#ifndef TrivialFunctions_hpp
#define TrivialFunctions_hpp

using namespace std;

void handleBullet(bool[], Bullet[], int[], SDL_Plotter&);
void handlePlotter();
void attack(Point bugs, Bullet bullet, double targetRadius, ShipFrame fire, SDL_Plotter& g, bool& flag);

void handleShipUI(string filename, Point start, ShipFrame& frame1);

void changeImage(string filename, ShipFrame& frame1);

bool byebye(ShipFrame bugs, int n, Bullet bullet, int m);

void setStart(Point start, ShipFrame& frame1);



#endif /* TrivialFunctions_hpp */
