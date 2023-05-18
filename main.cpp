
#include "function.cpp"

int main() {
    int soSinhVien = 0;
    int luaChon = 0;
    bool check = true;
    while (check == true) {
        menu();
        cin >> luaChon;
        switch (luaChon) {
        case 1:
            system("cls");
            nhapSinhVien(soSinhVien, sinhvien);
            break;
        case 2:
            system("cls");
            xemDanhSach(soSinhVien, sinhvien);
            break;
        case 3:
            system("cls");
            suaThongTin(soSinhVien, sinhvien);
            break;
        case 4:
            system("cls");
            timKiem(soSinhVien, sinhvien);
            break;
        case 5:
            system("cls");
            xoaSinhVien(soSinhVien, sinhvien);
            break;
        case 6:
            system("cls");
            thongKe(soSinhVien, sinhvien);
            break;
        case 7:
            system("cls");
            docFile(soSinhVien, sinhvien);
            cout << "Looi";
            break;
        case 8:
            system("cls");
            ghiFile(soSinhVien, sinhvien);
            break;
        case 0:
            check = false;
            break;
        }
        system("pause");
    }
    return 0;
}