#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std ;

class cTime {
private:
    int iGio, iPhut, iGiay ;
public:
    cTime() ;
    friend istream& operator >> (istream& in, cTime &x) ;
    friend ostream& operator << (ostream& out, const cTime &x) ;
    long long ConvertToSeconds() ;
    cTime TotalToSeconds(long total) ;
    friend cTime operator + (cTime a, int x) ;
    friend cTime operator - (cTime a, int x) ;
    friend cTime operator ++ (cTime &a) ;
    friend cTime operator ++ (cTime &a, int) ; 
    friend cTime operator -- (cTime &a) ;
    friend cTime operator -- (cTime &a, int) ;
    ~cTime() ;
} ;

#endif