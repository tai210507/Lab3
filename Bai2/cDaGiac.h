#ifndef CDAGIAC_H
#define CDAGIAC_H

#include <iostream>
#include <cmath>

const float PI = 3.14159265359;

class cDiem {
public:
    float x, y;
    cDiem(float _x = 0, float _y = 0);

    void nhap();
    void xuat() const;
    void tinhTien(float dx, float dy);
    void quay(float gocRad);
    void thuPhong(float k);
};

float tinhKhoangCach(cDiem d1, cDiem d2);

class cDaGiac {
private:
    int n;          // Số đỉnh của đa giác
    cDiem* dinh;    // Con trỏ quản lý mảng động các đỉnh
public:
    cDaGiac();      // Hàm thiết lập
    ~cDaGiac();     // Hàm hủy bỏ

    void nhap();
    void xuat();
    float tinhChuVi();
    float tinhDienTich();
    void phanLoai();
    void tinhTien(float dx, float dy);
    void quay(float gocDo);
    void phongTo(float k);
    void thuNho(float k);
};

#endif
