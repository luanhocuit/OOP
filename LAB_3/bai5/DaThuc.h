#ifndef DATHUC_H
#define DATHUC_H

#include <bits/stdc++.h>
using namespace std ;

class cDaThuc {
private :
    int n ;
    vector<double> a; 
public :
    cDaThuc(int bac = 0) ;
    ~cDaThuc() ;
    double tinhGiaTri(int x) ;
    friend istream& operator >> (istream& in, cDaThuc &a) ;
    friend ostream& operator << (ostream& out, cDaThuc a) ;
    friend cDaThuc operator + (cDaThuc a, cDaThuc b) ;
    friend cDaThuc operator - (cDaThuc a, cDaThuc b) ;
} ;
#endif