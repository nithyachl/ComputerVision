//
// Created by Nithya Chintalapati on 9/9/20.
//

# include <iostream>
# include <fstream>
#include <cmath>

using namespace std;

int matrix[800*3][800*3];
int center [2];

double *lineLineIntersection(double slopeperpbi12, double d, double d1, double slopeperpbi13, double d2, double d3);

double getMidpoint(int mathx1, int mathx2);

double getSlope(int b1, int b2, int b3, int b4);

void drawcricle(double rcircumcircle, double xcenter, double ycenter);

void drawCircle(int i, int i1, int x, int y);

void bresenham(int x1, int y1, int x2, int y2)//int x0, int y0, int x1, int y1)
{

    int h = x2 - x1 ;
    int w = y2 - y1 ;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
    if (w<0) dy1 = -1 ; else if (w>0) dy1 = 1 ;
    if (h<0) dx1 = -1 ; else if (h>0) dx1 = 1 ;
    if (w<0) dy2 = -1 ; else if (w>0) dy2 = 1 ;
    int longest = abs(w) ;
    int shortest = abs(h) ;
    if (!(longest>shortest)) {
        longest = abs(h) ;
        shortest = abs(w) ;
        if (h<0) dx2 = -1 ; else if (h>0) dx2 = 1 ;
        dy2 = 0 ;
    }
    int numerator = longest >> 1 ;
    for (int i=0;i<=longest;i++) {
        matrix[y1][x1] = 0;
        numerator += shortest ;
        if (!(numerator<longest)) {
            numerator -= longest ;
            x1 += dx1 ;
            y1 += dy1 ;
        } else {
            x1 += dx2 ;
            y1 += dy2 ;
        }
    }

}

double distance(double x, double y, double a, double b)
{
    return sqrt(pow(x - a, 2) + pow(y - b, 2));
}


void findcircumcenter(int x1, int x2, int x3,int y1, int y2, int y3 ){



    int mathy1 = 799-x1;
    int mathy2 = 799-x2;
    int mathy3 = 799-x3;
    int mathx1 = y1;
    int mathx2 = y2;
    int mathx3 = y3;

    cout << "mathx1: " << mathx1 << " mathy1: " << mathy1 << "\n";
    cout << "mathx2: " << mathx2 << " mathy2: " << mathy2 << "\n";
    cout << "mathx3: " << mathx3 << " mathy3: " << mathy3 << "\n";

    double midpoint12x = (double)getMidpoint(mathx1,mathx2);
    double midpoint12y = (double)getMidpoint(mathy1,mathy2);
    double midpoint13x = (double)getMidpoint(mathx1,mathx3);
    double midpoint13y = (double)getMidpoint(mathy1,mathy3);

    cout << "m13x: "<< midpoint13x << "\n";
    cout << "m13y: "<< midpoint13y << "\n";

    double slope12 = (double)-1 / (double)getSlope(mathy2, mathy1, mathx2, mathx1);
    double slope13 = (double)-1 / (double)getSlope(mathy3, mathy1, mathx3, mathx1);

    cout << "s12: "<< slope12 << "\n";
    cout << "s13: "<< slope13 << "\n";

    double b12 = (double)midpoint12y - (double)slope12 * (double)midpoint12x;

    double b13 = (double)midpoint13y - (double)slope13 * (double)midpoint13x;

    cout << "b12: "<< b12 << "\n";
    cout << "b13: "<<b13 << "\n";

    double xfinal =  (b12 - b13) / (slope13 - slope12);
    double yfinal =  slope12 * xfinal + b12;


    int markcenterx = (int)(799-yfinal);
    int markcentery = (int)(xfinal);

    center[0] = markcenterx;
    center[1] = markcentery;

    matrix[markcentery][markcenterx] = 0;


    cout << "circumcenterxval: " << markcenterx << "\n";
    cout << "circumcenteryval: " << markcentery;


}

double getSlope(int b1, int b2, int b3, int b4) {
    return (double)((double)(b1-b2)/(double)(b3-b4));
}

double getMidpoint(int a1, int a2) {
    return (double)((a1+a2)/((double)2));
}

void circle(double r, double xcenter, double ycenter) {

    int x, y, r2;

    r2 = (int)r * (int)r;
    for (x = -r; x <= r; x++) {

             y = (int) (sqrt(r2 - x*x) +0.5 );
                matrix[(int) (ycenter + y)][ (int)(xcenter + x)] = 0;
                matrix[(int) (ycenter - y)][ (int)(xcenter + x)] = 0;
            }
}




int main() {
    int dimx = 800;
    int dimy = 800;
    using namespace std;
    ofstream myfile;
    myfile.open ("next.ppm");
    myfile << "P3" << endl << dimx << ' ' << dimy << endl << "1" << endl;

    srand( time(NULL) );

    int x1 = 353;//(int)(rand()%800);
    int y1 = 178;//(int)(rand()%800);

    int x2 = 707;//(int)(rand()%800);
    int y2 = 178;//(int)(rand()%800);

    int x3 = 768;//(int)(rand()% 800);
    int y3 = 458;//(int)(rand()% 800);


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

 findcircumcenter( x1,  x2,  x3, y1,  y2, y3 );
 circle(rcircumcircle, center[0], center[1]);

  // cout << "circumcenterxval: " << circumcenter[0];
 // cout << "circumcenterxval: " << circumcenter[1];
   /**

 To calulate the coordinates of the circumcenter, find the intersection of the
perpendicular bisectors of any two of the triangle’s sides. **/


    for (int n = 0; n < dimy*3; ++n) {
        for (int m = 0; m < dimx*3; ++m) {

                myfile<< matrix[n][m]<< "" << matrix[n][m]<< "" <<matrix[n][m] << " ";//std::to_string(matrix[n][m])<< " ";

        }
        myfile << endl;
    }


myfile.close();


    return 0;
}





