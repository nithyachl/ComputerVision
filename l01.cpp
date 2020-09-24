//
// Created by Nithya Chintalapati on 9/9/20.
//

# include <iostream>
# include <fstream>
#include <cmath>

using namespace std;

int matrix[800][800 * 3];

double *lineLineIntersection(double slopeperpbi12, double d, double d1, double slopeperpbi13, double d2, double d3);

void bresenham(int x1, int y1, int x2, int y2)//int x0, int y0, int x1, int y1)
{
    int w = x2 - x1 ;
    int h = y2 - y1 ;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
    if (w<0) dx1 = -1 ; else if (w>0) dx1 = 1 ;
    if (h<0) dy1 = -1 ; else if (h>0) dy1 = 1 ;
    if (w<0) dx2 = -1 ; else if (w>0) dx2 = 1 ;
    int longest = abs(w) ;
    int shortest = abs(h) ;
    if (!(longest>shortest)) {
        longest = abs(h) ;
        shortest = abs(w) ;
        if (h<0) dy2 = -1 ; else if (h>0) dy2 = 1 ;
        dx2 = 0 ;
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

/**
    int dx, dy, p, x, y;

    dx=x1-x0;
    dy=y1-y0;

    x=x0;
    y=y0;

    p=2*dy-dx;
    //cout << p;


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

double distance(double x, double y, double a, double b)
{
    return sqrt(pow(x - a, 2) + pow(y - b, 2));
}


double * findcircumcenter(int x1, int x2, int x3,int y1, int y2, int y3 ){

    double* center;

    int mathy1 = 1;//799-x1;
    int mathy2 = -2;//799-x2;
    int mathy3 = -4;//799-x3;
    int mathx1 = 0;//y1;
    int mathx2 = 4;//y2;
    int mathx3 = 3;//y3;

//    cout << "mathx1: " << mathx1 << " mathy1: " << mathy1 << "\n";
//    cout << "mathx2: " << mathx2 << " mathy2: " << mathy2 << "\n";
//    cout << "mathx3: " << mathx3 << " mathy3: " << mathy3 << "\n";

    double slope12 = double(mathy2-mathy1)/double(mathx2-mathx1);
    //cout <<"slope: " <<slope12 << "\n";

    double slopeperpbi12 = -1/slope12;

    double midpointx = (mathx1 + mathx2)/2;
    double midpointy = (mathy1 + mathy2)/2;



    //cout << "midpointx: " << midpointx;
   //cout << "midpointy: " << midpointy;
    double slope13 = double(mathy3-mathy1)/double(mathx3-mathx1);
    double slopeperpbi13 = -1/slope13;
    double midpointx2 = (mathx1 + mathx3)/2;
    double midpointy2 = (mathy1 + mathy3)/2;
    //cout <<"slope: " <<slope13 << "\n";

    center = lineLineIntersection(slopeperpbi12, (double)-1, -(midpointy- (midpointx*slopeperpbi12)),slopeperpbi13, (double)-1, -(midpointy2- (midpointx2*slopeperpbi13)));
    cout << "circumcenterxval: " << center[0] << "\n";
    cout << "circumcenteryval: " << center[1];
    return center;
}

double *lineLineIntersection(double a1, double b1, double c1, double a2, double b2, double c2) {
    double *center;
        cout << "a1: " << a1 << " b1: " << b1 << " c1: " << c1 <<"\n";
    cout << "a2: " << a2 << " b2: " << b2 << " c2: " << c2 <<"\n";
    double determinant = a1*b2 - a2*b1;
    if (determinant == 0)
    {

        cout << "lines are parrallel";
    }

    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        center[0] = x;
        center[1]= y;
        return center;
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

  double *circumcenter = findcircumcenter(2, -2, 1, 1, 3, -2);// x1,  x2,  x3, y1,  y2, y3 );
 // cout << "circumcenterxval: " << circumcenter[0];
 // cout << "circumcenterxval: " << circumcenter[1];
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



