#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    char kata1, kata2, kata3, kata4;
    int a, b, c, d;

    cout << "Masukkan titik pertama: ";
    cin >> kata1;
    cout << "Masukkan titik kedua: ";
    cin >> kata2;
    cout << "Masukkan titik ketiga: ";
    cin >> kata3;
    cout << "Masukkan titik keempat: ";
    cin >> kata4;

    cout << endl;
    cout << "Garis yang dapat dibentuk adalah:\n";
    cout << kata1 << kata4 << endl;
    cout << kata4 << kata3 << endl;
    cout << kata3 << kata2 << endl;
    cout << kata2 << kata1 << endl << endl;

    cout << "Masukkan jarak antara titik simpul " << kata1 << " dengan " << kata4 << ": ";
    cin >> a;
    cout << "Masukkan jarak antara titik simpul " << kata4 << " dengan " << kata3 << ": ";
    cin >> b;
    cout << "Masukkan jarak antara titik simpul " << kata3 << " dengan " << kata2 << ": ";
    cin >> c;
    cout << "Masukkan jarak antara titik simpul " << kata2 << " dengan " << kata1 << ": ";
    cin >> d;

    int total = a + b + c + d;
    cout << "\nJadi panjang jarak totalnya = " << total << endl << endl;

    cout << "Mencari jalur terpendek dari " << kata1 << " menuju " << kata4 << ":\n";
    cout << "Alternatif pertama: " << kata1 << " -> " << kata4 << " = " << a << endl;
    cout << "Alternatif kedua: " << kata1 << " -> " << kata2 << " -> " << kata3 << " -> " << kata4 
         << " = " << d + c + b << endl;

    system("color f0");
    system("PAUSE");

    return EXIT_SUCCESS;
}
