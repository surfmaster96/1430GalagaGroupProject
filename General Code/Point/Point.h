//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Martyn Staalsen
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributors: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

struct Point
{
    int X, Y;
    
    //************************************************************
    // description: Constructs a point in default setting        *
    // return: nothing to return                                 *
    // precondition: Point must be in the correct environment    *
    // postcondition: A point is constructed with default values *
    //************************************************************
    Point();
    //************************************************************
    // description: Constructs a point using given values        *
    // return: nothing to return                                 *
    // precondition: X and Y must be valid and the enviornment   *
    //  must be correct                                          *
    // postcondition: A point is constructed with X and Y        *
    //************************************************************
    Point(int, int);
};

#endif // POINT_H_INCLUDED
