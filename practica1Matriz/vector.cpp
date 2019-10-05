#include "vector.h"

vector::vector(int n) :
    tam{n},
    vec{new double[n]{}} // Inicia todos a 0.0
    {
    }

std::ostream & operator<<(std::ostream & fs, const vector & v) {
    for (int i=0; i<v.tamanyo(); ++i) {
        fs << v.obten(i) << "";
    }
    return fs;
}

std::istream & operator>>(std::istream & fe, vector & v) {
    int i=0;
    double x;
    while ((i<v.tamanyo()) && (fe >> x)) {
        v.pon(i++, x);
    }
    return fe;
}
