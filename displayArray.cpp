#include "displayArray.h"

shipframe::shipframe(){
    for(int i = 0; i <= 2500;i++){
        Lone[i].x = Lone[i].y = 200;
        color[i].R = 0;
        color[i].B = 255;
        color[i].G = 255;
    }
}

void shipframe::setColor(int x,Color c){
    color[x] = c;
}


void shipframe::setLone(int x, Point p){
    Lone[x] = p;
}

Color shipframe::getColor(int x) const{
    return color[x];
}

Point shipframe::getLone(int x) const{
    return Lone[x];
}

void shipframe::displayframe(int x,int Move, shipframe, SDL_Plotter& g,double& X, double& Y){
    double m, n;
    
    for(int i = 0; i < x; i++){
        m = Lone[i].x;
        m += Move;
        n = Lone[i].y;
        //*****************X,Y for Bullet.
        X = Lone[x/3].x;
        X += Move;
        Y = Lone[x/3].y;
        g.plotPixel(m, n, color[i].R, color[i].G, color[i].B);
    }
}

void shipframe::eraseframe(int x,int Move, shipframe, SDL_Plotter& g){
    double m, n;
    
    for(int i = 0; i < x; i++){
        m = Lone[i].x;
        m += Move;
        n = Lone[i].y;
        g.plotPixel(m, n, 255, 255, 255);
    }
}

