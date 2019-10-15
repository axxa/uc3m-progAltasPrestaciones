#include "matrix.h"
#include <iostream>

using namespace std;

void pruebaAsignacionCopia(){
    matrix m;
    matrix m2{4,4};
    matrix m3{4,4};
    m2.set(0,0, 1);
    m2.set(0,1, 2);
    m2.set(0,2, 3);
    m2.set(0,3, 4);
    m2.set(1,0, 5);
    m2.set(1,1, 6);
    m2.set(1,2, 7);
    m2.set(1,3, 8);
    m2.set(2,0, 9);
    m2.set(2,1, 10);
    m2.set(2,2, 11);
    m2.set(2,3, 12);
    m2.set(3,0, 13);
    m2.set(3,1, 14);
    m2.set(3,2, 15);
    m2.set(3,3, 16);

    cout << "Matriz m nula inicialmente :" << m << "\n";
    m = m2;
    cout << "Matriz m2 copiada en m :" << m << "\n";

    cout << "Matriz m3 inicializada con 0s :" << m3 << "\n";
    m3 = m2;
    cout << "Matriz m2 copiada en m3 :" << m3 << "\n";

}
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

    cout << "Multiplicacion de matriz" << "\n" << m  << "\n   *" << m2 << "\n   =  \n";

    m3 = m * static_cast<matrix &&>(m2);

    cout << "m3\n"<< m3 << "\n" <<std::endl;
}

void pruebaMultiplicacionMatrix2(){
    matrix m{3,3};
    matrix m2{3,3};
    matrix m3;
    m.set(0,0, 2);m.set(0,1, 3);m.set(0,2, 1);
    m.set(1,0, 2);m.set(1,1, -7);m.set(1,2, 4);
    m.set(2,0, 2);m.set(2,1, 1);m.set(2,2, 4);

    m2.set(0,0, 3);m2.set(0,1, 4);m2.set(0,2, 5);
    m2.set(1,0, 1);m2.set(1,1, 1);m2.set(1,2, 4);
    m2.set(2,0, 2);m2.set(2,1, 1);m2.set(2,2, 4);

    cout << "Multiplicacion de matriz" << "\n" << m  << "\n   *" << m2 << "\n   =  \n";

    m3 = m * static_cast<matrix &&>(m2);

    cout << "m3\n"<< m3 << "\n" <<std::endl;
}

void pruebaMultiplicacionMatrix3(){
    matrix m{3,3};
    matrix m2{3,1};
    matrix m3;
    m.set(0,0, 5);m.set(0,1, 8);m.set(0,2, -4);
    m.set(1,0, 6);m.set(1,1, 9);m.set(1,2, -5);
    m.set(2,0, 4);m.set(2,1, 7);m.set(2,2, -2);

    m2.set(0,0, 2);m2.set(0,1, -3);m2.set(0,2, 1);


    cout << "Multiplicacion de matriz" << "\n" << m  << "\n   *" << m2 << "\n   =  \n";

    m3 = m * static_cast<matrix &&>(m2);

    cout << "m3\n"<< m3 << "\n" <<std::endl;
}

//5. Sobrecarga con parentesis
void pruebaParentesis(){

    matrix m{2,3};
    matrix m2{3,3};

    m.set(0,0, 2);m.set(0,1, 3);m.set(0,2, 1);
    m.set(1,0, 2);m.set(1,1, -7);m.set(1,2, 4);

    m2.set(0,0, 3);m2.set(0,1, 4);m2.set(0,2, 5);
    m2.set(1,0, 1);m2.set(1,1, 1);m2.set(1,2, 4);
    m2.set(2,0, 2);m2.set(2,1, 1);m2.set(2,2, 4);

    cout << "m (0,0)== 2 : " <<(m(0,0) == 2 ) << "\n";
    cout << "m2(0,0)== 3 : " <<(m2(0,0) == 3 )<< "\n";
    cout << "m (0,1)== 3 : " <<(m(0,1) == 3 )<< "\n";
    cout << "m2(1,0)== 1 : " <<(m2(1,0) == 1 )<< "\n";
    cout << "m (0,2)== 1 : " <<(m(0,2) == 1 )<< "\n";
    cout << "m2(2,0)== 2 : " <<(m2(2,0) == 2 )<< "\n";

    cout << "m2(0,1)== 4 : " <<(m2(0,1) == 4 )<< "\n";
    cout << "m2(1,1)== 1 : " <<(m2(1,1) == 1 )<< "\n";
    cout << "m2(2,1)== 4 : " <<(m2(2,1) == 1 )<< "\n";

    cout << "m2(0,2)== 5 : " <<(m2(0,2) == 5 )<< "\n";
    cout << "m2(1,2)== 4 : " <<(m2(1,2) == 4 )<< "\n";
    cout << "m2(2,2)== 4 : " <<(m2(2,2) == 4 )<< "\n";
}

int main() {

    //pruebaSumaMatriz();
    pruebaMultiplicacionMatrix3();
    //pruebaParentesis();
    //pruebaAsignacionCopia();
    return 0;
}

