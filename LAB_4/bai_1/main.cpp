#include <iostream>
using namespace std;

#include "SoPhuc.h"

int main() {
    SoPhuc a, b ;
    cin >> a >> b ;

    SoPhuc d(5) ;
    cout << "Day la so phuc chi co so thuc (ao = 0) : " << d << '\n' ;

    cout << "So phuc a : " << a << '\n';
    cout << "So phuc b : " << b << '\n';

    SoPhuc tong = a + b ;
    cout << "Tong : " << tong << '\n';
    SoPhuc hieu = a - b ;
    cout << "Hieu : " << hieu << '\n';
    SoPhuc tich = a * b ;
    cout << "Tich : " << tich << '\n';
    SoPhuc thuong = a / b ;
    cout << "Thuong : " << thuong << '\n';

    cout << "So sanh == : " ;
    if (a == b) cout << "2 so phuc bang nhau\n" ;
    else cout << "2 so phuc khac nhau\n" ;

    cout << "So sanh != : " ;
    if (a != b) cout << "2 so phuc khac nhau\n" ;
    else cout << "2 so phuc bang nhau\n" ;

    return 0;
}