#include <iostream>
#include <string>
#include "NhanVien.h"
using namespace std ;

// Hàm constructor của lớp nhân viên
NhanVien::NhanVien() {
    ma = hoten = sdt = email = "" ;
    tuoi = 0 ; luongcoban = 0.0 ;
}
// Hàm destructor của lớp nhân viên
NhanVien::~NhanVien() {}
// Hàm nhập thông tin của nhân viên
void NhanVien::nhap() {
    cout << "Nhap ma nhan vien : " ; cin >> ma ;
    cin.ignore() ; // Bỏ qua '\n' để sử dụng getline
    cout << "Nhap ho ten : " ; getline(cin, hoten) ;
    cout << "Nhap sdt : " ; cin >> sdt ;
    cout << "Nhap email : " ; cin >> email ;
    cout << "Nhap so tuoi : " ; cin >> tuoi ;
    cout << "Nhap luong co ban (dong) : " ; cin >> luongcoban ;
}
// Hàm in ra thông tin của nhân viên
void NhanVien::xuat() const {
    cout << ma << '\t' << hoten << '\t' << sdt << '\t' << email << '\t' 
         << tuoi << '\t' << luongcoban << '\t' ;
}
// Hàm overload toán tử >> cho lớp nhân viên
istream& operator >> (istream& in, NhanVien &x) {
    x.nhap() ; return in ;
}
// Hàm overload toán tử << cho lớp nhân viên
ostream& operator << (ostream& out, NhanVien&x) {
    x.xuat() ; return out ;
}
// Hàm get họ tên của nhân viên
string NhanVien::getHoTen() const {
    return hoten ;
};
// Hàm get mã nhân viên
string NhanVien::getMa() const {
    return ma ;
};


// Hàm constructor của lớp lập trình viên
LapTrinhVien::LapTrinhVien() : NhanVien() {
    // : NhanVien() có nghĩa là gọi constructor của lớp nhân viên trước rồi mới gọi constructor của lớp lập trình viên
    SoGioOvertime = 0 ;
}
// Hàm destructor của lớp lập trình viên
LapTrinhVien::~LapTrinhVien() {} 
// Hàm nhập vào thông tin của lập trình viên
void LapTrinhVien::nhap() {
    NhanVien::nhap() ; // Nhập thông tin chung của nhân viên rồi mới nhập thông tin cần thiết để trở thành lập trình viên
    cout << "Nhap so gio overtime : " ; cin >> SoGioOvertime ;
}
// Hàm tính lương của lập trình viên
double LapTrinhVien::tinhLuong() const {
    return luongcoban + SoGioOvertime * 200000;
}
// Hàm in ra thông tin của lập trình viên
void LapTrinhVien::xuat() const {
    NhanVien::xuat() ;
    cout << SoGioOvertime << '\t' << tinhLuong() << '\n' ;
}


// Hàm constructor của lớp kiểm chứng viên
KiemChungVien::KiemChungVien() : NhanVien() {
    // : NhanVien() có nghĩa là gọi constructor của lớp nhân viên trước rồi mới gọi constructor của lớp kiểm chứng viên
    SoLoiPhatHien = 0 ;
}
// Hàm destructor của lớp kiểm chứng viên
KiemChungVien::~KiemChungVien() {}
// Hàm nhập thông tin của kiểm chứng viên
void KiemChungVien::nhap() {
    NhanVien::nhap() ; // Nhập vào thông tin của nhân viên trước rồi nhập thêm các thông tin để thành kiểm chứng viên
    cout << "Nhap so loi da phat hien duoc : " ; cin >> SoLoiPhatHien ;
}
// Hàm tính lương của kiểm chứng viên
double KiemChungVien::tinhLuong() const {
    return luongcoban + SoLoiPhatHien * 50000 ;
}
// Hàm in ra thông tin của kiểm chứng viên
void KiemChungVien::xuat() const {
    NhanVien::xuat() ; // In ra thông tin chung của nhân viên trước rồi in thêm thông tin chi tiết của kiểm chứng viên
    cout << SoLoiPhatHien << '\t' << tinhLuong() << '\n' ;
}