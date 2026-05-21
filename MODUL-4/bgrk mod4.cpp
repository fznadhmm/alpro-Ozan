#include <iostream>
#include <conio.h>
using namespace std;

// Konstanta
const int MAX_USER = 10;
const int MAX_ITEM = 10;
const int MAX_VOUCHER = 5;
const int MAX_GAME = 5;

// Data Member
char memberUsername[MAX_USER][20];
char memberPassword[MAX_USER][20];
int saldo[MAX_USER] = {0};
int memberCount = 0;

// Data Item (Umum)
char itemNama[MAX_ITEM][20];
int itemHarga[MAX_ITEM];
int itemCount = 0;

// Admin
char adminUsername[] = "admin";
char adminPassword[] = "admin";

// Voucher
char voucherKode[MAX_VOUCHER][10];
int voucherDiskon[MAX_VOUCHER];
int voucherCount = 0;

// Riwayat
char riwayatPembelian[100][50];
int riwayatCount = 0;

// Game dan Item per Game
char namaGame[MAX_GAME][20];
int gameCount = 0;

char gameItemNama[MAX_GAME][MAX_ITEM][20];
int gameItemHarga[MAX_GAME][MAX_ITEM];
int gameItemCount[MAX_GAME] = {0};

void banner() {
    cout << "==================================================================================================================\n"
            "|  $$\\       $$\\ $$\\                           $$\\            $$$$$$\\    $$\\                                     |\n"
            "|  $$ |      \\__|$$ |                          \\__|          $$  __$$\\   $$ |                                    |\n"
            "|  $$ |      $$\\ $$$$$$$\\   $$$$$$\\   $$$$$$\\  $$\\  $$$$$$\\  $$ /  \\__|$$$$$$\\    $$$$$$\\   $$$$$$\\   $$$$$$\\    |\n"
            "|  $$ |      $$ |$$  __$$\\ $$  __$$\\ $$  __$$\\ $$ |$$  __$$\\ \\$$$$$$\\  \\_$$  _|  $$  __$$\\ $$  __$$\\ $$  __$$\\   |\n"
            "|  $$ |      $$ |$$ |  $$ |$$$$$$$$ |$$ |  \\__|$$ |$$ /  $$ | \\____$$\\   $$ |    $$ /  $$ |$$ |  \\__|$$$$$$$$ |  |\n"
            "|  $$ |      $$ |$$ |  $$ |$$   ____|$$ |      $$ |$$ |  $$ |$$\\   $$ |  $$ |$$\\ $$ |  $$ |$$ |      $$   ____|  |\n"
            "|  $$$$$$$$\\ $$ |$$$$$$$  |\\$$$$$$$\\ $$ |      $$ |\\$$$$$$  |\\$$$$$$  |  \\$$$$  |\\$$$$$$  |$$ |      \\$$$$$$$\\   |\n"
            "|  \\________|\\__|\\_______/  \\_______|\\__|      \\__| \\______/  \\______/    \\____/  \\______/ \\__|       \\_______|  |\n"
            "==================================================================================================================\n";
}

int myStrlen(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

bool myStrcmp(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false; 
        i++;
    }
    return a[i] == b[i];
}

void myStrcpy(char dest[], char src[]) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

bool usernameAda(char uname[]) {
    for (int i = 0; i < memberCount; i++) {
        if (myStrcmp(uname, memberUsername[i])) return true;
    }
    return false;
}

void daftarMember() {
    system("cls");
    if (memberCount >= MAX_USER) {
        cout << "Member penuh.\n"; return;
    }
    char uname[20], pass[20];
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n|  Daftar Member Baru   |\n~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Username: "; cin >> uname;
    if (usernameAda(uname)) {
        cout << "Username sudah digunakan.\n"; return;
    }
    cout << "Password: "; cin >> pass;

    myStrcpy(memberUsername[memberCount], uname);
    myStrcpy(memberPassword[memberCount], pass);
    saldo[memberCount++] = 0;

    cout << "Pendaftaran berhasil!\n";
}

