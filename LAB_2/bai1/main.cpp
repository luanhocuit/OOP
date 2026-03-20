#include <iostream>
#include "Date.h"

using namespace std ;

int main () {
    Date a ;
    a.Nhap() ;
    Date ketiep = a.NgayThangNamTiepTheo() ;
    ketiep.Xuat() ; 
    return 0 ;
}