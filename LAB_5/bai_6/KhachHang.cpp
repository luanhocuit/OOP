#include <iostream>
#include "KhachHang.h"
using namespace std ;
// Hàm constructor của lớp khách hàng
KhachHang::KhachHang() {
    ten = "" ; 
    soLuong = 0 ; donGia = 0.0 ;
}
// Hàm destructor của lớp khách hàng
KhachHang::~KhachHang() {}
// Hàm nhập vào thông tin của khách hàng 
void KhachHang::nhap() {
    getline(cin, ten) ;
    cin >> soLuong ; cin >> donGia ; // Do kiểu dữ liệu khác nhau nên không thể cin >> soLuong >> donGia ;
}
// Hàm in ra thông tin của khách hàng
void KhachHang::xuat() const {
    cout << "Ten khach hang : " << ten << '\n';
    cout << "So tien phai tra : " << (long long)tinhTien() << '\n' ;
}
// Hàm overload toán tử >> của lớp khách hàng
istream& operator >> (istream& in, KhachHang &x) {
    x.nhap() ; return in ;
}
// Hàm overload toán tử << của lớp khách hàng
ostream& operator << (ostream& out, KhachHang &x) {
    x.xuat() ; return out ;
}
// Hàm get tên của khách hàng
string KhachHang::getTen() const { return ten; }


// Hàm constructor của khách hàng A
KhachHangA::KhachHangA() : KhachHang() {} // : KhachHang() nghĩa là gọi constructor lớp KhachHang trước rồi mới gọi constructor của lớp KhachHangA
// Hàm destructor của khách hàng A
KhachHangA::~KhachHangA() {}
// Hàm nhập thông tin của khách hàng A
void KhachHangA::nhap() {
    KhachHang::nhap() ; 
}
// Hàm in ra thông tin của khách hàng A
void KhachHangA::xuat() const {KhachHang::xuat() ; }
// Hàm tính tiền của khách hàng A
double KhachHangA::tinhTien() const {
    // (Số lượng * Đơn giá) + 10% VAT <=> 110% * (Số lượng * Đơn giá)
    return (long long)(soLuong * donGia * 1.1) ;
}


// Hàm constructor của lớp khách hàng B
KhachHangB::KhachHangB() : KhachHang() { // : KhachHang() nghĩa là gọi constructor lớp KhachHang trước rồi mới gọi constructor của lớp KhachHangB
    soNamThanThiet = 0 ;
}
// Hàm destructor của lớp khách hàng B
KhachHangB::~KhachHangB() {}
// Hàm nhập thông tin của khách hàng B
void KhachHangB::nhap() {
    KhachHang::nhap() ;
    cin >> soNamThanThiet ;
}
// Hàm in ra thông tin của khách hàng B
void KhachHangB::xuat() const { KhachHang::xuat() ; }
// Hàm tính tiền của khách hàng B
double KhachHangB::tinhTien() const {
    // Khuyến mãi = MAX(số năm * 5%, 50%)
    double phanTramKM = max(soNamThanThiet * 0.05, 0.5);
    // (Số lượng * Đơn giá) * (1 - Khuyến mãi) + 10% VAT = 110% * (Số lượng * Đơn giá) * (1 - Khuyến mãi)
    return (long long)((soLuong * donGia) * (1.0 - phanTramKM) * 1.1);
}


// Hàm constructor của khách hàng C
KhachHangC::KhachHangC() : KhachHang() {} // : KhachHang() nghĩa là gọi constructor lớp KhachHang trước rồi mới gọi constructor của lớp KhachHangC
// Hàm destructor của khách hàng C
KhachHangC::~KhachHangC() {}
// Hàm nhập thông tin của khách hàng C
void KhachHangC::nhap() {
    KhachHang::nhap() ; 
}
// Hàm in ra thông tin của khách hàng C
void KhachHangC::xuat() const {KhachHang::xuat() ; }
// Hàm tính tiền của khách hàng C
double KhachHangC::tinhTien() const {
    // (Số lượng * Đơn giá) * 50% + 10% VAT
    return (long long)(soLuong * donGia * 0.5 * 1.1);
}