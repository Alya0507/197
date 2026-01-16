#include <iostream>
#include <string>
using namespace std;

const int baris = 3;
const int kolom = 3;

void tampilkanData(string data[baris][kolom]) {
    cout << "\n========== DATA KTP ==========\n";
    for (int i = 0; i < baris; i++) {
        cout << "KTP ke-" << i + 1 << ":\n";
        cout << "NIK   : " << data[i][0] << endl;
        cout << "Nama  : " << data[i][1] << endl;
        cout << "Alamat: " << data[i][2] << endl;
        cout << "-----------------------------\n";
    }
}

void urutkanData(string data[baris][kolom], int kolomUrut) {
    for (int i = 0; i < baris - 1; i++) {
        for (int j = i + 1; j < baris; j++) {
            if (data[i][kolomUrut] > data[j][kolomUrut]) {
                for (int k = 0; k < kolom; k++) {
                    swap(data[i][k], data[j][k]);
                }
            }
        }
    }
}

int main() {
    string data[baris][kolom];
	char ulang;
	
    cout << "=== INPUT DATA KTP ===\n";
    for (int i = 0; i < baris; i++) {
        cout << "\nMasukkan data untuk KTP ke-" << i + 1 << ":\n";
        cout << "NIK   : ";
        getline(cin, data[i][0]);
        cout << "Nama  : ";
        getline(cin, data[i][1]);
        cout << "Alamat: ";
        getline(cin, data[i][2]);
    }

    do{
    	int pilihan;
	    cout << "\n=== PILIHAN PENGURUTAN ===\n";
	    cout << "1. Urutkan berdasarkan NIK\n";
	    cout << "2. Urutkan berdasarkan Nama\n";
	    cout << "Masukkan pilihan (1 atau 2): ";
	    cin >> pilihan;
	    cin.ignore();
	
	    if (pilihan == 1) {
	        urutkanData(data, 0);
	    } else if (pilihan == 2) {
	        urutkanData(data, 1);
	    } else {
	        cout << "Pilihan tidak valid. Menampilkan data tanpa pengurutan.\n";
	    }
	
	    tampilkanData(data);
	    
	    cout << "Apakah ingin mengulang pengurutan (y/n) : ";
	    cin >> ulang;
	    cin.ignore();
	    
	}while(ulang != 'n' && ulang != 'N' );{
		cout << "terimakasih" << endl;
	}

    return 0;
}
