#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

class cTamGiac {
private :
    Diem a, b, c ;
public : 
    cTamGiac() ;
    cTamGiac(Diem a, Diem b, Diem c) ;
    void Nhap() ;
    void Xuat() ;
    void checkTamGiac() ;
    double ChuVi() ;
    double DienTich() ;
    void PhongTo(double k) ;
    void ThuNho(double k) ;
    ~cTamGiac() ;
} ;

#endif