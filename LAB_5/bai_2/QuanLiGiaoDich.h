#ifndef QUANLIGIAODICH_H
#define QUANLIGIAODICH_H

#include "GiaoDich.h"
#include <vector>

class QuanLiGiaoDich {
private:
    vector<Dat*> dsDat;
    vector<Nha*> dsNha;
    vector<ChungCu*> dsChungCu;
public:
    QuanLiGiaoDich() ;
    ~QuanLiGiaoDich();
    void themGiaoDichDat(Dat* d);
    void themGiaoDichNha(Nha* n);
    void themGiaoDichChungCu(ChungCu* c);
    void tinhTongSoLuongTungLoai() const ;
    double tinhTongTienTatCa() const ;
    double trungBinhThanhTienChungCu() const ;
    void xuatNhaGiaTriCaoNhat() const ;
    void xuatGiaoDichThang12Nam2024() const ;
};

#endif