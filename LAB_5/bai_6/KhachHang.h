#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
using namespace std;

class KhachHang {
protected:
    string ten;
    int soLuong;
    double donGia;
public:
    KhachHang();
    virtual ~KhachHang();
    virtual void nhap() ;
    virtual void xuat() const ;
    friend istream& operator >> (istream& in, KhachHang &x) ;
    friend ostream& operator << (ostream& out, KhachHang &x) ;
    virtual double tinhTien() const = 0;
    
    string getTen() const;
};

class KhachHangA : public KhachHang {
public:
    KhachHangA() ;
    ~KhachHangA() override ;
    void nhap() override ;
    void xuat() const override ;
    double tinhTien() const override;
};

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;
public:
    KhachHangB() ;
    ~KhachHangB() override ;
    void nhap() override ;
    void xuat() const override ;
    double tinhTien() const override;
};

class KhachHangC : public KhachHang {
public:
    KhachHangC() ;
    ~KhachHangC() override ;
    void nhap() override ;
    void xuat() const override ;
    double tinhTien() const override;
};

#endif