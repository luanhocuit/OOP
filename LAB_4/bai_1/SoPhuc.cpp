#include <iostream>
using namespace std ;

#include "SoPhuc.h"

// Constructor chứa tham số (ao = 0)
// Nếu người dùng chỉ nhập số thực => Tự động đổi thành số phức đặc biệt (phần ảo = 0)
SoPhuc::SoPhuc(int thuc, int ao) {
    iThuc = thuc ;
    iAo = ao ;
}

// Hàm nhập vào phần thực và phần ảo của 1 số phức
istream& operator >> (istream& in, SoPhuc &x) {
    cout << "Nhap vao so thuc : " ; in >> x.iThuc ;
    cout << "Nhap vao so ao : " ; in >> x.iAo ;
    return in ;
} ;

// Hàm in ra số phức mà người dùng đã nhập
ostream& operator << (ostream& out, SoPhuc &x) {
    out << x.iThuc ; // In ra phần thực trước
    if(x.iAo < 0) {  // Nếu phần ảo < 0 => in ra dấu -
        out << " - " << x.iAo << 'i' ;
    }
    else if(x.iAo > 0) {// Nếu phần ảo > 0 => in ra dấu +
        out << " + " << x.iAo << 'i' ;
    }
    // Nếu không phải 2 cái dạng trên => phần ảo = 0 => chỉ in phần thực
    return out ;
}
// Hàm tổng 2 số phức
// x = a + bi, y = c + di
// kq = (a + c) + (b + d)i
SoPhuc operator + (SoPhuc a, SoPhuc b) {
    SoPhuc kq(0) ;
    kq.iThuc = a.iThuc + b.iThuc ;
    kq.iAo = a.iAo + b.iAo ;
    return kq ;
} ;
// Hàm hiệu 2 số phức
// x = a + bi, y = c + di
// kq = (a - c) + (b - d)i
SoPhuc operator - (SoPhuc a, SoPhuc b) {
    SoPhuc kq(0) ;
    kq.iThuc = a.iThuc - b.iThuc ;
    kq.iAo = a.iAo - b.iAo ;
    return kq ;
} ;
// Hàm tích 2 số phức
// x = a + bi , y = a' + b'i 
// kq = (a.a' - b.b') + (a.b' + b'.a)i
SoPhuc operator * (SoPhuc a, SoPhuc b) {
    SoPhuc kq(0);
    kq.iThuc = a.iThuc * b.iThuc - a.iAo * b.iAo; // 
    kq.iAo = a.iThuc * b.iAo + a.iAo * b.iThuc;
    return kq;
} ;
// Hàm thương 2 số phức
// x = a + bi , y = a' + b'i
// kq = (a.a' + b.b') / mẫu + (b.a' - a.b')i / mẫu 
SoPhuc operator / (SoPhuc a, SoPhuc b) {
    SoPhuc kq(0) ;
    int mau = b.iThuc * b.iThuc + b.iAo * b.iAo; // mẫu = (a')^2 + (b')^2 
    // Mẫu = 0 => Không chia được
    if (mau == 0) {
        cout << "Loi: chia cho 0!\n" ;
        return 0 ;
    }
    kq.iThuc = (a.iThuc * b.iThuc + a.iAo * b.iAo) / mau; // (a.a' + b.b') / mẫu
    kq.iAo = (a.iAo * b.iThuc - a.iThuc * b.iAo) / mau; // (b.a' - a.b') / mẫu

    return kq;
} ;
// Hàm so sánh bằng nhau giữa 2 số phức
bool operator == (SoPhuc a, SoPhuc b) {
    return (a.iThuc == b.iThuc) && (a.iAo == b.iAo) ; // Nếu phần thực và phần ảo của 2 số phức đều giống nhau => bằng nhau
} ;
// Hàm so sánh khác nhau giữa 2 số phức
bool operator != (SoPhuc a, SoPhuc b) {
    return (a.iThuc != b.iThuc) || (a.iAo != b.iAo) ; // Nếu phần thực hoặc phần ảo của 2 số phức khác nhau => khác nhau
} ;

// Hàm destructor của lớp số phức
SoPhuc::~SoPhuc() {} ;