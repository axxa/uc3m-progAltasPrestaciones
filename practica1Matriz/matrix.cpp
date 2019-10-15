//
// Created by axxa on 8/10/19.
//

#include "matrix.h"
#include <algorithm> // std::copy
#include <iostream>

matrix::matrix(int i, int j) :
        rows_{(i>0)?(i):0},
        cols_{(j>0)?(j):0},
        buffer_{((i==0) && (j==0))?(nullptr):new double[i*j]{}} // Inicia todos a 0.0
{
}

matrix & matrix::operator=(matrix && m) {
    std::swap(rows_, m.rows_);
    std::swap(buffer_, m.buffer_);
    return *this;
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


matrix & matrix::operator=(const matrix & v)
{
    double * aux = new double[v.getSize()];
    std::copy(v.buffer_, v.buffer_+v.getSize(), aux);
    delete [] buffer_;
    rows_ = v.getRows();
    cols_ = v.getCols();
    buffer_ = aux;

    return *this;
}

matrix & matrix::operator+(matrix && m)
{
    if(rows_ == m.getRows() && cols_ == m.getCols())
        for(int i = 0 ; i < m.getSize() ; i++){
            this->buffer_[i] = this->buffer_[i] + m.getBuffer()[i];
        }
    return *this;

}

matrix & matrix::operator*(matrix && m)
{

    if(cols_ == m.getRows()) {
        matrix aux{rows_,m.getCols()}; //tamanio de la nueva matriz :2x3 * 3X3 = 2X3
        int z = 0;
        int zIni = 0;
        int k=0;

        for (int i = 0; i < getSize(); i++) {
            //k = i / aux.cols_ ;
            k = i / aux.cols_ ;
            zIni = k * aux.cols_;
            z = zIni;

            if((i-1) % aux.cols_ == 0){
                z = zIni;
                i = z;
            }

            for (int j = 0; j < m.getSize(); j++) {
                std::cout << "\naux.get(" << z <<")=" << aux.get(z) << "\n";
                std::cout << "get(" <<i<< ")" << "*" << "m.get("<<j<<")" << "=" << get(i) << "*" << m.get(j) <<"\n" ;
                aux.set(z, aux.get(z) + get(i) * m.get(j));
                std::cout << "aux.get(" << z <<")=" << aux.get(z) << "\n";
                z++;

                if((j+1) % aux.cols_ == 0 ){
                    i++;
                    z = zIni;
                }
            }
        }
        *this = aux;
    }

    return *this;

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
