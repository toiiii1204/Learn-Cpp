#include "header.h"

void menu() {
    system("cls");
    cout << setw(103) << "**************************************************" << endl;
    cout << setw(103) << "****   Chuong trinh quan ly diem sinh vien    ****" << endl;
    cout << setw(103) << "**************************************************" << endl;
    cout << setw(103) << "****      1.Nhap thong tin sinh vien          ****" << endl;
    cout << setw(103) << "****      2.Xem danh sach sinh vien           ****" << endl;
    cout << setw(103) << "****      3.Sua thong tin sinh vien           ****" << endl;
    cout << setw(103) << "****      4.Tim kiem thong tin sinh vien      ****" << endl;
    cout << setw(103) << "****      5.Xoa thong tin sinh vien           ****" << endl;
    cout << setw(103) << "****      6.Thong ke danh sach sinh vien      ****" << endl;
    cout << setw(103) << "****      7.Doc file thong tin sinh vien      ****" << endl;
    cout << setw(103) << "****      8.Luu thong tin sinh vien vao file  ****" << endl;
    cout << setw(103) << "****      0.Thoat chuong trinh                ****" << endl;
    cout << setw(103) << "**************************************************" << endl;
    cout << setw(103) << "**************************************************" << endl;
    cout << "\nVui long nhap lua chon cua ban: " << endl;
}

void nhapSinhVien(int &soSinhVien, SinhVien sinhvien[]) {
    int i = soSinhVien;
    cout << "Nhap so luong sinh vien: ";
    int soLuong = kiemTraSoLuong();
    while (soLuong > 0) {
        cout << "Nhap ten sinh vien thu " << (i + 1) << ": ";
        sinhvien[i].ten = kiemTraTen(); 
        cout << "Nhap ma sinh vien gom 7 chu so (0.......): ";
        sinhvien[i].maSinhVien = kiemTraMaSinhVien(soSinhVien, sinhvien);
        cout << "Nhap ten lop cua sinh vien: ";
        cin >> sinhvien[i].lop;
        cin.ignore();
        cout << "Nhap so luong mon hoc: ";
        sinhvien[i].soMonHoc = kiemTraSoLuong();
        nhapMonHoc(i, sinhvien);
        cout << endl;
        i++;
        soSinhVien++;
        soLuong--;
    }
    cout << "Nhap du lieu thanh cong!" << endl;
}

void nhapMonHoc(int viTriSV, SinhVien sinhvien[]) {
    for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
        cout << "Nhap ten mon hoc thu " << (i + 1) << ": ";
        sinhvien[viTriSV].monhoc[i].ten = kiemTraTenMonHoc();
        cout << "Nhap so tin chi: ";
        sinhvien[viTriSV].monhoc[i].tinChi = kiemTraSoLuong();
        nhapDiem(viTriSV, i, sinhvien);
    }
}

void nhapDiem(int viTriSV, int viTriMH, SinhVien sinhvien[]) {
    cout << "Nhap diem thuong xuyen 1: " << endl;
    sinhvien[viTriSV].monhoc[viTriMH].diemTX1 = kiemTraDiem();
    cout << "Nhap diem thuong xuyen 2: " << endl;
    sinhvien[viTriSV].monhoc[viTriMH].diemTX2 = kiemTraDiem();
    cout << "Nhap diem ket thuc mon: " << endl;
    sinhvien[viTriSV].monhoc[viTriMH].diemKT = kiemTraDiem();
    tinhDiem(viTriSV, viTriMH, sinhvien);
    quyDoiDiemHe4(viTriSV, viTriMH, sinhvien);
    quyDoiDiemChu(viTriSV, viTriMH, sinhvien);
    GPA(viTriSV, sinhvien);
}

void tinhDiem(int viTriSV, int viTriMH, SinhVien sinhvien[]) {
    sinhvien[viTriSV].monhoc[viTriMH].diemTK = (sinhvien[viTriSV].monhoc[viTriMH].diemTX1 + sinhvien[viTriSV].monhoc[viTriMH].diemTX2) / 4 + sinhvien[viTriSV].monhoc[viTriMH].diemKT / 2;
}

void quyDoiDiemHe4(int viTriSV, int viTriMH, SinhVien sinhvien[]) {
    if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 8.5 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 10) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 4.0;
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 8.0 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 8.4) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 3.5;
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 7.0 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 7.9) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 3.0;
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 6.5 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 6.9) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 2.5;
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 5.5 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 6.4) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 2.0;
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 5.0 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 5.4) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 1.5;
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 4.0 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 4.9) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 1.0;
    }
    else {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 0;
    }
}

