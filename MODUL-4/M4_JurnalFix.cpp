#include <iostream>
using namespace std;

//enih konstanta yg kt akn pake ygy
const int MAX = 10; //kalo enih utk maks barangnya brp, jd kt cm bs masukin 10 barang je...
const int MAX_namaBarang = 50; //enih untuk maks nama barangnya (cmiiw) :D

//enih ktmulai declare funtions //mmf berantakan
void menuUtama(char nama[][MAX_namaBarang], int stok[], int harga[], int &total);
void menuTivaiz(char nama[][MAX_namaBarang], int stok[], int harga[], int &total);
void inputBarang(char nama[][MAX_namaBarang], int stok[], int harga[], int &total);
void hapusBarang(char nama[][MAX_namaBarang], int stok[], int harga[], int &total);
void editBarang(char nama[][MAX_namaBarang], int stok[], int harga[], int  total);
void lihatBarang(char nama[][MAX_namaBarang], int stok[], int harga[], int  total);
void editHarga(int &harga, char namaBarang[]);
void tambahStok(int &stok,  char namaBarang[]);
void kurangiStok(int &stok,  char namaBarang[]);
void menuKalkulator();
void operasiDasar();
long long faktorial(int n);

void bannerTivaiz (){
    cout << "#===============================================#" << endl;
    cout << "|                 TIVAIZ STORE                  |" << endl;
    cout << "#===============================================#" << endl << endl;
}

void bannerKalkulator (){
    cout << "#===============================================#" << endl;
    cout << "|                  KALKULATOR                   |" << endl;
    cout << "#===============================================#" << endl <<endl;
}

void tampilDaftar(char nama[][MAX_namaBarang], int stok[], int harga[], int total) {
    for (int i = 0; i < total; i++) {
        cout << "No          : " << i + 1 << "\n";
        cout << "Nama Barang : " << nama[i] << "\n";
        cout << "Stok Barang : " << stok[i] << "\n";
        cout << "Harga/Stok  : Rp " << harga[i] << "\n";
        cout << "------------------------------------------------\n";
    }
}

void menuUtama(char nama[][MAX_namaBarang], int stok[], int harga[], int &total) {
    int pilihanUsertercinta;
    do{
        cout << "|==============================================|" << endl;
        cout << "|                                              |" << endl;
        cout << "[             MODULE 4 - FUNCTION              ]" << endl;
        cout << "|                                              |" << endl;
        cout << "|==============================================|" << endl << endl;
        cout << "1. TIVAIZ Store" << endl;
        cout << "2. Kalkulator TIVAIZ" << endl;
        cout << "0. Keluar" << endl;
        cout << "=====================================" << endl;
        cout << "Pilihan menu: ";
        cin >> pilihanUsertercinta;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka!\n";
            pilihanUsertercinta = -1;
            system ("pause");
            system ("cls");
            continue;
        }  
        if (pilihanUsertercinta == 1)
            menuTivaiz (nama, stok, harga, total);
        else if (pilihanUsertercinta == 2)
            menuKalkulator();
        else if (pilihanUsertercinta == 0)
            cout << "Terima kasih telah menggunakan TIVAIZ Store";
        else{
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2.\n";
            system ("pause");
            system ("cls");
        }
    }while (pilihanUsertercinta != 0);
}

