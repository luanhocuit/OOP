#include <iostream>
#include <cmath> 
using namespace std;

#include "DaGiac.h"

// Hàm thiết lập mặc định (constructor)
cDaGiac::cDaGiac() {
    n = 0 ;
    Dinh = NULL ;
}

// Hàm thiết lập có tham số
cDaGiac::cDaGiac(int n, Diem* Dinh) {
    this->n = n;
    this->Dinh = new Diem[n]; // Cấp phát động
    for (int i = 0; i < n; i++) {
        this->Dinh[i] = Dinh[i];
    }
}

// Destructor (giải phóng bộ nhớ sau khi cấp phát động)
cDaGiac::~cDaGiac() {
    if (Dinh != NULL) {
        delete[] Dinh;
    }
}

// Hàm nhập vào tọa độ các đỉnh của đa giác
void cDaGiac::Nhap() {
    do {
        cout << "Nhap so dinh cua da giac (n >= 3): "; // Nếu < 3 thì k thể tạo thành 1 đa giác
        cin >> n;
    } while (n < 3);

    if (Dinh != NULL) { // Giải phóng bộ nhớ nếu có cấp phát từ trước
        delete[] Dinh;
    }
    Dinh = new Diem[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap diem thu " << i + 1 << "\n";
        Dinh[i].Nhap();
    }
}

// Hàm in ra tọa độ các đỉnh của đa giác
void cDaGiac::Xuat() {
    cout << "Day la da giac gom " << n << " dinh cua ban:\n";
    for (int i = 0; i < n; i++) {
        cout << "Diem " << i + 1 << ": (" << Dinh[i].x << ", " << Dinh[i].y << ")\n";
    }
}

// Hàm tính chu vi đa giác
double cDaGiac::ChuVi() {
    if (n < 3) return 0;
    double p = 0;
    for (int i = 0; i < n; i++) {
        // % n : nếu i > n thì chia lấy dư cho n để không bị quá n đỉnh
        // Ex : nếu n = 12 mà muốn tính cạnh 12-1 nhưng khi i = 12 và i++ thì sẽ không truy cập được =>13 % 12 == 1 
        // từ đó có thể tính được cạnh 12-1
        int next = (i + 1) % n; 
        // Công thức tính độ dài theo tọa độ x, y 
        p += sqrt(pow(Dinh[next].x - Dinh[i].x, 2) + pow(Dinh[next].y - Dinh[i].y, 2));
    }
    return p;
}

// Hàm tính diện tích đa giác
double cDaGiac::DienTich() {
    if (n < 3) return 0;
    double s = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        // Công thức tính diện tích của đa giác n đỉnh : 
        // S = 1/2 x [(x1y2 + x2y3 + ...) - (y1x2 + y2x3 + ...)]
        s += (Dinh[i].x * Dinh[next].y) - (Dinh[next].x * Dinh[i].y);
    }
    return abs(s) / 2.0; 
}

// Hàm phóng to đa giác k lần 
void cDaGiac::PhongTo(double k) {
    if (n < 3) return;

    cout << "Toa do cua da giac sau khi phong to:\n";
    for (int i = 0; i < n; i++) {
        // Tạo biến tạm new_x, new_y để giữ kết quả tính toán => Sẽ không làm thay đổi giá trị ban đầu
        double new_x = Dinh[i].x * k;
        double new_y = Dinh[i].y * k;
        
        cout << "Diem " << i + 1 << ": (" << new_x << ", " << new_y << ")\n";
    }
}
// Hàm thu nhỏ đa giác
void cDaGiac::ThuNho(double k) {
    if (n < 3) return;

    cout << "Toa do cua da giac sau khi thu nho:\n";
    for (int i = 0; i < n; i++) {
        // Tương tự như hàm thu nhỏ
        double new_x = Dinh[i].x * k;
        double new_y = Dinh[i].y * k;
        cout << "Diem " << i + 1 << ": (" << new_x << ", " << new_y << ")\n";
    }
}