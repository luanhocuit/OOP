#include <iostream>
using namespace std;

#include "QLiNhanVien.h"

int main() {
    QLiNhanVien nv;
    nv.nhap();
    cout << "=== KET QUA === \n" ;
    cout << "DANH SACH NHAN VIEN : \n";
    nv.xuat();
    cout << "Tong luong cong ty phai tra : " << nv.tongLuong() << endl;

    cNhanVien minNV = nv.luongThapNhat();
    cout << "Nhan vien co luong thap nhat : " << minNV.getMaNV() << " " << minNV.getHoten() << endl;

    cNhanVien maxAgeNV = nv.tuoiCaoNhat();
    cout << "Nhan vien tuoi cao nhat : " << maxAgeNV.getMaNV() << " " << maxAgeNV.getHoten() << endl;

    nv.sapXepLuongTangDan();
    cout << "Danh sach sau khi sap xep theo luong tang dan : \n";
    nv.xuat();
    return 0;
}