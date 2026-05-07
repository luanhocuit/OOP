#include <iostream>
#include "Time.h"

using namespace std ;

// Input : Nhập vào thời gian
// Output : Nếu sai thì nhập lại, đúng thì tiếp tục
istream& operator >> (istream& in, cTime &a) {
    do {
        cout << "Nhap gio (0-23): ";
        cin >> a.iGio;
    } while (a.iGio < 0 || a.iGio > 23);

    do {
        cout << "Nhap phut (0-59): ";
        cin >> a.iPhut;
    } while (a.iPhut < 0 || a.iPhut > 59);

    do {
        cout << "Nhap giay (0-59): ";
        cin >> a.iGiay;
    } while (a.iGiay < 0 || a.iGiay > 59);
}

// Input : ___
// Output : In ra kết quả
ostream& operator << (ostream& out, cTime &a) {
    // In ra theo định dạng hh:mm:ss
    if (a.iGio < 10) cout << "0"; // Nếu < 10 thì in thêm số 0 rồi mới in giờ để đúng định dạng hh
    cout << a.iGio << ":";

    if (a.iPhut < 10) cout << "0"; // Nếu < 10 thì in thêm số 0 rồi mới in giờ để đúng định dạng mm
    cout << a.iPhut << ":";

    if (a.iGiay < 10) cout << "0"; // Nếu < 10 thì in thêm số 0 rồi mới in giờ để đúng định dạng ss
    cout << a.iGiay;
}
// Hàm cộng thêm x giây
cTime operator + (cTime a, int x) {
    a.iGiay += x; // Cộng thêm x giây vào
    a.iPhut += a.iGiay / 60; // Cộng thêm vào phút nếu > 60 (nếu <= 60 thì chia cho 60 = 0)
    a.iGiay %= 60; // mod 60 => ra số giây sau khi qua vòng mới
    a.iGio += a.iPhut / 60;
    a.iPhut %= 60;
    a.iGio %= 24;
    return a;
    
} ;
cTime operator - (cTime a, int x) {

} ;

cTime operator ++ (cTime a) {
    ++a ;
    return a;
}
cTime operator ++ (cTime a, int) {
    cTime tmp = a ;
    a++ ;
    return tmp ;
} ; 
cTime operator -- (cTime a) ;
cTime operator -- (cTime a, int) ;
// Hàm tính thời gian sau khi tăng 1 giây

// Hàm destructor của lớp Time
cTime::~cTime() {} ;