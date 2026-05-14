#include <iostream>
#include "Time.h"

using namespace std ;

// Hàm constructor mặc định của lớp Time
cTime::cTime() {
    iGio = 0;
    iPhut = 0;
    iGiay = 0;
}

// Hàm nhập vào thời gian => Nếu sai thì nhập lại
istream& operator >> (istream& in, cTime &a) {
    do {
        cout << "Nhap gio (0-23): ";
        in >> a.iGio;
    } while (a.iGio < 0 || a.iGio > 23);

    do {
        cout << "Nhap phut (0-59): ";
        in >> a.iPhut;
    } while (a.iPhut < 0 || a.iPhut > 59);

    do {
        cout << "Nhap giay (0-59): ";
        in >> a.iGiay;
    } while (a.iGiay < 0 || a.iGiay > 59);
    return in ;
}

// Hàm xuất ra kết quả ngày tháng năm
ostream& operator << (ostream& out, const cTime &a) {
    // In ra theo định dạng hh:mm:ss
    if (a.iGio < 10) out << "0"; // Nếu < 10 thì in thêm số 0 rồi mới in giờ để đúng định dạng hh
    out << a.iGio << ":";

    if (a.iPhut < 10) out << "0"; // Nếu < 10 thì in thêm số 0 rồi mới in giờ để đúng định dạng mm
    out << a.iPhut << ":";

    if (a.iGiay < 10) out << "0"; // Nếu < 10 thì in thêm số 0 rồi mới in giờ để đúng định dạng ss
    out << a.iGiay;
    return out ;
}
// Hàm chuyển đổi tổng thời gian sang giây
cTime cTime::TotalToSeconds(long total) {
    cTime res;
    total %= 86400; // Đảm bảo tổng giây nằm trong khoảng 0-86399
    if (total < 0) total += 86400; // Nếu tổng giây âm, cộng thêm 1 ngày => thời gian sẽ thành dương
    res.iGio = (total / 3600) % 24; // Lấy số giờ bằng cách chia tổng giây cho 3600 rồi mod 24 để lấy phần giờ
    res.iPhut = (total / 60) % 60; // Lấy số phút bằng cách chia tổng giây cho 60 rồi mod 60 để lấy phần phút
    res.iGiay = total % 60; // Lấy số giây bằng cách mod tổng giây cho 60 để lấy phần giây
    return res;
}

long long cTime::ConvertToSeconds() {
    return (iGio * 3600 + iPhut * 60 + iGiay) ;
}
// Hàm cộng thêm x giây
cTime operator + (cTime a, int x) {
    return a.TotalToSeconds(a.ConvertToSeconds() + x) ;
} ;
// Hàm trừ đi x giây
cTime operator - (cTime a, int x) {
    return a.TotalToSeconds(a.ConvertToSeconds() - x) ;
} ;
// Hàm tính ++ (prefix) của thời gian mà người dùng nhập vào
cTime operator ++ (cTime &a) {
    a = a + 1 ; // Cộng thêm 1 giây
    return a;
} ; 
// Hàm tính ++ (postfix) của thời gian mà người dùng nhập vào
cTime operator ++ (cTime &a, int) {
    cTime tmp = a ;
    a = a + 1 ;
    return tmp ;
} ; 
// Hàm tính -- (prefix) của thời gian mà người dùng nhập vào 
cTime operator -- (cTime &a) {
    a = a - 1 ; // Trừ đi 1 giây
    return a ;
} ;
// Hàm tính -- (postfix) của thời gian mà người dùng nhập vào
cTime operator -- (cTime &a, int) {
    cTime tmp = a ;
    a = a - 1 ;
    return tmp ;
} ;
// Hàm destructor của lớp Time
cTime::~cTime() {} ;