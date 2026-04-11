#include <iostream>
#include <cstdlib>  // thư viện cho rand, srand
#include <ctime>   // thư viện cho time

using namespace std ;

#include "Array.h"

// Hàm thiết lập mặc định (Constructor)
cArray::cArray() {
    n = 0 ;
    Mang = NULL ;
} 
// Hàm thiết lập chứa tham số (Overload Constructor)
cArray::cArray(int size) {
    n = size;
    Mang = new int[n];
}

// Hàm phá hủy (Destructor)
cArray::~cArray() {
    if(Mang != NULL) {
        delete [] Mang ;
    }
}

// Hàm tạo ra mảng ngẫu nhiên (sài hàm rand())
void cArray::TaoMang() {
    if (n <= 0 || Mang == NULL) return ;
    srand(time(0)) ;
    for(int i = 0 ; i < n ; i++) {
        Mang[i] = rand() % 201 - 100 ; // random số từ -100 - 100 
    }
}

// Hàm in mảng ra màn hình
void cArray::XuatMang() {
    for(int i = 0 ; i < n ; i++) {
        cout << Mang[i] << ' ' ;
    }
}

// Hàm sắp xếp mảng (dựa theo SelectionSort : O(n ^ 2) )
void cArray::SortArray() {
    int tmp ;
    do {
        cout << "Nhap : 1(Tang dan) hoac 2(Giam dan) : " ;
        cin >> tmp ;
    } while (tmp != 1 && tmp != 2) ;
    if (tmp == 1) {
        for(int i = 0 ; i < n ; i++) {
            int min = i ; 
            for(int j = i + 1 ; j < n ; j++) {
                if (Mang[j] < Mang[min]) min = j ;
            }
            swap(Mang[min], Mang[i]) ;
        }
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            int max = i;
            for (int j = i + 1; j < n; j++) {
                if (Mang[j] > Mang[max]) max = j;
            }
            swap(Mang[max], Mang[i]);
        }
    }
}

// Hàm đếm số lần xuất hiện của x trong mảng
int cArray::DemSoLanX(int x) {
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++) {
        if (Mang[i] == x) cnt++ ;
    }
    return cnt ;
}

// Hàm tìm phần tử lẻ nhỏ nhất trong mảng
int cArray::TimLeMin() {
    int res = INT_MAX ; // Gán res = số nguyên lớn nhất => mọi số khi duyệt qua vòng lặp đều gán lại vào res được
    for(int i = 0 ; i < n ; i++) {
        if(Mang[i] % 2 != 0 && Mang[i] < res) res = Mang[i] ;
    }
    return res ;
}

// Hàm check số nguyên tố
bool nt (int x) {
    if (x < 2) return false ;
    for(int i = 2 ; i * i <= x; i++) {
        if (x % i == 0) return false ;
    }
    return true ;
}

// Hàm tìm số nguyên tố lớn nhất trong mảng
int cArray::TimMaxNguyenTo() {
    int res = INT_MIN ;
    for(int i = 0 ; i < n ; i++) {
        if(nt(Mang[i]) && Mang[i] > res) res = Mang[i] ;
    }
    return res ;
}

// Hàm check mảng có tăng dần hay k
bool cArray::CheckTangDan() {
    for(int i = 0 ; i < n - 1 ; i++) {
        if (Mang[i] > Mang[i + 1]) return false ;
    }
    return true ;
}