#include <iostream>
using namespace std;

int main(){
    const int MAX = 100;
    int key;
    char teks [MAX];
    cout << "[ TASK 1/3 ] DECODE SIGNAL - Communication Room" << endl <<endl;
    cout << ">> Kirim sinyal terenkripsi dan deskripsi balasan dari Bumi!." << endl << endl;
    cout << "[ ENKRIPSI ]" << endl << endl;

    do{
        cout << "Masukkan key \t\t: "; cin >> key;
        if (cin.fail() || key <= 0){
        cin.clear();
        cin.ignore (MAX, '\n');
        cout << "[!] Key harus bilangan bulat positif. Coba lagi" << endl << endl;
        }
    }while (key <= 0);

    cin.ignore (MAX, '\n');    
    do{
    cout << "Masukkan teks \t\t: ";
    cin.getline (teks, MAX);
    cout << endl;

        if (teks [0] == '\0'){
            cout << "[!] Input tidak boleh kosong. Coba lagi" << endl << endl;
        }

    }while(teks [0] == '\0');

    //Matriks enkripsi
    int panjang = 0;
    while (teks [panjang] != '\0'){
        panjang++;
    }
    int baris = (panjang + 3) / 4; //buat itung jumlah barisnya

    char matriks [baris][4];
    int indeks = 0;

    for (int i = 0 ; i < baris ; i++){
        for (int j = 0 ; j < 4 ; j++){
             if (indeks < panjang){
                matriks [i][j] = teks [indeks];
            }
            else {
                matriks [i][j] = '_';
            }
            indeks++;
        }
    }
    cout << "Matriks Enkripsi: " << endl << endl;
    for (int i = 0 ; i < baris ; i++){
        for (int j = 0 ; j < 4 ; j++){
            cout << matriks [i][j] << " ";
            
        }
        cout << endl << endl;
    }
    cout << "Enkripsi sebelum ditambah key \t: ";
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < baris; i++) {
            cout << matriks[i][j];
        }
    }
    cout << endl;
    cout << "Enkripsi setelah ditambah key \t: ";
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < baris; i++) {
            cout << (char)(matriks[i][j] + key);
        }
    }
    cout << endl << endl;

    cout << "[ DESKRIPSI ]" << endl << endl;

    char enkripsi[MAX];
    // cin.ignore(MAX, '\n');
    do {
        cout << "Masukkan teks terenkripsi \t: ";
        cin.getline(enkripsi, MAX);

        if (enkripsi[0] == '\0') {
        cout << "[!] Input tidak boleh kosong. Coba lagi" << endl;
        }
    } while (enkripsi[0] == '\0');

 // hitung panjang enkripsi

    int panjangEnkripsi = 0;
    while (enkripsi[panjangEnkripsi] != '\0') {
        panjangEnkripsi++;
    }

// kurangi ASCII

    for (int i = 0; i < panjangEnkripsi; i++) {
        enkripsi[i] = enkripsi[i] - key;
    }
    cout << "Dekripsi setelah dikurang key \t: ";
    for (int i = 0; i < panjangEnkripsi; i++) {
        cout << enkripsi[i];
    }
    cout << endl << endl;

// isi matriks dekripsi per kolom

    int barisDekripsi = (panjangEnkripsi + 3) / 4;
    char matriksDekripsi[MAX][4];
    int indeks2 = 0;

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < barisDekripsi; i++) {
            if (indeks2 < panjangEnkripsi) {
                matriksDekripsi[i][j] = enkripsi[indeks2];
            } else {
                matriksDekripsi[i][j] = '_';
            }   
            indeks2++;
        }
    }

// tampilkan matriks dekripsi

    cout << "Matriks Dekripsi:" << endl << endl;
    for (int i = 0; i < barisDekripsi; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriksDekripsi[i][j] << " ";
        }
        cout << endl;
    }

