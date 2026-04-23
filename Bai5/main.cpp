#include <iostream>
#include "cDaThuc.h"
#include <limits>
using namespace std;

int main() {
    cDaThuc P, Q;

    cout << "NHAP DA THUC P(x)\n";
    P.nhap();
    cout << "P(x) = "; P.xuat();

    cout << "\n NHAP DA THUC Q(x) \n";
    Q.nhap();
    cout << "Q(x) = "; Q.xuat();

    // Tính giá trị
    float x;
    while (true) {
        cout << "\nNhap gia tri x de tinh P(x): ";
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "-> LOI: Gia tri x phai la SO. Vui long nhap lai!\n";
        } else {
            break;
        }
    }
    cout << "=> P(" << x << ") = " << P.tinhGiaTri(x) << endl;
    // Cộng trừ
    cDaThuc Tong = P.cong(Q);
    cout << "\n KET QUA \n";
    cout << "P(x) + Q(x) = "; Tong.xuat();

    cDaThuc Hieu = P.tru(Q);
    cout << "P(x) - Q(x) = "; Hieu.xuat();

    return 0;
}
