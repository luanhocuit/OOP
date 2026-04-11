#include <iostream>
#include "DaGiac.h"

using namespace std;

int main() {
    cDaGiac dg;
    dg.Nhap();
    
    cout << "Da giac ban nhap vao co cac dinh la : \n";
    dg.Xuat();
    
    cout << "Chu vi cua da giac la : " << dg.ChuVi() << '\n';
    cout << "Dien tich cua da giac la : " << dg.DienTich() << '\n';

    double k_phongto ;
    cout << "Nhap he so de phong to da giac (k > 1): ";
    cin >> k_phongto ; dg.PhongTo(k_phongto);
    
    double k_thunho ;
    cout << "\nNhap he so de thu nho da giac (0 < k < 1): ";
    cin >> k_thunho ; dg.ThuNho(k_thunho);
    
    return 0;
}