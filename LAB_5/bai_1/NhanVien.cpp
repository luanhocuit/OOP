#include <iostream>
#include "NhanVien.h"

using namespace std;
// Hàm constructor mặc định
NhanVien::NhanVien() {
    hoTen = "";
    ngay = thang = nam = 0;
}
// Hàm destructor
NhanVien::~NhanVien() {} ;

// Hàm nhập thông tin nhân viên
void NhanVien::nhap() {
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    cin >> ngay >> thang >> nam;
}
// Hàm xuất thông tin nhân viên
void NhanVien::xuat() const {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
}
// Hàm overload nhập thông tin nhân viên
istream& operator >> (istream& in, NhanVien& nv) {
    nv.nhap();
    return in;
}
// Hàm overload xuất thông tin nhân viên
ostream& operator << (ostream& out, const NhanVien& nv) {
    nv.xuat();
    return out;
}
// Hàm tính lương mặc định (có thể được override trong lớp con)
double NhanVien::tinhLuong() const {
    return 0.0; // Mặc định trả về 0, lớp con sẽ override
}


// Hàm lấy năm sinh
int NhanVien::getNam() const { return nam; }
// Hàm lấy tháng sinh
int NhanVien::getThang() const { return thang; }
// Hàm lấy ngày sinh
int NhanVien::getNgay() const { return ngay; }


// Hàm constructor mặc định cho NhanVienSanXuat
NhanVienSanXuat::NhanVienSanXuat() : NhanVien() { // : NhanVien() => Khởi tạo constructor của lớp nhân viên trước rồi mới khởi tạo constructor của nhân viên sản xuất
    soSanPham = 0;
    luongcoban = 0.0;
}
// Hàm destructor cho NhanVienSanXuat
NhanVienSanXuat::~NhanVienSanXuat() {} ;
// Hàm nhập thông tin nhân viên sản xuất
void NhanVienSanXuat::nhap() {
    NhanVien::nhap(); // Gọi hàm nhập của lớp cha
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    cout << "Nhap luong co ban: ";
    cin >> luongcoban;
}
// Hàm xuất thông tin nhân viên sản xuất
void NhanVienSanXuat::xuat() const {
    NhanVien::xuat(); // Gọi hàm xuất của lớp cha
    cout << "So san pham: " << soSanPham << endl;
    cout << "Luong co ban: " << luongcoban << endl;
}
// Hàm tính lương cho nhân viên sản xuất
double NhanVienSanXuat::tinhLuong() const {
    return luongcoban + soSanPham * 5000 ; // Lương = lương cơ bản + số sản phẩm * 5000
}


// Hàm constructor mặc định cho NhanVienVanPhong
NhanVienVanPhong::NhanVienVanPhong() : NhanVien() { // : NhanVien() => Khởi tạo constructor của lớp nhân viên trước rồi mới khởi tạo constructor của nhân viên văn phòng
    songayLamViec = 0;
}
// Hàm destructor cho NhanVienVanPhong
NhanVienVanPhong::~NhanVienVanPhong() {} ;
// Hàm nhập thông tin nhân viên văn phòng
void NhanVienVanPhong::nhap() {
    NhanVien::nhap(); // Gọi hàm nhập của lớp cha
    cout << "Nhap so ngay lam viec: ";
    cin >> songayLamViec;
}
// Hàm xuất thông tin nhân viên văn phòng
void NhanVienVanPhong::xuat() const {
    NhanVien::xuat(); // Gọi hàm xuất của lớp cha
    cout << "So ngay lam viec: " << songayLamViec << endl;
}
// Hàm tính lương cho nhân viên văn phòng
double NhanVienVanPhong::tinhLuong() const {
    return songayLamViec * 100000; // Lương = số ngày làm việc * 100000
}

