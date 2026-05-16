#ifndef GIAODICH_H
#define GIAODICH_H
#include <iostream>
using namespace std ;

class GiaoDich {
protected :
    string maGD ;
    int ngay, thang, nam ;
    double DonGia, dientich ;
public :
    GiaoDich() ;
    virtual ~GiaoDich() ;
    virtual void nhap() ;
    virtual void xuat() const ;
    friend istream& operator >> (istream& in, GiaoDich &x) ;
    friend ostream& operator << (ostream& out, GiaoDich &x) ;
    bool NamNhuan(int y) ;
    int dayInMonth(int m, int y) ;
    virtual double TotalMoney() const = 0 ;
    int getThang() const ;
    int getNam() const ; 
} ;

class Dat : public GiaoDich {
private :
    char type ;
public :
    Dat() ;
    ~Dat() override ;
    void nhap() override ;
    void xuat() const override ;
    double TotalMoney() const override ;
} ;

class Nha : public GiaoDich {
private :
    string loainha, diachi ;
public : 
    Nha() ;
    ~Nha() override ;
    void nhap() override ;
    void xuat() const override ;
    double TotalMoney() const override ;
} ;

class ChungCu : public GiaoDich {
private :
    string maCan ;
    int vitriTang ;
public :
    ChungCu() ;
    ~ChungCu() override ;
    void nhap() override ;
    void xuat() const override ;
    double TotalMoney() const override ;
} ;

#endif