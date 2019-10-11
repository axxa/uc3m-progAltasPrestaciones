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

matrix & matrix::operator=(const matrix & m)
{
    double * aux = new double[m.getSize()];
    std::copy(m.buffer_, m.buffer_+m.getSize(), aux);
    delete [] buffer_;

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
    int z = 0;
    if(cols_ == m.getRows()) {
        matrix aux{rows_,m.getCols()}; //tamanio de la nueva matriz
        for (int i = 0; i < 1/*getSize()*/; i++) {
            //z= 0;
            for (int j = 0; j < m.getSize(); j++) {
                if(static_cast<int>(j / aux.getCols()) > 1){

                }
                if(z == 3)
                    z = 0;

                //std::cout << "aux.set(" << z << ", aux.get(j) =" << aux.get(j) <<"+ " << get(i) <<"*" << m.get(j) <<"\n";
                std::cout << "\naux.get(" << z <<")=" << aux.get(z) << "\n";
                std::cout << get(i) << "*" << m.get(j) << "\n" ;
                aux.set(z, aux.get(z) + get(i) * m.get(j));
                std::cout << "aux.get(" << z <<")=" << aux.get(z) << "\n";
                z++;
            }
            //std::cout << "asi va \n" << aux <<"\n";

        }
        return aux;
    }


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
