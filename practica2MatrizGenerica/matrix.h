//
// Created by axxa on 8/10/19.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

template <typename T>
class matrix {
    public:

        //1. Constructor a partir de número de filas y columnas
        //2. Constructor por defecto. Se crea una matriz de cero filas y cero columnas que no
        //consume memoria dinámica
        matrix() : rows_{0},cols_{0}, buffer_{nullptr} {}
        explicit matrix(int i, int j);
        //-------------------------------------------------------
        //3. Debe soportar operaciones de copia y movimiento.
            //constructor copia
        matrix(const matrix & v);
            //asignacion copia
        matrix & operator=(const matrix & v);

            //contructor movimiento
        matrix(matrix && m) :
            buffer_{m.buffer_},
            rows_{m.getRows()},
            cols_{m.getCols()}
        {
            std::cout<< "CONSTRUCTOR DE MOVIMIENTO" << "\n";
            m.buffer_ = nullptr;
            m.rows_ = 0;
            m.cols_ = 0;
        }
            //asignacion movimiento
            matrix & operator=(const matrix && m);
        //-------------------------------------------------------
        //4. Destructor que debe liberar la memoria que pueda ser propiedad de la matriz.
        ~matrix() { delete []buffer_; }
        //-------------------------------------------------------
        //5. El operador paréntesis se sobrecargará con dos argumentos para acceder a una
        //posición de la matriz
        T operator()(int i, int j) const { return buffer_[i * cols_ + j]; }
        //-------------------------------------------------------
        //6. Los operadores + y * se sobrecargarán para implementar la suma y el producto de
        //matrices.
        matrix & operator+(const matrix & m);
        matrix & operator*(const matrix & multiplierM);
        //-------------------------------------------------------


        int getRows() const;
        int getCols() const;
        int getSize() const;

        T * getBuffer() const;
        T * setBuffer();
        T get(int i, int j) const { return buffer_[i * cols_ + j]; }
        T get(int pos) const { return buffer_[pos]; }
        void set(int i, int j, T x) { buffer_[i * cols_ + j] = x; }
        void set(int pos, T x) { buffer_[pos] = x; }

    private:
        int rows_;
        int cols_;
        T * buffer_;


};

template <typename T>
std::ostream & operator<<(std::ostream & fs, const matrix<T> & v);
template <typename T>
std::istream & operator>>(std::istream & fe, matrix<T> & v);



template <typename T>
matrix<T>::matrix(int i, int j) :
        rows_{(i>0)?(i):0},
        cols_{(j>0)?(j):0},
        buffer_{((i==0) && (j==0))?(nullptr):new T[i*j]{}}  // Inicia todos a 0.0
{
    std::cout<< "CONSTRUCTOR POR DEFECTO MATRIZ" << "\n";
}

template <typename T>
matrix<T>::matrix(const matrix<T> & v)
{
    std::cout<< "CONSTRUCTOR DE COPIA" << "\n";

    T * aux = new T[v.getSize()];
    std::copy(v.buffer_, v.buffer_+v.getSize(), aux);
    delete [] buffer_;
    rows_ = v.getRows();
    cols_ = v.getCols();
    buffer_ = aux;

}

template <typename T>
int matrix<T>::getRows() const {
    return rows_;
}

template <typename T>
int matrix<T>::getCols() const {
    return cols_;
}

template <typename T>
int matrix<T>::getSize() const {
    return rows_*cols_;
}

template <typename T>
T * matrix<T>::getBuffer() const {
    return buffer_;
}

template <typename T>
matrix<T> & matrix<T>::operator=(const matrix<T> & v)
{
    std::cout<< "OPERADOR DE COPIA" << "\n";
    T * aux = new T[v.getSize()];
    std::copy(v.buffer_, v.buffer_+v.getSize(), aux);
    delete [] buffer_;
    rows_ = v.getRows();
    cols_ = v.getCols();
    buffer_ = aux;

    return *this;
}

template <typename T>
matrix<T> & matrix<T>::operator=(const matrix<T> && m)
{
    std::cout<< "OPERADOR DE MOVIMIENTO" << "\n";
    if (this != &m)
    {
        delete [] buffer_;
        rows_ = m.rows_;
        cols_ = m.cols_;
        buffer_ = m.buffer_;

    }

    return *this;
}

template <typename T>
matrix<T> & matrix<T>::operator+(const matrix<T> & m)
{
    if(rows_ == m.getRows() && cols_ == m.getCols())
        for(int i = 0 ; i < m.getSize() ; i++){
            this->buffer_[i] = this->buffer_[i] + m.getBuffer()[i];
        }
    return *this;

}

template <typename T>
matrix<T> & matrix<T>::operator*(const matrix<T> & m)
{
    if(cols_ == m.getRows()) {
        matrix<T> aux{rows_,m.getCols()};
        int z = 0;
        int zIni = 0;
        int k=0;

        for (int i = 0; i < getSize(); i++) {
            zIni = k * aux.cols_;
            z = zIni;

            if((i-1) % aux.cols_ == 0){
                z = zIni;
                i = z;
            }

            for (int j = 0; j < m.getSize(); j++) {
                if(j==0)k++;
                aux.set(z, aux.get(z) + get(i) * m.get(j));
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

template <typename T>
std::ostream & operator<<(std::ostream & fs, const matrix<T> & m) {
    for (int i=0; i<m.getRows(); ++i) {
        fs << "\n" ;
        for (int j=0; j<m.getCols(); ++j) {
            fs << m.get(i, j) << " ";
        }
    }
    return fs;
}

template <typename T>
std::istream & operator>>(std::istream & fe, matrix<T> & m) {
    int i=0;
    int j=0;
    T x;
    while ((i+j<m.getSize() ) && (fe >> x)) {
        if(j >= m.getCols()){
            i++;
        }
        m.set(i,j++, x);
    }
    return fe;
}

#endif //MATRIX_H
