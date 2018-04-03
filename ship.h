/*This function is using to reading the .txt file, and the deafult dimension I set is 50x50;
which means it can hold 2500 objects.
Because there are a lot of waste space if you draw 50X50 everytime, I created another function named
displayArray, which is simply an object to hold "valid" points, for example, in "Shape2.txt", only 947
points have colors. Hence, draw displayArray will increase the efficient. (I think this can hold BUGS too)

Some tips:
since the dimention is 50x50, we can change it if you want hold some bigger guy, remember change all related
value, like in displayArray, 2500 = 50 x 50;
by reading .txt files, in main.cpp, the value of columen is associated with how many columns your .txt have.
btw, please use "." or some nonsense "char" to make sure each row have same columens.

*/

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
