#ifndef QUANLYNHANVIEN_H
#define QUANLYNHANVIEN_H

#include "NhanVien.h"
#include <vector>

class QuanLiNhanVien {
private:
    vector<LapTrinhVien*> dsLTV;
    vector<KiemChungVien*> dsKCV;
public:
    QuanLiNhanVien();
    ~QuanLiNhanVien();

    void themLapTrinhVien();          
    void themKiemChungVien();         
    void xuatDanhSach() const;        
    void xuatNVLuongThapHonTB() const; 
    void xuatNVLuongCaoNhat() const;   
    void xuatNVLuongThapNhat() const;  
    void xuatLTVLuongCaoNhat() const;  
    void xuatKCVLuongThapNhat() const; 
};

#endif