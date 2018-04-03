#include "Bullet.h"


flash::flash(){
    for(int i = 0; i<100; i++){
        int j = 0;
        Shot[i].x = Shot[i].y = 0;
        Shot[i].x +=i;
        Shot[i].y +=j;
        if(i%10 == 0){
            j++;
        }
        color[i].R = 255;
        color[i].G = 50;
        color[i].B = 120;
    }
}

void flash::setColor(int x,Color c){
    color[x]=c;
}
void flash::setShot(Point p){
    int m = 0, n = 0, x = 100;
    for(int i = 0; i<x; i++){
        Shot[i].x = p.x+m;
        Shot[i].y = p.y+n;
        m++;
        //***m%5, 5 is the wigth of bullet.
        if((m%5) == 0){
            n++;
            m = 0;
        }
    }
}

Color flash::getColor(int x) const{
    return color[x];
}

Point flash::getShot(int x) const{
    return Shot[x];
}

void flash::displayflash(int BulletSpeed, flash, SDL_Plotter& g){
    int x = 100;
    double m, n;
    for(int i = 0; i < x; i++){
        m = Shot[i].x;
        n = Shot[i].y;
        n -= BulletSpeed;
        g.plotPixel(m, n, 100, 50, 120);
    }
}

void flash::eraseflash(int BulletSpeed, flash, SDL_Plotter& g){
    double m, n;
    int x = 100;
    for(int i = 0; i < x; i++){
        m = Shot[i].x;
        n = Shot[i].y;
        n -= BulletSpeed;
        g.plotPixel(m, n, 255, 255, 255);
    }
}
