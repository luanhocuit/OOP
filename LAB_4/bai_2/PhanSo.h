#ifndef PHANSO_H
#define PHANSO_H

class PS {
private :
    int iTu, iMau ;
public : 
    PS(int tu = 0, int mau = 1) ;
    void rutgon() ;
    friend istream& operator >> (istream& in, PS &x) ;
    friend ostream& operator << (ostream& out, PS x) ;
    friend PS operator + (PS a, PS b) ;
    friend PS operator - (PS a, PS b) ;
    friend PS operator * (PS a, PS b) ;
    friend PS operator / (PS a, PS b) ;
    friend bool operator == (PS a, PS b) ;
    friend bool operator > (PS a, PS b) ;
    friend bool operator < (PS a, PS b) ;
    ~PS() ;
} ;

#endif