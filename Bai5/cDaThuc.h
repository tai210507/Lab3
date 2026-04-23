#ifndef CDATHUC_H
#define CDATHUC_H

class cDaThuc {
private:
    int bac;        // Bậc của đa thức (n)
    float* heSo;    // Mảng động lưu hệ số

    // Hàm hỗ trợ nội bộ: Chuẩn hóa bậc đa thức (bỏ các hệ số 0 ở bậc cao nhất)
    void chuanHoa();

public:
    // Các hàm thiết lập & Hủy bỏ
    cDaThuc();                          // Khởi tạo bậc 0
    cDaThuc(int b);                     // Khởi tạo bậc n
    cDaThuc(const cDaThuc& khac);
    ~cDaThuc();

    cDaThuc& operator=(const cDaThuc& khac); // Toán tử gán

    void nhap();
    void xuat() const;

    float tinhGiaTri(float x) const;

    // Cộng trừ trả về một đa thức mới
    cDaThuc cong(const cDaThuc& khac) const;
    cDaThuc tru(const cDaThuc& khac) const;
};

#endif
