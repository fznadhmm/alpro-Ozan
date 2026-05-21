#include <iostream>
using namespace std;

const int MAX_USER = 10;
const int MAX_CHAR = 20;

char memberUsername[MAX_USER][MAX_CHAR];
char memberPassword[MAX_USER][MAX_CHAR];
int memberCount = 0;
int totalLoginBerhasil = 0;
int totalLoginGagal = 0;

bool samakan(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

void salin(char dest[], char src[]) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

bool kosong(char str[]) {
    return str[0] == '\0';
}

void menuUtama();
void menuRegister();
int  menuLogin();
void halamanUser(int index);
void lihatStatistik();

bool usernameAda(char uname[]) {
    for (int i = 0; i < memberCount; i++) {
        if (samakan(uname, memberUsername[i])) return true;
    }
    return false;
}

void menuRegister() {
    system("cls");
    cout << "\n=== REGISTER ===\n";

    if (memberCount >= MAX_USER) {
        cout << "Registrasi penuh! Maksimal " << MAX_USER << " user.\n";
        system("pause");
        return;
    }

    char uname[MAX_CHAR], pass[MAX_CHAR];

    cout << "Masukkan Username : ";
    cin >> uname;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid!\n";
        system("pause");
        return;
    }

    if (kosong(uname)) {
        cout << "Username tidak boleh kosong!\n";
        system("pause");
        return;
    }

    if (usernameAda(uname)) {
        cout << "Username sudah terdaftar!\n";
        system("pause");
        return;
    }

    cout << "Masukkan Password : ";
    cin >> pass;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid!\n";
        system("pause");
        return;
    }

    if (kosong(pass)) {
        cout << "Password tidak boleh kosong!\n";
        system("pause");
        return;
    }

    salin(memberUsername[memberCount], uname);
    salin(memberPassword[memberCount], pass);
    memberCount++;

    cout << "Registrasi berhasil! Selamat datang, " << uname << "!\n";
    system("pause");
}



int menuLogin() {
    system("cls");
    cout << "\n=== LOGIN ===\n";

    char uname[MAX_CHAR], pass[MAX_CHAR];

    cout << "Masukkan Username : ";
    cin >> uname;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid!\n";
        system("pause");
        return -1;
    }

    bool usernameFound = false;
    for (int i = 0; i < memberCount; i++) {
        if (samakan(uname, memberUsername[i])) {
            usernameFound = true;
            break;
        }
    }

    if (!usernameFound) {
        cout << "Username tidak terdaftar!\n";
        totalLoginGagal++;
        system("pause");
        return -1;
    }

    cout << "Masukkan Password : ";
    cin >> pass;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid!\n";
        totalLoginGagal++;
        system("pause");
        return -1;
    }

    for (int i = 0; i < memberCount; i++) {
        if (samakan(uname, memberUsername[i]) && samakan(pass, memberPassword[i])) {
            cout << "Login berhasil!\n";
            totalLoginBerhasil++;
            system("pause");
            return i;
        }
    }

    cout << "Password salah!\n";
    totalLoginGagal++;
    system("pause");
    return -1;
}


void halamanUser(int index) {
    int pilih;
    do {
        system("cls");
        cout << "\n===== HALAMAN USER =====\n";
        cout << "Nomor Registrasi : " << index + 1 << "\n";
        cout << "Username         : " << memberUsername[index] << "\n";
        cout << "\n0. Sign Out\n";
        cout << "Pilih : ";
        cin >> pilih;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus berupa angka!\n";
            pilih = -1;
            system("pause");
            continue;
        }

        if (pilih == 0) {
            cout << "Anda telah Sign Out.\n";
            system("pause");
        } else {
            cout << "Pilihan tidak valid.\n";
            system("pause");
        }

    } while (pilih != 0);
}

void menuUtama() {
    int pilih;
    do {
        system("cls");
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus berupa angka!\n";
            pilih = -1;
            system("pause");
            continue;
        }

        if (pilih == 1) {
            menuRegister();
        } else if (pilih == 2) {
            int idx = menuLogin();
            if (idx != -1) {
                halamanUser(idx);
            }
        } else if (pilih == 3) {
            lihatStatistik();
        } else if (pilih == 4) {
            system("cls");
            cout << "\nTerima kasih!\n";
        } else {
            cout << "Pilihan tidak valid.\n";
            system("pause");
        }

    } while (pilih != 4);
}

int main (){
  menuUtama();
    return 0;
}