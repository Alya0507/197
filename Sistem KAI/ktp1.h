#ifndef KTP_H
#define KTP_H

#include <iostream>
using namespace std;

struct DataKTP {
    char nik[20];
    char nama[50];
};

inline void inputKTP(DataKTP &k) {
    cout << "\n=== DATA IDENTITAS PENUMPANG ===\n";

    cout << "Nama sesuai KTP : ";
    cin.ignore();
    cin.getline(k.nama, 50);

    cout << "No KTP (NIK)    : ";
    cin >> k.nik;
}

inline void tampilKTP(const DataKTP &k) {
    cout << "Nama (KTP) : " << k.nama << endl;
    cout << "NIK        : " << k.nik << endl;
}

#endif

