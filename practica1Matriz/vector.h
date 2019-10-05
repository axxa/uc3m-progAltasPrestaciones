#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class vector {
    public:
        vector(int n);
        int tamanyo() const { return tam; }
        double obten(int i) const { return vec[i]; }
        void pon(int i, double x) { vec[i] = x; }
    private:
        int tam;
        double * vec;
};

    std::ostream & operator<<(std::ostream & fs, const vector & v);
    std::istream & operator>>(std::istream & fe, vector & v);
#endif
