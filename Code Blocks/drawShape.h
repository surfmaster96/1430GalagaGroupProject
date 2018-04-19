//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //  Author: Martyn Staalsen
    //  Assignment Title: Group Project
    //  Assignment Description: Functions as a Clone of Galaga.
    //  Due Date: 4/26/2018
    //  Date Created: 4/18/2018
    //  Date Last Modified: 4/18/2018
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef DRAWSHAPE_H_INCLUDED
#define DRAWSHAPE_H_INCLUDED

#include <iostream>
#include "SDL_Plotter.h"
#include <sstream>
#include <fstream>

const int BACKGROUND_R = 0;
const int BACKGROUND_G = 0;
const int BACKGROUND_B = 0;
const int SCREEN_WIDTH = 500;
const int SCREEN_HIEGHT = 500;


    //************************************************************
    // description: simple function for plotting shapes from text files
    // return:   void
    // precondition:  text file exist formatted as indicated below, SDL plotter
    // postcondition: shape will have been plotted to the screen hopefully
    //************************************************************
void drawShape(string txt,int xpos,int ypos,SDL_Plotter& g,int scale);
//  Here's what you need to know about this function:
//
//      First, the FILE FORMATTING:
//          The file should be a .txt file.
//          The file should contain a square matrix of characters, which
//              can or can not be separated by spaces.
//          The first line of the file should be an integer
//              giving the side length of the square.
//          Generally, only letters will plot a color, while any character
//              in the array which does not have a color assigned to it will
//              not result in a pixel being plotted.
//          For best results, your arrays should have an odd numbered
//              side length, as explained in the FRAME PLACEMENT section.
//
//      Second, regarding COLORS and ANTI-ALIASING:
//          You can see what colors are plotted by which characters in the cpp,
//              obviously.
//      However, you should know that, generally speaking, colors are plotted
//          with capital letters.
//      Some lower case letters do have assigned colors.
//      In most cases where a lowercase letter has a color, that color is half
//          the brightness of the color assigned to the uppercase version of
//          that letter. This allows you to use lower case letters for
//          anti-aliasing. See the power up emblem txt files for an example
//          of this.
//
//      THIRD, regarding SCALE:
//          The last input parameter controls scale. Scale should be a positive
//              integer for most cases.
//
//      FOURTH, regarding ERASING:
//          You should notice the three constants at the top of this header.
//          They are here so that this function can erase itself for simple
//              animation testing.
//          Here's how erasing works: if you pass a scale that is <= 0,
//              the function will print every pixel of the file you pass it
//              AT WHATEVER SCALE IT HAD LAST.
//          This means you should probably not use this function to actually
//              animate real game objects without adding an "erase" parameter
//              to it, because you don't really have any control over erasing
//              if you are trying to animate several objects at the same time.
//              which have different scale sizes.
//
//      FIFTH, regarding FRAME PLACEMENT:
//          The x and y position inputed into this function will be the CENTER
//              of the plotted frame. Probably.
//          Because of this, to get an accurate center, you probably want to
//              plot odd-dimensioned arrays. Although the arrays might be a
//              single pixel off center.
//
//      Also, note that plotting involves modulusing by screen size so that you
//          can't print off screen.
//      Therefore, keep the screen size constants in here too please, or
//          somewhere.
//


#endif // DRAWSHAPE_H_INCLUDED
