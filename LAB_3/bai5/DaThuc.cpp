#include <bits/stdc++.h>

using namespace std ;

#include "DaThuc.h"

// Phương thức constructor có tham số
cDaThuc::cDaThuc(int bac) {
    n = bac ;
    a.resize(n + 1) ; // Thêm bậc x^0 cho hàm
} ;

// Hàm nhập vào
istream& operator >> (istream& in, cDaThuc &dt) {
    do {
        cout << "Nhap vao bac n (n >= 0) : " ;
        in >> dt.n ;
    } while (dt.n < 0) ; // Nhập vào bậc đa thức >= 0
    dt.a.resize(dt.n + 1) ;
    for(int i = 0 ; i <= dt.n ; i++) {
        cout << "Nhap vao he so cua x^" << i << ": " ;
        in >> dt.a[i] ;
    }
    return in ;
} ;

// Hàm in ra
ostream& operator << (ostream& out, cDaThuc dt) {
    bool first = true ; // biến first dùng để xác định có phải số đầu tiên không ?
        for (int i = dt.n; i >= 0; i--) {
            if (dt.a[i] == 0) continue; // Hệ số = 0 => skip
            if (!first && dt.a[i] > 0) out << " + "; // Không phải số đầu tiên và hệ số dương
            if (dt.a[i] < 0) out << " - ";
            double val = abs(dt.a[i]);
            if (val != 1 || i == 0) out << val; // Giá trị != 1 hoặc là số cuối cùng => in ra giá trị luôn
            if (i > 0) { // Chừng nào i != n => in x^..
                out << "x";
                if (i > 1) out << "^" << i; // Nếu lớn hơn 1 thì in ra số mũ
            }
            first = false;
        }
        if (first) out << "0"; // Nếu hết vòng lặp mà first nó vẫn true => không có phần tử => in ra 0
    return out;
} ;

// Hàm cộng 2 đa thức
cDaThuc operator + (cDaThuc a, cDaThuc b) {
    int tmp = max(a.n, b.n) ;
    cDaThuc res(tmp) ;
    for (int i = 0; i <= tmp; i++) {
        // (i <= a.n và i <= b.n) dùng để check coi đa thức đó hết chưa => hết rồi thì gán = 0 
        // nếu không sẽ bị lỗi "truy cập chỉ số ngoài mảng"
        double h1 = (i <= a.n) ? a.a[i] : 0;
        double h2 = (i <= b.n) ? b.a[i] : 0;
        res.a[i] = h1 + h2;
    }
    return res ;
} ;

// Hàm trừ 2 đa thức
cDaThuc operator - (cDaThuc a, cDaThuc b) {
    int tmp = max(a.n, b.n) ;
    cDaThuc res(tmp) ;
    for (int i = 0; i <= tmp; i++) {
        // tương tự như operator +
        double h1 = (i <= a.n) ? a.a[i] : 0;
        double h2 = (i <= b.n) ? b.a[i] : 0;
        res.a[i] = h1 - h2;
    }
    return res ;
} ;

// Hàm tính giá trị tại x
double cDaThuc::tinhGiaTri(int x) {
    double res = 0 ;
    for(int i = 0 ; i <= n ; i++) {
        res += a[i] * pow(x, i) ; // a[i] * x^i
    }
    return res ; 
}
// Phương thức Destructor
cDaThuc::~cDaThuc() {} ;