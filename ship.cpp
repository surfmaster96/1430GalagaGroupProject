#include "ship.h"


Ship::Ship(){
    for(int i = 0; i < 50;i++){
        for(int j = 0; j < 50; j++){
        color[i][j].R = 0;
        color[i][j].B = 255;
        color[i][j].G = 255;
        L[i][j].x = 400+i;
        L[i][j].y = 400+j;
        }
    }
}

void Ship::setColor(int x, int y,Color c){
    color[x][y] = c;
}
Point Ship::getL(int x, int y) const{
    return L[x][y];
}
void Ship::setL(int x, int y, Point p){
    L[x][y] = p;
}

Color Ship::getColor(int x, int y) const{
    return color[x][y];
}
//*******Do not use draw or display, because it waste too many RAM and GPU.
void Ship::draw(SDL_Plotter& g){
    for(int j = 0; j < 50; j++){
        for(int i = 0;i <50; i++){
            g.plotPixel(L[i][j].x, L[i][j].y, color[i][j].R, color[i][j].G, color[i][j].B);
        }
    }
}

void Ship::display(SDL_Plotter& g){
    for(int j = 0; j < 500; j++){
        g.plotPixel(L[j][j].x, L[j][j].y, color[j][j].R, color[j][j].G, color[j][j].B);
    }
}
