//
// Created by axxa on 8/10/19.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

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
        double operator()(int i, int j) const { return buffer_[i * cols_ + j]; }
        //-------------------------------------------------------
        //6. Los operadores + y * se sobrecargarán para implementar la suma y el producto de
        //matrices.
        matrix & operator+(const matrix & m);
        matrix & operator*(const matrix & multiplierM);
        //-------------------------------------------------------


        int getRows() const;
        int getCols() const;
        int getSize() const;

        double * getBuffer() const;
        double * setBuffer();
        double get(int i, int j) const { return buffer_[i * cols_ + j]; }
        double get(int pos) const { return buffer_[pos]; }
        void set(int i, int j, double x) { buffer_[i * cols_ + j] = x; }
        void set(int pos, double x) { buffer_[pos] = x; }

    private:
        int rows_;
        int cols_;
        double * buffer_;


};

std::ostream & operator<<(std::ostream & fs, const matrix & v);
std::istream & operator>>(std::istream & fe, matrix & v);

#endif //MATRIX_H
