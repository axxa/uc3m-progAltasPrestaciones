#include "matrix.h"
#include <iostream>

using namespace std;

void pruebaSumaMatriz(){
    matrix m{4,4};
    matrix m2{4,4};
    m.set(0,0, 1);
    m.set(0,1, 2);
    m.set(1,0, 3);
    m.set(1,1, 4);
    m.set(2,2, 1);

    m2.set(0,0, 1);
    m2.set(0,1, 2);
    m2.set(1,0, 3);
    m2.set(1,1, 4);
    m2.set(0,3, 2);
    //std::cout << "Hello, World!" << m.get(0,1)<< std::endl;
    //std::cout << "Hello, World!" << m.get(0,0)<< std::endl;

    //cout << "Ingrese la matriz\n";
    //cin >> m ;
    //m = m + static_cast<matrix &&>(m2);
    cout << "Suma de matriz" << "\n" << m  << "\n   +" << m2 << "\n   =";
    cout << (m + static_cast<matrix &&>(m2)) << std::endl;

}

void pruebaMultiplicacionMatrix(){
    matrix m{2,3};
    matrix m2{3,3};
    matrix m3;
    m.set(0,0, 2);m.set(0,1, 3);m.set(0,2, 1);
    m.set(1,0, 2);m.set(1,1, -7);m.set(1,2, 4);

    m2.set(0,0, 3);m2.set(0,1, 4);m2.set(0,2, 5);
    m2.set(1,0, 1);m2.set(1,1, 1);m2.set(1,2, 4);
    m2.set(2,0, 2);m2.set(2,1, 1);m2.set(2,2, 4);

    cout << "Multiplicacion de matriz" << "\n" << m  << "\n   *" << m2 << "\n   =";

    m3 = m * static_cast<matrix &&>(m2);

    //cout << (m * static_cast<matrix &&>(m2)) << std::endl;
}

//5. Sobrecarga con parentesis
void pruebaParentesis(){
    matrix m{2,3};
    m.set(0,0, 2);m.set(0,1, 3);m.set(0,2, 1);
    m.set(1,0, 2);m.set(1,1, -7);m.set(1,2, 4);
    cout << "m(0,1) : " <<m(0,1) ;
}

int main() {

    //pruebaSumaMatriz();
    //pruebaMultiplicacionMatrix();
    pruebaParentesis();
    return 0;
}

