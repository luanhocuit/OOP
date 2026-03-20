#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main() {
    SoPhuc a, b;

    cout << "Nhap so phuc a:\n"; a.Nhap() ;
    cout << "Nhap so phuc b:\n"; b.Nhap();
    
    cout << "\nSo phuc a: "; a.Xuat();
    cout << "\nSo phuc b: "; b.Xuat();

    SoPhuc tong = a.Tong(b);
    SoPhuc hieu = a.Hieu(b);
    SoPhuc tich = a.Tich(b);
    SoPhuc thuong = a.Thuong(b);

    cout << "\n\nTong: "; tong.Xuat();
    cout << "\nHieu: "; hieu.Xuat();
    cout << "\nTich: "; tich.Xuat();
    cout << "\nThuong: "; thuong.Xuat();
    return 0;
}