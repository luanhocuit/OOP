#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    Vector v1, v2, v_res, v_res1;
    double x ;
    cout << "Nhap thong tin cho Vector v1:" << '\n'  ; cin >> v1;
    cout << "\nNhap thong tin cho Vector v2:" << '\n' ; cin >> v2;

    cout << "\nVector v1 vua nhap la: " << v1;
    cout << "Vector v2 vua nhap la: " << v2;

    cout << "\nv1 + v2 : " ;
    v_res = v1 + v2; 
    cout << v_res ;

    cout << "v1 - v2 : " ;
    v_res = v1 - v2;
    cout << v_res << '\n';

    cout << "Nhap mot so thuc x: "; cin >> x ;
    v_res = v1 * x ;
    v_res1 = v2 * x ;
    cout << "v1 * " << x << ": " << v_res;
    cout << "v2 * " << x << ": " << v_res1;

    double res = v1 * v2;
    cout << "Tich vo huong cua v1 va v2 la: " << res << '\n' ;

    return 0;
}