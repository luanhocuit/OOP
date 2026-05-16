#include <iostream>
#include <algorithm>
using namespace std ;

#include "PhanSo.h"

// Constructor chứa tham số => nếu khởi tạo không có tham số thì gán giá trị mặc định là tử = 0 , mẫu = 1
PS::PS(int tu, int mau) {
    iTu = tu ;
    iMau = mau ;
}

// Hàm nhập vào phân số a , nếu hợp lệ thì tiếp tục chương trình => không thì nhập lại
istream& operator >> (istream& in, PS &a) {
    while(true) {
        cout << "Nhap tu so : " ;
        in >> a.iTu ;
        if(in.fail()) { // Nếu input khác số => in.fail() : true
            in.clear() ; // Xóa nội dung đã cin vào iTu
            in.ignore(100, '\n') ; // Xóa các dòng thừa, enter thừa
            cout << "Sai roi. Ban hay nhap lai tu so.\n" ;
        }
        else break ;
    }
    while(true) {
        cout << "Nhap mau so (khac 0) : " ;
        in >> a.iMau ;
        if(in.fail() || a.iMau == 0) { // Tương tự như trên
            in.clear() ;
            in.ignore(100, '\n') ;
            cout << "Sai roi. Ban hay nhap lai mau so.\n" ;
        }
        else break ;
    }
    if (a.iMau < 0) {
        a.iTu = -a.iTu ;
        a.iMau = -a.iMau ;
    }
    return in ;
}

// Hàm in ra kết quả của phân số
ostream& operator << (ostream& out, PS a) {
    if(a.iMau == 1) cout << a.iTu; // Nếu mẫu = 1 => Chỉ in tử 
    else if(a.iTu == 0) cout << 0; // Nếu tử = 0 => in ra 0 
    else cout << a.iTu << "/" << a.iMau; // Các trường hợp còn lại thì in theo dạng tử / mẫu
    cout << '\n';
    return out ;
}

// Hàm rút gọn phân số a
void PS::rutgon() {
    if (iTu == 0) { // Nếu tử = 0 => trả về 1 
        iMau = 1 ;
        return ;
    }
    int tmp = __gcd(iTu, iMau) ; 
    // Chia tử và mẫu cho UCLN của tử và mẫu
    iTu /= tmp ;
    iMau /= tmp ;
    if(iMau < 0) { // Chuyển dấu âm lên tử
        iTu = -iTu ;
        iMau =  -iMau ;
    }
} 
// Hàm tính tổng 2 phân số
PS operator + (PS a, PS b) {
    PS res ;
    // Quy đồng 2 phân số
    res.iMau = a.iMau * b.iMau ; 
    res.iTu = a.iTu * b.iMau + b.iTu * a.iMau ;
    res.rutgon() ; // Rút gọn phân số 
    return res ;
} ;
// Hàm tính hiệu 2 phân số
PS operator - (PS a, PS b) {
    PS res ;
    // Quy đồng 2 phân số
    res.iMau = a.iMau * b.iMau ;
    res.iTu = a.iTu * b.iMau - b.iTu * a.iMau ;
    res.rutgon() ; // Rút gọn phân số
    return res ;
} ;
// Hàm tính tích của 2 phân số
PS operator * (PS a, PS b) {
    PS res ;
    res.iMau = a.iMau * b.iMau ; // Mẫu số a * mẫu số b 
    res.iTu = a.iTu * b.iTu ; // Tử số a * tử số b 
    res.rutgon() ; // Rút gọn phân số
    return res ;
} ;
// Hàm tính thương của 2 phân số
PS operator / (PS a, PS b) {
    PS res ;
    res.iMau = a.iMau * b.iTu ; // Mẫu số a * tử số b
    res.iTu = a.iTu * b.iMau ; // Tử số a * mẫu số b
    res.rutgon() ; // Rút gọn phân số
    return res ;
} ;
// Hàm so sánh bằng nhau giữa phân số a và phân số b
bool operator == (PS a, PS b) {
    return a.iTu * b.iMau == b.iTu * a.iMau ; // Quy đồng 2 phân số rồi so sánh coi bằng nhau không ? 
} ;
// Hàm so sánh phân số a lớn hơn phân số b 
bool operator > (PS a, PS b) {
    return a.iTu * b.iMau > b.iTu * a.iMau ; // Quy đồng 2 phân số rồi so sánh coi tử số của a có lớn hơn tử số của b không ? 
} ;
// Hàm so sánh phân số a bé hơn phân số b 
bool operator < (PS a, PS b) {
    return a.iTu * b.iMau < b.iTu * a.iMau ; // Quy đồng 2 phân số rồi so sánh coi tử số của a có bé hơn tử số của b không ? 
} ;
// Hàm destructor của lớp phân số
PS::~PS() {} ;