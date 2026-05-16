#include <iostream>
using namespace std ;

#include "QuanLiSinhVien.h"

void inLuaChon(int choice, QuanLiSinhVien ql) {
    switch (choice) {
        case 1: ql.themCaoDang(); break;
        case 2: ql.themDaiHoc(); break;
        case 3: ql.xuatTatCa(); break;
        case 4: ql.xuatSVTotNghiep(); break;
        case 5: ql.xuatSVKhongTotNghiep(); break;
        case 6: ql.timMaxDaiHoc(); break;
        case 7: ql.timMaxCaoDang(); break;
        case 8: ql.thongKeKhongTotNghiep(); break;
        default :
            cout << "Ban nhap sai roi. Vui long nhap lai !\n" ;
        }
} ;


int main() {
    QuanLiSinhVien ql;
    int choice;

    do {
        cout << "\n========== MENU QUAN LY SINH VIEN ==========\n";
        cout << "1. Nhap SV Cao Dang\n";
        cout << "2. Nhap SV Dai Hoc\n";
        cout << "3. Xuat tat ca SV\n";
        cout << "4. Xuat SV du dieu kien tot nghiep\n";
        cout << "5. Xuat SV KHONG du dieu kien tot nghiep\n";
        cout << "6. SV Dai Hoc co DTB cao nhat\n";
        cout << "7. SV Cao Dang co DTB cao nhat\n";
        cout << "8. Thong ke so SV ko tot nghiep moi loai\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "--------------------------------------------\n";
        cout << "Chon chuc nang: "; cin >> choice;

        inLuaChon(choice, ql) ;
    } while (choice != 0);

    return 0;
}