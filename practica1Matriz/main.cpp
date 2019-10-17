#include "matrix.h"
#include <iostream>
#include <random>
#include <chrono>
using namespace std;
int n = 100;
void evaluacion(){
    matrix a{n,n};
    matrix b{n,n};
    matrix c{n,n};

    double s = 0;

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> dis(10, 2.5);
    for (int i = 0; i < a.getSize(); ++i) {
        a.set( i , dis(gen) );
        b.set( i , dis(gen) );
        c.set( i , dis(gen) );
    }
    matrix d{n,n};
    auto start = chrono::high_resolution_clock::now();
    d = a + static_cast<matrix &&>(b * static_cast<matrix &&>(c));
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;

    cout << "Tiempo de cálculo de la matriz D = " << diff.count() << endl;

    for (int i = 0; i < d.getSize(); ++i) {
        s = s + d.get(i);
    }

    s = s/(d.getSize());

    cout << "\n" << "s = " << s << "\n";

}
int main() {
    evaluacion();
    return 0;
}


