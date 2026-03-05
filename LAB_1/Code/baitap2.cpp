#include <iostream>
#include <algorithm>

using namespace std ;

// Xây dựng struct chứa tử số và mẫu số
struct PS {
    int tuso, mauso ;
} ;

// Hàm sosanh phân số 
int sosanh(PS a, PS b) {
    // Tạo 2 biến res1 và res2 để so sánh tử số của 2 phân số
    // a/b và c/d  => quy đồng được a*d/b*d và c*b / b*d => so sánh 2 tử số
    int res1 = a.tuso * b.mauso ;
    int res2 = b.tuso * a.mauso ;
    if(res1 == res2) {
        return 1 ;
    }
    else if(res1 < res2) {
        return 2 ;
    }
    else return -1 ;
}

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
void xuat(PS a, PS b) {
    if(sosanh(a, b) == 1) {
        cout << "Phan so thu 1 bang phan so thu 2" ;
    }
    else if(sosanh(a,b) == 2) {
        cout << "Phan so thu 1 be hon phan so thu 2" ;
    }
    else {
        cout << "Phan so thu 1 lon hon phan so thu 2" ;
    }
}

int main () {
    PS a, b ; 
    nhap(a, b) ;
    sosanh(a, b) ;
    xuat(a, b) ;
    return 0 ;
}