int loginMember() {
    char uname[20], pass[20];
    system("cls");
    cout << "~~~~~~~~~~~~~~~~~~~~~\n|    Login Member    |\n~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Username: "; cin >> uname;
    cout << "Password: "; cin >> pass;

    for (int i = 0; i < memberCount; i++) {
        if (myStrcmp(uname, memberUsername[i]) && myStrcmp(pass, memberPassword[i])) {
            cout << "Login berhasil!\n";
            system("pause");
            return i;
        }
    }
    cout << "Login gagal.\n";
    system("pause");
    return -1;
}

bool loginAdmin() {
    char uname[20], pass[20];
    system("cls");
    cout << "~~~~~~~~~~~~~~~~~~~~~\n|    Login Admin    |\n~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Username: "; cin >> uname;
    cout << "Password: "; cin >> pass;
    return myStrcmp(uname, adminUsername) && myStrcmp(pass, adminPassword);
}

int cariVoucher(char kode[]) {
    for (int i = 0; i < voucherCount; i++) {
        if (myStrcmp(kode, voucherKode[i])) {
            return voucherDiskon[i];
        }
    }
    return 0;
}

void tampilkanItem() {
    cout << "~~~~~~~~~~~~~~~~~~~~\n|    List Item    |\n~~~~~~~~~~~~~~~~~~~~\n";
    for (int i = 0; i < itemCount; i++) {
        cout << i + 1 << ". " << itemNama[i] << " - " << itemHarga[i] << " rupiah\n";
    }
}

int validasiPembayaran(int saldoUser, int totalHarga, int metodeBayar) {
    if (metodeBayar == 1) {
        if (saldoUser >= totalHarga) {
            cout << "Pembayaran berhasil dengan saldo!\n";
            cout << "Sisa saldo Anda: " << saldoUser - totalHarga << " rupiah\n";
            return saldoUser - totalHarga;
        } else {
            cout << "Saldo tidak cukup.\n";
            return -1;
        }
    } else if (metodeBayar == 2) {
        cout << "Pembayaran tunai berhasil.\n";
        return saldoUser;
    } else {
        cout << "Metode pembayaran tidak valid.\n";
        return -1;
    }
}

void pembeliMember(int index) {
    if (gameCount == 0) {
        cout << "Belum ada game tersedia.\n";
        return;
    }

    // Tampilkan daftar game
    for (int i = 0; i < gameCount; i++)
        cout << i + 1 << ". " << namaGame[i] << "\n";

    // Pilih game
    int gameIdx;
    cout << "Pilih game: ";
    cin >> gameIdx;
    gameIdx--;

    if (gameIdx < 0 || gameIdx >= gameCount) {
        cout << "Pilihan tidak valid\n";
        return;
    }

    if (gameItemCount[gameIdx] == 0) {
        cout << "Game ini tidak memiliki item.\n";
        return;
    }

    // Tampilkan item game
    for (int i = 0; i < gameItemCount[gameIdx]; i++)
        cout << i + 1 << ". " << gameItemNama[gameIdx][i] << " - " << gameItemHarga[gameIdx][i] << "\n";

    // Pilih item
    int itemIdx;
    cout << "Pilih item: ";
    cin >> itemIdx;
    itemIdx--;

    if (itemIdx < 0 || itemIdx >= gameItemCount[gameIdx]) {
        cout << "Pilihan tidak valid\n";
        return;
    }

    // Voucher
    char kode[20];
    cout << "Masukkan kode voucher (jika tidak ada, ketik '-'): ";
    cin >> kode;

    int diskon = 0;
    if (!myStrcmp(kode, "-")) {
        diskon = cariVoucher(kode);
        if (diskon > 0) {
            cout << "Voucher berhasil diterapkan! Diskon " << diskon << "%\n";
        } else {
            cout << "Voucher tidak valid atau tidak ditemukan.\n";
        }
    }

    // Harga dan pembayaran
    int hargaAsli = gameItemHarga[gameIdx][itemIdx];
    int hargaDiskon = hargaAsli - (hargaAsli * diskon / 100);
    cout << "Harga asli: " << hargaAsli << "\n";
    if (diskon > 0) cout << "Harga setelah diskon: " << hargaDiskon << "\n";

    cout << "Bayar dengan (1. Saldo, 2. Tunai): ";
    int metode;
    cin >> metode;

    int hasilSaldo = validasiPembayaran(saldo[index], hargaDiskon, metode);
    if (hasilSaldo == -1) return;
    saldo[index] = hasilSaldo;

    // Simpan riwayat: username + item yang dipilih SAAT INI
    int i = 0;
    while (memberUsername[index][i]) {
        riwayatPembelian[riwayatCount][i] = memberUsername[index][i];
        i++;
    }

    riwayatPembelian[riwayatCount][i++] = ':';
    riwayatPembelian[riwayatCount][i++] = ' ';

    int j = 0;
    while (gameItemNama[gameIdx][itemIdx][j]) {
        riwayatPembelian[riwayatCount][i++] = gameItemNama[gameIdx][itemIdx][j++];
    }

    riwayatPembelian[riwayatCount][i] = '\0';
    riwayatCount++;

    cout << "Pembelian berhasil dicatat.\n";
}

