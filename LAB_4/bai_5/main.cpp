#include <iostream>
#include "DaThuc.h"

using namespace std;

int main() {
    DaThuc dt1, dt2, res;
    double x;
    
    cout << "\n--- Nhap da thuc thu nhat (dt1) ---" << endl;
    cin >> dt1;
    cout << "--- Nhap da thuc thu hai (dt2) ---" << endl;
    cin >> dt2;
    cout << "\nDa thuc dt1 vua nhap: P(x) = " << dt1 << endl;
    cout << "Da thuc dt2 vua nhap: Q(x) = " << dt2 << endl;

    res = dt1 + dt2;
    cout << "\nKet qua P(x) + Q(x) = " << res << endl;

    res = dt1 - dt2;
    cout << "Ket qua P(x) - Q(x) = " << res << endl;

    cout << "\nNhap vao gia tri x de tinh P(x): ";
    cin >> x;
    double giaTri = dt1.tinhGiaTri(x);
    cout << "Gia tri cua da thuc P tai x = " << x << " la: P(" << x << ") = " << giaTri << endl;

    return 0;
}