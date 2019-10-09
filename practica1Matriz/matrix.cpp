//
// Created by axxa on 8/10/19.
//

#include "matrix.h"
#include <algorithm> // std::copy

matrix::matrix(int i, int j) :
        rows_{(i>0)?(i):0},
        cols_{(j>0)?(j):0},
        buffer_{((i==0) && (j==0))?(nullptr):new double[i*j]{}} // Inicia todos a 0.0
{
}

int matrix::getRows() const {
    return rows_;
}

int matrix::getCols() const {
    return cols_;
}

int matrix::getSize() const {
    return rows_*cols_;
}

double * matrix::getBuffer() const {
    return buffer_;
}

std::ostream & operator<<(std::ostream & fs, const matrix & m) {
    for (int i=0; i<m.getRows(); ++i) {
        fs << "\n" ;
        for (int j=0; j<m.getCols(); ++j) {
            fs << m.get(i, j) << " ";
        }
    }
    return fs;
}

std::istream & operator>>(std::istream & fe, matrix & m) {
    int i=0;
    int j=0;
    double x;
    while ((i+j<m.getSize() ) && (fe >> x)) {
        if(!j < m.getCols()){
            i = i++;
        }
        m.set(i,j++, x);
    }
    return fe;
}
