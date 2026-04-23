#include <iostream>
#include "cTamgiac.h"

using namespace std;

int main() {
    cTamGiac tg;
    tg.nhap();

    if(tg.kiemTraHopLe()) {
        tg.xuat();
        tg.phanLoai();
        cout << "Chu vi: " << tg.tinhChuVi() << endl;
        cout << "Dien tich: " << tg.tinhDienTich() << endl;
        float dx, dy;
        cout << "\n THUC HIEN TINH TIEN ";
        cout << "\nNhap do doi tren truc Ox (dx): "; cin >> dx;
        cout << "Nhap do doi tren truc Oy (dy): "; cin >> dy;

        tg.tinhTien(dx, dy);
        cout << "=> Tam giac sau khi tinh tien: ";
        tg.xuat();

        float gocDo;
        cout << "\n THUC HIEN QUAY ";
        cout << "\nNhap goc quay (tinh bang do, >0 la nguoc chieu kim dong ho): ";
        cin >> gocDo;

        tg.quay(gocDo);
        cout << "=> Tam giac sau khi quay " << gocDo << " do: ";
        tg.xuat();

        float k;
        cout << "\n THUC HIEN THU / PHONG ";
        cout << "\nNhap he so ti le k (k > 1 de phong to, 0 < k < 1 de thu nho): ";
        cin >> k;

        if (k > 0) {
            // Lưu ý: Hàm phongTo(k) thực chất là nhân tọa độ với k.
            // Nên nếu k = 0.5 (nhỏ hơn 1), nó sẽ tự động thành phép thu nhỏ.
            tg.phongTo(k);
            cout << "=> Tam giac sau khi thay doi ti le " << k << " lan: ";
            tg.xuat();
        } else {
            cout << "Loi: He so ti le k phai lon hon 0!\n";
        }

    } else {
        cout << "Loi: 3 diem ban nhap cung nam tren 1 duong thang hoac trung nhau!\n";
    }

    return 0;
}
