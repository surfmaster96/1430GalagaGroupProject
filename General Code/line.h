#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <cmath>
#include "point.h"
#include "color.h"

using namespace std;

class Line{
private:
    Point p1, p2;
    Color color;
    
    bool slope(double& ) const;
    bool y_intercept(double& ) const;
public:
    Line();
    Line(Point, Point);
    
    void draw(ostream& ) const;
    void draw(SDL_Plotter& ) const;
    
    Point getP1() const;
    Point getP2() const;
    Color getColor() const;
    
    void setP1(const Point);
    void setP2(const Point);
    void setColor (const Color);
    
};

#endif // LINE_H_INCLUDED

