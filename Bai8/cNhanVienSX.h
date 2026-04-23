#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <iostream>
#include <string>

using namespace std;

struct Date {
    int ngay, thang, nam;
};

class cNhanVienSX {
private:
    string maNhanVien;
    string hoTen;
    Date ngaySinh;
    int soSanPham;
    long long donGia;

public:
    cNhanVienSX();

    string getHoTen() const;
    int layNamSinh() const;

    void nhap();
    void xuat() const;
    long long tinhLuong() const;
};

#endif
