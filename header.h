
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <regex>

using namespace std;

struct MonHoc {
    string ten;
    int tinChi;
    float diemTX1;
    float diemTX2;
    float diemKT;
    float diemTK;
    float diemHe4;
    string diemChu;
};

struct SinhVien {
    string ten;
    string maSinhVien;
    string lop;
    float GPA;
    int soMonHoc;
    MonHoc monhoc[100];
}; SinhVien sinhvien[100];

void menu();
void nhapSinhVien(int& soSinhVien, SinhVien sinhvien[]);
void nhapMonHoc(int viTriSV, SinhVien sinhvien[]);
void nhapDiem(int viTriSV, int viTriMH, SinhVien sinhvien[]);
void tinhDiem(int viTiSV, int viTriMH, SinhVien sinhvien[]);
void quyDoiDiem(int viTiSV, int viTriMH, SinhVien sinhvien[]);
void tinhGPA(int viTiSV, SinhVien sinhvien[]);
void xemDanhSach(int viTiSV, SinhVien sinhvien[]);
void suaThongTin(int soSinhVien, SinhVien sinhvien[]);
void xemTimKiem(int viTriSV, SinhVien sinhvien[]);
void timKiem(int soSinhVien, SinhVien sinhvien[]);
void xoaSinhVien(int& soSinhVien, SinhVien sinhvien[]);
void docFile(int& soSinhVien, SinhVien sinhvien[]);
void ghiFile(int soSinhVien, SinhVien sinhvien[]);
void thongKe(int soSinhVien, SinhVien sinhvien[]);
string kiemTraTen();
string kiemTraTenMonHoc();
int kiemTraSo();
int kiemTraSoLuong();
string kiemTraMaSinhVien(int soSinhVien, SinhVien sinhvien[]);
double kiemTraDiem();
