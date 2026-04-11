#include <iostream>

using namespace std ;

#include "Diem.h"

Diem::Diem() {
    x = 0, y = 0 ;
}

Diem::Diem(double a, double b) {
    x = a ; // Gán tham số a vào x
    y = b ; // Gán tham số b vào y
}

// Nhập vào tọa độ (x, y)
void Diem::Nhap() {
    cout << "Nhap vao toa do x, y : " ;
    cin >> x >> y ;
}

// Xuất ra màn hình tọa độ (x, y)
void Diem::Xuat() {
    cout << "Day la toa do cua diem : (" << x << ", " << y << ")";
}

// Khai báo destructor
Diem::~Diem() {} ;