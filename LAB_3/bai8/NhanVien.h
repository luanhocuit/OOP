#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
using namespace std ;

class cNhanVien {
private :
    string maNV, hoten, ngaysinh ;
    int spGiaCong ;
    double DonGia ;
public :
    cNhanVien() ;
    ~cNhanVien() ;
    string getMaNV();
    string getHoten();
    string getNgaysinh();
    int getSPGiaCong();
    double getDonGia();

    void setMaNV(string ma);
    void setHoten(string ten);
    void setNgaysinh(string ns);
    void setSPGiaCong(int sp);
    void setDonGia(double dg);
    
    friend istream& operator >> (istream& in, cNhanVien &a) ;
    friend ostream& operator << (ostream& out, cNhanVien a) ;
    double luong() ;
} ;

#endif