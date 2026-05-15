#include <iostream>
#include "KhachHang.h"
using namespace std ;
// --- Định nghĩa lớp KhachHang ---
KhachHang::KhachHang() {
    ten = "" ; 
    soLuong = 0 ; donGia = 0.0 ;
}
KhachHang::~KhachHang() {}

void KhachHang::nhap() {
    getline(cin, ten) ;
    cin >> soLuong ;
    cin >> donGia ;
}

void KhachHang::xuat() const {
    cout << "Ten khach hang : " << ten << '\n';
    cout << "So tien phai tra : " << (long long)tinhTien() << '\n' ;
}

istream& operator >> (istream& in, KhachHang &x) {
    x.nhap() ; return in ;
}

ostream& operator << (ostream& out, KhachHang &x) {
    x.xuat() ; return out ;
}

string KhachHang::getTen() const { return ten; }


// --- Định nghĩa lớp KhachHangA ---

KhachHangA::KhachHangA() : KhachHang() {}

KhachHangA::~KhachHangA() {}

void KhachHangA::nhap() {
    KhachHang::nhap() ; 
}

void KhachHangA::xuat() const {KhachHang::xuat() ; }

double KhachHangA::tinhTien() const {
    // (Số lượng * Đơn giá) + 10% VAT <=> 110% * (Số lượng * Đơn giá)
    return (long long)(soLuong * donGia * 1.1) ;
}

// --- Định nghĩa lớp KhachHangB ---

KhachHangB::KhachHangB() : KhachHang() {
    soNamThanThiet = 0 ;
}

KhachHangB::~KhachHangB() {}

void KhachHangB::nhap() {
    KhachHang::nhap() ;
    cin >> soNamThanThiet ;
}

void KhachHangB::xuat() const { KhachHang::xuat() ; }

double KhachHangB::tinhTien() const {
    // Khuyến mãi = MAX(số năm * 5%, 50%)
    double phanTramKM = max(soNamThanThiet * 0.05, 0.5);
    // (Số lượng * Đơn giá) * (1 - Khuyến mãi) + 10% VAT = 110% * (Số lượng * Đơn giá) * (1 - Khuyến mãi)
    return (long long)((soLuong * donGia) * (1.0 - phanTramKM) * 1.1);
}

// --- Định nghĩa lớp KhachHangC ---

KhachHangC::KhachHangC() : KhachHang() {}

KhachHangC::~KhachHangC() {}

void KhachHangC::nhap() {
    KhachHang::nhap() ; 
}
void KhachHangC::xuat() const {KhachHang::xuat() ; }

double KhachHangC::tinhTien() const {
    // (Số lượng * Đơn giá) * 50% + 10% VAT
    return (long long)(soLuong * donGia * 0.5 * 1.1);
}