void quyDoiDiemChu(int viTr1, int viTriMH, SinhVien sinhvien[]) {
    if (sinhvien[viTr1].monhoc[viTriMH].diemHe4 == 4.0) {
        sinhvien[viTr1].monhoc[viTriMH].diemChu = "A";
    }
    else if (sinhvien[viTr1].monhoc[viTriMH].diemHe4 == 3.5) {
        sinhvien[viTr1].monhoc[viTriMH].diemChu = "B+";
    }
    else if (sinhvien[viTr1].monhoc[viTriMH].diemHe4 == 3.0) {
        sinhvien[viTr1].monhoc[viTriMH].diemChu = "B";
    }
    else if (sinhvien[viTr1].monhoc[viTriMH].diemHe4 == 2.5) {
        sinhvien[viTr1].monhoc[viTriMH].diemChu = "C+";
    }
    else if (sinhvien[viTr1].monhoc[viTriMH].diemHe4 == 2.0) {
        sinhvien[viTr1].monhoc[viTriMH].diemChu = "C";
    }
    else if (sinhvien[viTr1].monhoc[viTriMH].diemHe4 == 1.5) {
        sinhvien[viTr1].monhoc[viTriMH].diemChu = "D+";
    }
    else if (sinhvien[viTr1].monhoc[viTriMH].diemHe4 == 1.0) {
        sinhvien[viTr1].monhoc[viTriMH].diemChu = "D";
    }
    else {
        sinhvien[viTr1].monhoc[viTriMH].diemChu = "F";
    }
}

void GPA(int viTriSV, SinhVien sinhvien[]) {
    float tongDiem = 0.0;
    int tongTinChi = 0;
    for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
        tongTinChi += sinhvien[viTriSV].monhoc[i].tinChi;
        tongDiem += sinhvien[viTriSV].monhoc[i].diemHe4 * sinhvien[viTriSV].monhoc[i].tinChi;
    }
    sinhvien[viTriSV].GPA = tongDiem / tongTinChi;
}

void xemDanhSach(int soSinhVien, SinhVien sinhvien[]) {
    if (sinhvien[0].ten.empty() && sinhvien[0].maSinhVien.empty() && sinhvien[0].lop.empty()) {
        cout << "Danh sach trong." << endl;
    }
    else {
        for (int i = 0; i < soSinhVien; i++) {
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "\tMa sinh vien: " << sinhvien[i].maSinhVien << endl;
            cout << "\tHo ten: " << sinhvien[i].ten << endl;
            cout << "\tLop: " << sinhvien[i].lop << endl;
            for (int j = 0; j < sinhvien[i].soMonHoc; j++) {
                cout << "\n\tDiem mon " << sinhvien[i].monhoc[j].ten << endl;
                cout << "\tDiem thuong xuyen 1: " << sinhvien[i].monhoc[j].diemTX1 << endl;
                cout << "\tDiem thuong xuyen 2: " << sinhvien[i].monhoc[j].diemTX2 << endl;
                cout << "\tDiem thi ket thuc mon: " << sinhvien[i].monhoc[j].diemKT << endl;
                cout << "\tDiem tong ket: " << setprecision(2) << sinhvien[i].monhoc[j].diemTK << endl;
                cout << "\tDiem he 4: " << sinhvien[i].monhoc[j].diemHe4 << endl;
                cout << "\tDiem chu: " << sinhvien[i].monhoc[j].diemChu << endl;
            }
            cout << "\tGPA: " << setprecision(2) << sinhvien[i].GPA << endl;
        }
    }
}

void suaThongTin(int soSinhVien, SinhVien sinhvien[]) {
    string maSV;
    int viTriSV = -1;
    cout << "Nhap ma sinh vien can sua thong tin: ";
    cin >> maSV;
    cin.ignore();
    for (int i = 0; i < soSinhVien; i++) {
        if (maSV == sinhvien[i].maSinhVien) {
            viTriSV = i;
            break;
        }
    }
    if (viTriSV == -1) {
        cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
    }
    else {
        cout << "Nhap ten sinh vien moi: ";
        sinhvien[viTriSV].ten = kiemTraTen();
        cout << "Nhap lop cua sinh vien: ";
        cin >> sinhvien[viTriSV].lop;
        for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
            cout << "Nhap diem mon " << sinhvien[viTriSV].monhoc[i].ten;
            nhapDiem(viTriSV, i, sinhvien);
        }
    }
}

