#include "matrix.h"
#include "racional.h"
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

int n = 10;

void evaluacionRacional(){

    matrix<racional<int>> a{n,n};
    matrix<racional<int>> b{n,n};
    matrix<racional<int>> c{n,n};
    matrix<racional<int>> d{n,n};
    racional<int> s{0,0};

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> dis(2.5, 5);

    for (int i = 0; i < a.getSize(); ++i) {
        racional<int> r{static_cast<int>(dis(gen)),static_cast<int>(dis(gen))};
        a.set( i , r );
        b.set( i , r );
        c.set( i , r );
    }

    auto start = chrono::high_resolution_clock::now();
    d = a + b;
    d = d * c;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;

    cout << "Tiempo de cálculo de la matriz D = " << diff.count() << endl;
    s = d.diagonalSum();

    cout << "\n" << "s = " << s << "\n";

}

void evaluacion(){

    matrix<long double> a{n,n};
    matrix<long double> b{n,n};
    matrix<long double> c{n,n};
    matrix<long double> d{n,n};
    long double s = 0;

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> dis(10, 2.5);
    for (int i = 0; i < a.getSize(); ++i) {
        a.set( i , dis(gen) );
        b.set( i , dis(gen) );
        c.set( i , dis(gen) );
    }

    auto start = chrono::high_resolution_clock::now();
    d = a + b * c;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;

    cout << "Tiempo de cálculo de la matriz D = " << diff.count() << endl;

    s = d.diagonalSum();

    cout << "\n" << "s = " << s << "\n";

}

int main() {
    //evaluacion();
    evaluacionRacional();

    return 0;
}


