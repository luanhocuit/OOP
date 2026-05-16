#include <iostream>
#include "QuanLiKhachHang.h"
using namespace std ;

// Hàm constructor của lớp quản lí khách hàng
QuanLiKhachHang::QuanLiKhachHang() {}
// Hàm constructor của lớp quản lí khách hàng
QuanLiKhachHang::~QuanLiKhachHang() {
    // Vì khai báo là con trỏ nên phải xóa các phần tử
    for (auto p : a) delete p;
    for (auto p : b) delete p;
    for (auto p : c) delete p;
}
// Hàm overload toán tử >> của lớp quản lí khách hàng
istream& operator >> (istream& in , QuanLiKhachHang &d) {
    int x, y, z ; // Nhập số lượng khách hàng A,B,C
    if(!(in >> x >> y >> z)) return in ; 
    in.ignore() ; // ignore '\n' sau khi nhập x y z
    // Trong mỗi vòng lặp nhập vào thông tin của từng khách hàng A, B, C
    for(int i = 0 ; i < x ; i++) {
        KhachHang* tmp = new KhachHangA ;
        in >> *tmp ;
        in.ignore() ; // Phải ignore để vòng lặp tiếp theo getline không bị lỗi
        (d.a).push_back(tmp) ;
    }
    for(int i = 0 ; i < y ; i++) {
        KhachHang* tmp = new KhachHangB ;
        in >> *tmp ;
        in.ignore() ;
        (d.b).push_back(tmp) ;
    }
    for(int i = 0 ; i < z ; i++) {
        KhachHang* tmp = new KhachHangC ;
        in >> *tmp ;
        in.ignore() ;
        (d.c).push_back(tmp) ;
    }
    return in ;
}
// Hàm overload toán tử << của lớp quản lí khách hàng
ostream& operator << (ostream& out, QuanLiKhachHang &d) {
    cout << "--- Khach Hang x --- \n" ;
    for(auto p : d.a) cout << *p ;
    cout << "--- Khach Hang y --- \n" ;
    for(auto p : d.b) cout << *p ;
    cout << "--- Khach Hang z --- \n" ;
    for(auto p : d.c) cout << *p ;
    // Sau khi in xong khách hàng thì in ra tổng tiền công ty thu được
    cout << "Tong tien cong ty thu duoc : " << (long long)d.TinhTongTien() << '\n' ;
    return out ;
}
// Hàm tính tổng tiền của các khách hàng
double QuanLiKhachHang::TinhTongTien() {
    double tong = 0 ;
    for (auto p : a) tong += p->tinhTien() ;
    for (auto p : b) tong += p->tinhTien() ;
    for (auto p : c) tong += p->tinhTien() ;
    return tong ;
}