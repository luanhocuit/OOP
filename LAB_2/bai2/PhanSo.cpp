#include <iostream>

#include "PhanSo.h"
using namespace std ;

// Input : tử số và mẫu số
// Output : ước chung lớn nhất của tử và mẫu
int GCD(int a, int b) {
    if(b == 0) return a ;
    else return GCD(b, a % b) ;
}

// Input : phân số a 
// Output : Kết quả hợp lệ => tiếp tục chương trình
//          Không hợp lệ => Nhập lại
void PS::Nhap() {
    while(true) {
        cout << "Nhap tu so : " ;
        cin >> iTu ;
        if(cin.fail()) { // Nếu input khác số => cin.fail() : true
            cin.clear() ; // Xóa nội dung đã cin vào iTu
            cin.ignore(100, '\n') ; // Xóa các dòng thừa, enter thừa
            cout << "Sai roi. Ban hay nhap lai tu so.\n" ;
        }
        else break ;
    }
    while(true) {
        cout << "Nhap mau so (khac 0) : " ;
        cin >> iMau ;
        if(cin.fail()) { // Tương tự như trên
            cin.clear() ;
            cin.ignore(100, '\n') ;
            cout << "Sai roi. Ban hay nhap lai mau so.\n" ;
        }
        else if(iMau == 0) {
            cout << "Sai roi. Ban hay nhap lai mau so.\n" ;
        }
        else break ;
    }

}

// Input : phân số a
// Output : in ra kết quả của phân số
void PS::Xuat() {
    if(iMau == 1) cout << iTu;
    else if(iTu == 0) cout << 0;
    else cout << iTu << "/" << iMau;
    cout << '\n';
}

// Input : phân số a 
// Output : phân số a sau khi đã rút gọn
void PS::RutGon() {
    if (iTu == 0) {
        iMau = 1 ;
        return ;
    }
    int tmp = GCD(iTu, iMau) ;
    iTu /= tmp ;
    iMau /= tmp ;
    if(iMau < 0) { // Chuyển dấu âm lên tử
        iTu = -iTu ;
        iMau =  -iMau ;
    }
} 

// Input : 2 phân số a, b 
// Output : trả về kết quả (1 : a > b, 0 : a == b, -1 : a < b)
int PS::SoSanh(PS a,PS b) {
    int tmp1 = a.iTu * b.iMau ;
    int tmp2 = b.iTu * a.iMau ;
    if(tmp1 == tmp2) {
        return 0 ;
    }
    else if(tmp1 > tmp2) {
        return 1 ;
    }
    else {
        return -1 ;
    }
}

// Input : 2 phân số a, b
// Output : phân số res là tổng của a và b
PS PS::tong(PS b) {
    PS res ;
    res.iMau = iMau * b.iMau ;
    res.iTu = iTu * b.iMau + b.iTu * iMau ;
    res.RutGon() ;
    return res ;
}

// Input : 2 phân số a, b
// Output : phân số res là hiệu của a và b
PS PS::hieu(PS b) {
    PS res ;
    res.iMau = iMau * b.iMau ;
    res.iTu = iTu * b.iMau - b.iTu * iMau ;
    res.RutGon() ;
    return res ;
}

// Input : 2 phân số a, b
// Output : phân số res là tích của a và b
PS PS::tich(PS b) {
    PS res ;
    res.iMau = iMau * b.iMau ;
    res.iTu = iTu * b.iTu ;
    res.RutGon() ;
    return res ;
}

// Input : 2 phân số a, b
// Output : phân số res là thương của a và b
PS PS::thuong(PS b) {
    PS res ;
    res.iMau = iMau * b.iTu ;
    res.iTu = iTu * b.iMau ;
    res.RutGon() ;
    return res ;
}

