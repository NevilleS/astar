#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    string fileName, output, plot;

    if ( argc <= 1 ) {
        cout << "Usage: search fileName [output] [plot]\n";
        cout << "  fileName: data file to search\n";
        cout << "  output: output data file, default is output.txt\n";
        cout << "  plot: output graphical plot, default is plot.png\n";
    } else if ( argc == 2 ) {
        fileName = argv[1];
        output = "output.txt";
        plot = "plot.png";
    } else if ( argc == 3 ) {
        fileName = argv[1];
        output = argv[2];
        plot = "plot.png";
    } else if ( argc == 4 ) {
        fileName = argv[1];
        output = argv[2];
        plot = argv[3];
    }

    //TODO: actually perform the search
    return 0;
}
