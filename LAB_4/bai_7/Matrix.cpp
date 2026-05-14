#include <iostream>
using namespace std;

#include "Matrix.h"

// Hàm constructor mặc định
Matrix::Matrix() {
    iCot = iDong = 0;
    data = nullptr;
}
// Hàm copy constructor
Matrix::Matrix(const Matrix &a) {
    // Sao chép số dòng và số cột từ ma trận a
    iDong = a.iDong; 
    iCot = a.iCot;
    data = new double*[iDong]; // Cấp phát động cho mảng 2 chiều
    for (int i = 0; i < iDong; i++) {
        data[i] = new double[iCot]; // Mỗi dòng, cấp phát động cột cho dòng đó
        for (int j = 0; j < iCot; j++) {
            data[i][j] = a.data[i][j]; // Sao chép giá trị từ ma trận a vào ma trận mới
        }
    }
}
// Hàm operator = để gán ma trận
Matrix& Matrix::operator = (const Matrix &x) {
    if (this != &x) { // Kiểm tra tự gán (nếu v1 = v1 thì không cần gán lại => trả về *this luôn)
        // Giải phóng bộ nhớ hiện tại của ma trận này
        for (int i = 0; i < iDong; i++) {
            delete[] data[i]; // Xóa từng dòng 
        }
        delete[] data; // Xóa mảng

        // Sao chép số dòng và số cột từ ma trận x
        iDong = x.iDong;
        iCot = x.iCot;
        data = new double*[iDong]; // Cấp phát động cho mảng 2 chiều
        for (int i = 0; i < iDong; i++) {
            data[i] = new double[iCot]; // Mỗi dòng, cấp phát động cột cho dòng đó
            for (int j = 0; j < iCot; j++) {
                data[i][j] = x.data[i][j]; // Sao chép giá trị từ ma trận x vào ma trận này
            }
        }
    }
    return *this; // Trả về đối tượng hiện tại sau khi gán
}
// Hàm destructor để giải phóng bộ nhớ
Matrix::~Matrix() {
    for (int i = 0; i < iDong; i++) {
        delete[] data[i]; // Xóa từng dòng
    }
    delete[] data; // Xóa mảng
}
// Hàm nhập ma trận 
istream& operator >> (istream& in, Matrix &x) {
    cout << "Nhap so dong: "; in >> x.iDong; // Nhập số dòng
    cout << "Nhap so cot: "; in >> x.iCot; // Nhập số cột
    // Cấp phát động cho mảng 2 chiều dựa trên số dòng và số cột mới
    x.data = new double*[x.iDong];
    for (int i = 0; i < x.iDong; i++) {
        x.data[i] = new double[x.iCot]; // Mỗi dòng, cấp phát động cột cho dòng đó
        for (int j = 0; j < x.iCot; j++) {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            in >> x.data[i][j]; // Nhập giá trị cho phần tử tại vị trí [i][j]
        }
    }
    return in; 
}
// Hàm xuất ma trận
ostream& operator << (ostream& out, const Matrix &x) {
    for (int i = 0; i < x.iDong; i++) {
        for (int j = 0; j < x.iCot; j++) {
            out << x.data[i][j] << " "; // Xuất giá trị của phần tử tại vị trí [i][j] và thêm khoảng trắng
        }
        out << '\n'; // Xuất xuống dòng sau khi xuất xong một dòng của ma trận
    }
    return out; 
}

// Hàm cộng hai ma trận
Matrix operator + (Matrix a, Matrix b) {
    Matrix result ;
    if (a.iDong != b.iDong || a.iCot != b.iCot) {
        // 2 ma trận phải có cùng kích thước để cộng
        cout << "Hai ma tran phai co cung kich thuoc de cong!"; 
        return result; 
    }
    result.iDong = a.iDong; // Số dòng của ma trận kết quả bằng số dòng của ma trận a
    result.iCot = a.iCot; // Số cột của ma trận kết quả bằng số cột của ma trận a
    result.data = new double*[result.iDong]; // Cấp phát động cho mảng 2 chiều của ma trận kết quả
    for (int i = 0; i < result.iDong; i++) {
        result.data[i] = new double[result.iCot]; // Mỗi dòng, cấp phát động cột cho dòng đó trong ma trận kết quả
        for (int j = 0; j < result.iCot; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j]; // Cộng giá trị tương ứng từ ma trận a và b và lưu vào ma trận kết quả
        }
    }
    return result ;
}
// Hàm trừ hai ma trận
Matrix operator - (Matrix a, Matrix b) {
    Matrix result ;
    if (a.iDong != b.iDong || a.iCot != b.iCot) {
        // 2 ma trận phải có cùng kích thước để trừ
        cout << "Hai ma tran phai co cung kich thuoc de tru!"; 
        return result; 
    }
    result.iDong = a.iDong; // Số dòng của ma trận kết quả bằng số dòng của ma trận a
    result.iCot = a.iCot; // Số cột của ma trận kết quả bằng số cột của ma trận a
    result.data = new double*[result.iDong]; // Cấp phát động cho mảng 2 chiều của ma trận kết quả
    for (int i = 0; i < result.iDong; i++) {
        result.data[i] = new double[result.iCot]; // Mỗi dòng, cấp phát động cột cho dòng đó trong ma trận kết quả
        for (int j = 0; j < result.iCot; j++) {
            result.data[i][j] = a.data[i][j] - b.data[i][j]; // Trừ giá trị tương ứng từ ma trận a và b và lưu vào ma trận kết quả
        }
    }
    return result ;
}
// Hàm nhân hai ma trận
Matrix operator * (Matrix a, Matrix b) {
    Matrix result ;
    if (a.iCot != b.iDong) {
        // Số cột của ma trận a phải bằng số dòng của ma trận b để nhân
        cout << "So cot cua ma tran A phai bang so dong cua ma tran B de nhan!"; 
        return result; 
    }
    // a : a x b , b : b x c => result : a x c
    result.iDong = a.iDong ;
    result.iCot = b.iCot ; 
    result.data = new double*[result.iDong]; // Cấp phát động cho mảng 2 chiều của ma trận kết quả
    for (int i = 0; i < result.iDong; i++) {
        result.data[i] = new double[result.iCot]; // Mỗi dòng, cấp phát động cột cho dòng đó trong ma trận kết quả
        for (int j = 0; j < result.iCot; j++) {
            result.data[i][j] = 0; // Khởi tạo giá trị ban đầu là 0 trước khi tính tổng tích
            for (int k = 0; k < a.iCot; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j]; // Tính tổng tích của hàng i của ma trận a và cột j của ma trận b và lưu vào ma trận kết quả
            }
        }
    }
    return result ;
}
// Hàm nhân ma trận với vector
Vector operator * (Matrix a, Vector b) {
    Vector result ;
    if (a.iCot != b.size) {
        // Số cột của ma trận a phải bằng kích thước của vector b để nhân
        cout << "So cot cua ma tran A phai bang kich thuoc cua vector B de nhan!"; 
        return result; 
    }
    // a : m x n , b : n x 1 => result : m x 1
    result.size = a.iDong ; 
    result.data = new double[result.size]; // Cấp phát động cho mảng 1 chiều của vector kết quả
    for (int i = 0; i < result.size; i++) {
        result.data[i] = 0;
        for (int j = 0; j < a.iCot; j++) {
            // Tính giống công thức tích vô hướng (hàng i của ma trận với vector b)
            result.data[i] += a.data[i][j] * b.data[j]; 
        }
    }
    return result ;
}
