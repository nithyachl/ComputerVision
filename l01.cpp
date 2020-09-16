//
// Created by Nithya Chintalapati on 9/9/20.
//

# include <iostream>
# include <fstream>
#include <cstdio>

using namespace std;




int main() {

    constexpr auto dimx = 800u, dimy = 800u;

    using namespace std;
    ofstream ofs("one.ppm", ios_base::out| ios_base::binary );
    ofs << "P6" << endl << dimx << ' ' << dimy << endl << "255" << endl;

    for (auto j = 0u; j < dimy; ++j) {
        for (auto i = 0u; i < dimx; ++i) {
            ofs << (char)(255) <<(char) (255) << (char) (255) ;

        }

    }
    ofs.close();

    return EXIT_SUCCESS;



}


