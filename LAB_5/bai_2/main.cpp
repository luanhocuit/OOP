#include <iostream>
#include <iomanip>
#include "QuanLiGiaoDich.h"

using namespace std;

void inLuaChon(int choice, QuanLiGiaoDich quanLi) {
    switch (choice) {
        case 1: {
            Dat* d = new Dat();
            d->nhap();
            quanLi.themGiaoDichDat(d);
            break;
        }
        case 2: {
            Nha* n = new Nha();
            n->nhap();
            quanLi.themGiaoDichNha(n);
            break;
        }
        case 3: {
            ChungCu* c = new ChungCu();
            c->nhap();
            quanLi.themGiaoDichChungCu(c);
            break;
        }
        case 4:
            quanLi.tinhTongSoLuongTungLoai();
            break;
        case 5:
            cout << "\nTrung binh thanh tien Can ho chung cu: " 
                << fixed << setprecision(0) << quanLi.trungBinhThanhTienChungCu() << " (dong)\n";
            break;
        case 6:
            quanLi.xuatNhaGiaTriCaoNhat();
            break;
        case 7:
            quanLi.xuatGiaoDichThang12Nam2024();
            break;
        case 0:
            cout << "Dang thoat chuong trinh...\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai!\n";
    }
}

int main() {
    QuanLiGiaoDich quanLi;
    int choice;

    do {
        cout << "\n================ MENU QUAN LY GIAO DICH ================\n";
        cout << "1. Them giao dich Dat\n";
        cout << "2. Them giao dich Nha pho\n";
        cout << "3. Them giao dich Can ho chung cu\n";
        cout << "4. Tinh tong so luong tung loai\n";
        cout << "5. Tinh trung binh thanh tien cua Can ho chung cu\n";
        cout << "6. Tim giao dich Nha pho co tri gia cao nhat\n";
        cout << "7. Xuat danh sach giao dich thang 12 nam 2024\n";
        cout << "0. Thoat\n";
        cout << "--------------------------------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        inLuaChon(choice, quanLi) ;
    } while (choice != 0);

    return 0;
}