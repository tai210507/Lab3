#include "cDagiac.h"
#include <limits>
using namespace std;

cDiem::cDiem(float _x, float _y) : x(_x), y(_y) {}
void cDiem::nhap() { cin >> x >> y; }
void cDiem::xuat() const { cout << "(" << x << ", " << y << ")"; }
void cDiem::tinhTien(float dx, float dy) { x += dx; y += dy; }
void cDiem::quay(float gocRad) {
    float x_new = x * cos(gocRad) - y * sin(gocRad);
    float y_new = x * sin(gocRad) + y * cos(gocRad);
    x = x_new; y = y_new;
}
void cDiem::thuPhong(float k) { x *= k; y *= k; }

float tinhKhoangCach(cDiem d1, cDiem d2) {
    return sqrt((d1.x - d2.x)*(d1.x - d2.x) + (d1.y - d2.y)*(d1.y - d2.y));
}


cDaGiac::cDaGiac() {
    n = 0;
    dinh = nullptr;
}

// HÀM HỦY:
cDaGiac::~cDaGiac() {
    if (dinh != nullptr) {
        delete[] dinh;
        dinh = nullptr;
    }
}

void cDaGiac::nhap() {
    while (true) {
        cout << "Nhap so dinh cua da giac (n >= 3): ";
        cin >> n;


        if (cin.fail()) {
            cin.clear();


            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "-> LOI: Ban vua nhap chu. Vui long nhap mot SO NGUYEN!\n";
        }

        else if (n < 3) {
            cout << "-> LOI: Da giac phai co it nhat 3 dinh!\n";
        }

        else {
            break;
        }
    }


    dinh = new cDiem[n];


    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh thu " << i + 1 << " (x y): ";
        dinh[i].nhap();
    }
}

void cDaGiac::xuat() {
    cout << "Da giac co " << n << " dinh: ";
    for (int i = 0; i < n; i++) {
        dinh[i].xuat();
        if (i < n - 1) cout << " - ";
    }
    cout << endl;
}

float cDaGiac::tinhChuVi() {
    if (n < 3) return 0;
    float chuVi = 0;
    for (int i = 0; i < n; i++) {
        // Điểm nối tiếp theo
        int j = (i + 1) % n;
        chuVi += tinhKhoangCach(dinh[i], dinh[j]);
    }
    return chuVi;
}

// Sử dụng công thức Shoelace để tính diện tích đa giác tọa độ
float cDaGiac::tinhDienTich() {
    if (n < 3) return 0;
    float dienTich = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        dienTich += (dinh[i].x * dinh[j].y) - (dinh[j].x * dinh[i].y);
    }
    return abs(dienTich) / 2.0;
}

void cDaGiac::tinhTien(float dx, float dy) {
    for (int i = 0; i < n; i++) dinh[i].tinhTien(dx, dy);
}

void cDaGiac::quay(float gocDo) {
    float gocRad = gocDo * PI / 180.0;
    for (int i = 0; i < n; i++) dinh[i].quay(gocRad);
}

void cDaGiac::phongTo(float k) {
    for (int i = 0; i < n; i++) dinh[i].thuPhong(k);
}

void cDaGiac::thuNho(float k) {
    for (int i = 0; i < n; i++) dinh[i].thuPhong(1.0 / k);
}
void cDaGiac::phanLoai() {
    if (n < 3) return;

    bool rẽTrái = false;
    bool rẽPhải = false;

    // Duyệt qua tất cả các đỉnh
    for (int i = 0; i < n; i++) {

        int hienTai = i;
        int tiepTheo = (i + 1) % n;
        int tiepNua = (i + 2) % n;

        // Tạo vector 1 (từ Hiện Tại -> Tiếp Theo)
        float dx1 = dinh[tiepTheo].x - dinh[hienTai].x;
        float dy1 = dinh[tiepTheo].y - dinh[hienTai].y;

        // Tạo vector 2 (từ Tiếp Theo -> Tiếp Nữa)
        float dx2 = dinh[tiepNua].x - dinh[tiepTheo].x;
        float dy2 = dinh[tiepNua].y - dinh[tiepTheo].y;


        float tichCoHuong = (dx1 * dy2) - (dy1 * dx2);

        if (tichCoHuong > 0) rẽTrái = true;
        else if (tichCoHuong < 0) rẽPhải = true;

        // Nếu vừa có rẽ trái, vừa có rẽ phải => Chắc chắn là đa giác lõm
        if (rẽTrái && rẽPhải) {
            cout << "Phan loai: Da giac LOM" << endl;
            return; // Dừng hàm
        }
    }

    // Đa giác lồi + tất cả các cạnh bằng nhau
    bool laDeu = true;
    float canhDauTien = tinhKhoangCach(dinh[0], dinh[1]);
    for(int i = 1; i < n; i++) {
        if(abs(tinhKhoangCach(dinh[i], dinh[(i+1)%n]) - canhDauTien) > 0.0001) {
            laDeu = false;
            break;
        }
    }

    if (laDeu) {
        cout << "Phan loai: Da giac LOI va la Da giac DEU" << endl;
    } else {
        cout << "Phan loai: Da giac LOI" << endl;
    }
}
