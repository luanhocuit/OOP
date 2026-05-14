#include "DaThuc.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Hàm constructor có tham số
DaThuc::DaThuc(int bac) {
    this->bac = bac;
    heso.resize(bac + 1, 0); // Khởi tạo các hệ số bằng 0 (bac + 1 là do tính thêm hệ số x^0)
}

// Hàm destructor
DaThuc::~DaThuc() {} ;

// Hàm nhập đa thức
istream& operator >> (istream& in, DaThuc &dt) {
    do {
        cout << "Nhap vao bac cua da thuc (n >= 0): ";
        in >> dt.bac;
    } while (dt.bac < 0);

    dt.heso.resize(dt.bac + 1);
    for (int i = 0; i <= dt.bac; i++) {
        cout << "Nhap he so cua x^" << i << ": ";
        in >> dt.heso[i];
    }
    return in;
}

// Hàm xuất đa thức
ostream& operator << (ostream& out, DaThuc dt) {
    bool first = true; 
    for (int i = dt.bac; i >= 0; i--) {
        if (dt.heso[i] == 0) continue; // Bỏ qua hạng tử có hệ số 0

        // Xử lý dấu của hạng tử
        if (!first && dt.heso[i] > 0) out << " + ";
        if (dt.heso[i] < 0) {
            if (first) out << "-"; 
            else out << " - ";
        }

        double val = abs(dt.heso[i]);
        // In hệ số 
        if (val != 1 || i == 0) { // Giá trị khác 1 hoặc mũ = 0 => in hệ số
            out << val;
        }
        // In biến x và số mũ
        if (i > 0) { // Nếu mũ > 0 thì in biến x
            out << "x";
            if (i > 1) out << "^" << i; // Nếu mũ > 1 thì in số mũ
        }
        first = false; // Gán first = false sau khi in số hạng đầu tiên
    }
    if (first) out << "0"; // Nếu đa thức rỗng thì in 0 (không vào vòng lặp nào)
    return out;
}

// Hàm cộng 2 đa thức a và b
DaThuc operator + (DaThuc a, DaThuc b) {
    int maxBac = max(a.bac, b.bac) ; // Tìm bậc lớn nhất của 2 đa thức
    DaThuc res(maxBac) ;
    for (int i = 0; i <= maxBac; i++) {
        double h1 = (i <= a.bac) ? a.heso[i] : 0 ; // Nếu i vẫn còn <= bậc của a => lấy hệ số, không thì = 0
        double h2 = (i <= b.bac) ? b.heso[i] : 0 ; // Nếu i vẫn còn <= bậc của b => lấy hệ số, không thì = 0
        res.heso[i] = h1 + h2 ; 
    }
    return res;
}

// Hàm trừ 2 đa thức a và b
DaThuc operator - (DaThuc a, DaThuc b) {
    int maxBac = max(a.bac, b.bac); // Tìm bậc lớn nhất của 2 đa thức
    DaThuc res(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double h1 = (i <= a.bac) ? a.heso[i] : 0; // Nếu i vẫn còn <= bậc của a => lấy hệ số, không thì = 0
        double h2 = (i <= b.bac) ? b.heso[i] : 0; // Nếu i vẫn còn <= bậc của b => lấy hệ số, không thì = 0
        res.heso[i] = h1 - h2;
    }
    return res;
}

// Hàm tinh giá trị của đa thức tại x
double DaThuc::tinhGiaTri(double x) {
    double res = 0;
    for (int i = 0; i <= bac; i++) {
        res += heso[i] * pow(x, i); // Thay giá trị x vào đa thức và cộng dồn kết quả vào res
    }
    return res;
}