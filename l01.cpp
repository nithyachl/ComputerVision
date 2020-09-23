//
// Created by Nithya Chintalapati on 9/9/20.
//

# include <iostream>
# include <fstream>
#include <cmath>

using namespace std;

int matrix[800][800 * 3];

void bresenham(int x0, int y0, int x1, int y1)//int x1, int y1, int x2, int y2)
{

    int dx, dy, p, x, y;

    dx=x1-x0;
    dy=y1-y0;

    x=x0;
    y=y0;

    p=2*dy-dx;
    cout << p;
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

}

double distance(double x, double y, double a, double b)
{
    return sqrt(pow(x - a, 2) + pow(y - b, 2));
}


double * findcircumcenter(){
 /**double arr[2];
        // Line PQ is represented as ax + by = c
        double a, b, c;
lineFromPoints(P, Q, a, b, c);

// Line QR is represented as ex + fy = g
double e, f, g;
lineFromPoints(Q, R, e, f, g);

// Converting lines PQ and QR to perpendicular
// vbisectors. After this, L = ax + by = c
// M = ex + fy = g
perpendicularBisectorFromLine(P, Q, a, b, c);
perpendicularBisectorFromLine(Q, R, e, f, g);

// The point of intersection of L and M gives
// the circumcenter
pdd circumcenter =
        lineLineIntersection(a, b, c, e, f, g);
return arr;
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

    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x1, y1, x3, y3);
  int s =  0.5 * (a+b+c);

  double rincircle = sqrt(((s-a)*(s-b)*(s-c))/s);
  double rcircumcircle = (a*b*c)/(4*rincircle *s);

   /**

 To calulate the coordinates of the circumcenter, find the intersection of the
perpendicular bisectors of any two of the triangle’s sides. **/


    for (int n = 0; n < dimy; n++) {
        for (int m = 0; m < dimx*3; m++) {

                myfile<< std::to_string(matrix[n][m])<< " ";

        }
        myfile << endl;
    }


myfile.close();


    return 0;
}



