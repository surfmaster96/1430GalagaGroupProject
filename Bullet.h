#ifndef Bullet_h
#define Bullet_h

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"
#include "ship.h"


class flash{
private:
    Point Shot[100];
    Color color[100];
    
public:
    flash();
    
    void setColor(int,Color);
    void setShot(Point);
    
    Color getColor(int) const;
    Point getShot(int) const;
    
    void displayflash(int Move, flash, SDL_Plotter& g);
    void eraseflash(int Move, flash, SDL_Plotter& g);
    
    
    
    
};




#endif /* Bullet_h */
