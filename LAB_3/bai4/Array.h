#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std ;

class cArray {
private :
    int n ;
    int *Mang ;
public :
    cArray() ;
    cArray(int size) ;
    ~cArray() ;
    void TaoMang() ;
    void XuatMang() ;
    void SortArray() ;
    int DemSoLanX(int x) ;
    int TimLeMin() ;
    int TimMaxNguyenTo() ;
    bool CheckTangDan() ;
} ;

#endif