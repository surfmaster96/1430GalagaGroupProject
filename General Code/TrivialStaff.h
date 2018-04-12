#ifndef IFattack_h
#define IFattack_h

#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"
#include "ShipFrame.h"
#include "ship.h"
#include "Bullet.h"
#include <fstream>
#include <string>
#include <ostream>
#include <cmath>
using namespace std;

void attack(Point bugs, Bullet bullet, int targetRadius, ShipFrame fire, SDL_Plotter& g, bool& flag);

void handleShipUI(string filename, Point start, int& count1, ShipFrame& frame1, int column);



#endif /* IFattack_h */
