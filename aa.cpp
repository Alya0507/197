#include <iostream>
using namespace std;

const int SIZE = 3;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array2D[SIZE][SIZE] = {
        {9, 3, 5},
        {1, 8, 6},
        {2, 4, 7}
    };

    // Konversi ke array 1D
    int array1D[SIZE * SIZE];
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array1D[index++] = array2D[i][j];
        }
    }

    // Sorting dengan bubble sort
    bubbleSort(array1D, SIZE * SIZE);

    // Konversi kembali ke array 2D
    index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array2D[i][j] = array1D[index++];
        }
    }

    // Tampilkan array 2D yang sudah diurutkan
    cout << "Array 2D setelah diurutkan:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
