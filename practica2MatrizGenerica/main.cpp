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
    std::normal_distribution<> dis(10, 2.5);

    for (int i = 0; i < a.getSize(); ++i) {

        racional<int> r{static_cast<int>(dis(gen)),static_cast<int>(dis(gen))};
        //a.set( i , dis(gen) );
        //b.set( i , dis(gen) );
        //c.set( i , dis(gen) );

        a.set( i , r );
        b.set( i , r );
        c.set( i , r );
    }

    auto start = chrono::high_resolution_clock::now();
    d = a + b * c;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;

    cout << "Tiempo de cálculo de la matriz D = " << diff.count() << endl;

    for (int i = 0; i < d.getSize(); ++i) {
        s = s + d.get(i);
    }

    s = s/(d.getSize());

    cout << "\n" << "s = " << s << "\n";

}

void evaluacion(){

    matrix<float> a{n,n};
    matrix<float> b{n,n};
    matrix<float> c{n,n};
    matrix<float> d{n,n};
    float s = 0;

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

    for (int i = 0; i < d.getSize(); ++i) {
        s = s + d.get(i);
    }

    s = s/(d.getSize());

    cout << "\n" << "s = " << s << "\n";

}

void testracional(){
    racional<int> r{1,3};
    racional<int> r2{1,6};

    cout << r+ r2;

    racional<int> r3{1,3};
    racional<int> r4{1,5};

    cout << r3+ r4;

    racional<int> r5{2,5};
    racional<int> r6{3,4};

    cout << r5 *  r6;

}
int main() {
    //evaluacion();
    evaluacionRacional();
    //testracional();
    return 0;
}


