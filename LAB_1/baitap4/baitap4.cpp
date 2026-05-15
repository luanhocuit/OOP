#include <iostream>

using namespace std ;

// Xây dựng struct Date chứa ngày tháng năm
struct Date {
    int day ;
    int month ;
    int year ;
} ;

// Hàm check năm nhuận
bool namnhuan(int year) {
    if (year % 400 == 0) return true ;
    if (year % 100 == 0 && year % 4 != 0) return true ;
    return false ;
}

// Hàm tính ngày trong tháng
int dayInMonth (int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            if(namnhuan(year)) return 29;
            return 28;
    }
    return 0;
}
// Hàm tính ngày tiếp theo
Date NextDay(Date tmp) {
    Date res = tmp ;
    // Tạo biến maxDay để check ngày mà nhập vào đã hết tháng chưa
    int maxDay = dayInMonth(tmp.month, tmp.year) ;

    // Nếu ngày nhập vào chưa quá maxDay => res.day++ 
    if (tmp.day < maxDay) {
        res.day++ ;
    }
    // Nếu ngày nhập vào là maxDay rồi
    else {
        res.day = 1 ; // Set res.day về lại 1
        if (res.month < 12) { // Tương tự, check tháng
            res.month++ ;
        }
        // Tương tự, check năm
        else {
            res.month = 1 ;
            res.year++ ;
        }
    }
    return res ;
}
int main () {
    Date A ;
    cout << "Nhap vao ngay thang nam (cach nhau boi khoang trang) : " ;
    cin  >> A.day >> A.month >> A.year ;

    Date res = NextDay(A) ;
    cout << res.day << "/" << res.month << "/" << res.year ;
    return 0 ;
}