void menuTivaiz (char nama[][MAX_namaBarang], int stok[], int harga[], int &total){
    int pilihanUsertercinta;
    do{
        system ("cls");
        bannerTivaiz();
        cout << "1. Input Barang\n";
        cout << "2. Hapus Barang\n";
        cout << "3. Edit Barang\n";
        cout << "4. Lihat Barang\n";
        cout << "0. Kembali\n";
        cout << "================================\n";
        cout << "Pilih menu: ";
        cin >> pilihanUsertercinta;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka!\n";
            pilihanUsertercinta = -1; //reminder 2myself:
                                      //ini kyk pengaman, jd kalo ada input slh,program gak langsung close. sbnrnya bnyk cara lain tp lebih suka ini wkakw
            system ("pause");
            system ("cls"); 
            continue;
        }
        if (pilihanUsertercinta== 1)
            inputBarang(nama, stok, harga, total);
        else if (pilihanUsertercinta == 2)
            hapusBarang(nama, stok, harga, total);
        else if (pilihanUsertercinta == 3)
            editBarang (nama, stok, harga, total);
        else if (pilihanUsertercinta == 4)
            lihatBarang(nama, stok, harga, total);
        else if (pilihanUsertercinta == 0) { // balik
            system ("cls");
        }
        else {
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 4.\n";
            system ("pause");
            system ("cls");
        }
    }while (pilihanUsertercinta != 0);
}

void inputBarang (char nama[][MAX_namaBarang], int stok[], int harga[], int &total){
    system ("cls");
    bannerTivaiz ();
    cout << "-------------------------------------------------" << endl;
    cout << "                  INPUT BARANG                   " << endl << endl;
    cout << "-------------------------------------------------" << endl;
    if (total >= MAX){
        cout << "[Gagal] Kapasitas barang penuh!\n";
        system ("pause");
        return;
    }
    cout << "Nama Barang  : ";
    cin.ignore();
    cin.getline(nama[total], MAX_namaBarang);
    cout << "--------------------------------\n";
    cout << "Stok (unit)  : ";
    cin >> stok[total];
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Stok harus berupa angka!\n";
        system ("pause");
        return;
    }
    cout << "--------------------------------\n";
    cout << "Harga (Rp)   : ";
    cin >> harga[total];
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Harga harus berupa angka!\n";
        system ("pause");
        return;
    }
    total++;
    cout << "\n[Berhasil] " << nama[total - 1]
         << " ditambahkan! (Total barang: " << total << ")\n";
    system ("pause");;
}

void hapusBarang(char nama[][MAX_namaBarang], int stok[], int harga[], int &total) {
    system ("cls");
    bannerTivaiz();
    cout << "-------------------------------------------------" << endl;
    cout << "                  HAPUS BARANG                   " << endl << endl;
    cout << "-------------------------------------------------" << endl;
    if (total == 0){
        cout << "[Gagal] Belum ada barang!\n";
        system ("pause");
        return;
    }
    tampilDaftar(nama, stok, harga, total);
    cout << "Pilih nomor barang yang dihapus (1-" << total << "): ";
    int pilihanUsertercinta;
    cin >> pilihanUsertercinta;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system ("pause");
        return;
    }

    if (pilihanUsertercinta < 1 || pilihanUsertercinta > total) {
        cout << "[Gagal] Nomor " << pilihanUsertercinta << " tidak valid!"
             << " Pilih antara 1 sampai " << total << ".\n";
        system ("pause");
        return;
    }
    char namaHapus[MAX_namaBarang];
    for (int k = 0; k < MAX_namaBarang; k++) namaHapus[k] = nama[pilihanUsertercinta - 1][k];

    for (int i = pilihanUsertercinta - 1; i < total - 1; i++) {
        for (int k = 0; k < MAX_namaBarang; k++) nama[i][k] = nama[i + 1][k];
        stok[i]  = stok[i + 1];
        harga[i] = harga[i + 1];
    }
    total--;

    cout << "[Berhasil] " << namaHapus
         << " dihapus! (Total barang: " << total << ")\n";
    system ("pause");
}

void editHarga(int &harga, char namaBarang[]) {
    int hargaBaru;
    cout << "--------------------------------\n";
    cout << "Harga baru (Rp): ";
    cin >> hargaBaru;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system ("pause");
        return;
    }
    int hargaLama = harga;
    harga = hargaBaru;
    cout << "[Berhasil] Harga " << namaBarang
         << ": Rp " << hargaLama << " -> Rp " << harga << "\n";
    system ("pause");
}

