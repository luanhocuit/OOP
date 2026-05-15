#ifndef QUANLIKHACHHANG_H
#define QUANLIKHACHHANG_H
#include <iostream>
#include <vector>
#include "KhachHang.h"
using namespace std ;

class QuanLiKhachHang {
private :
    vector <KhachHang*> a ;
    vector <KhachHang*> b ;
    vector <KhachHang*> c ;
public :
    QuanLiKhachHang() ;
    ~QuanLiKhachHang() ;
    friend istream& operator >> (istream& in, QuanLiKhachHang &d) ;
    friend ostream& operator << (ostream& out , QuanLiKhachHang &d) ;
    double TinhTongTien() ;
} ;


#endif