#include <iostream>
#include <string>
#include "NhanVien.h"
using namespace std ;

NhanVien::NhanVien() {
    ma = hoten = sdt = email = "" ;
    tuoi = 0 ; luongcoban = 0.0 ;
}

NhanVien::~NhanVien() {}

void NhanVien::nhap() {
    cout << "Nhap ma nhan vien : " ; cin >> ma ;
    cin.ignore() ;
    cout << "Nhap ho ten : " ; getline(cin, hoten) ;
    cout << "Nhap sdt : " ; cin >> sdt ;
    cout << "Nhap email : " ; cin >> email ;
    cout << "Nhap so tuoi : " ; cin >> tuoi ;
    cout << "Nhap luong co ban (dong) : " ; cin >> luongcoban ;
}
void NhanVien::xuat() const {
    cout << ma << '\t' << hoten << '\t' << sdt << '\t' << email << '\t' 
         << tuoi << '\t' << luongcoban << '\t' ;
}

istream& operator >> (istream& in, NhanVien &x) {
    x.nhap() ; return in ;
}

ostream& operator << (ostream& out, NhanVien&x) {
    x.xuat() ; return out ;
}

string NhanVien::getHoTen() const {
    return hoten ;
};
string NhanVien::getMa() const {
    return ma ;
};

LapTrinhVien::LapTrinhVien() : NhanVien() {
    SoGioOvertime = 0 ;
}

LapTrinhVien::~LapTrinhVien() {} 

void LapTrinhVien::nhap() {
    NhanVien::nhap() ;
    cout << "Nhap so gio overtime : " ; cin >> SoGioOvertime ;
}

double LapTrinhVien::tinhLuong() const {
    return luongcoban + SoGioOvertime * 200000;
}

void LapTrinhVien::xuat() const {
    NhanVien::xuat() ;
    cout << SoGioOvertime << '\t' << tinhLuong() << '\n' ;
}

KiemChungVien::KiemChungVien() : NhanVien() {
    SoLoiPhatHien = 0 ;
}

KiemChungVien::~KiemChungVien() {}

void KiemChungVien::nhap() {
    NhanVien::nhap() ;
    cout << "Nhap so loi da phat hien duoc : " ; cin >> SoLoiPhatHien ;
}

double KiemChungVien::tinhLuong() const {
    return luongcoban + SoLoiPhatHien * 50000 ;
}

void KiemChungVien::xuat() const {
    NhanVien::xuat() ;
    cout << SoLoiPhatHien << '\t' << tinhLuong() << '\n' ;
}