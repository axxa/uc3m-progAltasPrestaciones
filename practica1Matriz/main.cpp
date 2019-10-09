#include "matrix.h"
#include <iostream>

using namespace std;

int main() {

    matrix m{4,4};

    m.set(0,0, 1);
    m.set(0,1, 2);
    m.set(1,0, 3);
    m.set(1,1, 4);
    //std::cout << "Hello, World!" << m.get(0,1)<< std::endl;
    //std::cout << "Hello, World!" << m.get(0,0)<< std::endl;

    //cout << "Ingrese la matriz\n";
    //cin >> m ;

    cout << "Mi matriz" << "\n" << m << std::endl;
    return 0;
}