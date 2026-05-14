#include <iostream>
#include "DaThuc.h"

using namespace std;

int main() {
    DaThuc dt1, dt2, res;
    double x;

    cout << "===== CHUONG TRINH THAO TAC VOI DA THUC =====" << endl;

    // 1. Test operator >> (Nhap da thuc)
    cout << "\n--- Nhap da thuc thu nhat (dt1) ---" << endl;
    cin >> dt1;
    cout << "--- Nhap da thuc thu hai (dt2) ---" << endl;
    cin >> dt2;

    // 2. Test operator << (Xuat da thuc)
    cout << "\nDa thuc dt1 vua nhap: P(x) = " << dt1 << endl;
    cout << "Da thuc dt2 vua nhap: Q(x) = " << dt2 << endl;

    // 3. Test operator + (Cong hai da thuc)
    res = dt1 + dt2;
    cout << "\nKet qua P(x) + Q(x) = " << res << endl;

    // 4. Test operator - (Tru hai da thuc)
    res = dt1 - dt2;
    cout << "Ket qua P(x) - Q(x) = " << res << endl;

    // 5. Test ham tinhGiaTri(double x)
    cout << "\nNhap vao gia tri x de tinh P(x): ";
    cin >> x;
    double giaTri = dt1.tinhGiaTri(x);
    cout << "Gia tri cua da thuc P tai x = " << x << " la: P(" << x << ") = " << giaTri << endl;

    cout << "\n================ KET THUC ================" << endl;

    return 0;
}