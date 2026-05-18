#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix a, b, resMatrix;
    Vector V, resVector;

    cout << "Nhap ma tran a : \n" ; cin >> a;
    cout << "Nhap ma tran b : \n" ; cin >> b;

    cout << "\nMa tran a ban vua nhap :\n" << a;
    cout << "Ma tran b ban vua nhap :\n" << b;

    resMatrix = a + b;
    cout << "Ket qua a + b :\n" << resMatrix;
    resMatrix = a - b;
    cout << "Ket qua a - b :\n" << resMatrix;

    resMatrix = a * b;
    cout << "Ket qua a * b :\n" << resMatrix ;

    cout << "\nNhap Vector V de nhan voi Ma tran a :\n" ; cin >> V; 
    cout << "Vector V ban vua nhap: " << V;

    resVector = a * V;
    cout << "Ket qua a * V : " << resVector;

    return 0;
}