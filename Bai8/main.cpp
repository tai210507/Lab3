#include "cNhanVienSX.h"
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void nhapDanhSach(vector<cNhanVienSX>& ds) {
    int n;
    while (true) {
        cout << "Nhap so luong nhan vien: ";
        if (cin >> n && n >= 0) {
            char nextChar = cin.peek();
            if (nextChar == '\n' || nextChar == ' ') break;
        }
        cout << "  -> LOI: So luong phai la so nguyen >= 0 (khong chua chu)!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ds.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "\n Nhap thong tin nhan vien thu " << i + 1 << " \n";
        ds[i].nhap();
    }
}

void xuatDanhSach(const vector<cNhanVienSX>& ds) {
    cout << "\n DANH SACH NHAN VIEN SAN XUAT \n";
    for (const auto& nv : ds) nv.xuat();
}

void inNhanVienLuongThapNhat(const vector<cNhanVienSX>& ds) {
    if (ds.empty()) return;
    long long minLuong = ds[0].tinhLuong();
    for (const auto& nv : ds) {
        if (nv.tinhLuong() < minLuong) minLuong = nv.tinhLuong();
    }
    cout << "\n NHAN VIEN CO LUONG THAP NHAT (" << minLuong << ") \n";
    for (const auto& nv : ds) {
        if (nv.tinhLuong() == minLuong) nv.xuat();
    }
}

void inNhanVienTuoiCaoNhat(const vector<cNhanVienSX>& ds) {
    if (ds.empty()) return;
    int minNam = ds[0].layNamSinh();
    for (const auto& nv : ds) {
        if (nv.layNamSinh() < minNam) minNam = nv.layNamSinh();
    }
    cout << "\n NHAN VIEN CO TUOI CAO NHAT (Nam sinh: " << minNam << ") \n";
    for (const auto& nv : ds) {
        if (nv.layNamSinh() == minNam) nv.xuat();
    }
}

int main() {
    vector<cNhanVienSX> danhSachNV;

    nhapDanhSach(danhSachNV);

    if (danhSachNV.empty()) {
        cout << "\nDanh sach trong!\n";
        return 0;
    }

    xuatDanhSach(danhSachNV);
    inNhanVienLuongThapNhat(danhSachNV);

    long long tong = 0;
    for(auto& nv : danhSachNV) tong += nv.tinhLuong();
    cout << "\nTong luong phai tra: " << tong << "\n";

    inNhanVienTuoiCaoNhat(danhSachNV);

    sort(danhSachNV.begin(), danhSachNV.end(), [](const cNhanVienSX& a, const cNhanVienSX& b) {
        return a.tinhLuong() < b.tinhLuong();
    });

    cout << "\n DANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG \n";
    xuatDanhSach(danhSachNV);

    return 0;
}
