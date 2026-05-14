#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
#include <vector>
using namespace std ;

class DaThuc {
private : 
    int bac ;
    vector<double> heso ;
public :
    DaThuc(int bac = 0) ;
    ~DaThuc() ;
    double tinhGiaTri(double x) ;
    friend istream& operator >> (istream& in, DaThuc &a) ;
    friend ostream& operator << (ostream& out, DaThuc a) ;
    friend DaThuc operator + (DaThuc a, DaThuc b) ;
    friend DaThuc operator - (DaThuc a, DaThuc b) ;
} ;

#endif