#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std ;

class SoPhuc {
private:
    int iThuc, iAo ;
public:
    SoPhuc(int thuc = 0, int ao = 0) ;
    friend istream& operator >> (istream& in, SoPhuc &x) ;
    friend ostream& operator << (ostream& out, SoPhuc &x) ;
    friend SoPhuc operator + (SoPhuc a, SoPhuc b) ;
    friend SoPhuc operator - (SoPhuc a, SoPhuc b) ;
    friend SoPhuc operator * (SoPhuc a, SoPhuc b) ;
    friend SoPhuc operator / (SoPhuc a, SoPhuc b) ;
    friend bool operator == (SoPhuc a, SoPhuc b) ;
    friend bool operator != (SoPhuc a, SoPhuc b) ;
    ~SoPhuc() ;
} ;
#endif