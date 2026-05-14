#include <iostream>

using namespace std ;

#include "Vector.h"

// Hàm constructor mặc định
Vector::Vector() {
    sochieu = 0 ;
    heso = NULL ;
}
// Hàm copy constructor
Vector::Vector(const Vector &x) {
    sochieu = x.sochieu ;
    if (sochieu > 0) {
        heso = new double[sochieu] ; // Cấp phát mảng động
        for (int i = 0 ; i < sochieu ; i++) {
            heso[i] = x.heso[i] ; // Sao chép từng hệ số
        }
    } else {
        heso = NULL ;
    }
}
// Hàm gán
Vector& Vector::operator = (const Vector &x) {
    if (this != &x) { // Kiểm tra tự gán (nếu v1 = v1 thì k cần gán lại => return *this luôn)
        if (heso != NULL) {
            delete[] heso ; // Xóa mảng động hiện tại
        }
        sochieu = x.sochieu ;
        if (sochieu > 0) {
            heso = new double[sochieu] ; // Cấp phát mảng động
            for (int i = 0 ; i < sochieu ; i++) {
                heso[i] = x.heso[i] ; // Sao chép từng hệ số
            }
        } else {
            heso = NULL ;
        }
    }
    return *this ;
}
// Hàm destructor
Vector::~Vector() {
    if (heso != NULL) {
        delete[] heso ; // Xóa mảng động
    }
}
// Hàm vào vector
istream& operator >> (istream& in, Vector &x) {
    cout << "Nhap so chieu : " ; in >> x.sochieu ;
    x.heso = new double[x.sochieu] ; // Cấp phát mảng động
    cout << "Nhap cac he so : " ;
    for (int i = 0 ; i < x.sochieu ; i++) {
        in >> x.heso[i] ; // Nhập hệ số
    }
    return in ;
}
// Hàm in ra vector
ostream& operator << (ostream& out, const Vector &x) {
    out << "(" ;
    for (int i = 0 ; i < x.sochieu ; i++) {
        out << x.heso[i] ; // In hệ số
        if(i < x.sochieu - 1) {
            out << ", " ; // In dấu phẩy giữa các hệ số
        }
    }
    out << ")" << '\n' ;
    return out ;
}
// Hàm cộng hai vector
Vector operator + (Vector a, Vector b) {
    Vector c ;
    if (a.sochieu != b.sochieu) { // Số chiều khác nhau => không thể cộng
        cout << "Khong the cong hai vector khac chieu" << '\n';
        return c ; // Trả về vector rỗng
    }
    c.sochieu = a.sochieu ;
    c.heso = new double[c.sochieu] ; // Cấp phát mảng động cho vector kết quả
    for (int i = 0 ; i < c.sochieu ; i++) {
        c.heso[i] = a.heso[i] + b.heso[i] ; // Cộng từng hệ số
    }
    return c ;
}
// Hàm trừ hai vector
Vector operator - (Vector a, Vector b) {
    Vector c ;
    if (a.sochieu != b.sochieu) { // Số chiều khác nhau => không thể trừ
        cout << "Khong the tru hai vector khac chieu" << '\n';
        return c ; // Trả về vector rỗng
    }
    c.sochieu = a.sochieu ;
    c.heso = new double[c.sochieu] ; // Cấp phát mảng động cho vector kết quả
    for (int i = 0 ; i < c.sochieu ; i++) {
        c.heso[i] = a.heso[i] - b.heso[i] ; // Trừ từng hệ số
    }
    return c ;
}
// Hàm nhân vector với một số thực
Vector operator * (Vector a, double x) {
    Vector c ;
    c.sochieu = a.sochieu ;
    c.heso = new double[c.sochieu] ; // Cấp phát mảng động cho vector kết quả
    for (int i = 0 ; i < c.sochieu ; i++) {
        c.heso[i] = a.heso[i] * x ; // Nhân từng hệ số với x
    }
    return c ;
}
// Hàm nhân hai vector (tích vô hướng)
double operator * (Vector a, Vector b) {
    if (a.sochieu != b.sochieu) { // Số chiều khác nhau => không thể nhân
        cout << "Khong the nhan hai vector khac chieu" << '\n';
        return 0 ; // Trả về 0
    }
    double tich = 0 ;
    for (int i = 0 ; i < a.sochieu ; i++) {
        tich += a.heso[i] * b.heso[i] ; // Cộng tích của từng hệ số
    }
    return tich ;
}
