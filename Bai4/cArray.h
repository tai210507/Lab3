#ifndef CARRAY_H
#define CARRAY_H

class cArray {
private:
    int* a;
    int n;


    bool laNguyenTo(int so) const;

public:
    cArray();
    ~cArray(); // Hàm hủy để giải phóng bộ nhớ

    void taoNgauNhien(int soPhanTu);
    void xuat() const;

    int demGiaTri(int x) const;
    bool kiemTraTangDan() const;

    bool timLeNhoNhat(int &ketQua) const;
    bool timNguyenToLonNhat(int &ketQua) const;

    void sapXepTang();
    void sapXepGiam();
};

#endif
