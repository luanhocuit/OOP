#ifndef DANHSACHNHANVIEN_H
#define DANHSACHNHANVIEN_H

#include <iostream>
#include "NhanVien.h"
#include <vector>
using namespace std;

class DanhSachNhanVien {
private:
    vector<NhanVien*> dsSX;
    vector<NhanVien*> dsVP;
public:
    DanhSachNhanVien();
    ~DanhSachNhanVien(); 
    void nhapDanhSach();
    void xuatDanhSach() const;
    double tinhTongLuong() const;
    NhanVienSanXuat* LuongThapNhat() const;
    NhanVienVanPhong* LonTuoiNhat() const;
};

#endif