#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    int ngay, thang, nam;
public:
    NhanVien() ;
    virtual ~NhanVien(); 
    virtual void nhap();
    virtual void xuat() const ;
    friend istream& operator >> (istream& in, NhanVien& nv) ;
    friend ostream& operator << (ostream& out, const NhanVien& nv) ;
    virtual double tinhLuong() const ;
    int getNam() const ;
    int getThang() const ;
    int getNgay() const ;
};

class NhanVienSanXuat : public NhanVien {
private :
    int soSanPham;
    double luongcoban ;
public :
    NhanVienSanXuat() ;
    ~NhanVienSanXuat() override ; 
    void nhap() override ;
    void xuat() const override ;
    double tinhLuong() const override ;
} ;

class NhanVienVanPhong : public NhanVien {
private :
    int songayLamViec ;
public :
    NhanVienVanPhong() ;
    ~NhanVienVanPhong() override ;
    void nhap() override ;
    void xuat() const override ;
    double tinhLuong() const override ;
} ;
#endif 