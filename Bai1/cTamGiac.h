#ifndef CTAMGIAC_H
#define CTAMGIAC_H

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

// Hàm tính khoảng cách giữa 2 điểm
float tinhKhoangCach(cDiem d1, cDiem d2);


class cTamGiac {
private:
    cDiem A, B, C;
public:
    void nhap();
    void xuat();
    bool kiemTraHopLe();
    void phanLoai();
    float tinhChuVi();
    float tinhDienTich();

    // Các phép biến đổi
    void tinhTien(float dx, float dy);
    void quay(float gocDo);
    void phongTo(float k);
    void thuNho(float k);
};

#endif
