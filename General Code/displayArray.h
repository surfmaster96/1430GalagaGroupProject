#ifndef displayArray_hpp
#define displayArray_hpp
#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"


class shipframe{
private:
    Color color[2500];
    Point Lone[2500];
    
public:
    shipframe();
    
    void setColor(int,Color);
    void setLone(int, Point);
    
    Color getColor(int) const;
    Point getLone(int) const;
    
    void displayframe(int,int Move, shipframe, SDL_Plotter& g, double&, double&);
    void eraseframe(int,int Move, shipframe, SDL_Plotter& g);
    
};






#endif /* displayArray_hpp */
