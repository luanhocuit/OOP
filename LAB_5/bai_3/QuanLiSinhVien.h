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
    
    void xuatTatCa() const;               // Câu b
    void xuatSVTotNghiep() const;         // Câu c
    void xuatSVKhongTotNghiep() const;    // Câu d
    void timMaxDaiHoc() const;            // Câu e
    void timMaxCaoDang() const;           // Câu f
    void thongKeKhongTotNghiep() const;   // Câu g
};

#endif