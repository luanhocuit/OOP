#include <iostream>
#include "Date.h"
#include <cmath>
using namespace std ;

// Hàm check năm nhuận
bool NamNhuan(int y) {
    // Chia hết cho 4 và không chia hết cho 100 hoặc chia hết cho 400 thì là năm nhuận
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ; 
}
// Hàm trả về số ngày trong tháng m của năm y
int dayInMonth(int m, int y) {
    switch(m) {
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
            return 31 ;
        case 4 : case 6 : case 9 : case 11 :
            return 30 ;
        case 2 : 
            return NamNhuan(y) ? 29 : 28 ;
        default : 
            return 0 ;
    }
}
// Hàm constuctor mặc định (1/1/1)
cDate::cDate() {
    iNgay = 1 ;
    iThang = 1 ;
    iNam = 1 ;
} ;
// Hàm nhập vào ngày tháng năm => Nếu sai thì nhập lại
istream& operator >> (istream&in , cDate &x) {
    do {
        cout << "Nhap vao ngay thang nam (cach nhau bang khoang trang) : " ;
        in >> x.iNgay >> x.iThang >> x.iNam ;
        
        if (x.iNam < 1) { // Năm phải bắt đầu từ 1
            cout << "Nam khong hop le, vui long nhap lai ! \n" ;
            continue ;
        }

        if (x.iThang > 12 || x.iThang < 1) { // Tháng phải thuộc [1;12]
            cout << "Thang khong hop le, vui long nhap lai ! \n" ;
            continue ;
        }
        int tmp = dayInMonth(x.iThang, x.iNam) ;
        if (x.iNgay < 1 || x.iNgay > tmp) { // Ngày phải trong [1; số lượng ngày trong tháng đó]
            cout << "Ngay khong hop le, vui long nhap lai ! \n" ;
            continue ;
        }
        break ; // Lặp cho đến khi nhập đúng => break
    } while (true) ; 
    return in ;
} ;
// Hàm in ra ngày tháng năm
ostream& operator << (ostream& out, const cDate &x) {
    out << x.iNgay << '/' << x.iThang << '/' << x.iNam ;
    return out ;
}
// Hàm tính tổng số ngày 
long long cDate::convertToDays() {
    long long days = 0 ;
    // Tính số ngày của các năm trước năm x.iNam
    for (int i = 1 ; i < iNam ; i++) {
        days += NamNhuan(i) ? 366 : 365 ;
    }
    // Tính số ngày của các tháng trước tháng x.iThang
    for (int i = 1 ; i < iThang ; i++) {
        days += dayInMonth(i, iNam) ;
    }
    // Cộng thêm số ngày trong tháng x.iThang
    days += iNgay ;
    return days ;
}
// Hàm chuyển từ tổng số ngày sang ngày tháng năm
cDate ConvertToDate(long long days) {
    cDate res ;
    // Tính năm
    while(true) {
        int tmp = NamNhuan(res.iNam) ? 366 : 365 ; //  Check năm nhuận => số ngày
        if(days > tmp) { // Nếu days vẫn còn => số lượng năm tăng lên 1
            days -= tmp ;
            res.iNam++ ;
        } else {
            break ; // Nếu không thì out => đã tính được số năm
        }
    }
    // Tính tháng
    for(int i = 1 ; i <= 12 ; i++) {
        int tmp = dayInMonth(i, res.iNam) ; // Check ngày trong tháng thứ i của năm res.iNam
        if(days > tmp) { // Nếu days vẫn còn => số lượng tháng tăng lên 1
            days -= tmp ;
            res.iThang++ ;
        } else {
            break ; // Nếu không thì out => đã tính được số tháng
        }
    }
    // Tính ngày
    res.iNgay = days ; // Còn lại chính là số ngày
    return res ;
}
// Hàm cộng thêm x ngày vào ngày tháng năm ban đầu người dùng nhập
cDate operator + (cDate &a, int x) {
    long long tmp = a.convertToDays() + x ; // Tổng số ngày sau khi cộng thêm x ngày
    return ConvertToDate(tmp) ; // Trả về giá trị ngày tháng năm sau khi cộng thêm x ngày
} ;
// Hàm trừ đi x ngày vào ngày tháng năm ban đầu người dùng nhập
cDate operator - (cDate &a, int x) {
    long long tmp = a.convertToDays() - x ; // Tổng số ngày sau khi trừ đi x ngày
    return ConvertToDate(tmp) ; // Trả về giá trị ngày tháng năm sau khi trừ đi x ngày
} ;
// Hàm tính ++ (prefix) của ngày tháng năm ban đầu người dùng nhập
cDate operator ++ (cDate &a) {
    a = a + 1 ;
    return a ;
} ;
// Hàm tính ++ (postfix) của ngày tháng năm ban đầu người dùng nhập
cDate operator ++ (cDate &a, int) {
    cDate tmp = a ;
    a = a + 1 ;
    return tmp ;
} ;
// Hàm tính -- (prefix) của ngày tháng năm ban đầu người dùng nhập
cDate operator -- (cDate &a) {
    a = a - 1 ;
    return a ;
} ;
// Hàm tính -- (postfix) của ngày tháng năm ban đầu người dùng nhập
cDate operator -- (cDate &a, int) {
    cDate tmp = a ;
    a = a - 1 ;
    return tmp ;
} ;
// Hàm tính khoảng cách giữa 2 ngày a và b
long long operator - (cDate &a, cDate &b) {
    long long tmp = abs(a.convertToDays() - b.convertToDays()) ;
    return tmp ; // Trả về số ngày giữa 2 ngày a và b
} ;
// Hàm tính lãi suất đơn sau (b - a) ngày với lãi suất r%/năm
double LaiSuatDon(cDate a, cDate b, double x, double r) {
    long long tmp = b - a ; 
    // Lãi đơn = Số tiền gốc + (Số tiền gốc * lãi suất * số ngày / 365) (do tính lãi theo năm nên chia cho 365)
    return x + (x  * r / 100.0 * tmp / 365.0) ;
} ;
// Hàm tính lãi suất kép sau (b - a) ngày với lãi suất r%/năm
double LaiSuatKep(cDate a, cDate b, double x, double r) {
    double n = (b - a) / 365.0 ;
    // Lãi kép = Số tiền gốc * (1 + lãi suất)^(số năm) <số năm = số ngày / 365>
    return x * pow(1 + (r / 100), n) ;
} ;
// Hàm destructor
cDate::~cDate() {} ;