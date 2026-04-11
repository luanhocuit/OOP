#include <bits/stdc++.h>
using namespace std;

#include "DaThuc.h"

int main() {
    cDaThuc A, B;

    cout << "NHAP DA THUC A : \n"; cin >> A ;
    cout << "NHAP DA THUC B : \n"; cin >> B ;

    cout << "A(x) = " << A << endl;
    cout << "B(x) = " << B << endl;

    // Cộng - Trừ
    cDaThuc tong = A + B, hieu = A - B;
    cout << "A + B = " << tong << endl;
    cout << "A - B = " << hieu << endl;

    // Tính giá trị
    cout << "Nhap gia tri x = " ;
    int x ; cin >> x;

    cout << "A(" << x << ") = " << A.tinhGiaTri(x) << endl;
    cout << "B(" << x << ") = " << B.tinhGiaTri(x) << endl;

    return 0;
}