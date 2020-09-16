//
// Created by Nithya Chintalapati on 9/9/20.
//

# include <iostream>
# include <fstream>

using namespace std;




int main() {

    constexpr auto dimx = 800u, dimy = 800u;

    using namespace std;
    ofstream ofs("other.ppm" );
    ofs << "P6" << endl << dimx << ' ' << dimy << endl << "255" << endl;
    auto x1 = 40;
    auto y1 = 0;

    auto x2 = 800;
    auto y2 = 800;

    auto dx = x2-x1;
    auto dy = y2-y1;

    auto j = y1;
    auto e = dy-dx;

    int matrix[800][800];
    for (auto n = 0u; n < dimy; ++n) {
        for (auto m = 0u; m < dimx; ++m) {
            matrix[n][m] = 255;
        }
    }

    for(int z = x1; z< x2;z++)
    {
        matrix[j][z] = 1; // switch these to matrix[z][j]?
        if(e >= 0)
        {
             j += 1;
             e -= dx;
        }
        e +=dy;
        z +=1;
    }



    for (auto a = 0u; a < dimy; ++a) {
        for (auto b = 0u; b < dimx; ++b) {

            if(matrix[a][b] == 255)
                ofs << (char)(255) <<(char) (255) << (char) (255);

            else if(matrix[a][b] ==1)
                ofs << (char)(1) <<(char) (1) << (char) (1);

        }

    }
    ofs.close();

    return EXIT_SUCCESS;



}


