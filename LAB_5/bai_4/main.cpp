#include <iostream>
#include "QuanLiNhanVien.h"
using namespace std ;

void hienThiMenu() {
    cout << "\n========== HE THONG QUAN LY NHAN VIEN ==========\n";
    cout << "1. Them Lap trinh vien\n";
    cout << "2. Them Kiem chung vien\n";
    cout << "3. Xuat danh sach nhan vien\n";
    cout << "4. Xuat NV luong thap hon trung binh\n";
    cout << "5. Xuat NV luong CAO NHAT cong ty\n";
    cout << "6. Xuat NV luong THAP NHAT cong ty\n";
    cout << "7. Xuat LAP TRINH VIEN luong cao nhat\n";
    cout << "8. Xuat KIEM CHUNG VIEN luong thap nhat\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "------------------------------------------------\n";
    cout << "Lua chon cua ban: ";
}

void inLuaChon(int choice, QuanLiNhanVien ql) {
    switch (choice) {
        case 1: ql.themLapTrinhVien(); break;
        case 2: ql.themKiemChungVien(); break;
        case 3: ql.xuatDanhSach(); break;
        case 4: ql.xuatNVLuongThapHonTB(); break;
        case 5: ql.xuatNVLuongCaoNhat(); break;
        case 6: ql.xuatNVLuongThapNhat(); break;
        case 7: ql.xuatLTVLuongCaoNhat(); break;
        case 8: ql.xuatKCVLuongThapNhat(); break;
        case 0: cout << "Dang thoat...\n"; break;
        default: cout << "Lua chon khong hop le!\n";
        }
} ;

int main() {
    QuanLiNhanVien ql;
    int choice;

    do {
        hienThiMenu();
        cin >> choice;

        inLuaChon(choice, ql) ;
    } while (choice != 0);

    return 0;
}