#include <iostream>
#include "Date.h"

using namespace std ;

// Input : năm y
// Output : nếu y là năm nhuận => 1, ngược lại => 0 
bool NamNhuan(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ;
}

// Input : tháng m, năm y 
// Output : Số ngày trong tháng m năm y
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

// Input : ngày tháng năm
// Output : Nếu sai thì nhập lại, không thì tiếp tục
void Date::Nhap() {
    do {
        cout << "Nhap vao ngay thang nam : " ;
        cin >> iNgay >> iThang >> iNam ;
        
        if (iThang > 12 || iThang < 1) {
            cout << "Thang khong hop le, vui long nhap lai ! \n" ;
            continue ;
        }
        int tmp = dayInMonth(iThang, iNam) ;
        if (iNgay < 1 || iNgay > tmp) {
            cout << "Ngay khong hop le, vui long nhap lai ! \n" ;
            continue ;
        }
        break ;
    } while (true) ;
} ;

// Input : ngày tháng năm hiện tại
// Output : res = ngày tháng năm kế tiếp
Date Date::NgayThangNamTiepTheo() {
    Date next = *this ; // Gán biến next = ngày tháng năm hiện tại
    next.iNgay++ ;
    if (next.iNgay > dayInMonth(next.iThang, next.iNam)) {
        next.iNgay = 1 ;
        next.iThang++ ;
    }
    if (next.iThang > 12) {
        next.iThang = 1 ;
        next.iNam++ ;
    }
    return next ;
} ;

// Input : ___
// Output : in ra kết quả của ngày tháng năm kế tiếp
void Date::Xuat() {
    cout << "Ngay ke tiep la : " << iNgay << '/' << iThang << '/' << iNam ;
}