void xemTimKiem(int viTriSV, SinhVien sinhvien[]) {
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\tMa sinh vien: " << sinhvien[viTriSV].maSinhVien << endl;
    cout << "\tHo ten: " << sinhvien[viTriSV].ten << endl;
    cout << "\tLop: " << sinhvien[viTriSV].lop << endl;
    for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
        cout << "\n\tDiem mon " << sinhvien[viTriSV].monhoc[i].ten << endl;
        cout << "\tDiem thuong xuyen 1: " << sinhvien[viTriSV].monhoc[i].diemTX1 << endl;
        cout << "\tDiem thuong xuyen 2: " << sinhvien[viTriSV].monhoc[i].diemTX2 << endl;
        cout << "\tDiem thi ket thuc mon: " << sinhvien[viTriSV].monhoc[i].diemKT << endl;
        cout << "\tDiem tong ket: " << setprecision(2) << sinhvien[viTriSV].monhoc[i].diemTK << endl;
        cout << "\tDiem he 4: " << sinhvien[viTriSV].monhoc[i].diemHe4 << endl;
        cout << "\tDiem chu: " << sinhvien[viTriSV].monhoc[i].diemChu << endl;
    }
    cout << "\tGPA: " << setprecision(2) << sinhvien[viTriSV].GPA << endl;
}

void timKiem(int soSinhVien, SinhVien sinhvien[]) {
    string maSV;
    string ten1;
    int viTriSV = -1;
    cout << "Nhap ma sinh vien can tim thong tin: ";
    cin >> maSV;
    for (int i = 0; i < soSinhVien; i++) {
        if (maSV == sinhvien[i].maSinhVien) {
            viTriSV = i;
            break;
        }
    }
    if (viTriSV == -1) {
        cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
    }
    xemTimKiem(viTriSV, sinhvien);
}

void xoaSinhVien(int& soSinhVien, SinhVien sinhvien[]) {
    string mSV;
    int viTriSV = -1;
    cout << "Nhap ma sinh vien can xoa thong tin: ";
    cin >> mSV;
    for (int i = 0; i < soSinhVien; i++) {
        if (mSV == sinhvien[i].maSinhVien) {
            viTriSV = i;
            break;
        }
    }
    if (viTriSV == -1) {
        cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
    }
    for (int i = viTriSV; i < soSinhVien - 1; i++) {
        sinhvien[i] = sinhvien[i + 1];
    }
    soSinhVien--;
    cout << "Xoa thong tin sinh vien thanh cong!" << endl;
}

void docFile(int &soSinhVien, SinhVien sinhvien[]) {
    ifstream fileIn;
    fileIn.open("D:\\Workspaces\\C++\\BTL\\data.txt", ios::in);
    if (fileIn.fail()) {
        cout << "Loi mo tep.";
        return;
    }
    int i = soSinhVien;
    while (!fileIn.eof()) {
        getline(fileIn, sinhvien[i].ten);
        fileIn >> sinhvien[i].maSinhVien >> sinhvien[i].lop;
        fileIn >> sinhvien[i].soMonHoc;
        for (int j = 0; j < sinhvien[i].soMonHoc; j++) {
            fileIn.ignore();
            getline(fileIn, sinhvien[i].monhoc[j].ten,'_');
            fileIn >> sinhvien[i].monhoc[j].tinChi;
            fileIn >> sinhvien[i].monhoc[j].diemTX1 >> sinhvien[i].monhoc[j].diemTX2 >> sinhvien[i].monhoc[j].diemKT >> sinhvien[i].monhoc[j].diemTK >> sinhvien[i].monhoc[j].diemHe4 >> sinhvien[i].monhoc[j].diemChu;
        }
        fileIn >> sinhvien[i].GPA;
        fileIn.ignore();
        i++;
        soSinhVien++;
    }
    cout << "Doc file thanh cong." << endl;
    fileIn.close();
}

