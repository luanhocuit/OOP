#include <iostream>
#include <string>
#include "SinhVien.h"
using namespace std ;

// Hàm constructor của lớp sinh viên 
SinhVien::SinhVien() {
    maso = hoten = "" ;
    tinchi = 0 ; dtb = 0.0 ; // Gán 0.0 để cho máy không cần phải chuyển từ 0 (int) thành double lại
}
// Hàm destructor của lớp sinh viên
SinhVien::~SinhVien() {} ;

// Hàm nhập vào thông tin của sinh viên
void SinhVien::nhap() {
    cout << "Nhap ma so sinh vien : " ; cin >> maso ;
    cin.ignore() ; // Bỏ qua '\n' để có thể dùng getline
    cout << "Nhap ho va ten : " ; getline(cin, hoten) ;
    cout << "Nhap so tin chi da hoc : " ; cin >> tinchi ;
    cout << "Nhap diem trung binh : " ; cin >> dtb ; 
}
// Hàm in ra thông tin của sinh viên
void SinhVien::xuat() const {
    cout << maso << '\t' << hoten << '\t' << '\t' << tinchi << '\t' << dtb << '\t' ;
}
// Hàm overload toán tử >> của lớp sinh viên
istream& operator >> (istream& in, SinhVien &x) {
    x.nhap() ; return in ;
}
// Hàm overload toán tử << của lớp sinh viên
ostream& operator << (ostream &out, SinhVien &x) {
    x.xuat() ; return out ;
}
// Hàm get điểm trung bình của sinh viên
double SinhVien::getDTB() const {
    return dtb ;
}


// Hàm constructor của lớp sinh viên cao đẳng
CaoDang::CaoDang() : SinhVien() { 
    // : SinhVien() có nghĩa là gọi constructor của lớp sinh viên trước rồi 
    // mới gán tiếp các giá trị được định nghĩa trong lớp constructor của lớp sinh viên cao đẳng
    diachi = "" ; diemthitotnghiep = 0.0 ;
}
// Hàm destructor của lớp sinh viên cao đẳng
CaoDang::~CaoDang() {} 

// Hàm nhập thông tin của sinh viên cao đẳng
void CaoDang::nhap() {
    SinhVien::nhap() ; // Nhập thông tin chung của sinh viên rồi mới nhập thông tin cần có của sinh viên cao đẳng
    cin.ignore() ;
    cout << "Nhap dia chi : " ; getline(cin, diachi) ;
    cout << "Nhap diem thi tot nghiem : " ; cin >> diemthitotnghiep ;
}
// Hàm in ra thông tin của sinh viên cao đẳng
void CaoDang::xuat() const {
    SinhVien::xuat() ; // In ra thông tin chung của sinh viên rồi mới in thông tin chi tiết của sinh viên cao đẳng
    cout << diachi << '\t' << diemthitotnghiep << '\n' ;
}
// Hàm check sinh viên cao đẳng đó có đủ điều kiện để tốt nghiệp không 
bool CaoDang::totnghiep() const {
    return (tinchi >= 120) && (dtb >= 5) && (diemthitotnghiep >= 5) ;
}


// Hàm constructor của lớp sinh viên đại học 
DaiHoc::DaiHoc() : SinhVien() {
    // : SinhVien() có nghĩa là gọi constructor của lớp sinh viên trước rồi 
    // mới gán tiếp các giá trị được định nghĩa trong lớp constructor của lớp sinh viên đại học
    tenluanvan = "" ; diemluanvan = 0.0 ;
}
// Hàm destructor của lớp sinh viên đại học
DaiHoc::~DaiHoc() {} 

// Hàm nhập thông tin của sinh viên đại học
void DaiHoc::nhap() {
    SinhVien::nhap() ; // Nhập thông tin chung của sinh viên rồi mới nhập thông tin cần có của sinh viên đại học
    cin.ignore() ;
    cout << "Nhap ten de tai luan van : " ; getline(cin, tenluanvan) ;
    cout << "Nhap diem luan van : " ; cin >> diemluanvan ;
}
// Hàm in ra thông tin của sinh viên đại học
void DaiHoc::xuat() const {
    SinhVien::xuat() ; // In ra thông tin cơ bản của sinh viên rồi mới in ra thông tin chi tiết của sinh viên đại học
    cout << tenluanvan << '\t' << diemluanvan << '\n' ;
}
// Hàm check sinh viên đại học đó có đủ điều kiện để tốt nghiệp không
bool DaiHoc::totnghiep() const {
    return (tinchi >= 170) && (dtb >= 5) && (diemluanvan >= 5) ;
}