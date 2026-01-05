#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void registrasi();
int login();


typedef struct Akun {
    char username[30];
    char password[30];
    struct Akun* next;
} Akun;

Akun* head = NULL;

void registrasi() {
    Akun* baru = (Akun*) malloc(sizeof(Akun));

    printf("\n===== REGISTRASI AKUN =====\n");
    printf("Buat Username : ");
    scanf("%s", baru->username);
    printf("Buat Password : ");
    scanf("%s", baru->password);

    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Akun* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }

    printf("Registrasi berhasil!\n");
}

/* ================= LOGIN ================= */
int login() {
    if (head == NULL) {
        printf("\nBelum ada akun! Silakan registrasi dulu.\n");
        return 0;
    }

    char user[30], pass[30];
    printf("\n===== LOGIN =====\n");
    printf("Username : ");
    scanf("%s", user);
    printf("Password : ");
    scanf("%s", pass);

    Akun* temp = head;
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

