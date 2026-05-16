#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    cTime t1, t2, res;
    int seconds;
    cout << "Nhap thoi gian t1:" << '\n' ; cin >> t1;
    cout << "Thoi gian ban vua nhap: " << t1 << '\n' ;
    
    cout << "Nhap so giay muon CONG vao t1: ";
    cin >> seconds ; res = t1 + seconds;
    cout << t1 << " + " << seconds << "s = " << res << '\n' ;

    cout << "Nhap so giay muon TRU di tu t1: ";
    cin >> seconds ; res = t1 - seconds;
    cout << t1 << " - " << seconds << "s = " << res << '\n' ;

    cout << "\n---Toan tu ++ (prefix)---\n" ;
    cout << "Gia tri truoc: " << t1 << '\n' ;
    cout << "Gia tri khi thuc thi ++t1 : " << ++t1 << '\n' ;
    cout << "Gia tri sau do: " << t1 << '\n' ;

    cout << "\n---Toan tu ++ (postfix)---\n" ;
    cout << "Gia tri truoc: " << t1 << '\n' ;
    cout << "Gia tri khi thuc thi t1++ : " << t1++ << '\n' ;
    cout << "Gia tri sau do: " << t1 << '\n' ;

    cout << "\n---Toan tu -- (prefix)---\n" ;
    cout << "Gia tri truoc: " << t1 << '\n' ;
    cout << "Gia tri khi thuc thi --t1 : " << --t1 << '\n' ;

    cout << "\n---Toan tu -- (postfix)---\n" ;
    cout << "Gia tri truoc: " << t1 << '\n' ;
    cout << "Gia tri khi thuc thi t1-- : " << t1-- << '\n' ;
    cout << "Gia tri sau do: " << t1 << '\n' ;
    
    return 0;
}