#include "cDaThuc.h"
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;


cDaThuc::cDaThuc() {
    bac = 0;
    heSo = new float[1];
    heSo[0] = 0;
}

cDaThuc::cDaThuc(int b) {
    if (b < 0) b = 0;
    bac = b;
    heSo = new float[bac + 1];
    for (int i = 0; i <= bac; i++) heSo[i] = 0;
}

cDaThuc::cDaThuc(const cDaThuc& khac) {
    bac = khac.bac;
    heSo = new float[bac + 1];
    for (int i = 0; i <= bac; i++) {
        heSo[i] = khac.heSo[i];
    }
}

cDaThuc::~cDaThuc() {
    if (heSo != nullptr) {
        delete[] heSo;
        heSo = nullptr;
    }
}

cDaThuc& cDaThuc::operator=(const cDaThuc& khac) {
    if (this != &khac) {
        delete[] heSo; // Xóa mảng cũ
        bac = khac.bac;
        heSo = new float[bac + 1];
        for (int i = 0; i <= bac; i++) {
            heSo[i] = khac.heSo[i];
        }
    }
    return *this;
}


void cDaThuc::chuanHoa() {
    while (bac > 0 && heSo[bac] == 0) {
        bac--;
    }
}

void cDaThuc::nhap() {

    while (true) {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;

        if (cin.fail()) {
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "-> LOI: Bac da thuc phai la SO NGUYEN. Vui long nhap lai!\n";
        } else {
            if (bac < 0) bac = 0; // Xử lý số âm
            break; // Thoát vòng lặp nếu nhập đúng
        }
    }

    delete[] heSo;
    heSo = new float[bac + 1];


    for (int i = bac; i >= 0; i--) {
        while (true) {
            cout << "Nhap he so cua x^" << i << ": ";
            cin >> heSo[i];

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "-> LOI: He so phai la SO. Vui long nhap lai!\n";
            } else {
                break; // Thoát vòng lặp nếu nhập đúng số
            }
        }
    }

    chuanHoa();
}

void cDaThuc::xuat() const {
    if (bac == 0 && heSo[0] == 0) {
        cout << "0\n";
        return;
    }

    bool laPhanTuDauTien = true;
    for (int i = bac; i >= 0; i--) {
        if (heSo[i] == 0) continue; // Bỏ qua hệ số 0

        // In dấu cộng/trừ
        if (heSo[i] > 0 && !laPhanTuDauTien) cout << " + ";
        else if (heSo[i] < 0) {
            if (laPhanTuDauTien) cout << "-";
            else cout << " - ";
        }

        // In giá trị hệ số
        float giaTriTuyetDoi = abs(heSo[i]);
        if (giaTriTuyetDoi != 1 || i == 0) cout << giaTriTuyetDoi;

        // In x và số mũ
        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }

        laPhanTuDauTien = false;
    }
    cout << endl;
}

//TÍNH TOÁN
float cDaThuc::tinhGiaTri(float x) const {
    float ketQua = 0;
    for (int i = 0; i <= bac; i++) {
        ketQua += heSo[i] * pow(x, i);
    }
    return ketQua;
}

cDaThuc cDaThuc::cong(const cDaThuc& khac) const {
    int bacMax = (bac > khac.bac) ? bac : khac.bac;
    cDaThuc kq(bacMax);

    for (int i = 0; i <= bacMax; i++) {
        float hs1 = (i <= bac) ? heSo[i] : 0;
        float hs2 = (i <= khac.bac) ? khac.heSo[i] : 0;
        kq.heSo[i] = hs1 + hs2;
    }
    kq.chuanHoa();
    return kq;
}

cDaThuc cDaThuc::tru(const cDaThuc& khac) const {
    int bacMax = (bac > khac.bac) ? bac : khac.bac;
    cDaThuc kq(bacMax);

    for (int i = 0; i <= bacMax; i++) {
        float hs1 = (i <= bac) ? heSo[i] : 0;
        float hs2 = (i <= khac.bac) ? khac.heSo[i] : 0;
        kq.heSo[i] = hs1 - hs2;
    }
    kq.chuanHoa();
    return kq;
}
