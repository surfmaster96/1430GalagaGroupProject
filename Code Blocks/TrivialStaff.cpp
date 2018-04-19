#include "TrivialStaff.h"
#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"
#include "ShipFrame.h"
#include "ship.h"
#include <fstream>
#include <string>
#include <ostream>
using namespace std;

void attack(Point bugs, Bullet bullet, double targetRadius, ShipFrame fire, SDL_Plotter& g, bool& flag){
    //the point of bugs is the center of the bugs, for bullet, the point is the top one.
    double distance;
    //bullet.getLocation();
    flag = false;
    distance = sqrt(pow((bugs.X - bullet.getLocation().X),2)+pow((bugs.Y - bullet.getLocation().Y),2));
    //cout <<bugs.X<<endl;
    //cout <<bugs.Y<<endl;
    if(distance < targetRadius){
        fire.displayFire(g, bugs);
        //g.Sleep(25);
        flag = true;
        //cout <<"Break"<<endl;
    }
}

void handleShipUI(string filename, Point start, ShipFrame& frame1)
{
    ifstream readIn;
    Point location;
    string junkLine;
    Ship mainChar;
    Color color1;
    int count1 = 0, column = 0;
    int readR = 0, readC = 0;
    char colorChar;
    bool one = false, two = false, three = false;
    
    // ## Begin Read of Design ##
    readIn.open(filename.c_str());
    if(!readIn)
    {
        cout << "Error: Reading of Ship Shape failed." << endl;
    }
    
    getline(readIn, junkLine);
    column = junkLine.size();
    while(readIn >> colorChar)
    {
        // Ship's Location
        location = Point(start.X + readC, start.Y+readR);
        
        /*
         If you need more colors, just simply copy the if statement and change
         color1's value to make a new color.
         */
        
        if(colorChar == 'R') // if it's R
        { // we set to red
            color1 = Color(255,0,60);
            
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            one = true;
        }
        if(colorChar == 'W') // if it's W
        { // we set to white
            color1 = Color(255,255,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            two = true;
        }
        if(colorChar == 'B') // if it's B
        { // we set to blue
            color1 = Color(0,120,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            three = true;
        }
        
        // ## Bullet Related ##
        if(one||two||three) // If One, Two or Three are true
        { // set frame1 to a new location and new color and iterate count1.
            frame1.setLocation(count1, location);
            frame1.setColor(count1, color1);
            count1++;
            /*
             We take divisor of count1, then we can get some Point of
             the "fire" Point, which can be used for creating bullet.
             */
        }
        
        readC++;
        //Need The Matirx Information!!!
        if(readC % column == 0)
        {
            readR++;
            readC = 0;
        }
        
        one = two = three = false;
    }
    frame1.setCount(count1);
    readIn.close(); // close our open file.
    //cout << "Successfully Reading File, \n converting..." << endl;
    //cout << count1 << endl;
}
