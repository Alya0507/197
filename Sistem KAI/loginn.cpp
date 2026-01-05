#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Akun {
    char username[30];
    char password[30];
    struct Akun* next;
} Akun;

Akun* head = NULL;

void registrasi() {
    Akun* baru = (Akun*) malloc(sizeof(Akun));
    Akun* temp;

    if (baru == NULL) {
        printf("Gagal alokasi memori!\n");
        return;
    }

    printf("\n===== REGISTRASI AKUN =====\n");
    printf("Buat Username : ");
    scanf("%29s", baru->username);
    printf("Buat Password : ");
    scanf("%29s", baru->password);

    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }

    printf("Registrasi berhasil!\n");
}

int login() {
    char user[30], pass[30];
    Akun* temp;

    if (head == NULL) {
        printf("\nBelum ada akun. Silakan registrasi dulu.\n");
        return 0;
    }

    printf("\n===== LOGIN =====\n");
    printf("Username : ");
    scanf("%29s", user);
    printf("Password : ");
    scanf("%29s", pass);

    temp = head;
    while (temp != NULL) {
        if (strcmp(temp->username, user) == 0 &&
            strcmp(temp->password, pass) == 0) {
            printf("Login berhasil! Selamat datang, %s!\n", user);
            return 1;
        }
        temp = temp->next;
    }

    printf("Username atau password salah!\n");
    return 0;
}

