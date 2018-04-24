#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "color.h"
#include "point.h"
#include "SDL_Plotter.h"
#include <cmath>

using namespace std;

class Circle{
private:
    Color color;
    double radius;
    Point center;
    
public:
    Circle();
    
    void setColor(Color);
    void setRadius(double);
    void setCenter(Point);
    
    Color  gerColor()  const;
    double getRadius() const;
    Point  getCenter() const;
    
    void draw(SDL_Plotter& ) const;
};

#endif // CIRCLE_H_INCLUDED

