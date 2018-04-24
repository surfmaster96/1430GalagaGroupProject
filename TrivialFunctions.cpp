#include "TrivialFunctions.h"

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

bool byebye(ShipFrame bugs, int n, Bullet bullet, int m){
    double distance;
    bool flag = false;
    Point center;
    center= bugs.getCenter();
    distance = sqrt(pow((center.X - bullet.getLocation().X),2)+pow((center.Y - bullet.getLocation().Y),2));
    if(distance < bugs.getBugRadius()){
        flag = true;
    }
    return flag;
}

void catchShip(ShipFrame &bugs, ShipFrame &spaceship){
    double distance;
    bool flag = false;
    Point center1, center2;
    if(!bugs.getbugsfall()&& !spaceship.getbugsfall()){
        center1= bugs.getCenter();
        center2=spaceship.getCenter();
        distance = sqrt(pow((center1.X - center2.X),2)+pow((center1.Y - center2.Y),2));
        if(distance < bugs.getBugRadius()){
            flag = true;
        }
        bugs.setbugsfall(flag);
        spaceship.setbugsfall(flag);
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
    bool print = true;
    bool Acenter = false;
    
    // ## Begin Read of Design ##
    readIn.open(filename.c_str());
    if(!readIn)
    {
        cout << "Error: Reading of Ship Shape failed." << endl;
    }
    
    readIn >> column;
    //column = junkLine.size();
    while(readIn >> colorChar)
    {
        // Ship's Location
        location = Point(start.X + readC, start.Y+readR);
        
        /*
         If you need more colors, just simply copy the if statement and change
         color1's value to make a new color.
         */
        print = true;
        if(colorChar == 'R') // if it's R
        { // we set to red
            color1 = Color(255,5,5);
            
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'W') // if it's W
        { // we set to white
            color1 = Color(255,255,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'B') // if it's B
        { // we set to blue
            color1 = Color(0,120,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'r') // if it's B
        { // we set to blue
            color1 = Color(150,0,0);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'P') // if it's B
        { // we set to blue
            color1 = Color(151,0,222);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'p') // if it's B
        { // we set to blue
            color1 = Color(255,0,222);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'T') // if it's B
        { // we set to blue
            color1 = Color(0,255,222);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 't') // if it's B
        { // we set to blue
            color1 = Color(0,150,111);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'G') // if it's B
        { // we set to blue
            color1 = Color(0,151,151);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'O') // if it's B
        { // we set to blue
            color1 = Color(222,71,0);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'Y') // if it's B
        { // we set to blue
            color1 = Color(255,255,0);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar == 'y') // if it's B
        { // we set to blue
            color1 = Color(150,150,0);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
        }
        else if(colorChar =='$')//find a center point and blue.
        {
            color1 = Color(0,120,255);
            mainChar.setLocation(readR, readC, location);
            mainChar.setColor(readR, readC, color1);
            Acenter = true;
        }
        else{
            print = false;
        }
        
        // ## Bullet Related ##
        if(print) // If One, Two or Three are true
        { // set frame1 to a new location and new color and iterate count1.
            frame1.setLocation(count1, location);
            frame1.setColor(count1, color1);
            count1++;
            /*
             We take divisor of count1, then we can get some Point of
             the "fire" Point, which can be used for creating bullet.
             */
        }
        if(Acenter){
            frame1.midNum = count1;
            frame1.setCenter(location);
            Acenter = false;
        }
        readC++;
        //Need The Matirx Information!!!
        if(readC % column == 0)
        {
            readR++;
            readC = 0;
        }
    }
    frame1.setCount(count1);
    readIn.close(); // close our open file.
    //cout << "Successfully Reading File, \n converting..." << endl;
    //cout << count1 << endl;
}

void setStart(Point start, ShipFrame& frame1){
    int count = frame1.getCount();
    Point temp, center;
    center = frame1.getCenter();
    for(int i = 0; i <= count; i++){
        temp = frame1.getLocation(i);
        temp.X = (temp.X-center.X+start.X);
        temp.Y = (temp.Y-center.Y+start.Y);
        frame1.setLocation(i, temp);
        
        /*
         void ShipFrame::setLocation(int x, Point p)
         {
         location[x] = p;
         }
         */
    }
}

//designed for same size of ship with different color.
void changeImage(string filename, ShipFrame& frame1)
{
    ifstream readIn;
    Ship mainChar;
    Color color1;
    int count1 = 0;
    char colorChar;
    bool print = true;
    
    // ## Begin Read of Design ##
    readIn.open(filename.c_str());
    if(!readIn)
    {
        cout << "Error: Reading of Ship Shape failed." << endl;
    }
    //column = junkLine.size();
    while(readIn >> colorChar)
    {
        print = true;
        if(colorChar == 'R') // if it's R
        { // we set to red
            color1 = Color(255,5,5);
        }
        else if(colorChar == 'W') // if it's W
        { // we set to white
            color1 = Color(255,255,255);
        }
        else if(colorChar == 'B') // if it's B
        { // we set to blue
            color1 = Color(0,120,255);
        }
        else if(colorChar == 'r') // if it's B
        { // we set to blue
            color1 = Color(150,0,0);
        }
        else if(colorChar == 'P') // if it's B
        { // we set to blue
            color1 = Color(151,0,222);
        }
        else if(colorChar == 'p') // if it's B
        { // we set to blue
            color1 = Color(255,0,222);
        }
        else if(colorChar == 'T') // if it's B
        { // we set to blue
            color1 = Color(0,255,222);
        }
        else if(colorChar == 't') // if it's B
        { // we set to blue
            color1 = Color(0,150,111);
        }
        else if(colorChar == 'G') // if it's B
        { // we set to blue
            color1 = Color(0,151,151);
        }
        else if(colorChar == 'O') // if it's B
        { // we set to blue
            color1 = Color(222,71,0);
        }
        else if(colorChar == 'Y') // if it's B
        { // we set to blue
            color1 = Color(255,255,0);
        }
        else if(colorChar == 'y') // if it's B
        { // we set to blue
            color1 = Color(150,150,0);
        }
        else if(colorChar =='$')//find a center point and blue.
        {
            color1 = Color(0,120,255);
        }
        else{
            print = false;
        }
        if(print)
        {
            frame1.setColor(count1, color1);
            count1++;
        }
    }
    readIn.close(); // close our open file.
}
