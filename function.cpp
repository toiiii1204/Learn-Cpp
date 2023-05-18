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
    int soLuong;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;
    while (soLuong > 0) {
        cout << "Nhap ten sinh vien thu " << (soSinhVien + 1) << ": ";
        cin.ignore();
        getline(cin, sinhvien[soSinhVien].ten);
        cout << "Nhap ma sinh vien: ";
        cin >> sinhvien[soSinhVien].maSinhVien;
        cout << "Nhap ten lop cua sinh vien: ";
        cin >> sinhvien[soSinhVien].lop;
        cout << "Nhap so luong mon hoc: ";
        cin >> sinhvien[soSinhVien].soMonHoc;
        nhapMonHoc(soSinhVien, sinhvien);
        cout << endl;
        soSinhVien++;
        soLuong--;
    }
    cout << "Nhap du lieu thanh cong!" << endl;
}

void nhapMonHoc(int viTriSV, SinhVien sinhvien[]) {
    for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
        cout << "Nhap ten mon hoc thu " << (i + 1) << ": ";
        getline(cin, sinhvien[viTriSV].monhoc[i].ten);
        cout << "Nhap so tin chi: ";
        cin >> sinhvien[viTriSV].monhoc[i].tinChi;
        nhapDiem(viTriSV, i, sinhvien);
    }
}

