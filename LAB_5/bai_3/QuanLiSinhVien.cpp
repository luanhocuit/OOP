#include <iostream>
#include "QuanLiSinhVien.h"

using namespace std ;

QuanLiSinhVien::QuanLiSinhVien() {}

QuanLiSinhVien::~QuanLiSinhVien() {
    for (auto p : dsCaoDang) delete p;
    for (auto p : dsDaiHoc) delete p;
}

void QuanLiSinhVien::themCaoDang() {
    CaoDang* p = new CaoDang();
    p->nhap();
    dsCaoDang.push_back(p);
}

void QuanLiSinhVien::themDaiHoc() {
    DaiHoc* p = new DaiHoc();
    p->nhap();
    dsDaiHoc.push_back(p);
}

void QuanLiSinhVien::xuatTatCa() const {
    cout << "DANH SACH TAT CA SINH VIEN\n";
    for (auto p : dsCaoDang) p->xuat();
    for (auto p : dsDaiHoc) p->xuat();
}

void QuanLiSinhVien::xuatSVTotNghiep() const {
    cout << "SINH VIEN DU DIEU KIEN TOT NGHIEP\n";
    for (auto p : dsCaoDang) if (p->totnghiep()) p->xuat();
    for (auto p : dsDaiHoc) if (p->totnghiep()) p->xuat();
}

void QuanLiSinhVien::xuatSVKhongTotNghiep() const {
    cout << "SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP\n";
    for (auto p : dsCaoDang) if (!p->totnghiep()) p->xuat();
    for (auto p : dsDaiHoc) if (!p->totnghiep()) p->xuat();
}

void QuanLiSinhVien::timMaxDaiHoc() const {
    if (dsDaiHoc.empty()) { 
        cout << "Danh sach sinh vien Dai Hoc rong.\n"; 
        return ; 
    }
    DaiHoc* maxSV = dsDaiHoc[0];
    for (auto p : dsDaiHoc) {
        if (p->getDTB() > maxSV->getDTB()) {
            maxSV = p ;
        }
    } ;
    cout << "SV Dai Hoc co DTB cao nhat: "; maxSV->xuat();
}

void QuanLiSinhVien::timMaxCaoDang() const {
    if (dsCaoDang.empty()) { 
        cout << "Danh sach sinh vien Cao Dang rong.\n" ; 
        return ; 
    }
    CaoDang* maxSV = dsCaoDang[0];
    for (auto p : dsCaoDang) {
        if (p->getDTB() > maxSV->getDTB()) {
            maxSV = p;
        }
    }
    cout << "SV Cao Dang co DTB cao nhat: "; maxSV->xuat();
}

void QuanLiSinhVien::thongKeKhongTotNghiep() const {
    int countCD = 0, countDH = 0;
    for (auto p : dsCaoDang) {
        if (!p->totnghiep()) countCD++;
    }
    for (auto p : dsDaiHoc) {
        if (!p->totnghiep()) countDH++;
    }
    cout << "Thong ke SV KHONG tot nghiep :\n";
    cout << "- Cao Dang : " << countCD << " sinh vien\n" 
         << "- Dai Hoc : " << countDH << " sinh vien\n";
}