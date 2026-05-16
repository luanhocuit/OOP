#ifndef QUANLYSINHVIEN_H
#define QUANLYSINHVIEN_H

#include "SinhVien.h"
#include <vector>

class QuanLiSinhVien {
private:
    vector<CaoDang*> dsCaoDang;
    vector<DaiHoc*> dsDaiHoc;

public:
    QuanLiSinhVien();
    ~QuanLiSinhVien();

    void themCaoDang();
    void themDaiHoc();
    
    void xuatTatCa() const;               
    void xuatSVTotNghiep() const;         
    void xuatSVKhongTotNghiep() const;    
    void timMaxDaiHoc() const;            
    void timMaxCaoDang() const;           
    void thongKeKhongTotNghiep() const;   
};

#endif