void nhapDiem(int viTriSV, int viTriMH, SinhVien sinhvien[]) {
    float diem1, diem2, diem3;
    while (true) {
        cout << "Nhap diem thuong xuyen 1: " << endl;
        cin >> diem1;
        if (diem1 >= 0 && diem1 <= 10) {
            sinhvien[viTriSV].monhoc[viTriMH].diemTX1 = diem1;
            break;
        }
        cout << "Gia tri ngoai khoang cho phep, nhap lai!" << endl;
    }
    while (true) {
        cout << "Nhap diem thuong xuyen 2: " << endl;
        cin >> diem2;
        if (diem2 >= 0 && diem2 <= 10) {
            sinhvien[viTriSV].monhoc[viTriMH].diemTX2 = diem2;
            break;
        }
        cout << "Gia tri ngoai khoang cho phep, nhap lai!" << endl;
    }
    while (true) {
        cout << "Nhap diem ket thuc mon: " << endl;
        cin >> diem3;
        if (diem3 >= 0 && diem3 <= 10) {
            sinhvien[viTriSV].monhoc[viTriMH].diemKT = diem3;
            break;
        }
        cout << "Gia tri ngoai khoang cho phep, nhap lai!" << endl;
    }
    cout << endl;
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
    int luaChon;
    string maSV;
    int viTriSV = -1;
    bool check = true;
    cout << "Nhap ma sinh vien can sua thong tin: ";
    cin >> maSV;
    for (int i = 0; i < soSinhVien; i++) {
        if (maSV == sinhvien[i].maSinhVien) {
            viTriSV = i;
        }
    }
    if (viTriSV == -1) {
        cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
    }
    else {
        while (check) {
            cout << setw(97) << "********************************" << endl;
            cout << setw(97) << "*   1.Sua ten sinh vien        *" << endl;
            cout << setw(97) << "*   2.Sua lop cua sinh vien    *" << endl;
            cout << setw(97) << "*   3.Sua ma sinh vien         *" << endl;
            cout << setw(97) << "*   4.Sua diem cua sinh vien   *" << endl;
            cout << setw(97) << "*   0.Thoat                    *" << endl;
            cout << setw(97) << "********************************" << endl;
            cout << "Chon thong tin can sua: " << endl;
            cin >> luaChon;
            switch (luaChon) {
            case 1:
                cout << "Nhap ten sinh vien moi: ";
                cin.ignore();
                getline(cin, sinhvien[viTriSV].ten);
                cout << "Sua ten thanh cong!" << endl;
                break;
            case 2:
                cout << "Nhap lop cua sinh vien: ";
                cin >> sinhvien[viTriSV].lop;
                cout << "Sua lop thanh cong!" << endl;
                break;
            case 3:
                cout << "Nhap ma sinh vien moi: ";
                cin >> sinhvien[viTriSV].maSinhVien;
                cout << "Sua ma sinh vien thanh cong!" << endl;
                break;
            case 4:
                cout << "Nhap diem cua sinh vien: ";
                for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
                    cout << "Nhap diem mon " << sinhvien[viTriSV].monhoc[i].ten;
                    nhapDiem(viTriSV, i, sinhvien);
                }
                cout << "Sua diem thanh cong!" << endl;
                break;
            case 0:
                check = false;
                break;
            default:
                cout << "Nhap lua chon sai, vui long nhap lai!";
                break;
            }
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
    int luaChon = 0;
    string mSV;
    string ten1;
    int viTriSV = 0;
    while (luaChon != 0) {
        cout << setw(97) << "**********************************************" << endl;
        cout << setw(97) << "*   1.Tim kiem thong tin theo ten            *" << endl;
        cout << setw(97) << "*   2.Tim kiem thong tin theo ma sinh vien   *" << endl;
        cout << setw(97) << "*   0.Thoat                                  *" << endl;
        cout << setw(97) << "**********************************************" << endl;
        cin >> luaChon;
        switch (luaChon) {
        case 1:
            cout << "Nhap ten sinh vien can tim: ";
            cin.ignore();
            getline(cin, ten1);
            for (int i = 0; i < soSinhVien; i++) {
                if (ten1 == sinhvien[i].ten) {
                    viTriSV = i;
                }
            }
            if (viTriSV == 0) {
                cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
            }
            xemTimKiem(viTriSV, sinhvien);
            break;
        case 2:
            cout << "Nhap ma sinh vien can tim: ";
            cin >> mSV;
            for (int i = 0; i < soSinhVien; i++) {
                if (mSV == sinhvien[i].maSinhVien) {
                    viTriSV = i;
                }
            }
            if (viTriSV == 0) {
                cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
            }
            xemTimKiem(viTriSV, sinhvien);
            break;
        case 0:
            luaChon = 0;
        default:
            cout << "Nhap sai lua chon, vui long nhap lai!" << endl;
            break;
        }
    }
}

void xoaSinhVien(int& soSinhVien, SinhVien sinhvien[]) {
    string mSV;
    int viTriSV = 0;
    cout << "Nhap ma sinh vien can xoa thong tin: ";
    cin >> mSV;
    for (int i = 0; i < soSinhVien; i++) {
        if (mSV == sinhvien[i].maSinhVien) {
            viTriSV = i;
        }
    }
    if (viTriSV == 0) {
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
        cout << "Doc xong ten." << endl;
        fileIn >> sinhvien[i].maSinhVien >> sinhvien[i].lop;
        cout << "Doc xong lop va ma sinh vien" << endl;
        fileIn >> sinhvien[i].soMonHoc;
        for (int j = 0; j < sinhvien[i].soMonHoc; j++) {
            fileIn.ignore();
            getline(fileIn, sinhvien[i].monhoc[j].ten,' ');
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
            fileOut << sinhvien[i].monhoc[j].ten << " " << sinhvien[i].monhoc[j].tinChi << endl;
            fileOut << sinhvien[i].monhoc[j].diemTX1 << " " << sinhvien[i].monhoc[j].diemTX2 << " " << sinhvien[i].monhoc[j].diemKT << " " << setprecision(2) << sinhvien[i].monhoc[j].diemTK << " " << sinhvien[i].monhoc[j].diemHe4 << " " << sinhvien[i].monhoc[j].diemChu << endl;
        }
        fileOut << setprecision(2) << sinhvien[i].GPA << endl;
    }
    cout << "\nGhi file thanh cong" << endl;
    fileOut.close();
}
void thongKe(int soSinhVien, SinhVien sinhvien[]) {
    float maxGPA = sinhvien[0].GPA;
    float max2GPA = sinhvien[0].GPA;
    float max3GPA = sinhvien[0].GPA;
    for (int i = 0; i < soSinhVien; i++) {
        if (sinhvien[i].GPA > maxGPA) {
            maxGPA = sinhvien[i].GPA;
        }
    }
    for (int i = 0; i < soSinhVien; i++) {
        if (sinhvien[i].GPA > max2GPA && sinhvien[i].GPA < maxGPA) {
            max2GPA = sinhvien[i].GPA;
        }
    }
    for (int i = 0; i < soSinhVien; i++) {
        if (sinhvien[i].GPA > max3GPA && sinhvien[i].GPA < maxGPA && sinhvien[i].GPA < max2GPA) {
            max3GPA = sinhvien[i].GPA;
        }
    }

    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < soSinhVien; i++) {
        if (maxGPA == sinhvien[i].GPA) {
            cout << "Sinh vien co GPA cao nhat: " << sinhvien[i].ten << endl;
            cout << "GPA: " << setprecision(2) << maxGPA << endl;
            break;
        }
    }
    for (int i = 0; i < soSinhVien; i++) {
        if (max2GPA == sinhvien[i].GPA) {
            cout << "Sinh vien co GPA cao thu hai: " << sinhvien[i].ten << endl;
            cout << "GPA: " << setprecision(2) << max2GPA << endl;
            break;
        }
    }
    for (int i = 0; i < soSinhVien; i++) {
        if (max3GPA == sinhvien[i].GPA) {
            cout << "Sinh vien co GPA cao thu 3: " << sinhvien[i].ten << endl;
            cout << "GPA: " << setprecision(2) << max3GPA << endl;
            break;
        }
    }
}