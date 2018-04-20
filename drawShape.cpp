
#include "drawShape.h"


void drawShape(string txt,int xpos, int ypos, SDL_Plotter& g,int scale)
{
    ifstream text;
    string line;
    text.open(txt);
    if(!text)
    {
        cout<<"NO BUENO"<<endl;
    }

    char val;
    int m=0,n=0;
    int dim;
    int R,G,B;
    static int real_scale;
    bool print;

    if (scale > 0)
    {
        real_scale = scale;
    }


    // store text file in "picture"
    text >> dim;
    for(int y = 1; y<=dim;y++)
    {
        for(int x = 1; x <= dim; x++)
        {
            print = true;
            text >> val;
            if (scale <=0)
            {
                R = BACKGROUND_R;
                G = BACKGROUND_G;
                B = BACKGROUND_B;
            }
            else if(val == 'R')
            {
                R = 255;
                G = 5;
                B = 5;
            }
            else if(val == 'r')
            {
                R = 150;
                G = 0;
                B = 0;
            }
            else if(val == 'P')
            {
                R = 151;
                G = 0;
                B = 222;
            }
            else if(val == 'p')
            {
                R = 255;
                G = 0;
                B = 222;
            }
            else if(val == 'T')
            {
                R = 0;
                G = 255;
                B = 222;
            }
            else if(val == 't')
            {
                R = 0;
                G = 150;
                B = 111;
            }
            else if(val == 'G')
            {
                R = 0;
                G = 151;
                B = 151;
            }
            else if(val == 'O')
            {
                R = 222;
                G = 71;
                B = 0;
            }
            else if(val == 'Y')
            {
                R = 255;
                G = 255;
                B = 0;
            }
            else if(val == 'y')
            {
                R = 150;
                G = 150;
                B = 0;
            }
            else if(val == 'W')
            {
                R = 255;
                G = 255;
                B = 255;
            }
            else if(val == 'B')
            {
                R = 0;
                G = 104;
                B = 222;
            }
            else
            {
                print = false;
            }
            for(int j = 1; j <=real_scale; j++)
            {
                for(int i=1;i<=real_scale; i++)
                {
                    if(print)
                    {
                        g.plotPixel((xpos+x*real_scale+i-dim*real_scale/2)%SCREEN_WIDTH,
                        (ypos + y*real_scale+j-dim*real_scale/2)%SCREEN_HIEGHT,R,G,B);
                    }
                }
            }
        }
    }
}
