#include <iostream>
#include "PhanSo.h"

using namespace std ;

int main () {
    PS a, b ;
    cout << "Nhap phan so a \n" ; a.Nhap() ;
    cout << "Nhap phan so b \n" ; b.Nhap() ;
    a.RutGon() ; b.RutGon() ;
    
    //In ra phân số sau khi rút gọn
    cout << "Phan so a sau khi rut gon : " ; a.Xuat() ;
    cout << "Phan so b sau khi rut gon : ";  b.Xuat() ;

    // Tính toán 
    PS Tong = a.tong(b) ;
    PS Hieu = a.hieu(b) ;
    PS Tich = a.tich(b) ;
    PS Thuong = a.thuong(b) ;

    // In ra kết quả 
    cout << "Tong cua 2 phan so la : " ; Tong.Xuat() ;
    cout << "Hieu cua 2 phan so la : " ; Hieu.Xuat() ;
    cout << "Tich cua 2 phan so la : " ; Tich.Xuat() ;
    cout << "Thuong cua 2 phan so la : " ; Thuong.Xuat() ;

    return 0 ;
}