// hasil final skip '_'

    cout << endl << "Hasil Dekripsi Final \t: ";
    for (int i = 0; i < barisDekripsi; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriksDekripsi[i][j] != '_') {
                cout << matriksDekripsi[i][j];
            }
        }
    }
    cout << endl;
    cout << ">> [TASK 1/3] COMPLETE - Signal channel restored." << endl;
    cout << "Tekan ENTER untuk melanjutkan ke [ TASK 2 ] !" << endl;

    system ("pause");
    system ("cls");

    cout << endl;

    //TASK2

    cout << "[TASK 2/3] REPAIR TEXT CONSOLE - Captain's Bridge" << endl;
    cout << ">> Konsol teks mengalami interfensi kosmik." << endl;
    cout << ">> Verifikasi integritas data teks sebelum terlambat!" << endl << endl;

    char pilih;
    do {
        cout << "[VERIFIKASI TEKS]" << endl << endl;
    // kalimat ke-1
        char kalimat1[MAX];
        cin.ignore(MAX, '\n');
        cout << "Masukkan Kalimat ke-1 \t: ";
        cin.getline(kalimat1, MAX);

    // hitung panjang dan jumlah huruf
        int panjangKalimat1 = 0;
        int jumlah1 = 0;
    while (kalimat1[panjangKalimat1] != '\0') {
        if (kalimat1[panjangKalimat1] != ' ') {
            jumlah1++;
        }
        panjangKalimat1++;        
    }
    cout << "----------------------------------------" << endl;
    cout << "Hasil untuk Kalimat ke-1:" << endl;
    cout << "Jumlah Huruf \t\t: " << jumlah1 << endl;

    cout << "1. Asli \t\t: ";
    for (int i = 0; i < panjangKalimat1; i++) {
        if (kalimat1[i] != ' ') {
            cout << kalimat1[i];
            if (i < panjangKalimat1 - 1) {
                cout << ", ";
            }
        }
    }
    cout << endl;
    cout << "2. Inverse \t\t: ";
    for (int i = panjangKalimat1 - 1; i >= 0; i--) {
        if (kalimat1[i] != ' ') {
            cout << kalimat1[i];
            if (i > 0) {
                cout << ", ";
            }
        }
    }
    cout << endl;
    // cari index pertama dan terakhir yang bukan spasi
    int awal = 0;
    int akhir = panjangKalimat1 - 1;

    while (kalimat1[awal] == ' ') awal++;
    while (kalimat1[akhir] == ' ') akhir--;

    // swap
    char simpan = kalimat1[awal];
    kalimat1[awal] = kalimat1[akhir];
    kalimat1[akhir] = simpan;

    cout << "3. Swap Awal-Akhir \t: ";
    for (int i = 0; i < panjangKalimat1; i++) {
        if (kalimat1[i] != ' ') {
            cout << kalimat1[i];
        }
    }
    cout << endl;

    int kiri = 0;
    int kanan = panjangKalimat1 - 1;
    bool palindrome = (jumlah1 != 0);

    while (kiri < kanan) {
        while (kalimat1[kiri] == ' ') kiri++;
        while (kalimat1[kanan] == ' ') kanan--;
        if (kalimat1[kiri] != kalimat1[kanan]) {
            palindrome = false;
        break;
        }
        kiri++;
        kanan--;
    }
    cout << "4. Palindrome? \t\t: ";
    if (palindrome) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    cout << endl;

    // kalimat ke-2
    char kalimat2[MAX];
    cout << "Masukkan Kalimat ke-2 \t: ";
    cin.getline(kalimat2, MAX);

    int panjangKalimat2 = 0;
    int jumlah2 = 0;
    while (kalimat2[panjangKalimat2] != '\0') {
        if (kalimat2[panjangKalimat2] != ' ') {
            jumlah2++;
        }
        panjangKalimat2++;
    }
    cout << "----------------------------------------" << endl;
    cout << "Hasil untuk Kalimat ke-2:" << endl;
    cout << "Jumlah Huruf \t\t: " << jumlah2 << endl;

    // asli
    cout << "1. Asli \t\t: ";
    for (int i = 0; i < panjangKalimat2; i++) {
        if (kalimat2[i] != ' ') {
            cout << kalimat2[i];
            if (i < panjangKalimat2 - 1) cout << ", ";
        }
    }
    cout << endl;

    // inverse
    cout << "2. Inverse \t\t: ";
    for (int i = panjangKalimat2 - 1; i >= 0; i--) {
        if (kalimat2[i] != ' ') {
            cout << kalimat2[i];
            if (i > 0) cout << ", ";
        }
    }
    cout << endl;

    // swap
    awal = 0;
    akhir = panjangKalimat2 - 1;
    while (kalimat2[awal] == ' ') awal++;
    while (kalimat2[akhir] == ' ') akhir--;
    simpan = kalimat2[awal];
    kalimat2[awal] = kalimat2[akhir];
    kalimat2[akhir] = simpan;

    cout << "3. Swap Awal-Akhir \t: ";
    for (int i = 0; i < panjangKalimat2; i++) {
        if (kalimat2[i] != ' ') cout << kalimat2[i];
    }
    cout << endl;

    // palindrome
    kiri = 0;
    kanan = panjangKalimat2 - 1;
    palindrome = (jumlah2 != 0);
    while (kiri < kanan) {
        while (kalimat2[kiri] == ' ') kiri++;
        while (kalimat2[kanan] == ' ') kanan--;
        if (kalimat2[kiri] != kalimat2[kanan]) {
            palindrome = false;
        break;
        }
        kiri++;
        kanan--;
    }
    cout << "4. Palindrome? \t\t: ";
    if (palindrome)
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
    cout << endl;

    // kalimat ke-3
    char kalimat3[MAX];
    cout << "Masukkan Kalimat ke-3 \t: ";
    cin.getline(kalimat3, MAX);

    int panjangKalimat3 = 0;
    int jumlah3 = 0;
    while (kalimat3[panjangKalimat3] != '\0') {
        if (kalimat3[panjangKalimat3] != ' ') {
            jumlah3++;
        }
        panjangKalimat3++;
    }
    cout << "----------------------------------------" << endl;
    cout << "Hasil untuk Kalimat ke-3:" << endl;
    cout << "Jumlah Huruf \t\t: " << jumlah3 << endl;

    // asli
    cout << "1. Asli \t\t: ";
    for (int i = 0; i < panjangKalimat3; i++) {
        if (kalimat3[i] != ' ') {
            cout << kalimat3[i];
            if (i < panjangKalimat3 - 1) cout << ", ";
        }
    }   
    cout << endl;

    // inverse
    cout << "2. Inverse \t\t: ";
    for (int i = panjangKalimat3 - 1; i >= 0; i--) {
        if (kalimat3[i] != ' ') {
            cout << kalimat3[i];
            if (i > 0) cout << ", ";
        }
    }
    cout << endl;

    // swap
    awal = 0;
    akhir = panjangKalimat3 - 1;
    while (kalimat3[awal] == ' ') awal++;
    while (kalimat3[akhir] == ' ') akhir--;
    simpan = kalimat3[awal];
    kalimat3[awal] = kalimat3[akhir];
    kalimat3[akhir] = simpan;

    cout << "3. Swap Awal-Akhir \t: ";
    for (int i = 0; i < panjangKalimat3; i++) {
        if (kalimat3[i] != ' ') cout << kalimat3[i];
    }
    cout << endl;

    // palindrome
    kiri = 0;
    kanan = panjangKalimat3 - 1;
    palindrome = (jumlah3 != 0);
    while (kiri < kanan) {
        while (kalimat3[kiri] == ' ') kiri++;
        while (kalimat3[kanan] == ' ') kanan--;
        if (kalimat3[kiri] != kalimat3[kanan]) {
            palindrome = false;
        break;
        }
        kiri++;
        kanan--;
    }
    cout << "4. Palindrome? \t\t: ";
    if (palindrome) cout << "YES" << endl;
    else cout << "NO" << endl;
    cout << endl;
    cout << "==========================================================" << endl;
    
    do {
        cout << "Verifikasi Teks Lain? (y/n): ";
        cin >> pilih;
        if (cin.fail() || (pilih != 'y' && pilih != 'Y' && pilih != 'n' && pilih != 'N')) {
            cin.clear();
            cin.ignore(MAX, '\n');
            cout << "[!] Input tidak valid. Masukkan y atau n." << endl;
        }
    } while (cin.fail() || (pilih != 'y' && pilih != 'Y' && pilih != 'n' && pilih != 'N'));

    } while (pilih == 'y' || pilih == 'Y');
    
    cout << endl << ">> [TASK 2/3] COMPLETE - Text console back online." << endl;
    cout << ">> Tekan ENTER untuk melanjutkan ke [ TASK 3 ]!." << endl;
    system ("pause");
    system ("cls");
    cout << endl;

