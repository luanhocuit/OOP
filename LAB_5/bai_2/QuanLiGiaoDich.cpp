#include "QuanLiGiaoDich.h"
#include <iostream>
#include <iomanip>

using namespace std ;
// Hàm constructor cho lớp quản lí giao dịch
QuanLiGiaoDich::QuanLiGiaoDich() {
    for (auto &x : dsDat) x = nullptr ;
    for (auto &x : dsNha) x = nullptr ;
    for (auto &x : dsChungCu) x = nullptr ;
}

// Hàm destructor của lớp quản lí giao dịch
QuanLiGiaoDich::~QuanLiGiaoDich() {
    // Vì khai báo là con trỏ nên phải xóa (tương tự như việc cấp phát động)
    for (auto x : dsDat) delete x ; // Xóa từng giao dịch đất trong danh sách giao dịch đất
    for (auto x : dsNha) delete x ; // Xóa từng giao dịch nhà trong danh sách giao dịch nhà
    for (auto x : dsChungCu) delete x ; // Xóa từng giao dịch chung cư trong danh sách giao dịch chung cư
    dsDat.clear(); // Xóa vector chứa danh sách giao dịch đất
    dsNha.clear(); // Xóa vector chứa danh sách giao dịch nhà
    dsChungCu.clear(); // Xóa vector chứa danh sách giao dịch chung cư
}
// Hàm thêm giao dịch đất vào danh sách
void QuanLiGiaoDich::themGiaoDichDat(Dat* d) { 
    if (d) dsDat.push_back(d) ; // Nếu d != null (d có tồn tại) => thêm vào danh sách
}
// Hàm thêm giao dịch nhà vào danh sách
void QuanLiGiaoDich::themGiaoDichNha(Nha* n) { 
    if (n) dsNha.push_back(n) ; // Nếu n != null (n có tồn tại) => thêm vào danh sách
}
// Hàm thêm giao dịch chung cư vào danh sách
void QuanLiGiaoDich::themGiaoDichChungCu(ChungCu* c) { 
    if (c) dsChungCu.push_back(c) ; // Nếu c != null (c có tồn tại) => thêm vào danh sách
}

// Hàm in ra tổng số lượng từng loại
void QuanLiGiaoDich::tinhTongSoLuongTungLoai() const {
    cout << "TONG SO LUONG GIAO DICH \n" ;
    cout << "1. Giao dich Dat: " << dsDat.size() << '\n' ;
    cout << "2. Giao dich Nha: " << dsNha.size() << '\n' ;
    cout << "3. Giao dich Chung cu: " << dsChungCu.size() << '\n' ;
}

// Hàm tính tổng tiền giao dịch
double QuanLiGiaoDich::tinhTongTienTatCa() const {
    double tong = 0;
    for (auto x : dsDat) tong += x->TotalMoney();
    for (auto x : dsNha) tong += x->TotalMoney();
    for (auto x : dsChungCu) tong += x->TotalMoney();
    return tong;
}

// Hàm tính trung bình thành tiền của lớp Chung cư
double QuanLiGiaoDich::trungBinhThanhTienChungCu() const {
    if (dsChungCu.empty()) return 0;
    double tong = 0;
    for (auto x : dsChungCu) {
        tong += x->TotalMoney();
    }
    return tong / dsChungCu.size(); // tổng tiền chia cho số lượng giao dịch chung cư
}

// Hàm tính Giao dịch nhà có giá trị cao nhất
void QuanLiGiaoDich::xuatNhaGiaTriCaoNhat() const {
    if (dsNha.empty()) { // Nếu danh sách chứa giao dịch nhà rỗng => in ra không có giao dịch nào
        cout << "Khong co giao dich nha nao." << endl;
        return;
    }
    Nha* maxNha = dsNha[0] ; // Khởi tạo biến maxNha để tìm giao dịch nhà có giá trị cao nhất
    for (int i = 1; i < dsNha.size(); ++i) {
        if (dsNha[i]->TotalMoney() > maxNha->TotalMoney()) { // Nếu thành tiền hiện tại lớn hơn biến maxNha
            maxNha = dsNha[i]; // Cập nhật maxNha
        }
    }
    cout << "GIAO DICH NHA CO GIA TRI CAO NHAT\n" ;
    maxNha->xuat() ;
    cout << "=> Thanh tien: " << fixed << setprecision(0) << (long long)maxNha->TotalMoney() << " (dong)" << '\n' ;
}

// Hàm xuất các giao dịch trong tháng 12/2024 (nếu có)
void QuanLiGiaoDich::xuatGiaoDichThang12Nam2024() const {
    cout << "DANH SACH GIAO DICH THANG 12/2024\n";
    bool found = false;
    // Duyệt qua danh sách Đất => check coi có giao dịch vào tháng 12/2024 ?
    for (auto &x : dsDat) {
        if (x->getThang() == 12 && x->getNam() == 2024) {
            x->xuat();
            cout << "Thanh tien: " << fixed << setprecision(0) << x->TotalMoney() << '\n' ;
            found = true;
        }
    }
    // Duyệt qua danh sách Nhà => check coi có giao dịch vào tháng 12/2024 ?
    for (auto &x : dsNha) {
        if (x->getThang() == 12 && x->getNam() == 2024) {
            x->xuat();
            cout << "Thanh tien: " << fixed << setprecision(0) << x->TotalMoney() << '\n' ;
            found = true;
        }
    }
    // Duyệt qua danh sách Chung cư => check coi có giao dịch vào tháng 12/2024 ?
    for (auto x : dsChungCu) {
        if (x->getThang() == 12 && x->getNam() == 2024) {
            x->xuat();
            cout << "Thanh tien: " << fixed << setprecision(0) << x->TotalMoney() << '\n' ;
            found = true;
        }
    }
    // Kiểm tra xem có tìm thấy giao dịch nào không (nghĩa là biến found vẫn là false và chưa có vòng lặp nào thỏa)
    if (!found) {
        cout << "Khong co giao dich nao trong thoi gian nay." << '\n' ;
    }
}