void ghiFile(int soSinhVien, SinhVien sinhvien[]) {
    ofstream fileOut;
    fileOut.open("D:\\Workspaces\\C++\\BTL\\data.txt", ios::app);
    if (fileOut.fail()) {
        cout << "Loi mo tep.";
        return;
    }
    for (int i = 0; i < soSinhVien; i++) {
        fileOut << sinhvien[i].ten << endl;
        fileOut << sinhvien[i].maSinhVien << " " << sinhvien[i].lop << endl;
        fileOut << sinhvien[i].soMonHoc << endl;
        for (int j = 0; j < sinhvien[i].soMonHoc; j++) {
            fileOut << sinhvien[i].monhoc[j].ten << "_" << sinhvien[i].monhoc[j].tinChi << endl;
            fileOut << sinhvien[i].monhoc[j].diemTX1 << " " << sinhvien[i].monhoc[j].diemTX2 << " " << sinhvien[i].monhoc[j].diemKT << " " << setprecision(2) << sinhvien[i].monhoc[j].diemTK << " " << sinhvien[i].monhoc[j].diemHe4 << " " << sinhvien[i].monhoc[j].diemChu << endl;
        }
        fileOut << setprecision(2) << sinhvien[i].GPA << endl;
    }
    cout << "\nGhi file thanh cong" << endl;
    fileOut.close();
}
void thongKe(int soSinhVien, SinhVien sinhvien[]) {
    float maxGPA = sinhvien[0].GPA;
    int max1;
    float max2GPA = sinhvien[0].GPA;
    int max2;
    float max3GPA = sinhvien[0].GPA;
    int max3;
    for (int i = 0; i < soSinhVien; i++) {
        if (sinhvien[i].GPA > maxGPA) {
            maxGPA = sinhvien[i].GPA;
            max1 = i;
        }
    }
    for (int i = 0; i < soSinhVien; i++) {
        if (sinhvien[i].GPA > max2GPA && sinhvien[i].GPA < maxGPA) {
            max2GPA = sinhvien[i].GPA;
            max2 = i;

        }
    }
    for (int i = 0; i < soSinhVien; i++) {
        if (sinhvien[i].GPA > max3GPA && sinhvien[i].GPA < maxGPA && sinhvien[i].GPA < max2GPA) {
            max3GPA = sinhvien[i].GPA;
            max3 = i;
        }
    }

    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < soSinhVien; i++) {
        if (maxGPA == sinhvien[i].GPA) {
            cout << "Sinh vien co GPA cao nhat: " << sinhvien[i].ten << endl;
            cout << "GPA: " << setprecision(2) << maxGPA << endl;
        }
    }
    for (int i = 0; i < soSinhVien; i++) {
        if (max2GPA == sinhvien[i].GPA && sinhvien[i].ten != sinhvien[max1].ten ) {
            cout << "Sinh vien co GPA cao thu hai: " << sinhvien[i].ten << endl;
            cout << "GPA: " << setprecision(2) << max2GPA << endl;
        }
    }
    for (int i = 0; i < soSinhVien; i++) {
        if (max3GPA == sinhvien[i].GPA && sinhvien[i].ten != sinhvien[max2].ten) {
            cout << "Sinh vien co GPA cao thu 3: " << sinhvien[i].ten << endl;
            cout << "GPA: " << setprecision(2) << max3GPA << endl;
        }
    }
}

string kiemTraTen() {
    regex rg("([A-Z][a-z]+( |$))+");
    string str;
    while (true) {
        getline(cin, str);
        if (regex_match(str, rg)) {
            return str;
        }
        cout << "Nhap ten sai! Vui long nhap lai: ";
    }
}

string kiemTraTenMonHoc() {
   regex rg("([A-Z][a-zA-Z ]+([1-9]|$))");
    string str;
    while (true) {
        getline(cin, str);
        if (regex_match(str, rg)) {
            return str;
        }
        cout << "Nhap ten sai! Vui long nhap lai: ";
    }
}

int kiemTraSo() {
    while (true) {
        bool check = 1;
        int temp;
        string str;
        getline(cin, str);
        for (int i = 0; i < str.length(); i++) {
            if (!isdigit(str[i])) {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            temp = stoi(str);
            if (temp > 2000000000) {
                 cout << "Gia tri qua lon! Vui long nhap lai:" << endl;
            }
            else if (temp < 0) {
                cout << "Nhap gia tri sai! Vui long nhap lai:" << endl;
            }
            else {
                return temp;
            }           
        }
        else {
            cout << "Nhap gia tri sai! Vui long nhap lai: " << endl;
        }
        
    }
}

int kiemTraSoLuong() {
    int temp;
    while (true) {
        temp = kiemTraSo();
        if (temp == 0) {
            cout << "So luong phai lon hon 0! Vui long nhap lai: ";
        }
        else return temp;
    }
    
}

string kiemTraMaSinhVien(int soSinhVien, SinhVien sinhvien[]) {
    regex rg("^[0]([0-9]){6}");
    string str;
    bool check = false;
    while (true) {
        cin >> str;
        if (regex_match(str, rg)) {
            check = true;
            if (soSinhVien == 0) {
                return str;
            }
            else {
                for (int i = 0; i < soSinhVien; i++) {
                    if (str == sinhvien[i].maSinhVien) {
                        cout << "Ma sinh vien da ton tai! Vui long nhap lai: ";
                        check = false;
                        break;
                    }
                }
            }
        }
        else cout << "Ma sinh vien khong dung dinh dang! Vui long nhap lai: ";
        if (check == true) {
            return str;
        }
    }
}


double kiemTraDiem() {
    double temp;
    while (true) {
        temp = kiemTraSo();
        if (temp < 0 || temp > 10) {
            cout << "Gia tri ngoai khoang cho phep! Vui long nhap lai: ";
        }
        else return temp;  
    }

}