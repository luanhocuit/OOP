#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    Time t;
    cout << "Nhap thoi gian : \n"; t.Nhap();

    cout << "\nThoi gian ban dau: "; t.Xuat();

    t.TinhCongThemMotGiay();

    cout << "\nSau khi cong them 1 giay: "; t.Xuat();
    return 0;
}