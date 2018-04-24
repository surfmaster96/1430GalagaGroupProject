#include "line.h"
#include "color.h"
#include "point.h"

bool Line::slope(double& m) const{
    bool flag = true;
    flag = (p1.x != p2.x);
    
    if(flag){
        m = static_cast<double>((p1.y-p2.y))/(p1.x-p2.x);
    }
    return flag;
}
bool Line::y_intercept(double& b) const{
    bool flag = true;
    double m;
    flag = slope(m);
    if(flag){
        b = p1.y - p1.x * m;
    }
    return flag;
}




Line::Line(){
    p2.x = 1;
    p2.y = 1;
}
Line::Line(Point a, Point b){
    p1 = a;
    p2 = b;
}

void Line::draw(ostream& output) const{
    //p1.draw(output);
    //p2.draw(output);
    double m,b;
    if(slope(m)){
        y_intercept(b);
        cout << "y= "<<m<<"x + " << b ;
    }
    else{
        cout << "x = "<<p1.x;
    }
    
}
void Line::draw(SDL_Plotter& g) const{
    double m, b, y;
    if(slope(m)){
        y_intercept(b);
        for(double x = min(p1.x, p2.x);x <= (p1.x, p2.x); x += 0.1){
            y = m * x + b;
            g.plotPixel(x + 0.5,y, color.R, color.G, color. B);
        }
    }
    else{
        for(double y = min(p1.y,p2.y); y <= max(p1.y,p2.y);y+=0.1){
            g.plotPixel(p1.x, y+0.5, color.R, color.G, color.B);
        }
    }
}

Point Line::getP1() const{
    return p1;
}
Point Line::getP2() const{
    return p2;
}
Color Line::getColor() const{
    return color;
}

void Line::setP1(const Point a){
    p1 = a;
    
}
void Line::setP2(const Point a){
    p2 = a;
}
void Line::setColor (const Color c){
    color = c;
}

