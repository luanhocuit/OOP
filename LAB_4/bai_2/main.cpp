#include <iostream>
using namespace std;

#include "PhanSo.h"

int main() {
    PS a, b;
    cout << "Nhap phan so thu nhat : \n" ; cin >> a;
    cout << "Nhap phan so thu hai :\n"; cin >> b;

    cout << "Hai phan so vua nhap :\n";
    cout << "a = " << a ;
    cout << "b = " << b ;

    // Tổng 
    PS tong = a + b; cout << "Tong : " << tong ;
    // Hiệu
    PS hieu = a - b; cout << "Hieu : " << hieu ;
    // Tích
    PS tich = a * b; cout << "Tich : " << tich ;
    // Thương
    PS thuong = a / b; cout << "Thuong : " << thuong ;

    // So sánh 2 phân số
    cout << "So sanh 2 phan so : " ;
    if(a == b) cout << "a bang b\n" ;
    else if(a > b) cout << "a lon hon b\n" ;
    else cout << "a be hon b\n" ;

    return 0;
}