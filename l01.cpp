//
// Created by Nithya Chintalapati on 9/9/20.
//

# include <iostream>
# include <fstream>


using namespace std;


typedef int matrix[800][800];

int main() {

    ofstream MyFile("first.ppm", ios_base::out | ios_base::binary);
    MyFile << "P3" << endl << 800u << ' ' << 800u << endl << "256" << endl;



    for (auto i = 0u; i < 800u; ++i)
    {
        for (auto j = 0u; j < 800u; ++j)
        {
            MyFile << 1 <<1 << 1;
        }

    }



    // 10 test cases


    MyFile.close();

    return 0;
/**

    constexpr auto dimx = 800, dimy = 800;

    using namespace std;
    ofstream ofs("first.ppm", ios_base::out | ios_base::binary);
    ofs << "P3" << endl << dimx << ' ' << dimy << endl << "256" << endl;

    for (auto j = 0u; j < dimy; ++j)
        for (auto i = 0u; i < dimx; ++i)
            ofs << 1 << 1<< 1;   // red, green, blue

    ofs.close();

    return EXIT_SUCCESS;
**/
}


