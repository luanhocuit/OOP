#ifndef TIME_H
#define TIME_H

class cTime {
private:
    int iGio, iPhut, iGiay ;
public:
    cTime() ;
    friend istream& operator >> (istream& in, cTime &x) ;
    friend ostream& operator << (ostream& out, cTime &x) ;
    friend cTime operator + (cTime a, int x) ;
    friend cTime operator - (cTime a, int x) ;
    friend cTime operator ++ (cTime a) ;
    friend cTime operator ++ (cTime a, int) ; 
    friend cTime operator -- (cTime a) ;
    friend cTime operator -- (cTime a, int) ;
    void TinhCongThemMotGiay();
    ~cTime() ;
} ;

#endif