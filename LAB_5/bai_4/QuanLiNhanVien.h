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

    void themLapTrinhVien();          // Yeu cau a
    void themKiemChungVien();         // Yeu cau a
    void xuatDanhSach() const;        // Yeu cau b
    void xuatNVLuongThapHonTB() const; // Yeu cau c
    void xuatNVLuongCaoNhat() const;   // Yeu cau d
    void xuatNVLuongThapNhat() const;  // Yeu cau e
    void xuatLTVLuongCaoNhat() const;  // Yeu cau f
    void xuatKCVLuongThapNhat() const; // Yeu cau g
};

#endif