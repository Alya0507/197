
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string prodi;
    string noTelp;
    bool aktif;
};

class SistemMahasiswa {
private:
    Mahasiswa dataMahasiswa[100];
    int jumlahData;

public:
    SistemMahasiswa() {
        jumlahData = 0;
        for(int i = 0; i < 100; i++) {
            dataMahasiswa[i].aktif = false;
        }
    }
    
    void tambahMahasiswa() {
        
        cout << "\n=== INPUT DATA MAHASISWA ===" << endl;
        cout << "NIM : ";
        cin >> dataMahasiswa[jumlahData].nim;
        cin.ignore();
        cout << "Nama : ";
        getline(cin, dataMahasiswa[jumlahData].nama);
        cout << "Program Studi : ";
        getline(cin, dataMahasiswa[jumlahData].prodi);
        cout << "Nomor Telepon: ";
        getline(cin, dataMahasiswa[jumlahData].noTelp);
        
        dataMahasiswa[jumlahData].aktif = true;
        jumlahData++;
        cout << "Data mahasiswa berhasil ditambahkan!" << endl;
    }
    
    void tampilkanSemua() {
        if (jumlahData == 0) {
            cout << "Tidak ada data mahasiswa." << endl;
            return;
        }
        
        cout << "\n=== DATA MAHASISWA ===" << endl;
        
        int nomor = 1;
        for (int i = 0; i < jumlahData; i++) {
            if(dataMahasiswa[i].aktif) {
                cout << "\nMahasiswa " << nomor << ":" << endl;
                cout << "  NIM           : " << dataMahasiswa[i].nim << endl;
                cout << "  Nama          : " << dataMahasiswa[i].nama << endl;
                cout << "  Program Studi : " << dataMahasiswa[i].prodi << endl;
                cout << "  Nomor Telepon   : " << dataMahasiswa[i].noTelp << endl;
                nomor++;
            }
        }
        cout << "\nTotal mahasiswa: " << nomor - 1 << endl;
    }
    
