//
// Created by Nithya Chintalapati on 9/9/20.
//

# include <iostream>
# include <fstream>
#include <cmath>

using namespace std;

int matrix[800][800];
int center [2];
int centerin[2];
int centroid[2];
int ninept[2];


double getMidpoint(int mathx1, int mathx2);

double getSlope(int b1, int b2, int b3, int b4);


void findincenter(int x1, int x2, int x3, int y1, int y2, int y3);

void findcentroid(int x1, int x2, int x3, int y1, int y2, int y3);

void findcentroid(int x1, int x2, int x3, int y1, int y2, int y3) {

    int mathy1 = 799-x1;
    int mathy2 = 799-x2;
    int mathy3 = 799-x3;
    int mathx1 = y1;
    int mathx2 = y2;
    int mathx3 = y3;

    double x = (mathx1+mathx2+mathx3)/3;
    double y = (mathy1+mathy2+mathy3)/3;

    int finalx = (int)(799-y);
    int finaly = (int)(x);

    centroid[0] = (int)finalx;
    centroid[1] = (int)finaly;
}

void findincenter(int x1, int x2, int x3, int y1, int y2, int y3, double a, double b, double c) {
    int mathy1 = 799-x1;
    int mathy2 = 799-x2;
    int mathy3 = 799-x3;
    int mathx1 = y1;
    int mathx2 = y2;
    int mathx3 = y3;

    double x = (a * mathx3 + b * mathx1 + c * mathx2) / (a + b + c);
    double y = (a * mathy3 + b * mathy1 + c * mathy2) / (a + b + c);



    int finalx = (int)(799-y);
    int finaly = (int)(x);

    cout << "incenterxval: " << finalx << "\n";
    cout << "incenteryval: " << finaly<<"\n";

    centerin[0] = (int)finalx;
    centerin[1] = (int)finaly;



}


