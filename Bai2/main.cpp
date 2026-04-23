#include <iostream>
#include "cDagiac.h"

using namespace std;

int main() {
    cDaGiac dg;

    dg.nhap();

    dg.xuat();
    dg.phanLoai();
    cout << "Chu vi: " << dg.tinhChuVi() << endl;
    cout << "Dien tich: " << dg.tinhDienTich() << endl;

    // Các phép biến đổi
    float dx, dy;
    cout << "\n TINH TIEN \nNhap dx dy: "; cin >> dx >> dy;
    dg.tinhTien(dx, dy);
    dg.xuat();

    float goc;
    cout << "\n QUAY \nNhap goc quay (do): "; cin >> goc;
    dg.quay(goc);
    dg.xuat();

    float k;
    cout << "\n THU / PHONG \nNhap he so k (>0): "; cin >> k;
    if (k > 0) {
        dg.phongTo(k);
        dg.xuat();
    } else {
        cout << "He so k phai lon hon 0!\n";
    }

    return 0;
}
