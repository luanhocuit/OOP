#include <iostream>
#include <iomanip>
#include "QuanLiNhanVien.h"
using namespace std ;
QuanLiNhanVien::QuanLiNhanVien() {}
QuanLiNhanVien::~QuanLiNhanVien() {
    for (auto p : dsLTV) delete p;
    for (auto p : dsKCV) delete p;
}

void themLapTrinhVien() {} // Thân hàm thực tế nằm dưới đây

void QuanLiNhanVien::themLapTrinhVien() {
    LapTrinhVien* p = new LapTrinhVien();
    p->nhap();
    dsLTV.push_back(p);
}

void QuanLiNhanVien::themKiemChungVien() {
    KiemChungVien* p = new KiemChungVien();
    p->nhap();
    dsKCV.push_back(p);
}

void QuanLiNhanVien::xuatDanhSach() const {
    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    for (auto p : dsLTV) p->xuat();
    for (auto p : dsKCV) p->xuat();
}

void QuanLiNhanVien::xuatNVLuongThapHonTB() const {
    if (dsLTV.empty() && dsKCV.empty()) return;
    double tong = 0;
    for (auto p : dsLTV) tong += p->tinhLuong();
    for (auto p : dsKCV) tong += p->tinhLuong();
    double tb = tong / (dsLTV.size() + dsKCV.size());

    cout << "\n--- NV LUONG THAP HON MUC TRUNG BINH (" << fixed << setprecision(0) << tb << ") ---\n";
    for (auto p : dsLTV) if (p->tinhLuong() < tb) p->xuat();
    for (auto p : dsKCV) if (p->tinhLuong() < tb) p->xuat();
}

void QuanLiNhanVien::xuatNVLuongCaoNhat() const {
    NhanVien* maxNV = nullptr;
    for (auto p : dsLTV) if (!maxNV || p->tinhLuong() > maxNV->tinhLuong()) maxNV = p;
    for (auto p : dsKCV) if (!maxNV || p->tinhLuong() > maxNV->tinhLuong()) maxNV = p;
    if (maxNV) {
        cout << "\nNV LUONG CAO NHAT: " << maxNV->getHoTen() << " (" << maxNV->tinhLuong() << ")\n";
    }
}

void QuanLiNhanVien::xuatNVLuongThapNhat() const {
    NhanVien* minNV = nullptr;
    for (auto p : dsLTV) if (!minNV || p->tinhLuong() < minNV->tinhLuong()) minNV = p;
    for (auto p : dsKCV) if (!minNV || p->tinhLuong() < minNV->tinhLuong()) minNV = p;
    if (minNV) {
        cout << "\nNV LUONG THAP NHAT: " << minNV->getHoTen() << " (" << minNV->tinhLuong() << ")\n";
    }
}

void QuanLiNhanVien::xuatLTVLuongCaoNhat() const {
    if (dsLTV.empty()) return;
    LapTrinhVien* max = dsLTV[0];
    for (auto p : dsLTV) if (p->tinhLuong() > max->tinhLuong()) max = p;
    cout << "\nLTV LUONG CAO NHAT: " << max->getHoTen() << " (" << max->tinhLuong() << ")\n";
}

void QuanLiNhanVien::xuatKCVLuongThapNhat() const {
    if (dsKCV.empty()) return;
    KiemChungVien* min = dsKCV[0];
    for (auto p : dsKCV) if (p->tinhLuong() < min->tinhLuong()) min = p;
    cout << "\nKCV LUONG THAP NHAT: " << min->getHoTen() << " (" << min->tinhLuong() << ")\n";
}