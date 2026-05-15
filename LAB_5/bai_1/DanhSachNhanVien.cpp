#include <iostream>
using namespace std;

#include "DanhSachNhanVien.h"
// Hàm constructor mặc định
DanhSachNhanVien::DanhSachNhanVien() {}
// Hàm destructor 
DanhSachNhanVien::~DanhSachNhanVien() {
    for (auto nv : dsSX) delete nv ;
    for (auto nv : dsVP) delete nv ;
    dsSX.clear() ;
    dsVP.clear() ;
}
// Hàm nhập danh sách nhân viên
void DanhSachNhanVien::nhapDanhSach() {
    int n1, n2;
    cout << "Nhap so luong NVSX: "; cin >> n1;
    for (int i = 0; i < n1; i++) {
        NhanVien* nv = new NhanVienSanXuat();
        cin >> *nv;
        dsSX.push_back(nv);
    }

    cout << "Nhap so luong NVVP: "; cin >> n2;
    for (int i = 0; i < n2; i++) {
        NhanVien* nv = new NhanVienVanPhong();
        cin >> *nv;
        dsVP.push_back(nv);
    }
}
// Hàm xuất danh sách nhân viên
void DanhSachNhanVien::xuatDanhSach() const {
    cout << "\n--- DANH SACH NHAN VIEN SAN XUAT ---\n";
    for (auto nv : dsSX) cout << *nv << endl;

    cout << "\n--- DANH SACH NHAN VIEN VAN PHONG ---\n";
    for (auto nv : dsVP) cout << *nv << endl;
}
// Hàm tính tổng lương của tất cả nhân viên
double DanhSachNhanVien::tinhTongLuong() const {
    double tong = 0;
    for (auto nv : dsSX) tong += nv->tinhLuong();
    for (auto nv : dsVP) tong += nv->tinhLuong();
    return tong;
}
// Hàm tìm nhân viên sản xuất có lương thấp nhất
NhanVienSanXuat* DanhSachNhanVien::LuongThapNhat() const {
    if(dsSX.empty()) return nullptr; // Nếu danh sách rỗng, trả về rỗng
    NhanVienSanXuat* minNV = nullptr;
    for (NhanVien* nv : dsSX) {
        NhanVienSanXuat* nvSX = (NhanVienSanXuat*)nv ; // Ép kiểu về NhanVienSanXuat do danh sách chỉ chứa NhanVienSanXuat
        if (nvSX) { // Nếu NhanVienSanXuat có tồn tại
            // Nếu chưa có nhân viên hoặc lương hiện tại < lương thấp nhất => update
            if (!minNV || nvSX->tinhLuong() < minNV->tinhLuong()) { 
            // Sau nhân viên đầu tiên, minNV trỏ đến nhân viên != null => không thể = 0 (địa chỉ ô nhớ != 0) -> Chỉ so sánh mức lương
                minNV = nvSX;
            }
        }
    }
    return minNV;
}
// Hàm so sánh tuổi của 2 nhân viên 
bool SoSanhTuoi(const NhanVien* nv1, const NhanVien* nv2) {
    if (nv1->getNam() != nv2->getNam()) {
        return nv1->getNam() < nv2->getNam(); // Năm nhỏ hơn => tuổi cao hơn
    }
    if (nv1->getThang() != nv2->getThang()) {
        return nv1->getThang() < nv2->getThang(); // Tháng nhỏ hơn => tuổi cao hơn
    }
    return nv1->getNgay() < nv2->getNgay(); // Ngày nhỏ hơn => tuổi cao hơn
}
// Hàm tìm nhân viên văn phòng có tuổi cao nhất
NhanVienVanPhong* DanhSachNhanVien::LonTuoiNhat() const {
    if(dsVP.empty()) return nullptr; // Nếu danh sách rỗng, trả về rỗng
    NhanVienVanPhong* oldestNV = nullptr;
    for (NhanVien* nv : dsVP) {
        NhanVienVanPhong* nvVP = (NhanVienVanPhong*)nv ; // Ép kiểu về NhanVienVanPhong do danh sách chỉ chứa NhanVienVanPhong
        if (nvVP) { // Nếu NhanVienVanPhong có tồn tại
            // Nếu chưa có nhân viên hoặc tuổi hiện tại > tuổi cao nhất => update
            if (!oldestNV || SoSanhTuoi(nvVP, oldestNV)) { 
            // Sau nhân viên đầu tiên, oldestNV trỏ đến nhân viên != null => không thể = 0 (địa chỉ ô nhớ != 0) -> Chỉ so sánh tuổi
                oldestNV = nvVP;
            }
        }
    }
    return oldestNV;
}
