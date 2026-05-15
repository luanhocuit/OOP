#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std ;

// Xây dựng struct chứa tử số và mẫu số
struct PS {
    int tuso, mauso ;
} ;

// Hàm nhập vào phân số
void nhap(PS &a, PS &b) {
    do {
        cout << "Vui long nhap phan so hop le (mau != 0) :\n" ;
        cout << "Nhap vao tu so thu 1 : "; 
        cin >> a.tuso ; 
        cout << "Nhap vao mau so thu 1 : " ; 
        cin >> a.mauso ;  
    } while (a.mauso == 0) ; // Nếu mẫu = 0 thì nhập lại

    do {
        cout << "Vui long nhap phan so hop le (mau != 0) :\n" ;
        cout << "Nhap vao tu so thu 2 : "; 
        cin >> b.tuso ; 
        cout << "Nhap vao mau so thu 2 : " ; 
        cin >> b.mauso ;
    } while (b.mauso == 0) ; // Nếu mẫu = 0 thì nhập lại
}

// Hàm in ra phân số
void xuat(PS a) {
    // Nếu tử = 0 => in ra 0
    if(a.tuso == 0) {
        cout << 0 << '\n';
        return ;
    }

    // Nếu tử = mẫu => in ra 1
    if(a.tuso == a.mauso) {
        cout << 1 << '\n';
        return  ;
    }
    // Còn lại in theo dạng a/b
    cout << a.tuso << '/' << a.mauso << '\n' ; 
}

// Hàm tính tổng 
PS Tong(PS A, PS B) {
    PS res ;
    res.mauso = A.mauso * B.mauso ;
    res.tuso = A.tuso * B.mauso + B.tuso * A.mauso ;
    int tmp = __gcd(res.tuso, res.mauso) ;
    res.tuso /= tmp, res.mauso /= tmp ;
    return res ;
}

// Hàm tính hiệu 
PS Hieu(PS A, PS B) {
    PS res ;
    res.mauso = A.mauso * B.mauso ;
    res.tuso = A.tuso * B.mauso - B.tuso * A.mauso ;
    int tmp = __gcd(res.tuso, res.mauso) ;
    res.tuso /= tmp, res.mauso /= tmp ;
    return res ;
}

// Hàm tính tích
PS Tich(PS A, PS B) {
    PS res ;
    res.mauso = A.mauso * B.mauso ;
    res.tuso = A.tuso * B.tuso ;
    int tmp = __gcd(res.tuso, res.mauso) ;
    res.tuso /= tmp, res.mauso /= tmp ;
    return res ;
}

// Hàm tính thương
PS Thuong(PS A, PS B) {
    PS res ;
    res.mauso = A.mauso * B.tuso ;
    res.tuso = A.tuso * B.mauso ;
    int tmp = __gcd(res.tuso, res.mauso) ;
    res.tuso /= tmp, res.mauso /= tmp ;
    return res ;
}

int main () {
    PS a, b ; 
    nhap(a, b) ;
    PS tong = Tong(a, b) ;
    PS hieu = Hieu(a, b) ;
    PS tich = Tich(a, b) ;
    PS thuong = Thuong(a, b) ;
    cout << "Tong : "; xuat(tong) ;
    cout << "Hieu : "; xuat(hieu) ;
    cout << "Tich : "; xuat(tich) ;
    cout << "Thuong : "; xuat(thuong) ;
    return 0 ;
}