void menuMember() {
    int index = loginMember();
    if (index == -1) return;
    
    int pilih;
    do {
        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~\n|    Menu Member   |\n~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1. Top Up Diamond\n2. Isi Saldo\n3. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) {
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~\n|    Menu Member   |\n~~~~~~~~~~~~~~~~~~~~\n";
            pembeliMember(index);
            system("pause");
        } else if (pilih == 2) {
            int isi;
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~\n|    Menu Member   |\n~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Jumlah isi saldo: ";
            cin >> isi;
            saldo[index] += isi;
            cout << "Saldo sekarang: " << saldo[index] << " rupiah\n";
            system("pause");
        }
    } while (pilih != 3);
}

void menuAdmin() {
    if (!loginAdmin()) {
        cout << "Login admin gagal.\n";
        system("pause");
        return;
    }

    int pilih;
    do {
        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~\n|    Menu Admin    |\n~~~~~~~~~~~~~~~~~~~~\n";
        cout << "1. Kelola Game\n2. Buat Voucher\n3. Lihat Riwayat\n4. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) {
            int sub;
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~\n|    Menu Admin    |\n~~~~~~~~~~~~~~~~~~~~\n";
            cout << "1. Tambah Game\n2. Hapus Game\n3. Kelola Item Game\nPilih: ";
            cin >> sub;
            if (sub == 1) {
                if (gameCount >= MAX_GAME) {
                    cout << "Jumlah game maksimal tercapai.\n";
                    continue;
                }
                cout << "Nama game: ";
                cin.ignore();
                cin.getline(namaGame[gameCount], 20);
                gameCount++;
                cout << "Game ditambahkan.\n";

            } else if (sub == 2) {
                for (int i = 0; i < gameCount; i++) {
                    cout << i + 1 << ". " << namaGame[i] << endl;
                }
                int hapus;
                cout << "Pilih nomor: ";
                cin >> hapus;
                if (hapus < 1 || hapus > gameCount) {
                    cout << "Pilihan tidak valid.\n";
                } else {
                    for (int i = hapus - 1; i < gameCount - 1; i++) {
                        myStrcpy(namaGame[i], namaGame[i + 1]);
                        gameItemCount[i] = gameItemCount[i + 1];
                        for (int j = 0; j < MAX_ITEM; j++) {
                            myStrcpy(gameItemNama[i][j], gameItemNama[i + 1][j]);
                            gameItemHarga[i][j] = gameItemHarga[i + 1][j];
                        }
                    }
                    gameCount--;
                    cout << "Game berhasil dihapus.\n";
                }

            } else if (sub == 3) {
                for (int i = 0; i < gameCount; i++) {
                    cout << i + 1 << ". " << namaGame[i] << endl;
                }
                int pilihGame;
                cout << "Pilih game: ";
                cin >> pilihGame;

                if (pilihGame < 1 || pilihGame > gameCount) {
                    cout << "Pilihan tidak valid.\n";
                } else {
                    int aksi;
                    int gameIdx = pilihGame - 1;
                    cout << "1. Tambah Item\n2. Lihat Item\nPilih: ";
                    cin >> aksi;

                    if (aksi == 1) {
                        if (gameItemCount[gameIdx] >= MAX_ITEM) {
                            cout << "Item penuh.\n";
                            continue;
                        }
                        cout << "Nama item: ";
                        cin.ignore();
                        cin.getline(gameItemNama[gameIdx][gameItemCount[gameIdx]], 20);
                        cout << "Harga item: ";
                        cin >> gameItemHarga[gameIdx][gameItemCount[gameIdx]];
                        gameItemCount[gameIdx]++;
                        cout << "Item berhasil ditambahkan.\n";
                    } else if (aksi == 2) {
                        cout << "Item pada " << namaGame[gameIdx] << ":\n";
                        for (int j = 0; j < gameItemCount[gameIdx]; j++) {
                            cout << j + 1 << ". " << gameItemNama[gameIdx][j]
                                 << " - " << gameItemHarga[gameIdx][j] << " rupiah\n";
                        }
                    }
                }
            }

        } else if (pilih == 2) {
            if (voucherCount >= MAX_VOUCHER) {
                cout << "Voucher penuh.\n";
                continue;
            }
            cout << "Kode voucher: ";
            cin >> voucherKode[voucherCount];
            cout << "Diskon (%): ";
            cin >> voucherDiskon[voucherCount];
            voucherCount++;
            cout << "Voucher dibuat.\n";

        } else if (pilih == 3) {
        	system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\n|    Riwayat Pembelian   |\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            for (int i = 0; i < riwayatCount; i++) {
                cout << i + 1 << ". " << riwayatPembelian[i] << endl;
            }
        }
        system("pause");
    } while (pilih != 4);
}

