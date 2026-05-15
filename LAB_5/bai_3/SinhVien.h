#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
using namespace std ;

class SinhVien {
protected :
    string maso, hoten ;
    int tinchi ;
    double dtb ;
public :
    SinhVien() ;
    virtual ~SinhVien() ;
    virtual void nhap() ;
    virtual void xuat() const ;
    friend istream& operator >> (istream& in, SinhVien &x) ;
    friend ostream& operator << (ostream& out, SinhVien&x) ;
    virtual bool totnghiep() const = 0 ;
    double getDTB() const ;
} ;
class CaoDang : public SinhVien {
private :
    string diachi ;
    double diemthitotnghiep ;
public :
    CaoDang() ;
    ~CaoDang() override ;
    void nhap() override ;
    void xuat() const override ;
    bool totnghiep() const override ;
} ;

class DaiHoc : public SinhVien {
private :
    string tenluanvan ;
    double diemluanvan ;
public :
    DaiHoc() ;
    ~DaiHoc() override ;
    void nhap() override ;
    void xuat() const override ;
    bool totnghiep() const override ;
} ;

#endif