    void cariMahasiswaBerdasarkanNIM() {
        if (jumlahData == 0) {
            cout << "Tidak ada data mahasiswa." << endl;
            return;
        }
        
        string nimCari;
        cout << "\nMasukkan NIM yang dicari: ";
        cin >> nimCari;
        
        bool ditemukan = false;
        for (int i = 0; i < jumlahData; i++) {
            if (dataMahasiswa[i].aktif && dataMahasiswa[i].nim == nimCari) {
                cout << "\n=== DATA YANG DICARI ===" << endl;
                cout << "NIM         : " << dataMahasiswa[i].nim << endl;
                cout << "Nama        : " << dataMahasiswa[i].nama << endl;
                cout << "Program Studi: " << dataMahasiswa[i].prodi << endl;
                cout << "Nomor Telepon : " << dataMahasiswa[i].noTelp << endl;
                ditemukan = true;
                break;
                
            }
        }
        
        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan!" << endl;
        }
    }
    
    void urutkanBerdasarkanNIM() {
        if (jumlahData == 0) {
            cout << "Tidak ada data mahasiswa." << endl;
            return;
        }
        
        int pilihan;
        cout << "\nPilih jenis pengurutan:" << endl;
        cout << "1. Ascending (A-Z)" << endl;
        cout << "2. Descending (Z-A)" << endl;
        cout << "Pilih (1/2): ";
        cin >> pilihan;
        
    
        for(int i = 0; i < jumlahData - 1; i++) {
            for(int j = 0; j < jumlahData - i - 1; j++) {
                bool tukar = false;
                
                if(pilihan == 1) {
                    if(dataMahasiswa[j].aktif && dataMahasiswa[j+1].aktif && 
                       dataMahasiswa[j].nim > dataMahasiswa[j+1].nim) {
                        tukar = true;
                    }
                } else if(pilihan == 2) {
                    if(dataMahasiswa[j].aktif && dataMahasiswa[j+1].aktif && 
                       dataMahasiswa[j].nim < dataMahasiswa[j+1].nim) {
                        tukar = true;
                    }
                }
                
                if(tukar) {
                    Mahasiswa temp = dataMahasiswa[j];
                    dataMahasiswa[j] = dataMahasiswa[j+1];
                    dataMahasiswa[j+1] = temp;
                }
            }
        }
        
        if (pilihan == 1) {
            cout << "Data berhasil diurutkan secara ascending berdasarkan NIM." << endl;
        } else if (pilihan == 2) {
            cout << "Data berhasil diurutkan secara descending berdasarkan NIM." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
            return;
        }
        
        tampilkanSemua();
    }
    
    void urutkanBerdasarkanNama() {
        if (jumlahData == 0) {
            cout << "Tidak ada data mahasiswa." << endl;
            return;
        }
        
        int pilihan;
        cout << "\nPilih jenis pengurutan:" << endl;
        cout << "1. Ascending (A-Z)" << endl;
        cout << "2. Descending (Z-A)" << endl;
        cout << "Pilih (1/2): ";
        cin >> pilihan;
        
    
        for(int i = 0; i < jumlahData - 1; i++) {
            for(int j = 0; j < jumlahData - i - 1; j++) {
                bool tukar = false;
                
                if(pilihan == 1) {
                    // Ascending
                    if(dataMahasiswa[j].aktif && dataMahasiswa[j+1].aktif && 
                       dataMahasiswa[j].nama > dataMahasiswa[j+1].nama) {
                        tukar = true;
                    }
                } else if(pilihan == 2) {
                    // Descending
                    if(dataMahasiswa[j].aktif && dataMahasiswa[j+1].aktif && 
                       dataMahasiswa[j].nama < dataMahasiswa[j+1].nama) {
                        tukar = true;
                    }
                }
                
                if(tukar) {
                    Mahasiswa temp = dataMahasiswa[j];
                    dataMahasiswa[j] = dataMahasiswa[j+1];
                    dataMahasiswa[j+1] = temp;
                }
            }
        }
        
        if (pilihan == 1) {
            cout << "Data berhasil diurutkan secara ascending berdasarkan Nama." << endl;
        } else if (pilihan == 2) {
            cout << "Data berhasil diurutkan secara descending berdasarkan Nama." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
            return;
        }
        
        tampilkanSemua();
    }
    
    void hapusMahasiswa() {
        if (jumlahData == 0) {
            cout << "Tidak ada data mahasiswa." << endl;
            return;
        }
        
        string nimHapus;
        cout << "\nMasukkan NIM mahasiswa yang akan dihapus: ";
        cin >> nimHapus;
        
        bool ditemukan = false;
        for(int i = 0; i < jumlahData; i++) {
            if(dataMahasiswa[i].aktif && dataMahasiswa[i].nim == nimHapus) {
                dataMahasiswa[i].aktif = false;
                ditemukan = true;
                cout << "Data mahasiswa dengan NIM " << nimHapus << " berhasil dihapus!" << endl;
                break;
            }
        }
        
        if(!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nimHapus << " tidak ditemukan!" << endl;
        }
    }
    
    void dataContoh() {
        jumlahData = 0;
        for(int i = 0; i < 100; i++) {
            dataMahasiswa[i].aktif = false;
        }
        
        dataMahasiswa[0] = {"2023001", "Ahmad Rizki", "Teknik Informatika", "081234567890", true};
        dataMahasiswa[1] = {"2023005", "Sari Dewi", "Sistem Informasi", "081987654321", true};
        dataMahasiswa[2] = {"2023003", "Budi Santoso", "Teknik Informatika", "081122334455", true};
        dataMahasiswa[3] = {"2023007", "Citra Andini", "Teknik Komputer", "081567890123", true};
        dataMahasiswa[4] = {"2023002", "Diana Putri", "Sistem Informasi", "081998877665", true};
        
        jumlahData = 5;
        cout << "Data contoh berhasil dimuat!" << endl;
    }
};

int main() {
    SistemMahasiswa sistem;
    int pilihan;
    
    do {
        cout << "\n=== SISTEM PENGELOLAAN DATA MAHASISWA ===" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Urutkan berdasarkan NIM" << endl;
        cout << "5. Urutkan berdasarkan Nama" << endl;
        cout << "6. Hapus Mahasiswa" << endl;
        cout << "7. Muat Data Contoh" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilih menu (1-8): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                sistem.tambahMahasiswa();
                break;
            case 2:
                sistem.tampilkanSemua();
                break;
            case 3:
                sistem.cariMahasiswaBerdasarkanNIM();
                break;
            case 4:
                sistem.urutkanBerdasarkanNIM();
                break;
            case 5:
                sistem.urutkanBerdasarkanNama();
                break;
            case 6:
                sistem.hapusMahasiswa();
                break;
            case 7:
                sistem.dataContoh();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan sistem!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(pilihan != 8);
    
    return 0;
}
