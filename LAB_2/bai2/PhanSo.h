#ifndef PHANSO_H
#define PHANSO_H
class PS {
private :
    int iTu, iMau ;
public : 
    void Nhap() ;
    void Xuat() ;
    int SoSanh(PS a, PS b) ; // 1 : a > b, 0 : a == b, -1 : a < b
    void RutGon() ;
    PS tong(PS b),
       hieu(PS b),
       tich(PS b),
       thuong(PS b) ;
} ;

#endif