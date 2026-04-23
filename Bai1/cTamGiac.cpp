#include "cTamgiac.h"
#include <limits>

using namespace std;

cDiem::cDiem(float _x, float _y) : x(_x), y(_y) {}

void cDiem::nhap() {
    while (true) {
        cin >> x >> y;

        if (cin.fail()) {

            cin.clear();


            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "-> Loi: Ban phai nhap so. Vui long nhap lai toa do: ";
        } else {
            // Nếu nhập đúng là số, thoát khỏi vòng lặp
            break;
        }
    }
}

void cDiem::xuat() const {
    cout << "(" << x << ", " << y << ")";
}

void cDiem::tinhTien(float dx, float dy) {
    x += dx;
    y += dy;
}

void cDiem::quay(float gocRad) {
    float x_new = x * cos(gocRad) - y * sin(gocRad);
    float y_new = x * sin(gocRad) + y * cos(gocRad);
    x = x_new;
    y = y_new;
}

void cDiem::thuPhong(float k) {
    x *= k;
    y *= k;
}

// Hàm tính khoảng cách
float tinhKhoangCach(cDiem d1, cDiem d2) {
    return sqrt((d1.x - d2.x)*(d1.x - d2.x) + (d1.y - d2.y)*(d1.y - d2.y));
}

void cTamGiac::nhap() {
    cout << "Nhap toa do dinh A (x y): "; A.nhap();
    cout << "Nhap toa do dinh B (x y): "; B.nhap();
    cout << "Nhap toa do dinh C (x y): "; C.nhap();
}

void cTamGiac::xuat() {
    cout << "Tam giac tao boi 3 dinh: ";
    A.xuat(); cout << " - "; B.xuat(); cout << " - "; C.xuat(); cout << endl;
}

bool cTamGiac::kiemTraHopLe() {
    float a = tinhKhoangCach(B, C);
    float b = tinhKhoangCach(A, C);
    float c = tinhKhoangCach(A, B);
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void cTamGiac::phanLoai() {
    if (!kiemTraHopLe()) {
        cout << "Day khong phai la tam giac hop le.\n";
        return;
    }
    float a = tinhKhoangCach(B, C);
    float b = tinhKhoangCach(A, C);
    float c = tinhKhoangCach(A, B);

    float eps = 0.0001; // Sai số khi so sánh số thực
    bool vuong = abs(a*a + b*b - c*c) < eps || abs(a*a + c*c - b*b) < eps || abs(b*b + c*c - a*a) < eps;
    bool can = abs(a-b) < eps || abs(a-c) < eps || abs(b-c) < eps;
    bool deu = abs(a-b) < eps && abs(a-c) < eps;

    cout << "Loai tam giac: ";
    if (deu) cout << "Deu\n";
    else if (vuong && can) cout << "Vuong can\n";
    else if (vuong) cout << "Vuong\n";
    else if (can) cout << "Can\n";
    else cout << "Thuong\n";
}

float cTamGiac::tinhChuVi() {
    return tinhKhoangCach(B, C) + tinhKhoangCach(A, C) + tinhKhoangCach(A, B);
}

float cTamGiac::tinhDienTich() {
    float a = tinhKhoangCach(B, C);
    float b = tinhKhoangCach(A, C);
    float c = tinhKhoangCach(A, B);
    float p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void cTamGiac::tinhTien(float dx, float dy) {
    A.tinhTien(dx, dy);
    B.tinhTien(dx, dy);
    C.tinhTien(dx, dy);
}

void cTamGiac::quay(float gocDo) {
    float gocRad = gocDo * PI / 180.0;
    A.quay(gocRad);
    B.quay(gocRad);
    C.quay(gocRad);
}

void cTamGiac::phongTo(float k) {
    A.thuPhong(k);
    B.thuPhong(k);
    C.thuPhong(k);
}

void cTamGiac::thuNho(float k) {
    A.thuPhong(1.0/k);
    B.thuPhong(1.0/k);
    C.thuPhong(1.0/k);
}
