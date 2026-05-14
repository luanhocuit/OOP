#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

int main() {
    cDate d1, d2;
    int x;
    double tiengui, laisuat;

    cout << "Nhap ngay thu nhat (d1):" << '\n'; cin >> d1;
    cout << "Ngay ban vua nhap: " << d1 << '\n';

    // Nhập số ngày muốn cộng vào d1
    cout << "\nNhap so ngay muon cong vao d1: "; cin >> x;
    cout << d1 << " + " << x << " ngay = " << (d1 + x) << '\n';

    // Nhập số ngày muốn trừ đi từ d1
    cout << "\nNhap so ngay muon tru di tu d1: "; cin >> x;
    cout << d1 << " - " << x << " ngay = " << (d1 - x) << '\n';

    cDate temp = d1;
    cout << "Kiem tra ++ -- (postfix va prefix)" << '\n' ;

    cout << "\n++ (postfix) : " << '\n' ;
    cout << "Ngay ban dau: " << temp << '\n' ;
    cout << "Ngay sau khi ++ (postfix): " << temp++ << '\n' ;
    cout << "Ngay (sau khi postfix): " << temp << '\n' ;

    cout << "\n++ (prefix) : " << '\n' ;
    cout << "Ngay ban dau: " << temp << '\n' ;
    cout << "Ngay sau khi ++ (prefix): " << ++temp << '\n' ;
    cout << "Ngay (sau khi prefix): " << temp << '\n' ;

    cout << "\n-- (postfix) : " << '\n' ;
    cout << "Ngay ban dau: " << temp << '\n' ;
    cout << "Ngay sau khi -- (postfix): " << temp-- << '\n' ;
    cout << "Ngay (sau khi postfix): " << temp << '\n' ;

    cout << "-- (prefix) : " << '\n' ;
    cout << "Ngay ban dau: " << temp << '\n' ;
    cout << "Ngay sau khi -- (prefix): " << --temp << '\n' ;
    cout << "Ngay (sau khi prefix): " << temp << '\n' ;

    // Nhâp ngày thứ hai để tính khoảng cách
    cout << "\nNhap ngay thu hai (d2):" << '\n' ; cin >> d2;
    long long khoangcach = d2 - d1;
    cout << "Khoang cach giua " << d1 << " va " << d2 << " la: " << khoangcach << " ngay" << '\n';

    // Tính lãi suất
    cout << "\nNhap so tien muon gui (dong) : " ; cin >> tiengui;
    cout << "Nhap lai suat (%/nam): " ; cin >> laisuat;

    // Làm tròn 4 chữ số thập phân
    cout << fixed << setprecision(4); 
    cout << "Tong tien (Lai don) sau " << khoangcach << " ngay: " << LaiSuatDon(d1, d2, tiengui, laisuat) << '\n';
    cout << "Tong tien (Lai kep) sau " << khoangcach << " ngay: " << LaiSuatKep(d1, d2, tiengui, laisuat) << '\n';

    return 0;
}