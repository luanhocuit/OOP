#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std ;

// Xây dựng struct chứa tử số và mẫu số
struct PS {
    int tuso, mauso ;
} ;

// Hàm rút gọn phân số 
void rutgon(PS &a) {
    // Để rút gọn ta lấy tử và mẫu chia cho UCLN của tử và mẫu
    int tmp = __gcd(abs(a.tuso),abs(a.mauso)) ; // Lấy trị tuyệt đối để UCLN không bị sai
    a.tuso /= tmp ;
    a.mauso /= tmp ;
}

// Hàm nhập vào phân số
void nhap(PS &a) {
    do {
        cout << "Vui long nhap phan so hop le (mau != 0) :\n" ;
        cout << "Nhap vao tu so : "; 
        cin >> a.tuso ; 
        cout << "Nhap vao mau so : " ; 
        cin >> a.mauso ; 
    } while (a.mauso == 0) ; // Nếu mẫu = 0 thì nhập lại

    // Nếu mẫu số < 0 thì đổi dấu âm lên tử số
    if(a.mauso < 0) {
        a.tuso = -a.tuso ;
        a.mauso = -a.mauso ;
    }
}

// Hàm in ra phân số
void xuat(PS a) {
    // Nếu tử = 0 => in ra 0
    if(a.tuso == 0) {
        cout << 0 ;
        return ;
    }

    // Nếu tử = mẫu => in ra 1
    if(a.tuso == a.mauso) {
        cout << 1 ;
        return  ;
    }
    // Còn lại in theo dạng a/b
    cout << a.tuso << '/' << a.mauso ; 
}

int main () {
    PS a ; 
    nhap(a) ;
    rutgon(a) ;
    xuat(a) ;
    return 0 ;
}