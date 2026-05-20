#include <iostream>
#include "GIaoDich.h"
using namespace std ;
// Hàm constructor mặc định của lớp giao dịch
GiaoDich::GiaoDich() {
    maGD = "" ;
    ngay = thang = nam = 1 ;
    DonGia = dientich = 0.0 ; // Gán 0.0 do kiểu dữ liệu là double (nếu để 0 thì máy phải chuyển từ int về double)
}
// Hàm destructor của lớp giao dịch
GiaoDich::~GiaoDich() {}
// Hàm check năm nhuận
bool GiaoDich::NamNhuan(int y) {
    // Chia hết cho 4 và không chia hết cho 100 hoặc chia hết cho 400 thì là năm nhuận
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ; 
}
// Hàm trả về số ngày trong tháng m của năm y
int GiaoDich::dayInMonth(int m, int y) {
    switch(m) {
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
            return 31 ;
        case 4 : case 6 : case 9 : case 11 :
            return 30 ;
        case 2 : 
            return NamNhuan(y) ? 29 : 28 ; // Nếu là năm nhuận thì 29 ngày, không thì 28 ngày
        default : 
            return 0 ;
    }
}
// Hàm nhập vào thông tin giao dịch
void GiaoDich::nhap() {
    cout << "Nhap vao ma giao dich : " ; cin >> maGD ;
    do {
        cout << "Nhap vao ngay thang nam (cach nhau bang khoang trang) : " ;
        cin >> ngay >> thang >> nam ;
        
        if (nam < 1) { // Năm phải bắt đầu từ 1
            cout << "Nam khong hop le, vui long nhap lai ! \n" ;
            continue ;
        }

        if (thang > 12 || thang < 1) { // Tháng phải thuộc [1;12]
            cout << "Thang khong hop le, vui long nhap lai ! \n" ;
            continue ;
        }
        int tmp = dayInMonth(thang, nam) ;
        if (ngay < 1 || ngay > tmp) { // Ngày phải trong [1; số lượng ngày trong tháng đó]
            cout << "Ngay khong hop le, vui long nhap lai ! \n" ;
            continue ;
        }
        break ; // Lặp cho đến khi nhập đúng => break
    } while (true) ; 
    cout << "Nhap don gia (dong) : " ; cin >> DonGia ;
    cout << "Nhap dien tich (m^2) : " ; cin >> dientich ;
}
// Hàm ỉn ra thông tin giao dịch
void GiaoDich::xuat() const {
    cout << "Ma GD : " << maGD << '\n' ;
    cout << "Ngay : " << ngay << '/' << thang << '/' << nam << '\n' ;
    cout << "Don gia : " << (long long)DonGia << "(dong)" << '\n' 
         << "Dien tich : " << dientich << "(m^2)" << '\n' ;
}
// Hàm overload toán tử >> 
istream& operator >> (istream& in, GiaoDich &x) {
    x.nhap() ; return in ;
}
// Hàm overload toán tử <<
ostream& operator << (ostream& out, GiaoDich &x) {
    x.xuat() ; return out ;
}
// Hàm get tháng
int GiaoDich::getThang() const { 
    return thang ; 
}
// Hàm get năm
int GiaoDich::getNam() const { 
    return nam ; 
}


// Hàm constructor mặc định của lớp đất
Dat::Dat() : GiaoDich() { // : GiaoDich() => khởi tạo constructor của lớp giao dịch trước rồi mới khởi tạo constructor của lớp đất
    type = 'X' ; 
}
// Hàm destructor của lớp đất
Dat::~Dat() {} 

// Hàm nhập vào thông tin giao dịch đất
void Dat::nhap() {
    GiaoDich::nhap() ; // Gọi hàm này để nhập thông tin giao dịch
    // Các câu lệnh bên dưới để nhập thêm thông tin bổ sung để giao dịch trở thành giao dịch đất
    do {
        cout << "Nhap loai dat (A, B, C) : " ; cin >> type ;
    } while (type != 'A' && type != 'B' && type != 'C') ; // Nếu nhập không đúng => nhập lại
}
// Hàm in ra thông tin giao dịch đất
void Dat::xuat() const {
    GiaoDich::xuat() ; // Gọi hàm này để in ra các thông tin giao dịch
    // Các câu lệnh bên dưới để in thêm các thông tin bổ sung để giao dịch trở thành giao dịch đất
    cout << "Loai dat : " << type << '\n' ;
}
// Hàm tính tổng tiền của giao dịch đất
double Dat::TotalMoney() const {
    if (type == 'B' || type == 'C') return dientich * DonGia ; // Nếu loại B hoặc C => Tiền = Diện tích * Đơn giá
    return dientich * DonGia * 1.5 ; // Nếu là loại A => Tiền = Diện tích * Đơn giá * 1.5
}



