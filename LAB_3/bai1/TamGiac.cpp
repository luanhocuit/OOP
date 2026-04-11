#include <iostream>
#include <math.h>
using namespace std ;

#include "TamGiac.h"

// Hàm thiết lặp mặc định cho cTamGiac
cTamGiac::cTamGiac() { 
    a = Diem() ;
    b = Diem() ;
    c = Diem() ;
}

// Hàm thiết lập cho cTamGiac (truyền vào tham số a, b, c)
cTamGiac::cTamGiac(Diem a, Diem b, Diem c) { 
    this->a = a ;
    this->b = b ;
    this->c = c ;
}

// Hàm nhập vào tọa độ các điểm a, b, c
void cTamGiac::Nhap() { 
    cout << "Nhap diem A : \n" ;
    a.Nhap() ;
    cout << "Nhap diem B : \n" ;
    b.Nhap() ;
    cout << "Nhap diem C : \n" ;
    c.Nhap() ;
} 

 // Hàm xuất ra cTamGiac (tọa độ của 3 điểm trong cTamGiac)
void cTamGiac::Xuat() {
    cout << "Day la tam giac cua ban : \n" ;
    cout << "Diem A : (" << a.x << "," << a.y << ")\n" ;
    cout << "Diem B : (" << b.x << "," << b.y << ")\n" ;
    cout << "Diem C : (" << c.x << "," << c.y << ")\n" ;
}


// Hàm check tam giác loại gì
void cTamGiac::checkTamGiac() {
    // Check thẳng hàng 
    if ((b.x - a.x)*(c.y - a.y) == (b.y - a.y)*(c.x - a.x)) {
        cout << "Day khong phai la tam giac\n";
        return;
    }

    // Bình phương các cạnh (check cạnh thì do cạnh luôn > 0 nên không cần dùng sqrt để sai số)
    double c1 = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y); // AB^2
    double c2 = (c.x - a.x)*(c.x - a.x) + (c.y - a.y)*(c.y - a.y); // AC^2
    double c3 = (c.x - b.x)*(c.x - b.x) + (c.y - b.y)*(c.y - b.y); // BC^2

    // Check bằng nhau
    bool ab_ac = (c1 == c2);
    bool ab_bc = (c1 == c3);
    bool ac_bc = (c2 == c3);

    // Check tam giác vuông (pytago)
    bool vuong = (c1 + c2 == c3) ||
                 (c1 + c3 == c2) ||
                 (c2 + c3 == c1);

    // Xét các loại tam giac
    if (ab_ac && ac_bc) {
        cout << "Day la tam giac deu\n";
    }
    else if (vuong && (ab_ac || ab_bc || ac_bc)) {
        cout << "Day la tam giac vuong can\n";
    }
    else if (vuong) {
        cout << "Day la tam giac vuong\n";
    }
    else if (ab_ac || ab_bc || ac_bc) {
        cout << "Day la tam giac can\n";
    }
    else {
        cout << "Day la tam giac thuong\n";
    }
}

// Hàm tính chu vi của tam giác
double cTamGiac::ChuVi() {
    double c1 = sqrt(pow(b.x - a.x , 2) + pow(b.y - a.y, 2)) ; // Tính độ dài cạnh AB
    double c2 = sqrt(pow(c.x - a.x , 2) + pow(c.y - a.y, 2)) ; // Tính độ dài cạnh AC
    double c3 = sqrt(pow(c.x - b.x , 2) + pow(c.y - b.y, 2)) ; // Tính độ dài cạnh BC
    return c1 + c2 + c3 ;
}

// Hàm tính diện tích tam giác (công thức Heron)
double cTamGiac::DienTich() {
    double c1 = sqrt(pow(b.x - a.x , 2) + pow(b.y - a.y, 2)) ; // Tính độ dài cạnh AB
    double c2 = sqrt(pow(c.x - a.x , 2) + pow(c.y - a.y, 2)) ; // Tính độ dài cạnh AC
    double c3 = sqrt(pow(c.x - b.x , 2) + pow(c.y - b.y, 2)) ; // Tính độ dài cạnh BC

    double p = (c1 + c2 + c3) / 2 ; // Tính nửa chu vi cua tam giác 
    return sqrt(p * (p - c1) * (p - c2) * (p - c3)) ; 
}

// Hàm phóng to tam giác ra k lần
void cTamGiac::PhongTo(double k) {
    // Tính trọng tâm G của 3 đỉnh a, b, c
    double gx = (a.x + b.x + c.x) / 3 ; 
    double gy = (a.y + b.y + c.y) / 3 ;

    /* Tính tọa độ mới = trọng tâm G + khoảng cách giữa mỗi đỉnh với trọng tâm * k lần (áp dụng phép vị tự)
    - Nghĩa là ban đầu có khoảng cách là (a.x - g.x) <ví dụ với phần Ox của đỉnh a>
    thì sau khi nhân với k lần và cộng với tọa độ của tâm G sẽ ra tọa độ mới sau khi nhân k lần lên
    */
    a.x = gx + k * (a.x - gx);
    a.y = gy + k * (a.y - gy);

    b.x = gx + k * (b.x - gx);
    b.y = gy + k * (b.y - gy);

    c.x = gx + k * (c.x - gx);
    c.y = gy + k * (c.y - gy);

    cout << "Toa do cua tam giac sau khi phong to : \n" ;
    Xuat() ;
}

// Hàm thu nhỏ tam giác lại 
void cTamGiac::ThuNho(double k) {
    // Tương tự như phóng to nhưng nếu 0 < k < 1 thì phép phóng to sẽ là phép thu nhỏ
    double gx = (a.x + b.x + c.x) / 3 ; 
    double gy = (a.y + b.y + c.y) / 3 ;

    a.x = gx + k * (a.x - gx);
    a.y = gy + k * (a.y - gy);

    b.x = gx + k * (b.x - gx);
    b.y = gy + k * (b.y - gy);

    c.x = gx + k * (c.x - gx);
    c.y = gy + k * (c.y - gy);

    cout << "Toa do cua tam giac sau khi thu nho:\n";
    Xuat();
}

// Khai báo destructor
cTamGiac::~cTamGiac() {} ;