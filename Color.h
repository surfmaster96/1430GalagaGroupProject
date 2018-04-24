//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Author: Martyn Staalsen
//  Assignment Title: Group Project
//  Assignment Description: Functions as a clone of Galaga.
//  Due Date: 4/26/2018
//  Date Created: 4/3/2018
//  Date Last Modified: 4/4/2018
//  Contributor: Andrew Zimmerman
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color
{
    int R,G,B;
    
    //************************************************************
    // description: Constructs a color in default setting        *
    // return: nothing to return                                 *
    // precondition: Color must be in the correct environment    *
    // postcondition: A Color is constructed with default values *
    //************************************************************
    Color();
    //************************************************************
    // description: Constructs a point using given values        *
    // return: nothing to return                                 *
    // precondition: r, g, and b must be valid and the           *
    //  environment must be correct                              *
    // postcondition: A point is constructed with r, g, and b    *
    //************************************************************
    Color(int r, int g, int b);
    
};


#endif // COLOR_H_INCLUDED

