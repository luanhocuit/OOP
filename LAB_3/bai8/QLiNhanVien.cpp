#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

#include "QLiNhanVien.h"

// Phương thức Constructor
QLiNhanVien::QLiNhanVien() {
    n = 0;
    ds = NULL;
}

// Phương thức Destructor
QLiNhanVien::~QLiNhanVien() {
    delete[] ds;
}

// Hàm nhập
void QLiNhanVien::nhap() {
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    ds = new cNhanVien[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap nhan vien thu " << i + 1 << " : \n";
        cin >> ds[i];
    }
}

// Hàm xuất
void QLiNhanVien::xuat() {
    cout << "MaNV\tHoTen\tNgaySinh\tSP\tDonGia\tLuong\n";
    for (int i = 0; i < n; i++) {
        cout << ds[i];
    }
}

// Hàm tính tổng lương
double QLiNhanVien::tongLuong() {
    double tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].luong();
    }
    return tong;
}

// Hàm tìm nhân viên có lương thấp nhất
cNhanVien QLiNhanVien::luongThapNhat() {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].luong() < ds[idx].luong()) {
            idx = i;
        }
    }
    return ds[idx];
}

// Hàm tìm nhân viên có tuổi cao nhất 
cNhanVien QLiNhanVien::tuoiCaoNhat() {
    int idx = 0;

    for (int i = 1; i < n; i++) {
        // Tách ra thành ngày tháng năm bằng stringstream
        int d1, m1, y1; 
        int d2, m2, y2;
        char c;

        stringstream ss1(ds[i].getNgaysinh());
        ss1 >> d1 >> c >> m1 >> c >> y1 ; // Dùng c để chứa '/'
        stringstream ss2(ds[idx].getNgaysinh());
        ss2 >> d2 >> c >> m2 >> c >> y2; // Dùng c để chứa '/'

        // Sắp theo năm, cùng năm thì xét tháng, cùng năm và tháng thì xét ngày
        if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2)) {
            idx = i;
        }
    }
    return ds[idx];
}

// Hàm sắp xếp tăng dần theo lương
void QLiNhanVien::sapXepLuongTangDan() {
    sort(ds, ds + n, [](cNhanVien a, cNhanVien b) {
        return a.luong() < b.luong();
    });
}