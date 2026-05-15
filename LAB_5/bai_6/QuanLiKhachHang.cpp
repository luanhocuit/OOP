#include <iostream>
#include "QuanLiKhachHang.h"
using namespace std ;

QuanLiKhachHang::QuanLiKhachHang() {}

QuanLiKhachHang::~QuanLiKhachHang() {
    for (auto p : a) delete p;
    for (auto p : b) delete p;
    for (auto p : c) delete p;
}

istream& operator >> (istream& in , QuanLiKhachHang &d) {
    int x, y, z ;
    if(!(in >> x >> y >> z)) return in ;
    in.ignore() ;
    for(int i = 0 ; i < x ; i++) {
        KhachHang* tmp = new KhachHangA ;
        in >> *tmp ;
        in.ignore() ;
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

ostream& operator << (ostream& out, QuanLiKhachHang &d) {
    cout << "--- Khach Hang x --- \n" ;
    for(auto p : d.a) cout << *p ;
    cout << "--- Khach Hang y --- \n" ;
    for(auto p : d.b) cout << *p ;
    cout << "--- Khach Hang z --- \n" ;
    for(auto p : d.c) cout << *p ;
    cout << "Tong tien cong ty thu duoc : " << (long long)d.TinhTongTien() << '\n' ;
    return out ;
}

double QuanLiKhachHang::TinhTongTien() {
    double tong = 0 ;
    for (auto p : a) tong += p->tinhTien() ;
    for (auto p : b) tong += p->tinhTien() ;
    for (auto p : c) tong += p->tinhTien() ;
    return tong ;
}