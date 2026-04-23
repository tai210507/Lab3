#include <iostream>
#include "cArray.h"

using namespace std;

int main() {
    cArray arr;
    int n;

    cout << "Nhap so luong phan tu muon tao ngau nhien: ";
    cin >> n;

    arr.taoNgauNhien(n);
    cout << "\n MANG VUA TAO \n";
    arr.xuat();

    // Kiểm tra tăng dần
    if (arr.kiemTraTangDan()) {
        cout << "\n=> Mang hien tai DANG sap xep tang dan.\n";
    } else {
        cout << "\n=> Mang hien tai KHONG tang dan.\n";
    }

    // Đếm số lần xuất hiện
    int x;
    cout << "\nNhap gia tri x can dem: ";
    cin >> x;
    cout << "=> So lan " << x << " xuat hien trong mang: " << arr.demGiaTri(x) << endl;

    // Tìm số lẻ nhỏ nhất
    int leNhoNhat;
    if (arr.timLeNhoNhat(leNhoNhat)) {
        cout << "\n=> So le nho nhat trong mang la: " << leNhoNhat << endl;
    } else {
        cout << "\n=> Mang khong co so le nao!" << endl;
    }

    // Tìm số nguyên tố lớn nhất
    int nguyenToLonNhat;
    if (arr.timNguyenToLonNhat(nguyenToLonNhat)) {
        cout << "=> So nguyen to lon nhat trong mang la: " << nguyenToLonNhat << endl;
    } else {
        cout << "=> Mang khong co so nguyen to nao!" << endl;
    }

    // Sắp xếp
    cout << "\n MANG SAU KHI SAP XEP TANG DAN\n";
    arr.sapXepTang();
    arr.xuat();

    cout << "\n MANG SAU KHI SAP XEP GIAM DAN \n";
    arr.sapXepGiam();
    arr.xuat();

    return 0;
}
