#include <iostream>

using namespace std ;

// Xây dựng struct chứ họ tên, điểm toán và điểm văn của học sinh
struct HS {
    string hoten ;
    double toan, van ;
} ;

// Hầm nhập dữ liệu cho học sinh
void nhap(HS &a) {
    cout << "Nhap vao ho ten : " ;
    getline(cin, a.hoten) ;
    cout << "Nhap vao diem toan va diem van (cach nhau boi khoang trang) : " ;
    cin >> a.toan >> a.van ;
}

// Hàm in ra dữ liệu của học sinh
void xuat(HS &a) {
    double tb = (a.toan + a.van) / 2 ;
    cout << "Ho ten : " << a.hoten << '\n' ;
    cout << "Diem trung binh : " << tb ; 
}

int main () {
    HS a ;
    nhap(a) ;
    xuat(a) ;
    return 0 ;
}