// Hàm constructor mặc định của lớp nhà
Nha::Nha() : GiaoDich() {// : GiaoDich() => khởi tạo constructor của lớp giao dịch trước rồi mới khởi tạo constructor của lớp nhà
    loainha = diachi = "" ;
}
// Hàm destructor của lớp nhà
Nha::~Nha() {}
// Hàm nhập vào thông tin giao dịch nhà
void Nha::nhap() {
    GiaoDich::nhap() ;// Gọi hàm này để nhập thông tin giao dịch
    // Các câu lệnh bên dưới để nhập thêm thông tin bổ sung để giao dịch trở thành giao dịch nhà
    do {
        cout << "Nhap loai nha (caocap, thuong) : " ; cin >> loainha ;
    } while (loainha != "caocap" && loainha != "thuong") ; // Nếu nhập không đúng => nhập lại
    cin.ignore() ;
    cout << "Nhap dia chi : " ; getline(cin, diachi) ;
}
// Hàm in ra thông tin giao dịch nhà
void Nha::xuat() const {
    GiaoDich::xuat() ;// Gọi hàm này để in ra các thông tin giao dịch
    // Các câu lệnh bên dưới để in thêm các thông tin bổ sung để giao dịch trở thành giao dịch nhà
    cout << "Loai nha : " << loainha << '\n' ;
    cout << "Dia chi : " << diachi << '\n' ;
}
// Hàm tính tổng tiền giao dịch nhà
double Nha::TotalMoney() const {
    if (loainha == "caocap") return dientich * DonGia ; // Nếu là loại cao cấp => Tiền = Diện tích * Đơn giá
    return dientich * DonGia * 0.9 ; // Nếu là loại thường => Tiền = Diện tích * Đơn giá * 90%
}



// Hàm constructor mặc định của lớp chung cư
ChungCu::ChungCu() : GiaoDich() {// : GiaoDich() => khởi tạo constructor của lớp giao dịch trước rồi mới khởi tạo constructor của lớp chung cư
    maCan = "" ;
    vitriTang = 0 ;
}
// Hàm destructor của lớp chung cư
ChungCu::~ChungCu() {}
// Hàm nhập vào thông tin giao dịch chung cư
void ChungCu::nhap() {
    GiaoDich::nhap() ;// Gọi hàm này để nhập thông tin giao dịch
    // Các câu lệnh bên dưới để nhập thêm thông tin bổ sung để giao dịch trở thành giao dịch chung cư
    cout << "Nhap ma can ho : " ; cin >> maCan ;
    do {
        cout << "Nhap vi tri tang : " ; cin >> vitriTang ;
    } while (vitriTang <= 0) ; // Nếu vị trí tầng <= 0 => nhập lại

}
// Hàm in ra thông tin giao dịch chung cư
void ChungCu::xuat() const {
    GiaoDich::xuat() ;// Gọi hàm này để in ra các thông tin giao dịch
    // Các câu lệnh bên dưới để in thêm các thông tin bổ sung để giao dịch trở thành giao dịch chung cư
    cout << "Ma can ho : " << maCan << '\n' ;
    cout << "Vi tri tang : " << vitriTang << '\n' ;
}
// Hàm tính tổng tiền giao dịch chung cư
double ChungCu::TotalMoney() const {
    if(vitriTang == 1) return dientich * DonGia * 2 ; // Nếu ở tầng 1 => Tiền = Diện tích * Đơn giá * 2
    else if (vitriTang >= 15) return dientich * DonGia * 1.2 ; // Nếu ở tầng 15 trở lên => Tiền = Diện tích * Đơn giá * 1.2
    return dientich * DonGia ; // Các tầng còn lại => Tiền = Diện tích * Đơn giá
}