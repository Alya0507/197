#include <iostream>
using namespace std;
//Ktp menggunakan metode sorting dan searching
const int MAX = 100;

struct KTP {
    string nama;
    string nik;
    string tempatLahir;
    string tanggalLahir;
    string jenisKelamin;
    string golDarah;
    string alamat;
    string agama;
    string status;
    string pekerjaan;
    string kewarganegaraan;
};

void inputData(KTP data[], int &n) {
    cout << "Masukkan jumlah data KTP: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama             : "; getline(cin, data[i].nama);
        cout << "NIK              : "; getline(cin, data[i].nik);
        cout << "Tempat Lahir     : "; getline(cin, data[i].tempatLahir);
        cout << "Tanggal Lahir    : "; getline(cin, data[i].tanggalLahir);
        cout << "Jenis Kelamin    : "; getline(cin, data[i].jenisKelamin);
        cout << "Golongan Darah   : "; getline(cin, data[i].golDarah);
        cout << "Alamat           : "; getline(cin, data[i].alamat);
        cout << "Agama            : "; getline(cin, data[i].agama);
        cout << "Status           : "; getline(cin, data[i].status);
        cout << "Pekerjaan        : "; getline(cin, data[i].pekerjaan);
        cout << "Kewarganegaraan  : "; getline(cin, data[i].kewarganegaraan);
    }
}

void tampilkanData(const KTP data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n==========================\n";
        cout << "Data KTP ke-" << i + 1 << endl;
        cout << "==========================\n";
        cout << "Nama            : " << data[i].nama << endl;
        cout << "NIK             : " << data[i].nik << endl;
        cout << "Tempat, Tgl Lhr : " << data[i].tempatLahir << ", " << data[i].tanggalLahir << endl;
        cout << "Jenis Kelamin   : " << data[i].jenisKelamin << endl;
        cout << "Golongan Darah  : " << data[i].golDarah << endl;
        cout << "Alamat          : " << data[i].alamat << endl;
        cout << "Agama           : " << data[i].agama << endl;
        cout << "Status          : " << data[i].status << endl;
        cout << "Pekerjaan       : " << data[i].pekerjaan << endl;
        cout << "Kewarganegaraan : " << data[i].kewarganegaraan << endl;
    }
}

void bubbleSortNama(KTP data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].nama > data[j + 1].nama) {
                KTP temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "\nData berhasil diurutkan berdasarkan Nama (A-Z).\n";
}

void cariNIK(KTP data[], int n) {
    string cari;
    cout << "\nMasukkan NIK yang ingin dicari: ";
    cin.ignore();
    getline(cin, cari);

    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (data[i].nik == cari) {
            cout << "\nData ditemukan!\n";
            cout << "Nama            : " << data[i].nama << endl;
            cout << "NIK             : " << data[i].nik << endl;
            cout << "Tempat, Tgl Lhr : " << data[i].tempatLahir << ", " << data[i].tanggalLahir << endl;
            cout << "Jenis Kelamin   : " << data[i].jenisKelamin << endl;
            cout << "Golongan Darah  : " << data[i].golDarah << endl;
            cout << "Alamat          : " << data[i].alamat << endl;
            cout << "Agama           : " << data[i].agama << endl;
            cout << "Status          : " << data[i].status << endl;
            cout << "Pekerjaan       : " << data[i].pekerjaan << endl;
            cout << "Kewarganegaraan : " << data[i].kewarganegaraan << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nNIK tidak ditemukan!\n";
    }
}

int main() {
    KTP data[MAX];
    int n, pilihan;

    inputData(data, n);

    do {
        cout << "\n===============================";
        cout << "\n MENU DATA KTP";
        cout << "\n===============================";
        cout << "\n1. Tampilkan Semua Data";
        cout << "\n2. Urutkan Data Berdasarkan Nama";
        cout << "\n3. Cari Data Berdasarkan NIK";
        cout << "\n4. Keluar";
        cout << "\nPilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(data, n);
                break;
            case 2:
                bubbleSortNama(data, n);
                break;
            case 3:
                cariNIK(data, n);
                break;
            case 4:
                cout << "\nTerima kasih!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
