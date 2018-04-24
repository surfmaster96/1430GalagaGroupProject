#include "circle.h"

Circle::Circle(){
    color.R  = 225;
    radius   = 15;
    center.x = 100;
    center.y = 100;
}

void Circle::setColor(Color c){
    color = c;
    
}
void Circle::setRadius(double r){
    radius = r;
}
void Circle::setCenter(Point p){
    center = p;
}

Color  Circle::gerColor()  const{
    return color;
    
    
}
double Circle::getRadius() const{
    return radius;
}
Point  Circle::getCenter() const{
    return center;
}

void Circle::draw(SDL_Plotter& g) const{
    double y;
    //for(double x = - radius; x<=radius; x += 0.01){
    //    y = sqrt(pow(radius,2) - pow(x, 2));
    //    g.plotPixel(center.x + x,center.y + y, color.R, color.G, color.B);
    //    g.plotPixel(center.x + x,center.y - y, color.R, color.G, color.B);
    //}
    
    for(int x = -radius; x <= radius; x++){
        for(int y = -radius; y <= radius; y++){
            if(sqrt(x*x + y*y)<=radius){
                g.plotPixel(center.x + x,center.y + y, color.R, color.G, color.B);
            }
        }
    }
}

