#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Matrix ;

class Vector {
private :
    int size ; 
    double* data; 
public :
    Vector() ;
    Vector(const Vector &a) ;
    Vector& operator = (const Vector &x) ;
    ~Vector() ;
    friend Vector operator * (Matrix a, Vector b);
    friend istream& operator >> (istream& in, Vector &x);
    friend ostream& operator << (ostream& out, const Vector &x);
} ;
#endif