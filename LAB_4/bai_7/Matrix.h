#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;
#include "Vector.h" 

class Matrix{
private:
    int iDong, iCot; 
    double** data;  // Cấp phát động cho mảng 2 chiều để lưu trữ giá trị của ma trận
public:
    Matrix();
    Matrix(const Matrix &a);
    Matrix& operator = (const Matrix &x);
    ~Matrix();

    friend istream& operator >> (istream& in, Matrix &x);
    friend ostream& operator << (ostream& out, const Matrix &x);
    friend Matrix operator + (Matrix a, Matrix b);
    friend Matrix operator - (Matrix a, Matrix b);
    friend Matrix operator * (Matrix a, Matrix b);  
    friend Vector operator * (Matrix a, Vector b); // a : m x n, b : n x 1 => kết quả là vector c : m x 1
};

#endif