void tambahStok(int &stok, char namaBarang[]) {
    int jumlah;
    cout << "--------------------------------\n";
    cout << "Jumlah tambah: ";
    cin >> jumlah;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system ("pause");
        return;
    }

    int stokLama = stok;
    stok += jumlah;
    cout << "[Berhasil] Stok " << namaBarang
         << ": " << stokLama << " -> " << stok << "\n";
    system ("pause");
}

void kurangiStok(int &stok, char namaBarang[]) {
    int jumlah;
    cout << "--------------------------------\n";
    cout << "Jumlah kurang: ";
    cin >> jumlah;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system ("pause");
        return;
    }

    if (jumlah >= stok) {
        cout << "[Gagal] Stok minimal 1!\n";
        cout << "Stok saat ini  : " << stok << "\n";
        cout << "Maks dikurangi : " << stok - 1 << "\n";
        system ("pause");
        return;
    }

    int stokLama = stok;
    stok -= jumlah;
    cout << "[Berhasil] Stok " << namaBarang
         << ": " << stokLama << " -> " << stok << "\n";
    system ("pause");
}

void editBarang(char nama[][MAX_namaBarang], int stok[], int harga[], int total) {
    system ("cls");
    bannerTivaiz();
    cout << "-------------------------------------------------" << endl;
    cout << "                   EDIT BARANG                   " << endl << endl;
    cout << "-------------------------------------------------" << endl;
    if (total == 0) {
        cout << "[Gagal] Belum ada barang!\n";
        system ("pause");
        return;
    }

    tampilDaftar(nama, stok, harga, total);

    cout << "Pilih nomor barang yang diedit (1-" << total << "): ";
    int pilihanUsertercinta;
    cin >> pilihanUsertercinta;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system ("pause");
        return;
    }

    if (pilihanUsertercinta < 1 || pilihanUsertercinta > total) {
        cout << "[Gagal] Nomor " << pilihanUsertercinta << " tidak valid!"
             << " Pilih antara 1 sampai " << total << ".\n";
        system ("pause");
        return;
    }

    int indeks = pilihanUsertercinta - 1;
    int opsi_dopsi;
    do {
        system ("cls");
        bannerTivaiz();
        cout << "-------------------------------------------------" << endl;
        cout << "                   EDIT BARANG                   " << endl << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Barang: " << nama[indeks] << "\n";
        cout << "--------------------------------\n";
        cout << "1. Edit Harga\n";
        cout << "2. Tambah Stok\n";
        cout << "3. Kurangi Stok\n";
        cout << "0. Kembali\n";
        cout << "--------------------------------\n";
        cout << "Pilih opsi: ";
        cin >> opsi_dopsi;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka!\n";
            system ("pause");
            continue;
        }
        if (opsi_dopsi == 1) 
            editHarga  (harga[indeks], nama[indeks]);
        else if (opsi_dopsi == 2) 
            tambahStok (stok[indeks],  nama[indeks]);
        else if (opsi_dopsi == 3) 
            kurangiStok(stok[indeks],  nama[indeks]);
        else if (opsi_dopsi == 0) {}
        else {
            cout << "[Gagal] Opsi tidak valid!\n";
            system ("pause");
        }
    } while (opsi_dopsi != 0);
}

void lihatBarang(char nama[][MAX_namaBarang], int stok[], int harga[], int total) {
    system ("cls");
    bannerTivaiz();
        cout << "-------------------------------------------------" << endl;
        cout << "                   LIHAT BARANG                   " << endl << endl;
        cout << "-------------------------------------------------" << endl;
    if (total == 0) {
        cout << "Belum ada barang di toko.\n";
    } else {
        for (int i = 0; i < total; i++) {
            cout << "No          : " << i + 1 << "\n";
            cout << "Nama Barang : " << nama[i] << "\n";
            cout << "Stok Barang : " << stok[i] << "\n";
            cout << "Harga/Stok  : Rp " << harga[i] << "\n";
            cout << "Total Harga : Rp " << stok[i] * harga[i] << "\n";
            cout << "------------------------------------------------\n";
        }
        cout << "Total barang : " << total << " jenis\n";
    }

    cout << "--------------------------------\n";
    system ("pause");
}

