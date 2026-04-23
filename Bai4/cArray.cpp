#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


cArray::cArray() {
    a = nullptr;
    n = 0;
}

cArray::~cArray() {
    if (a != nullptr) {
        delete[] a;
        a = nullptr;
    }
}

//Hàm kiểm tra nguyên tố
bool cArray::laNguyenTo(int so) const{
    if (so < 2) return false;
    for (int i = 2; i * i <= so; i++) {
        if (so % i == 0) return false;
    }
    return true;
}

// Các phương thức chính
void cArray::taoNgauNhien(int soPhanTu) {
    if (a != nullptr) {
        delete[] a; // Xóa mảng cũ nếu đã có
    }

    n = soPhanTu;
    if (n <= 0) {
        a = nullptr;
        return;
    }

    a = new int[n];

    // Khởi tạo hạt giống ngẫu nhiên
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; // Sinh số ngẫu nhiên từ 0 đến 99
    }
}

void cArray::xuat() const {
    if (n <= 0 || a == nullptr) {
        cout << "Mang rong." << endl;
        return;
    }
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}

int cArray::demGiaTri(int x) const {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) dem++;
    }
    return dem;
}

bool cArray::kiemTraTangDan() const {
    if (n <= 1) return true; // Mảng 0 hoặc 1 phần tử mặc định là tăng dần
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i+1]) return false; // Phát hiện điểm giảm là sai ngay
    }
    return true;
}

bool cArray::timLeNhoNhat(int &ketQua) const {
    bool timThay = false;
    int minLe;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) { // Nếu là số lẻ
            if (!timThay) {
                minLe = a[i];
                timThay = true;
            } else if (a[i] < minLe) {
                minLe = a[i];
            }
        }
    }

    if (timThay) ketQua = minLe;
    return timThay;
}

bool cArray::timNguyenToLonNhat(int &ketQua) const {
    bool timThay = false;
    int maxNT;

    for (int i = 0; i < n; i++) {
        if (laNguyenTo(a[i])) {
            if (!timThay) {
                maxNT = a[i];
                timThay = true;
            } else if (a[i] > maxNT) {
                maxNT = a[i];
            }
        }
    }

    if (timThay) ketQua = maxNT;
    return timThay;
}

// Sử dụng thuật toán Selection Sort
void cArray::sapXepTang() {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        // Hoán vị
        swap(a[i], a[min_idx]);
    }
}

void cArray::sapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_idx]) {
                max_idx = j;
            }
        }
        swap(a[i], a[max_idx]);
    }
}
