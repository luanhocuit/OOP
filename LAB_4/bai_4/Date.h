#ifndef DATE_H
#define DATE_H

class cDate {
private :
    int iNgay, iThang, iNam ;
public :
    cDate() ;
    friend istream& operator >> (istream& in, cDate &a) ;
    friend ostream& operator << (ostream& out, cDate a) ;
    friend cDate operator + (cDate &a, cDate &b) ;
    friend cDate operator - (cDate &a, cDate &b) ;
    friend cDate operator ++ (cDate &a) ;
    friend cDate operator ++ (cDate &a, int) ;
    friend cDate operator -- (cDate &a) ;
    friend cDate operator -- (cDate &a, int) ;
    friend cDate operator - (cDate &a) ;
    double LaiSuat(cDate a, cDate b, int x) ;
    ~cDate() ;
} ;
#endif