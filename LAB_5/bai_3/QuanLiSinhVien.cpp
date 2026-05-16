#include <iostream>
#include "QuanLiSinhVien.h"

using namespace std ;

// Hàm constructor của lớp quản lí sinh viên
QuanLiSinhVien::QuanLiSinhVien() {}
// Hàm destructor của lớp quản lí sinh viên
QuanLiSinhVien::~QuanLiSinhVien() {
    // Do dùng con trỏ nên chúng ta phải duyệt từng danh sách rồi xóa từng phần tử
    for (auto p : dsCaoDang) delete p; // Xóa từng sinh viên cao đẳng trong danh sách
    for (auto p : dsDaiHoc) delete p; // Xóa từng sinh viên đại học trong danh sách
}
// Hàm nhập và thêm 1 sinh viên cao đẳng vào danh sách sinh viên cao đẳng
void QuanLiSinhVien::themCaoDang() {
    CaoDang* p = new CaoDang(); // Tạo con trỏ p trỏ tới sinh viên cao đẳng được cấp phát động
    p->nhap(); // Nhập thông tin của sinh viên cao đẳng
    dsCaoDang.push_back(p); // Đưa thông tin của sinh viên đó vào danh sách sinh viên cao đẳng
}
// Hàm nhập và thêm 1 sinh viên đại học vào danh sách sinh viên đại học
void QuanLiSinhVien::themDaiHoc() {
    DaiHoc* p = new DaiHoc(); // Tạo con trỏ p trỏ tới sinh viên đại học được cấp phát động
    p->nhap(); // Nhập thông tin của sinh viên đại học
    dsDaiHoc.push_back(p); // Đưa thông tin của sinh viên đó vào danh sách sinh viên đại học
}

// Hàm in ra thông tin của các sinh viên (từ cao đẳng đến đại học)
void QuanLiSinhVien::xuatTatCa() const {
    cout << "DANH SACH TAT CA SINH VIEN\n";
    for (auto p : dsCaoDang) p->xuat();
    for (auto p : dsDaiHoc) p->xuat();
}
// Hàm in các ra sinh viên đủ điều kiện tốt nghiệp
void QuanLiSinhVien::xuatSVTotNghiep() const {
    cout << "SINH VIEN DU DIEU KIEN TOT NGHIEP\n";
    cout << "SINH VIEN CAO DANG : \n";
    for (auto p : dsCaoDang) if (p->totnghiep()) p->xuat();
    cout << "SINH VIEN DAI HOC : \n";
    for (auto p : dsDaiHoc) if (p->totnghiep()) p->xuat();
}
// Hàm in các ra sinh viên không đủ điều kiện tốt nghiệp
void QuanLiSinhVien::xuatSVKhongTotNghiep() const {
    cout << "SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP\n";
    cout << "SINH VIEN CAO DANG : \n";
    for (auto p : dsCaoDang) if (!p->totnghiep()) p->xuat();
    cout << "SINH VIEN DAI HOC : \n";
    for (auto p : dsDaiHoc) if (!p->totnghiep()) p->xuat();
}
// Hàm in ra sinh viên đại học có điểm trung bình cao nhất
void QuanLiSinhVien::timMaxDaiHoc() const {
    if (dsDaiHoc.empty()) { 
        cout << "Danh sach sinh vien Dai Hoc rong.\n"; 
        return ; 
    }
    DaiHoc* maxSV = dsDaiHoc[0]; // Đặt sinh viên đầu tiên vào biến maxSV để so sánh
    for (auto p : dsDaiHoc) {
        if (p->getDTB() > maxSV->getDTB()) { // Nếu điểm trung bình của sinh viên hiện tại > điểm trung bình của sinh viên ở biến maxSV
            maxSV = p ; // Cập nhật lại sinh viên có điểm trung bình cao hơn
        }
    } ;
    cout << "SV Dai Hoc co DTB cao nhat: "; maxSV->xuat();
}
// Hàm in ra sinh viên cao đẳng có điểm trung bình cao nhất
void QuanLiSinhVien::timMaxCaoDang() const {
    if (dsCaoDang.empty()) { 
        cout << "Danh sach sinh vien Cao Dang rong.\n" ; 
        return ; 
    }
    CaoDang* maxSV = dsCaoDang[0];
    for (auto p : dsCaoDang) {
        if (p->getDTB() > maxSV->getDTB()) { // Nếu điểm trung bình của sinh viên hiện tại > điểm trung bình của sinh viên ở biến maxSV
            maxSV = p; // Cập nhật lại sinh viên có điểm trung bình cao hơn
        }
    }
    cout << "SV Cao Dang co DTB cao nhat: "; maxSV->xuat();
}
// Hàm ỉn ra số lượng sinh viên không đủ điều kiện tốt nghiệp
void QuanLiSinhVien::thongKeKhongTotNghiep() const {
    int countCD = 0, countDH = 0;
    for (auto p : dsCaoDang) {
        if (!p->totnghiep()) countCD++;
    }
    for (auto p : dsDaiHoc) {
        if (!p->totnghiep()) countDH++;
    }
    cout << "Thong ke SV KHONG tot nghiep :\n";
    cout << "- Cao Dang : " << countCD << " sinh vien\n" 
         << "- Dai Hoc : " << countDH << " sinh vien\n";
}