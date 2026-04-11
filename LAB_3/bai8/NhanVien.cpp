#include <iostream>

using namespace std ;

#include "NhanVien.h"

// Phương thức Constructor
cNhanVien::cNhanVien() {
    maNV = hoten = ngaysinh = "" ;
    spGiaCong = 0 ; DonGia = 0 ;
} ;

// Phương thức Destructor
cNhanVien::~cNhanVien () {} ;

// Get
string cNhanVien::getMaNV() { return maNV ; } ;
string cNhanVien::getHoten() { return hoten ; } ;
string cNhanVien::getNgaysinh() { return ngaysinh ; } ;
int cNhanVien::getSPGiaCong() { return spGiaCong ; };
double cNhanVien::getDonGia() { return DonGia ; };

// Set
void cNhanVien::setMaNV(string ma) {maNV = ma ;} ;
void cNhanVien::setHoten(string ten) {hoten = ten ;} ;
void cNhanVien::setNgaysinh(string ns) {ngaysinh = ns ;} ;
void cNhanVien::setSPGiaCong(int sp) {spGiaCong = sp ;} ;
void cNhanVien::setDonGia(double dg) {DonGia = dg ;} ;

istream& operator >> (istream& in, cNhanVien &a) {
    cout << "Nhap vao ma NV (SX___) : " ; in >> a.maNV ;
    in.ignore() ;
    cout << "Nhap vao ho va ten : " ; getline(in, a.hoten) ;
    cout << "Nhap vao ngay sinh (dd/mm/yyyy) : " ; in >> a.ngaysinh ;
    cout << "Nhap vao so luong san pham gia cong : " ; in >> a.spGiaCong ;
    cout << "Nhap vao don gia cua san pham do : " ; in >> a.DonGia ;
    return in ;
} ;
ostream& operator<<(ostream& out, cNhanVien a) {
    out << a.maNV << "\t"
        << a.hoten << "\t"
        << a.ngaysinh << "\t"
        << a.spGiaCong << "\t"
        << a.DonGia << "\t"
        << a.luong() << endl;
    return out;
}
double cNhanVien::luong() {
    return spGiaCong * DonGia ;
} ;