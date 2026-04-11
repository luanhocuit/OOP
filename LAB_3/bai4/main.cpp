#include <iostream>
using namespace std;

#include "Array.h"

int main() {
    int n;
    cout << "Nhap so phan tu: "; cin >> n;
    cArray a(n);

    cout << "Tao mang ngau nhien...... \n";
    a.TaoMang();
    cout << "Mang da tao ngau nhien la : ";
    a.XuatMang();

    cout << "\nSap xep mang : \n";
    a.SortArray() ;
    cout << "Mang sau sap xep: ";
    a.XuatMang();
    
    cout << "\nNhap x de dem : ";
    int x ; cin >> x ;
    cout << "So lan xuat hien cua " << x << " = " << a.DemSoLanX(x) << '\n' ;

    cout << "Tim so le nho nhat : ";
    int leMin = a.TimLeMin();
    if (leMin == INT_MAX) cout << "Khong co so le\n";
    else cout << "So le nho nhat: " << leMin << endl;

    cout << "Tim so nguyen to lon nhat : ";
    int maxNT = a.TimMaxNguyenTo();
    if (maxNT == INT_MIN) cout << "Khong co so nguyen to\n";
    else cout << "So NT lon nhat: " << maxNT << endl;

    cout << "Check tang dan : ";
        if (n == 1) cout << "Mang VUA tang dan VUA giam dan\n";
    else if (a.CheckTangDan()) cout << "Mang tang dan\n";
    else cout << "Mang KHONG tang dan\n";

    return 0;
}