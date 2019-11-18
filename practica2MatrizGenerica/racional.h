#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>

template <typename T>
//template <typename T, unsigned int N>
class racional {
    //Evita que sean enteros sin signo
    //static_assert(std::is_base_of< T, int>::value, "T must extend int");
    //Evita que no sean tipos enteros

    public:
        racional() : numerador{0},denominador{1}{}
        explicit racional(int,int);
        racional & operator+(const racional & m);
        racional & operator*(const racional & m);
        racional & operator/(const racional & m);
        racional & operator/(const int num);
        int numerador;
        int denominador;
    private:
        int gcd(int a, int b)
        {
            if (a == 0)
                return b;
            return gcd(b%a, a);
        }
        void reduceFraction(int &den3, int &num3)
        {
            // Finding gcd of both terms
            int common_factor = gcd(num3,den3);

            // Converting both terms into simpler
            // terms by dividing them by common factor
            den3 = den3/common_factor;
            num3 = num3/common_factor;
        }

};

template <typename T>
racional<T> & racional<T>::operator+(const racional<T> & r)
{
    // Finding gcd of den1 and den2
    int den3 = gcd(denominador,r.denominador);

    // Denominator of final fraction obtained
    // finding LCM of den1 and den2
    // LCM * GCD = a * b
    den3 = (denominador*r.denominador) / den3;

    // Changing the fractions to have same denominator
    // Numerator of the final fraction obtained
    int num3 = (numerador)*(den3/denominador) + (r.numerador)*(den3/r.denominador);

    // Calling function to convert final fraction
    // into it's simplest form
    reduceFraction(den3,num3);

    numerador = num3;
    denominador = den3;

    return *this;

}

template <typename T>
racional<T> & racional<T>::operator*(const racional<T> & r)
{
    int den3 = denominador * r.denominador;
    int num3 = numerador * r.numerador;

    reduceFraction(den3,num3);

    numerador = num3;
    denominador = den3;

    return *this;

}

template <typename T>
racional<T> & racional<T>::operator/(const racional<T> & r)
{
    //TODO

    return *this;

}

template <typename T>
racional<T> & racional<T>::operator/(const int num)
{
    denominador = denominador * num;
    return *this;

}

template <typename T>
std::ostream & operator<<(std::ostream & fs, const racional<T> & r);

template <typename T>
racional<T>::racional(int numeradorP, int denominadorP) :
        numerador{numeradorP},
        denominador{(denominadorP==0)?(1):denominadorP}

{
    //std::cout<< "CONSTRUCTOR POR DEFECTO RACIONAL" << "\n";
}

template <typename T>
std::ostream & operator<<(std::ostream & fs, const racional<T> & r) {
    fs << r.numerador << "/" << r.denominador;
    return fs;
}

#endif //RACIONAL_H