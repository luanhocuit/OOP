#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std ;

class Vector {
private :
    int sochieu ;
    double* heso ;
public :
    Vector() ;
    Vector(const Vector &x) ; // Hàm copy constructor
    ~Vector() ;
    Vector& operator = (const Vector &x) ; // Hàm gán (trả về tham chiếu vì đang cấp phát động)
    friend istream& operator >> (istream& in, Vector &x) ;
    friend ostream& operator << (ostream& out, const Vector &x) ;
    friend Vector operator + (Vector a, Vector b) ;
    friend Vector operator - (Vector a, Vector b) ;
    friend Vector operator * (Vector a, double x) ;
    friend double operator * (Vector a, Vector b) ;
} ;

#endif