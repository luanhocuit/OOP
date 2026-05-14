#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    cTime t1, t2, res;
    int seconds;
    // 1. Test operator >> (Nhap thoi gian)
    cout << "Nhap thoi gian t1:" << endl;
    cin >> t1;
    cout << "Thoi gian ban vua nhap: " << t1 << endl;
    // 2. Test operator + (Cong them giay)
    cout << "Nhap so giay muon CONG vao t1: ";
    cin >> seconds;
    res = t1 + seconds;
    cout << t1 << " + " << seconds << "s = " << res << endl;
    // 3. Test operator - (Tru di giay)
    cout << "Nhap so giay muon TRU di tu t1: ";
    cin >> seconds;
    res = t1 - seconds;
    cout << t1 << " - " << seconds << "s = " << res << endl;
    cout << '\n' ;
    // 4. Test operator ++ (Prefix)
    cout << "Gia tri truoc: " << t1 << endl;
    cout << "Gia tri khi thuc thi ++t1: " << ++t1 << endl;
    cout << "Gia tri sau do: " << t1 << endl;
    cout << '\n' ;
    // 5. Test operator ++ (Postfix)
    cout << "Gia tri truoc: " << t1 << endl;
    cout << "Gia tri khi thuc thi t1++: " << t1++ << endl;
    cout << "Gia tri sau do: " << t1 << endl;
    cout << '\n' ;
    // 6. Test operator -- (Prefix)
    cout << "Gia tri truoc: " << t1 << endl;
    cout << "Gia tri khi thuc thi --t1: " << --t1 << endl;
    cout << '\n' ;
    // 7. Test operator -- (Postfix)
    cout << "Gia tri truoc: " << t1 << endl;
    cout << "Gia tri khi thuc thi t1--: " << t1-- << endl;
    cout << "Gia tri sau do: " << t1 << endl;
    
    return 0;
}