#ifndef DAGIAC_H
#define DAGIAC_H

#include "Diem.h"

class cDaGiac {
private:
    int n;         
    Diem* Dinh;     
public:
    cDaGiac();
    cDaGiac(int n, Diem* Dinh);
    ~cDaGiac();     
    void Nhap();
    void Xuat();
    double ChuVi();
    double DienTich();
    void PhongTo(double k);
    void ThuNho(double k);
};
#endif