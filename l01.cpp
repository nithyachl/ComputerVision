//
// Created by Nithya Chintalapati on 9/9/20.
//

# include <iostream>
# include <fstream>

using namespace std;

int matrix[800][800 * 3];

void bresenham(int x1, int y1, int x2, int y2)
{

    int dy = 2 * (y2 - y1);
    int e = dy - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        //cout << "(" << x << "," << y << ")\n";
        matrix[y][x] = 0;
        // Add slope to increment angle formed
        e += dy;

        // Slope error reached limit, time to
        // increment y and update slope error.
        if (e >= 0)
        {
            y++;
            e  -= 2 * (x2 - x1);
        }
    }
    /**
       int dx = x2-x1;
       int dy = y2-y1;

       int j = y1;
       int e = dy-dx;

       matrix[y1][x1] = matrix[y2][x2] = 0;
       for(int z = x1; z<= x2 -1;z++)
       {
           matrix[j][z] = 0; // switch these to matrix[z][j]?
           if(e >= 0)
           {
               j += 1;
               e -= dx;
           }
           e +=dy;
           z +=1;
       }

       int dx, dy, p, x, y;

       dx=x1-x0;
       dy=y1-y0;

       x=x0;
       y=y0;

       p=2*dy-dx;

       while(x<x1)
       {
           if(p>=0)
           {
               matrix[y][x] = 0;
               y=y+1;
               p=p+2*dy-2*dx;
           }
           else
           {
               matrix[y][x] = 0;
               p=p+2*dy;
           }
           x=x+1;
       }
         **/
}

int main() {
    int dimx = 800;
    int dimy = 800;
    using namespace std;
    ofstream myfile;
    myfile.open ("next.ppm");
    myfile << "P3" << endl << dimx << ' ' << dimy << endl << "1" << endl;

    srand( time(NULL) );

    int x1 = (int)(rand()%800);
    int y1 = (int)(rand()%800);

    int x2 = (int)(rand()%800);
    int y2 = (int)(rand()%800);

    int x3 = (int)(rand()% 800);
    int y3 = (int)(rand()% 800);


    if (x2> x3)
    {
        int temp = x2;
        x2 = x3;
        x3 = temp;

    }
    if (x1> x2)
    {
        int temp = x1;
        x1 = x2;
        x2 = temp;

    }
    if (x2> x3)
    {
        int temp = x2;
        x2 = x3;
        x3 = temp;

    }

    if (y2> y3)
    {
        int temp = y2;
        y2 = y3;
        y3 = temp;

    }
    if (y1> y2)
    {
        int temp = y1;
        y1 = y2;
        y2 = temp;

    }
    if (y2> y3)
    {
        int temp = y2;
        y2 = y3;
        y3 = temp;

    }



    cout << "x1: " << x1 << " y1: " << y1 << "\n";
    cout << "x2: " << x2 << " y2: " << y2 << "\n";
    cout << "x3: " << x3 << " y3: " << y3 << "\n";




    for (int n = 0; n < dimy; ++n) {
        for (int m = 0; m < dimx*3; ++m) {
            matrix[n][m] = 1;
        }
    }

    bresenham(x1, y1, x2, y2);
    bresenham(x2, y2, x3, y3);
    bresenham(x1, y1, x3, y3);
/**
    int dx = x2-x1;
    int dy = y2-y1;

    int j = y1;
    int e = dy-dx;

    matrix[y1][x1] = matrix[y2][x2] = 0;
    for(int z = x1; z<= x2 -1;z++)
    {
        matrix[j][z] = 0; // switch these to matrix[z][j]?
        if(e >= 0)
        {
            j += 1;
            e -= dx;
        }
        e +=dy;
        z +=1;
    }

    int dx2 = x3-x2;
    int dy2 = y3-y2;

    int j2 = y2;
    int e2 = dy2-dx2;

    //matrix[y1][x1] = matrix[y2][x2] = 0;
    for(int n = x2; n<= x3 ;n++)
    {
        matrix[j2][n] = 0; // switch these to matrix[z][j]?
        if(e2 >= 0)
        {
            j2 += 1;
            e2 -= dx2;
        }
        e2 +=dy2;
        n +=1;
    }
**/
    for (int n = 0; n < dimy; n++) {
        for (int m = 0; m < dimx*3; m++) {

                myfile<< std::to_string(matrix[n][m])<< " ";

        }
        myfile << endl;
    }


myfile.close();


    return 0;
}



