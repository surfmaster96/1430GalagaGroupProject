#ifndef READSHAPE_hpp
#define READSHAPE_hpp

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"

class Ship{
private:
    Color color[50][50];
    Point L[50][50];
    
public:
    Ship();
    
    void setColor(int,int,Color);
    void setCenter(Point);
    Point getL(int x, int y) const;
    void setL(int, int, Point);
    
    Color getColor(int, int) const;
    Point getCenter() const;
    
    void draw(SDL_Plotter& );
    void display(SDL_Plotter& );
};
#endif /* READSHAPE_hpp */