void bresenham(int x1, int y1, int x2, int y2)//int x0, int y0, int x1, int y1)
{

    int dx = x2 - x1 ;
    int dy = y2 - y1 ;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
    if (dy<0){
        dy1 = -1 ;
    }
    else if (dy>0){
        dy1 = 1 ;
    }
    if (dx<0) {
        dx1 = -1;
    }
    else if (dx>0){
        dx1 = 1 ;}
    if (dy<0){
        dy2 = -1;
    }
    else if (dy>0){
        dy2 = 1 ;
    }
    int longest = abs(dy) ;
    int shortest = abs(dx) ;
    if (!(longest>shortest)) {
        longest = abs(dx) ;
        shortest = abs(dy) ;
        if (dx<0)
        {
            dx2 = -1 ;
        }

        else if (dx>0) {
            dx2 = 1;
        }
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

    cout << "markcenterx: "<< markcenterx << "\n";
    cout << "markcentery: "<< markcentery << "\n";

    center[0] = markcenterx;
    center[1] = markcentery;

    matrix[markcentery][markcenterx] = 0;


    cout << "circumcenterxval: " << markcenterx << "\n";
    cout << "circumcenteryval: " << markcentery << "\n";


}

double getSlope(int b1, int b2, int b3, int b4) {
    return (double)((double)(b1-b2)/(double)(b3-b4));
}

double getMidpoint(int a1, int a2) {
    return (double)((a1+a2)/((double)2));
}

void circle(double r, double xcenter, double ycenter) {

    int x = 0, y, xmax, y2, y2_new, ty;
    xmax = (int) (r * 0.70710678); // maximum x at radius/sqrt(2)

    y = r;

    y2 = y * y;
    ty = (2 * y) - 1;
    y2_new = y2;



    for (x = 0; x <= xmax ; x++) {



        if ((y2 - y2_new) >= ty) {
            y2 -= ty;
            y -= 1;
            ty -= 2;
        }


        if(xcenter + x < 800 && ycenter + y < 800 && xcenter + x > 0 && ycenter + y > 0 )
            matrix[(int) (ycenter + y)][(int) (xcenter + x)] = 0;

        if(xcenter + x < 800 && ycenter - y < 800 && xcenter + x > 0 && ycenter - y > 0  )
            matrix[(int) (ycenter - y)][(int) (xcenter + x)] = 0;

        if(xcenter - x < 800 && ycenter + y < 800 && xcenter - x > 0 && ycenter + y > 0 )
            matrix[(int) (ycenter + y)][(int) (xcenter - x)] = 0;

        if(xcenter - x < 800 && ycenter - y < 800 && xcenter - x > 0 && ycenter - y > 0 )
            matrix[(int) (ycenter - y)][(int) (xcenter - x)] = 0;

         if(xcenter + y < 800 && ycenter + x < 800 && xcenter + y > 0 && ycenter + x > 0)
             matrix[(int) (ycenter + x)][(int) (xcenter + y)] = 0;

         if(xcenter + y < 800 && ycenter - x < 800 && xcenter + y > 0 && ycenter - x > 0)
            matrix[(int) (ycenter - x)][(int) (xcenter + y)] = 0;

        if(xcenter - y < 800 && ycenter + x < 800 && xcenter - y > 0 && ycenter + x > 0  )
            matrix[(int) (ycenter + x)][(int) (xcenter - y)] = 0;

        if(xcenter - y < 800 && ycenter - x < 800 && xcenter - y > 0 && ycenter - x > 0 )
            matrix[(int) (ycenter - x)][(int) (xcenter - y)] = 0;


        y2_new -= (2 * x) - 3;
    }

}


void extendLine(int i, int i1, int i2, int i3) {

    double a = distance(i, i1, i2, i3);

    int xc;
    int yc;

    int length = 50;


    while((i + (length * (i2 - i) / a)) < 800 && (i1 + (length * (i3 - i1) / a)) < 800 && i + (length * (i2 - i) / a) > 0 && (i1 + (length * (i3 - i1) / a)) > 0)
    {
        length += 1;
    }


    xc = i + (length * (i2 - i) / a);
    yc = i1 + (length * (i3 - i1) / a);

    if(length > 800)
    {
        length = 800;
    }

    cout << "length" << length << "\n";
    cout << "xc: " << xc;
    cout << "yc: " << yc;

    int xd;
    int yd;

    int length2 = 10;


    while(( i2 + (length2 * (i - i2) / a) < 800) && (i3 + (length2 * (i1 - i3) / a) < 800) && ( i2 + (length2 * (i - i2) / a) > 0) && (i3 + (length2 * (i1 - i3) / a) > 0))
    {
        length2 += 10;
    }

    if(length2 > 800)
    {
    length2 = 800;
    }

    xd = i2 + (length2 * (i - i2) / a);
    yd = i3 + (length2 * (i1 - i3) / a);


    cout<< "length2: " << length2 << "\n";
    cout << "xd: " << xd;
    cout << "yd: " << yd;


    //bresenham(xd,yd,xc,yc);




    bresenham(xc,yc,xd,yd);

}

void find9point(int x1, int x2, int x3, int y1, int y2, int y3) {

    int mathy1 = 799-x1;
    int mathy2 = 799-x2;
    int mathy3 = 799-x3;
    int mathx1 = y1;
    int mathx2 = y2;
    int mathx3 = y3;

    double point1x = (double)getMidpoint(mathx1,mathx2);
    double point1y = (double)getMidpoint(mathy1,mathy2);
    double point2x = (double)getMidpoint(mathx1,mathx3);
    double point2y = (double)getMidpoint(mathy1,mathy3);
    double point3x = (double)getMidpoint(mathx2,mathx3);
    double point3y = (double)getMidpoint(mathy2,mathy3);

    double midpoint12x = (double)getMidpoint(point1x,point2x);
    double midpoint12y = (double)getMidpoint(point1y,point2y);
    double midpoint13x = (double)getMidpoint(point1x,point3x);
    double midpoint13y = (double)getMidpoint(point1y,point3y);

    double slope12 = (double)-1 / (double)getSlope(point2y, point1y, point2x, point1x);
    double slope13 = (double)-1 / (double)getSlope(point3y, point1y, point3x, point1x);

    double b12 = (double)midpoint12y - (double)slope12 * (double)midpoint12x;

    double b13 = (double)midpoint13y - (double)slope13 * (double)midpoint13x;


    double xfinal =  (b12 - b13) / (slope13 - slope12);
    double yfinal =  slope12 * xfinal + b12;


    int markcenterx = (int)(799-yfinal);
    int markcentery = (int)(xfinal);


    ninept[0] = markcenterx;
    ninept[1] = markcentery;

}

int main() {
    int dimx = 800;
    int dimy = 800;
    using namespace std;
    ofstream myfile;
    myfile.open ("triangle.ppm");
    myfile << "P3" << endl << dimx << ' ' << dimy << endl << "1" << endl;

    srand( time(NULL) );

//    int x1 = (int)(rand()% 800);
//    int y1 = (int)(rand()% 800);
//
//    int x2 = (int)(rand()% 800);
//    int y2 = (int)(rand()% 800);
//
//    int x3 = (int)(rand()% 800);
//    int y3 = (int)(rand()% 800);


    double x1 = rand()/(double)RAND_MAX;
    double y1 = rand()/(double)RAND_MAX;

    double x2 = rand()/(double)RAND_MAX;
    double y2 = rand()/(double)RAND_MAX;

    double x3 = rand()/(double)RAND_MAX;
    double y3 = rand()/(double)RAND_MAX;

//    int x1 = 66;
//    int y1 = 54;
//
//    int x2 = 68;
//    int y2 = 215;
//
//    int x3 = 148;
//    int y3 = 350;


    if (x2> x3)
    {
        double temp = x2;
        x2 = x3;
        x3 = temp;

    }
    if (x1> x2)
    {
        double temp = x1;
        x1 = x2;
        x2 = temp;

    }
    if (x2> x3)
    {
        double temp = x2;
        x2 = x3;
        x3 = temp;

    }

    if (y2> y3)
    {
        double temp = y2;
        y2 = y3;
        y3 = temp;

    }
    if (y1> y2)
    {
        double temp = y1;
        y1 = y2;
        y2 = temp;

    }
    if (y2> y3)
    {
        double temp = y2;
        y2 = y3;
        y3 = temp;

    }



    cout << "x1: " << x1 << " y1: " << y1 << "\n";
    cout << "x2: " << x2 << " y2: " << y2 << "\n";
    cout << "x3: " << x3 << " y3: " << y3 << "\n";




    for (int n = 0; n < dimy; ++n) {
        for (int m = 0; m < dimx; ++m) {
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
 findincenter(x1,  x2,  x3, y1,  y2, y3,a,b,c);
 circle(rincircle, centerin[0], centerin[1]);
 findcentroid( x1,  x2,  x3, y1,  y2, y3 );
 //bresenham(centroid[0],centroid[1], center[0],center[1]);
 extendLine(centroid[0],centroid[1], center[0],center[1]);
 find9point(x1,  x2,  x3, y1,  y2, y3);
 circle(rcircumcircle/2, ninept[0], ninept[1]);



    for (int n = 0; n < dimy; ++n) {
        for (int m = 0; m < dimx; ++m) {

                myfile<< matrix[n][m] << " "<< matrix[n][m] << " " << matrix[n][m] << "     ";          //std::to_string(matrix[n][m]) << " ";

        }
        myfile << endl;
    }


myfile.close();


    return 0;
}








