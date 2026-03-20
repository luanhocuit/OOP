#include <iostream>
#include "SoPhuc.h"

using namespace std ;

// Input : Nhập vào số phức
// Output : ___
void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}

// Input : ___
// Output : In ra kết quả sau khi tính
void SoPhuc::Xuat() {
    cout << iThuc;
    if (iAo >= 0) cout << " + " << iAo << "i";
    else cout << " - " << -iAo << "i";
}

// Input : 2 số phức a và b
// Output : kq = tổng a và b 
SoPhuc SoPhuc::Tong(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc + sp.iThuc;
    kq.iAo = iAo + sp.iAo;
    return kq;
}

// Input : 2 số phức a và b
// Output : kq = hiệu a và b
SoPhuc SoPhuc::Hieu(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc - sp.iThuc;
    kq.iAo = iAo - sp.iAo;
    return kq;
}

// Input : 2 số phức a và b
// Output : kq = tích a và b
SoPhuc SoPhuc::Tich(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    kq.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
    return kq;
}

// Input : 2 số phức a và b
// Output : kq = thương a và b
SoPhuc SoPhuc::Thuong(SoPhuc sp) {
    SoPhuc kq;
    int mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
    if (mau == 0) {
        cout << "Loi: chia cho 0!\n";
        kq.iThuc = kq.iAo = 0;
        return kq;
    }
    kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mau;
    kq.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mau;

    return kq;
}