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

// hàm in ra ngày tháng năm
ostream& operator << (ostream& out, cDate x) {
    out << x.iNgay << '/' << x.iThang << '/' << x.iNam ;
    return out ;
}