#include <iostream>
using namespace std;

#include "TamGiac.h"

int main() {
    cTamGiac tg;

    // Nhập tam giác
    tg.Nhap() ;

    // Xuất tam giác ban đầu
    cout << "\nTam giac ban dau : \n" ;
    tg.Xuat() ;   

    // Kiểm tra loại tam giác
    cout << "\nKiem tra loai tam giac : \n" ;
    tg.checkTamGiac() ;

    // Tính chu vi
    cout << "Chu vi tam giac : " << tg.ChuVi() << '\n' ;

    // Tính diện tích
    cout << "Dien tich tam giac : " << tg.DienTich() << '\n' ;

    // Phóng to tam giác
    double k ;
    cout << "\nNhap he so phong to k (>1): " ;
    cin >> k ; tg.PhongTo(k) ;

    // Thu nhỏ tam giác
    cout << "\nNhap he so thu nho k (0 < k < 1): " ;
    cin >> k ; tg.ThuNho(k) ;

    return 0;
}