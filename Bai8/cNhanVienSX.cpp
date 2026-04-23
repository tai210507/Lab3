#include "cNhanVienSX.h"
#include <iomanip>
#include <limits>
#include <cctype>

cNhanVienSX::cNhanVienSX() {
    maNhanVien = "";
    hoTen = "";
    ngaySinh = {1, 1, 2000};
    soSanPham = 0;
    donGia = 0;
}

string cNhanVienSX::getHoTen() const { return hoTen; }
int cNhanVienSX::layNamSinh() const { return ngaySinh.nam; }
long long cNhanVienSX::tinhLuong() const { return (long long)soSanPham * donGia; }


bool kiemTraTenHopLe(const string& ten) {
    if (ten.empty()) return false;
    for (char c : ten) {
        if (isdigit(c)) return false;
    }
    return true;
}


long long nhapSoNguyenAnToan(const string& thongBao) {
    long long giaTri;
    while (true) {
        cout << thongBao;
        if (cin >> giaTri && giaTri >= 0) {
            char nextChar = cin.peek();
            if (nextChar == '\n' || nextChar == ' ') {
                return giaTri;
            }
        }
        cout << "  -> LOI: Vui long chi nhap so nguyen >= 0 (khong chua chu)!\n";
        cin.clear(); // Xóa trạng thái lỗi của cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void cNhanVienSX::nhap() {
    cout << "Nhap ma nhan vien: ";
    cin >> maNhanVien;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        if (kiemTraTenHopLe(hoTen)) break;
        cout << "  -> LOI: Ten khong duoc chua chu so hoac de trong!\n";
    }

    while (true) {
        cout << "Nhap ngay sinh (ngay thang nam): ";
        if (cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam) {
            if (ngaySinh.ngay > 0 && ngaySinh.ngay <= 31 &&
                ngaySinh.thang > 0 && ngaySinh.thang <= 12 &&
                ngaySinh.nam > 1900) {
                break;
            }
        }
        cout << "  -> LOI: Ngay thang nam phai la so va hop le (khong chua chu)!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    soSanPham = nhapSoNguyenAnToan("Nhap so san pham da gia cong: ");
    donGia = nhapSoNguyenAnToan("Nhap don gia 1 san pham: ");
}

void cNhanVienSX::xuat() const {
    cout << "Ma NV: " << maNhanVien
         << "  Ho ten: " << hoTen
         << "  NS: " << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam
         << "  So SP: " << soSanPham
         << "  Don gia: " << donGia
         << "  Luong: " << tinhLuong() << "\n";
}