int main() {
    int flow = 1;
    char input;

    do {
        system("cls");
        banner();
        cout << ((flow == 1) ? "\033[1;35m~~~~~~~~~~~~~~~~~\n|    Sign In    |\n~~~~~~~~~~~~~~~~~\033[0m\n" : "~~~~~~~~~~~~~~~~~\n|    Sign In    |\n~~~~~~~~~~~~~~~~~\n");
        cout << ((flow == 2) ? "\033[1;35m~~~~~~~~~~~~~~~~~\n|    Sign Up    |\n~~~~~~~~~~~~~~~~~\033[0m\n" : "~~~~~~~~~~~~~~~~~\n|    Sign Up    |\n~~~~~~~~~~~~~~~~~\n");
        cout << ((flow == 3) ? "\033[1;35m~~~~~~~~~~~~~~~~~\n|     Exit      |\n~~~~~~~~~~~~~~~~~\033[0m\n" : "~~~~~~~~~~~~~~~~~\n|     Exit      |\n~~~~~~~~~~~~~~~~~\n");

        input = _getch();

        switch (input) {
            case 72: // Panah atas
                flow = (flow == 1) ? 3 : flow - 1;
                break;
            case 80: // Panah bawah
                flow = (flow == 3) ? 1 : flow + 1;
                break;
            case 13: // Enter
                if (flow == 1) {
                    system("cls");
                    int pilih;
                    cout << "~~~~~~~~~~~~~~~~~~~\n| Sign In sebagai |\n~~~~~~~~~~~~~~~~~~~\n1. Member\n2. Admin\nPilih: ";
                    cin >> pilih;
                    if (pilih == 1) menuMember();
                    else if (pilih == 2) menuAdmin();
                    else cout << "Pilihan tidak valid.\n";
                } else if (flow == 2) {
                    daftarMember();
                    system("pause");
                } else {
                    cout << "Terima kasih.\n";
                    return 0;
                }
                break;
        }
    } while (true);
}