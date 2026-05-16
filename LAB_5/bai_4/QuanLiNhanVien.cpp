#include <iostream>
#include <iomanip>
#include "QuanLiNhanVien.h"
using namespace std ;
// Hàm constructor của lớp quản lí nhân viên
QuanLiNhanVien::QuanLiNhanVien() {}
// Hàm destructor của lớp quản lí nhân viên
QuanLiNhanVien::~QuanLiNhanVien() {
    // Vì khai báo là con trỏ nên phải xóa từng phần tử đã khai báo
    for (auto p : dsLTV) delete p;
    for (auto p : dsKCV) delete p;
}
// Hàm nhập và thêm thông tin của lập trình viên vào danh sách
void QuanLiNhanVien::themLapTrinhVien() {
    LapTrinhVien* p = new LapTrinhVien(); 
    p->nhap(); // Nhập thông tin của lập trình viên
    dsLTV.push_back(p); // Đưa thông tin của nhân viên đó vào danh sách
}
// Hàm nhập và thêm thông tin của kiểm chứng viên vào danh sách
void QuanLiNhanVien::themKiemChungVien() {
    KiemChungVien* p = new KiemChungVien();
    p->nhap(); // Nhập thông tin của kiểm chứng viên
    dsKCV.push_back(p); // Đưa thông tin của nhân viên đó vào danh sách
}
// Hàm in ra thông tin danh sách nhân viên
void QuanLiNhanVien::xuatDanhSach() const {
    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    for (auto p : dsLTV) p->xuat();
    for (auto p : dsKCV) p->xuat();
}
// Hàm in ra thông tin của nhân viên dưới mức trung bình chung
void QuanLiNhanVien::xuatNVLuongThapHonTB() const {
    if (dsLTV.empty() && dsKCV.empty()) return; // Nếu rỗng => không in gì hết
    double tong = 0;
    for (auto p : dsLTV) tong += p->tinhLuong();
    for (auto p : dsKCV) tong += p->tinhLuong();
    double tb = tong / (dsLTV.size() + dsKCV.size()); // Tính trung bình lương của nhân viên
    // In ra thông tin của nhân viên dưới mức trung bình chung (lập trình viên rồi tới kiểm chứng viên)
    cout << "\n--- NV LUONG THAP HON MUC TRUNG BINH (" << tb << ") ---\n";
    for (auto p : dsLTV) if (p->tinhLuong() < tb) p->xuat();
    for (auto p : dsKCV) if (p->tinhLuong() < tb) p->xuat();
}
// Hàm in ra nhân viên có lương cao nhất
void QuanLiNhanVien::xuatNVLuongCaoNhat() const {
    NhanVien* maxNV = nullptr; // Đặt biến maxNV = rỗng
    // Nếu lương nhân viên hiện tại > lương nhân viên của maxNv => cập nhật maxNV
    for (auto p : dsLTV) if (!maxNV || p->tinhLuong() > maxNV->tinhLuong()) maxNV = p;
    for (auto p : dsKCV) if (!maxNV || p->tinhLuong() > maxNV->tinhLuong()) maxNV = p;
    if (maxNV) { // Nếu biến maxNV != rỗng => in ra thông tin nhân viên đó
        cout << "\nNV LUONG CAO NHAT: " << maxNV->getHoTen() << " (" << maxNV->tinhLuong() << ")\n";
    }
}
// Hàm in ra thông tin nhân viên có lương thấp nhất
void QuanLiNhanVien::xuatNVLuongThapNhat() const {
    // Logic tương tự như trên nhưng thay vì > thì <
    NhanVien* minNV = nullptr;
    for (auto p : dsLTV) if (!minNV || p->tinhLuong() < minNV->tinhLuong()) minNV = p;
    for (auto p : dsKCV) if (!minNV || p->tinhLuong() < minNV->tinhLuong()) minNV = p;
    if (minNV) {
        cout << "\nNV LUONG THAP NHAT: " << minNV->getHoTen() << " (" << minNV->tinhLuong() << ")\n";
    }
}
// Hàm in ra thông tin lập trình viên có mức lương cao nhất
void QuanLiNhanVien::xuatLTVLuongCaoNhat() const {
    // Logic tương tự như hàm in ra nhân viên có lương cao nhất nhưng chỉ xét trong danh sách lập trình viên
    if (dsLTV.empty()) return;
    LapTrinhVien* max = dsLTV[0];
    for (auto p : dsLTV) if (p->tinhLuong() > max->tinhLuong()) max = p;
    cout << "\nLTV LUONG CAO NHAT: " << max->getHoTen() << " (" << max->tinhLuong() << ")\n";
}
// Hàm in ra thông tin kiểm chứng viên có mức lương thấp nhất
void QuanLiNhanVien::xuatKCVLuongThapNhat() const {
    // Logic tương tự như hàm in ra nhân viên có lương thấp nhất nhưng chỉ xét trong danh sách kiểm chứng viên
    if (dsKCV.empty()) return;
    KiemChungVien* min = dsKCV[0];
    for (auto p : dsKCV) if (p->tinhLuong() < min->tinhLuong()) min = p;
    cout << "\nKCV LUONG THAP NHAT: " << min->getHoTen() << " (" << min->tinhLuong() << ")\n";
}