#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

int hasil;

int faktorial(int nilai){
	hasil = nilai;
	while (nilai > 1){
		hasil = hasil * (nilai - 1);
		nilai = hasil - 1;
	}
	return hasil;
}
int main(){
	int p, nq, max, x, i ,j, n, k, r, s, tr, no;
	int a[100];
	div_t xx;
	
	for (i = 0; i < 100; i++){
		a[i] = 0;
	}
	
	cout << "--------------------------\n";
	cout << "PROGRAM GENERATE PERMUTASI\n\n";
	
	cout << "Masukkan nilai n :  ";
	cin >> n;
	
	for (i = 1; i <= n; i++){
		cout << "Masukkan nilai himpunan a[" << i << "] : ";
		cin >> a[i];
	}
	cout << "Nilai r : ";
	cin >> tr;
	
	p = faktorial(n);
	nq = faktorial (n - tr);
	if (nq == 0) nq = 1;
	max = p / nq;
	
	cout << "Nilai permutasi : "<<max<<endl;
	getch();
	
	return 0;
}
