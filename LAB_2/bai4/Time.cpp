#include <iostream>
#include "Time.h"

using namespace std ;

// Input : Nhập vào thời gian
// Output : Nếu sai thì nhập lại, đúng thì tiếp tục
void Time::Nhap() {
    do {
        cout << "Nhap gio (0-23): ";
        cin >> iGio;
    } while (iGio < 0 || iGio > 23);

    do {
        cout << "Nhap phut (0-59): ";
        cin >> iPhut;
    } while (iPhut < 0 || iPhut > 59);

    do {
        cout << "Nhap giay (0-59): ";
        cin >> iGiay;
    } while (iGiay < 0 || iGiay > 59);
}

// Input : ___
// Output : In ra kết quả
void Time::Xuat() {
    if (iGio < 10) cout << "0";
    cout << iGio << ":";

    if (iPhut < 10) cout << "0";
    cout << iPhut << ":";

    if (iGiay < 10) cout << "0";
    cout << iGiay;
}

// Input : thời gian hiện tại
// Output : thời gian sau khi cộng thêm 1 giây
void Time::TinhCongThemMotGiay() {
    iGiay++;

    if (iGiay == 60) {
        iGiay = 0;
        iPhut++;

        if (iPhut == 60) {
            iPhut = 0;
            iGio++;

            if (iGio == 24) {
                iGio = 0;
            }
        }
    }
}