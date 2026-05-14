
#include <iostream>

using namespace std;
#include "Vector.h"
// Hàm constructor mặc định
Vector::Vector() {  
    size = 0;
    data = nullptr;
}
// Hàm copy constructor
Vector::Vector(const Vector &a) {
    size = a.size; // Sao chép kích thước từ vector a
    data = new double[size]; // Cấp phát động cho mảng 1 chiều của vector mới
    for (int i = 0; i < size; i++) {
        data[i] = a.data[i]; // Sao chép giá trị từ vector a vào vector mới
    }
}
// Hàm operator = để gán vector
Vector& Vector::operator = (const Vector &x) {
    if (this != &x) { // Kiểm tra tự gán (nếu v1 = v1 thì không cần gán lại => trả về *this luôn)
        // Giải phóng bộ nhớ hiện tại của vector này
        delete[] data; // Xóa mảng hiện tại

        size = x.size; // Sao chép kích thước từ vector x
        data = new double[size]; // Cấp phát động cho mảng 1 chiều của vector mới
        for (int i = 0; i < size; i++) {
            data[i] = x.data[i]; // Sao chép giá trị từ vector x vào vector này
        }
    }
    return *this; // Trả về đối tượng hiện tại sau khi gán
}
// Hàm nhập vector
istream& operator >> (istream& in, Vector &x) {
    cout << "Nhap kich thuoc vector: "; in >> x.size; // Nhập kích thước của vector
    x.data = new double[x.size]; // Cấp phát động cho mảng 1 chiều của vector
    for (int i = 0; i < x.size; i++) {
        cout << "Nhap phan tu [" << i << "]: ";
        in >> x.data[i]; // Nhập giá trị cho phần tử tại vị trí [i] của vector
    }
    return in; 
}
// Hàm in ra vector
ostream& operator << (ostream& out, const Vector &x) {
    out << "(" ;
    for (int i = 0; i < x.size; i++) {
        out << x.data[i] ; // Xuất giá trị của phần tử tại vị trí [i] 
        if (i < x.size - 1) {
            out << ","; // Thêm dấu phẩy giữa các phần tử, nhưng không thêm sau phần tử cuối cùng
        }
    }
    out << ")\n"; // Xuất dấu đóng ngoặc đơn sau khi xuất xong vector
    return out; 
}
// Hàm destructor để giải phóng bộ nhớ
Vector::~Vector() {
    delete[] data; // Xóa mảng động của vector khi đối tượng bị hủy
}