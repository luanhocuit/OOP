#include <iostream>
#include "DanhSachNhanVien.h"

using namespace std;

int main() {
    DanhSachNhanVien ql;
    ql.nhapDanhSach();
    ql.xuatDanhSach();

    cout << "\n--- TONG LUONG TOAN CONG TY: " << ql.tinhTongLuong() << " VND" << endl;
    NhanVienSanXuat* nvsxMin = ql.LuongThapNhat();
    if (nvsxMin) {
        cout << "\n--- NHAN VIEN SAN XUAT CO LUONG THAP NHAT:" << endl;
        cout << *nvsxMin; 
        cout << "Luong nhan duoc : " << nvsxMin->tinhLuong() << " VND" << endl;
    } else {
        cout << "\n--- Khong co nhan vien san xuat nao trong danh sach." << endl;
    }
    NhanVienVanPhong* nvvpOld = ql.LonTuoiNhat();
    if (nvvpOld) {
        cout << "\n--- NHAN VIEN VAN PHONG LON TUOI NHAT:" << endl;
        cout << *nvvpOld;
    } else {
        cout << "\n--- Khong co nhan vien van phong nao trong danh sach." << endl;
    }

    return 0;
}