//task 3
    cout << "[ TASK 3/3 ] ALIGN NAVIGATION MATRIX - Engine Core" << endl;
    cout << ">> Sistem navigasi mati total akibat sabotase." << endl;
    cout << ">> Rekonstruksi matriks koordinat sekarang!" << endl << endl;
    cout << "[ MATRIX NAVIGATION ]" << endl << endl;

    int n;
    do {
        cout << "Masukkan ukuran Navigation Matrix (min 3, max 5): ";
        cin >> n;
        if (cin.fail() || n < 3 || n > 5) {
            cin.clear();
            cin.ignore(MAX, '\n');
            cout << "[!] Input tidak valid. Masukkan ukuran antara 3 sampai 5." << endl << endl;
        }
    } while (cin.fail() || n < 3 || n > 5);

        
    int ganjil[5][5];
    int genap[5][5];

    // isi matriks ganjil
    cout << "Odd Coordinate Matrix (Ganjil):" << endl;
    int nilaiGanjil = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ganjil[i][j] = nilaiGanjil;
            if (ganjil[i][j] < 10) cout << " 0" << ganjil[i][j];
            else cout << " " << ganjil[i][j];
            nilaiGanjil += 2;
        }
        cout << endl;
    }

    cout << endl;

    // isi matriks genap
    cout << "Even Coordinate Matrix (Genap):" << endl;
    int nilaiGenap = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            genap[i][j] = nilaiGenap;
            if (genap[i][j] < 10) cout << " 0" << genap[i][j];
            else cout << " " << genap[i][j];
            nilaiGenap += 2;
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << endl << "Matriks koordinat telah dipulihkan" << endl;
    cout << "Lakukanlah proses-proses berikut ini untuk membuat matriks koordinat lebih akurat!" << endl;
    cout << "1. Coordinate Matrix Integration" << endl;
    cout << "2. Matrix Transpose" << endl;
    cout << "3. Snake Traverse" << endl << endl;
    cout << "Tekan ENTER untuk melanjutkan..." << endl;

    system("pause");
    system("cls");
    
    //integration
    int gabungGG[5][5];
    cout << "COORDINATE MATRIX INTEGRATION:" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            gabungGG[i][j] = ganjil[i][j] + genap[i][j];
            if (gabungGG[i][j] < 10) cout << " 0" << gabungGG[i][j];
            else cout << " " << gabungGG[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    //transpose cihuy
    cout << "MATRIX TRANSPOSE:" << endl;
    cout << "------------------------------------------------------------" << endl;
    int transpose[5][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = gabungGG[j][i];
            if (transpose[i][j] < 10) cout << " 0" << transpose[i][j];
            else cout << " " << transpose[i][j];
        }
        cout << endl;
    }
    cout << endl;

    //ular ssstt
    cout << "SNAKE TRAVERSE:" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // baris genap: kiri ke kanan
            for (int j = 0; j < n; j++) {
                if (transpose[i][j] < 10) cout << " 0" << transpose[i][j];
                else cout << " " << transpose[i][j];
            }
        } else {
            // baris ganjil: kanan ke kiri
            for (int j = n - 1; j >= 0; j--) {
                if (transpose[i][j] < 10) cout << " 0" << transpose[i][j];
                else cout << " " << transpose[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << endl << ">> [TASK 3/3] COMPLETE - Navigation matrix aligned." << endl;
    cout << "==========================================================================" << endl;
    cout << "  ALL TASK COMPLETE - SHIP SYSTEM RESTORED" << endl;
    cout << "==========================================================================" << endl;
    return 0;
}