void menuKalkulator() {
    int pilihanUsertercinta;
    do {
        system ("cls");
        bannerKalkulator();
        cout << "1. Operasi Dasar (+, -, *, /)\n";
        cout << "2. Faktorial\n";
        cout << "0. Kembali\n";
        cout << "================================\n";
        cout << "Pilih menu: ";
        cin >> pilihanUsertercinta;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka!\n";
            pilihanUsertercinta = -1;
            system ("pause");
            system ("cls");
            continue;
        }

        if (pilihanUsertercinta == 1) {
            operasiDasar();
        } else if (pilihanUsertercinta == 2) {
            system ("cls");
            bannerKalkulator();
            cout << "--------------------------------\n";
            int nakHitung_apa;
            cout << "N : ";
            cin >> nakHitung_apa;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "[Gagal] Input harus berupa angka!\n";
                system ("pause");
                continue;
            }

            cout << "--------------------------------\n";
            if (nakHitung_apa < 0) {
                cout << "[Gagal] Faktorial tidak bisa untuk angka negatif!\n";
            } else {
                cout << nakHitung_apa << "! = " << faktorial(nakHitung_apa) << "\n";
            }
            system ("pause");
        } else if (pilihanUsertercinta == 0) { //balik
             system ("cls");
        } else {
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2.\n";
            system ("pause");
            system ("cls");
        }
    } while (pilihanUsertercinta != 0);
}

void operasiDasar() {
    system ("cls");
    bannerKalkulator();
    cout << "--------------------------------\n";

    char ini_operator;
    cout << "Operator (+, -, *, /) : ";
    cin >> ini_operator;

    if (ini_operator != '+' && ini_operator != '-' && ini_operator != '*' && ini_operator != '/') {
        cout << "[Gagal] Operator tidak valid!\n";
        system ("pause");
        return;
    }

    float angkaSatuy, angkaDuaw;
    cout << "--------------------------------\n";
    cout << "Angka pertama : ";
    cin >> angkaSatuy;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system ("pause");
        return;
    }

    cout << "--------------------------------\n";
    cout << "Angka kedua   : ";
    cin >> angkaDuaw;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system ("pause");
        return;
    }

    cout << "--------------------------------\n";
    if      (ini_operator == '+') cout << angkaSatuy << " + " << angkaDuaw << " = " << angkaSatuy + angkaDuaw << "\n";
    else if (ini_operator == '-') cout << angkaSatuy << " - " << angkaDuaw << " = " << angkaSatuy - angkaDuaw << "\n";
    else if (ini_operator == '*') cout << angkaSatuy << " * " << angkaDuaw << " = " << angkaSatuy * angkaDuaw << "\n";
    else if (ini_operator == '/') {
        if (angkaDuaw == 0) cout << "[Gagal] Tidak bisa dibagi nol!\n";
        else        cout << angkaSatuy << " / " << angkaDuaw << " = " << angkaSatuy / angkaDuaw << "\n";
    }
    system ("pause");;
}
//inilah sosok pengguaan rekursif ituh :[
long long faktorial(int n) {
    if (n == 0) return 1;
    return n * faktorial(n - 1);
}

//enilah sosok si main ituh
int main (){ 
    char namaBarang[MAX][MAX_namaBarang];
    int  stokBarang[MAX];
    int  hargaBarang[MAX];
    int  totalBarang = 0;

    menuUtama(namaBarang, stokBarang, hargaBarang, totalBarang);
 

    return 0;
}
