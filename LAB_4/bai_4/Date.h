#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std ;

class cDate {
private :
    int iNgay, iThang, iNam ;
public :
    cDate() ;
    friend bool NamNhuan(int y) ;
    friend int dayInMonth(int m, int y) ;
    friend istream& operator >> (istream& in, cDate &a) ;
    friend ostream& operator << (ostream& out, const cDate &a) ;
    long long convertToDays() const ;
    friend cDate ConvertToDate(long long days) ;
    friend cDate operator + (cDate &a, int x) ;
    friend cDate operator - (cDate &a, int x) ;
    friend cDate operator ++ (cDate &a) ;
    friend cDate operator ++ (cDate &a, int) ;
    friend cDate operator -- (cDate &a) ;
    friend cDate operator -- (cDate &a, int) ;
    friend long long operator - (const cDate &a, const cDate &b) ;
    friend double LaiSuatDon(const cDate &a, const cDate &b, double x, double r) ;
    friend double LaiSuatKep(const cDate &a, const cDate &b, double x, double r) ;
    ~cDate() ;
} ;
#endif