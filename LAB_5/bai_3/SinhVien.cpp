#include <iostream>
#include <string>
#include "SinhVIen.h"
using namespace std ;

SinhVien::SinhVien() {
    maso = hoten = "" ;
    tinchi = 0 ; dtb = 0.0 ;
}

SinhVien::~SinhVien() {} ;

void SinhVien::nhap() {
    cout << "Nhap ma so sinh vien : " ; cin >> maso ;
    cin.ignore() ;
    cout << "Nhap ho va ten : " ; getline(cin, hoten) ;
    cout << "Nhap so tin chi da hoc : " ; cin >> tinchi ;
    cout << "Nhap diem trung binh : " ; cin >> dtb ; 
}

void SinhVien::xuat() const {
    cout << maso << '\t' << hoten << '\t' << '\t' << tinchi << '\t' << dtb << '\t' ;
}

istream& operator >> (istream& in, SinhVien &x) {
    x.nhap() ; return in ;
}

ostream& operator << (ostream &out, SinhVien &x) {
    x.xuat() ; return out ;
}

double SinhVien::getDTB() const {
    return dtb ;
}

CaoDang::CaoDang() : SinhVien() {
    diachi = "" ; diemthitotnghiep = 0.0 ;
}

CaoDang::~CaoDang() {} 

void CaoDang::nhap() {
    SinhVien::nhap() ;
    cin.ignore() ;
    cout << "Nhap dia chi : " ; getline(cin, diachi) ;
    cout << "Nhap diem thi tot nghiem : " ; cin >> diemthitotnghiep ;
}

void CaoDang::xuat() const {
    SinhVien::xuat() ;
    cout << diachi << '\t' << diemthitotnghiep << '\n' ;
}

bool CaoDang::totnghiep() const {
    return (tinchi >= 120) && (dtb >= 5) && (diemthitotnghiep >= 5) ;
}

DaiHoc::DaiHoc() : SinhVien() {
    tenluanvan = "" ; diemluanvan = 0.0 ;
}
DaiHoc::~DaiHoc() {} 

void DaiHoc::nhap() {
    SinhVien::nhap() ;
    cin.ignore() ;
    cout << "Nhap ten de tai luan van : " ; getline(cin, tenluanvan) ;
    cout << "Nhap diem luan van : " ; cin >> diemluanvan ;
}

void DaiHoc::xuat() const {
    SinhVien::xuat() ;
    cout << tenluanvan << '\t' << diemluanvan << '\n' ;
}

bool DaiHoc::totnghiep() const {
    return (tinchi >= 170) && (dtb >= 5) && (diemluanvan >= 5) ;
}