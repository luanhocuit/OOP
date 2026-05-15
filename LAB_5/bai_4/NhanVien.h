#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <iostream>
#include <string>
using namespace std ;

class NhanVien {
protected :
    string ma, hoten, sdt, email ;
    int tuoi ;
    double luongcoban ;
public :
    NhanVien() ;
    virtual ~NhanVien() ;
    virtual void nhap() ;
    virtual void xuat() const ;
    friend istream& operator >> (istream& in, NhanVien &x) ;
    friend ostream& operator << (ostream& out, NhanVien &x) ;
    virtual double tinhLuong() const = 0;
    string getHoTen() const ;
    string getMa() const ;
} ;

class LapTrinhVien : public NhanVien {
private :
    double SoGioOvertime ;
public :
    LapTrinhVien() ;
    ~LapTrinhVien() override ;
    void nhap() override ;
    void xuat() const override ;
    double tinhLuong() const override ;
} ;

class KiemChungVien : public NhanVien {
private :
    int SoLoiPhatHien ;
public :
    KiemChungVien() ;
    ~KiemChungVien() override ;
    void nhap() override ;
    void xuat() const override ;
    double tinhLuong() const override ;
} ;
// Tong luong, Trung binh luong => se duoc viet o ham quan li nhan vien
// Dung trung binh luong de tao danh sach nhan vien duoi muc trung binh => in ra
#endif