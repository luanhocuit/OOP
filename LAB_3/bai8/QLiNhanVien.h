#ifndef QLINHANVIEN_H
#define QLINHANVIEN_H

#include "NhanVien.h"

class QLiNhanVien {
private:
    int n;
    cNhanVien *ds; 
public:
    QLiNhanVien();
    ~QLiNhanVien();
    void nhap();
    void xuat();
    double tongLuong();
    cNhanVien luongThapNhat();
    cNhanVien tuoiCaoNhat();
    void sapXepLuongTangDan();
};

#endif