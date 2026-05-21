// ==================================================================
//  DEKLARASI STRUCT
// ==================================================================

// #include <iostream>
// using namespace std;

// // Deklarasi struct
// struct Mahasiswa {
//     string nama;
//     string nim;
//     float  ipk;
// };

// // Fungsi untuk menampilkan data
// void tampilkan(Mahasiswa m) {
//     cout << "Nama : " << m.nama << endl;
//     cout << "NIM  : " << m.nim  << endl;
//     cout << "IPK  : " << m.ipk  << endl;
// }

// int main() {
//     // Cara 1 — inisialisasi langsung
//     Mahasiswa mhs1 = {"Jovanka 144P Kiara", "F1D02510061", 3.85};

//     // Cara 2 — isi field satu per satu
//     Mahasiswa mhs2;
//     mhs2.nama = "Caylazefa Gracia Getsemani Ario";
//     mhs2.nim  = "F1D02410044";
//     mhs2.ipk  = 3.99;

//     // Akses dan tampilkan
//     cout << "=== Data Mahasiswa 1 ===" << endl;
//     tampilkan(mhs1);

//     cout << "\n=== Data Mahasiswa 2 ===" << endl;
//     tampilkan(mhs2);

//     // Ubah nilai field
//     mhs1.ipk = 3.90;
//     cout << "\nIPK Jo setelah update: " << mhs1.ipk << endl;
//     return 0;
// }


// ==================================================================
//  NESTED STRUCT
// ==================================================================

// #include <iostream>
// using namespace std;

// // ── LEVEL 1: struct paling dalam ──────────────────
// struct Mahasiswa {
//     string nama;
//     int    nim;
//     float  ipk;
// };

// // ── LEVEL 2: mengandung Mahasiswa ─────────────────
// struct Fakultas {
//     string    nama_fak;
//     string    dekan;
//     Mahasiswa mhs;
// };

// // ── LEVEL 3: mengandung Fakultas (yang berisi Mahasiswa) ──
// struct Universitas {
//     string   nama_univ;
//     string   kota;
//     Fakultas fak;
// };

// // ── FUNCTION: tampilkan satu objek Mahasiswa ──────
// void tampilMahasiswa(Mahasiswa m) {
//     cout << "      Nama      : " << m.nama << "\n";
//     cout << "      NIM       : " << m.nim  << "\n";
//     cout << "      IPK       : " << m.ipk << "\n";
// }

// // ── FUNCTION: tampilkan satu objek Fakultas + Mahasiswa di dalamnya ──
// void tampilFakultas(Fakultas f) {
//     cout << "   Fakultas     : " << f.nama_fak << "\n";
//     cout << "   Dekan        : " << f.dekan    << "\n";
//     cout << "   [ Mahasiswa ]\n";
//     tampilMahasiswa(f.mhs);  // memanggil function level 1
// }

// // ── FUNCTION: tampilkan satu objek Universitas (semua level) ──
// void tampilUniversitas(Universitas u) {
//     cout << "================================\n";
//     cout << "Universitas  : " << u.nama_univ << "\n";
//     cout << "Kota         : " << u.kota      << "\n";
//     cout << "[ Fakultas ]\n";
//     tampilFakultas(u.fak);   // memanggil function level 2
//     cout << "================================\n";
// }

// int main() {
//     // Data univ 1 — inisialisasi bertahap
//     Universitas univ;

//     // mengisi data mahasiswa (level 1)
//     univ.fak.mhs.nama = "Misel Ingusan";
//     univ.fak.mhs.nim  = 12345;
//     univ.fak.mhs.ipk  = 3.85;

//     // mengisi data fakultas (level 2)
//     univ.fak.nama_fak = "Teknik Informatika";
//     univ.fak.dekan    = "Dr. Gaza PHD";

//     // mengisi data universitas (level 3)
//     univ.nama_univ    = "Universitas Labu Api";
//     univ.kota         = "Terong Tawah";

//     // Data univ 2 — inisialisasi langsung
//     Universitas univ2 = {
//         "Universitas Gomong",
//         "Sembalun",
//         { "Ilmu Komputer", "#sapa Prof. Sagos",
//         { "Misel belum cebok", 67890, 3.72 } }
//     };

//     // Panggil function untuk menampilkan semua data
//     cout << "\n===== DATA UNIVERSITAS =====\n";
//     tampilUniversitas(univ);
//     tampilUniversitas(univ2);

//     return 0;
// }


// ==================================================================
//  ARRAY OF STRUCT
// ==================================================================

// #include <iostream>
// using namespace std;

// struct Mahasiswa {
//     string nama;
//     int    nim;
//     float  ipk;
// };

// // Fungsi untuk menampilkan data
// void tampilkan(Mahasiswa mhs[]) {
//     cout << "\nNo  Nama                NIM   IPK\n";
//     cout << "--- ------------------- ------ ----\n";
//     for (int i = 0; i < 5; i++) {
//         cout << i+1 << ".  "
//             << mhs[i].nama << "\t"
//             << mhs[i].nim  << "  "
//             << mhs[i].ipk  << "\n";
//     }
// }

// void ipkTertinggi(Mahasiswa mhs[]){
//     int idxMax = 0;
//     for (int i = 1; i < 5; i++) {
//         if (mhs[i].ipk > mhs[idxMax].ipk)
//             idxMax = i;
//     }
//     cout << "\nIPK tertinggi: " << mhs[idxMax].nama
//         << " (" << mhs[idxMax].ipk << ")\n";
// }
// int main() {
//     // Inisialisasi array of struct langsung
//     Mahasiswa mhs[5] = {
//         { "Kumis Plenger",  12001, 3.85 },
//         { "Diki Plenger",  12002, 3.72 },
//         { "Widya Plenger", 12003, 3.91 },
//         { "Husna Plenger",  12004, 3.60 },
//         { "Gaza Org bnr",   12005, 3.45 }
//     };

//     // Tampilkan semua data
//     tampilkan(mhs);
//     // Cari IPK tertinggi
//     ipkTertinggi(mhs);

//     return 0;
// }


// ==================================================================
//  STRUCT OF ARRAY
// ==================================================================
// #include <iostream>
// #include <iomanip>
// using namespace std;

// const int MAKS = 100; // kapasitas maksimum

// // ── STRUCT OF ARRAY ───────────────────────────────
// // Field-nya adalah array, bukan nilai tunggal
// struct DataMahasiswa {
//     string nama[MAKS];
//     int    nim [MAKS];
//     float  ipk [MAKS];
//     int    jumlah;      // berapa elemen yang terisi
// };

// // ── FUNCTION: tambah satu mahasiswa ──────────────
// void tambahMahasiswa(DataMahasiswa &d, string nm, int n, float ip) {
//     if (d.jumlah >= MAKS) {
//         cout << "Data penuh!\n";
//         return;
//     }
//     int i        = d.jumlah;
//     d.nama[i]    = nm;
//     d.nim [i]    = n;
//     d.ipk [i]    = ip;
//     d.jumlah++;
// }

// // ── FUNCTION: tampilkan semua mahasiswa ──────────
// void tampilSemua(const DataMahasiswa &d) {
//     cout << left << setw(4)  << "No" << setw(18) << "Nama" << setw(10)  << "NIM" << setw(6) << "IPK" << "\n";
//     cout << string(38, '-') << "\n";

//     for (int i = 0; i < d.jumlah; i++) {
//         cout << left << setw(4)  << i + 1 << setw(18) << d.nama[i] << setw(10) << d.nim[i]  << setw(6) << d.ipk[i] << "\n";
//     }
// }

// // ── FUNCTION: cari mahasiswa berdasarkan NIM ─────
// void cariByNIM(const DataMahasiswa &d, int cariNIM) {
//     for (int i = 0; i < d.jumlah; i++) {
//         if (d.nim[i] == cariNIM) {
//             cout << "Ditemukan!\n";
//             cout << "  Nama : " << d.nama[i] << "\n";
//             cout << "  NIM  : " << d.nim[i]  << "\n";
//             cout << "  IPK  : " << d.ipk[i] << "\n";
//             return;
//         }
//     }
//     cout << "NIM " << cariNIM << " tidak ditemukan.\n";
// }

// // ── FUNCTION: hitung rata-rata IPK ───────────────
// float rataIPK(const DataMahasiswa &d) {
//     if (d.jumlah == 0) return 0;
//     float total = 0;
//     for (int i = 0; i < d.jumlah; i++)
//         total += d.ipk[i];
//     return total / d.jumlah;
// }

// // ── FUNCTION: cari IPK tertinggi ─────────────────
// void ipkTertinggi(const DataMahasiswa &d) {
//     int idx = 0;
//     for (int i = 1; i < d.jumlah; i++)
//         if (d.ipk[i] > d.ipk[idx]) idx = i;

//     cout << "IPK tertinggi: " << d.nama[idx] << " (" << d.ipk[idx] << ")\n";
// }

// // ── MAIN ──────────────────────────────────────────
// int main() {
//     DataMahasiswa data;
//     data.jumlah = 0; // wajib diinisialisasi ke 0

//     // Tambah data
//     // tambahMahasiswa(data, "Cayla", 12001, 3.85);
//     // tambahMahasiswa(data, "BAUU", 12002, 3.72);
//     // tambahMahasiswa(data, "Tidak", 12003, 3.91);
//     // tambahMahasiswa(data, "Pernah", 12004, 3.60);
//     // tambahMahasiswa(data, "Mandi", 12005, 3.45);
//     for(int i = 0; i < 5; i++){
//         cout << "Masukkan nama :"; cin >> data.nama[i];
//         cout << "Masukkan nama :"; cin >> data.nim[i];
//         cout << "Masukkan nama :"; cin >> data.ipk[i];
//         data.jumlah ++;
//     }

//     // Tampilkan semua
//     cout << "\n===== DAFTAR MAHASISWA =====\n";
//     tampilSemua(data);

//     // Cari berdasarkan NIM
//     cout << "\n===== PENCARIAN NIM 12003 =====\n";
//     cariByNIM(data, 12003);

//     // Statistik
//     cout << "\n===== STATISTIK =====\n";
//     cout << "Rata-rata IPK : " << fixed << setprecision(2) << rataIPK(data) << "\n";

//     // IPK Tertinggi
//     cout << "\n===== IPK Tertinggi =====\n";
//     ipkTertinggi(data);

//     return 0;
// }


// ==================================================================
//  STRUCT WITH FUNCTION
// ==================================================================

// #include <iostream>
// #include <iomanip>
// using namespace std;

// const int MAKS = 100;

// // Field-nya adalah array, bukan nilai tunggal
// struct DataMahasiswa {
//     string nama[MAKS];
//     int    nim [MAKS];
//     float  ipk [MAKS];
//     int    jumlah = 0;

//     // ── FUNCTION: tambah satu mahasiswa ──────────
//     void tambahMahasiswa(string nm, int n, float ip) {
//         if (jumlah >= MAKS) {
//             cout << "Data penuh!\n";
//             return;
//         }
//         nama[jumlah] = nm;
//         nim [jumlah] = n;
//         ipk [jumlah] = ip;
//         jumlah++;
//     }

//     // ── FUNCTION: tampilkan semua ─────────────────
//     void tampilSemua() {
//         cout << left << setw(4)  << "No" << setw(18) << "Nama" << setw(10) << "NIM" << "IPK\n";
//         cout << string(38, '-') << "\n";
//         for (int i = 0; i < jumlah; i++) {
//             cout << left << setw(4)  << i + 1 << setw(18) << nama[i]  << setw(10) << nim[i] << ipk[i] << "\n";
//         }
//     }

//     // ── FUNCTION: cari berdasarkan NIM ───────────
//     void cariByNIM(int cariNIM) {
//         for (int i = 0; i < jumlah; i++) {
//             if (nim[i] == cariNIM) {
//                 cout << "Ditemukan!\n";
//                 cout << "  Nama : " << nama[i] << "\n";
//                 cout << "  NIM  : " << nim[i]  << "\n";
//                 cout << "  IPK  : " << fixed << setprecision(2) << ipk[i] << "\n";
//                 return;
//             }
//         }
//         cout << "NIM " << cariNIM << " tidak ditemukan.\n";
//     }

//     // ── FUNCTION: rata-rata IPK ───────────────────
//     float rataIPK() {
//         if (jumlah == 0) return 0;
//         float total = 0;
//         for (int i = 0; i < jumlah; i++)
//             total += ipk[i];
//         return total / jumlah;
//     }

//     // ── FUNCTION: IPK tertinggi ───────────────────
//     void ipkTertinggi() {
//         int idx = 0;
//         for (int i = 1; i < jumlah; i++)
//             if (ipk[i] > ipk[idx])
//                 idx = i;
//         cout << "IPK Tertinggi: " << nama[idx] << " (" << fixed << setprecision(2) << ipk[idx] << ")\n";
//     }
// };

// // ── MAIN ──────────────────────────────────────────
// int main() {
//     DataMahasiswa data;

//     // Tambah data
//     data.tambahMahasiswa("Jovanka", 12001, 3.85);
//     data.tambahMahasiswa("144p",  12002, 3.72);
//     data.tambahMahasiswa("Tuyul", 12003, 3.91);
//     data.tambahMahasiswa("Tumbler",12004, 3.60);
//     data.tambahMahasiswa("Kiara", 12005, 3.45);

//     // Tampilkan semua
//     cout << "\n===== DAFTAR MAHASISWA =====\n";
//     data.tampilSemua();

//     // Cari berdasarkan NIM
//     cout << "\n===== PENCARIAN NIM 12003 =====\n";
//     data.cariByNIM(12003);

//     // Statistik
//     cout << "\n===== STATISTIK =====\n";
//     cout << "Rata-rata IPK : " << fixed << setprecision(2) << data.rataIPK() << "\n";

//     // IPK Tertinggi
//     cout << "\n===== IPK TERTINGGI =====\n";
//     data.ipkTertinggi();

//     return 0;
// }



// ==================================================================
//  ANSI ESCAPE CODE
// ==================================================================

// #include <iostream>
// #define RED     "\033[31m"
// #define GREEN   "\033[32m"
// #define YELLOW  "\033[33m"
// #define BLUE    "\033[34m"
// #define RESET   "\033[0m"
// using namespace std;

// void logo(){
//     cout << RED R"(
//                                                                                                                   ##
//  ##    ##                                                     :####:                                       ##     ##
//  ##    ##                                                    :######     ##                                ##     ##
//  ##    ##                                                    ##:  :#     ##                                ##
//  ##    ##  ##    ##   :#####.  ##.####    :####              ##        #######    .####:   ##.####    :###.##   ####     ##.####    :###:##)";
//     cout << GREEN R"(
//  ##    ##  ##    ##  ########  #######    ######             ###:      #######   .######:  #######   :#######   ####     #######   .#######
//  ########  ##    ##  ##:  .:#  ###  :##   #:  :##            :#####:     ##      ##:  :##  ###  :##  ###  ###     ##     ###  :##  ###  ###
//  ########  ##    ##  ##### .   ##    ##    :#####             .#####:    ##      ########  ##    ##  ##.  .##     ##     ##    ##  ##.  .##
//  ##    ##  ##    ##  .######:  ##    ##  .#######                :###    ##      ########  ##    ##  ##    ##     ##     ##    ##  ##    ##
//  ##    ##  ##    ##     .: ##  ##    ##  ## .  ##                  ##    ##      ##        ##    ##  ##.  .##     ##     ##    ##  ##.  .## )";
//     cout << YELLOW R"(
//  ##    ##  ##:  ###  #:.  :##  ##    ##  ##:  ###            #:.  :##    ##.     ###.  :#  ##    ##  ###  ###     ##     ##    ##  ###  ###
//  ##    ##   #######  ########  ##    ##  ########            #######:    #####   .#######  ##    ##  :#######  ########  ##    ##  .#######
//  ##    ##    ###.##  . ####    ##    ##    ###.##            .#####:     .####    .#####:  ##    ##   :###.##  ########  ##    ##   :###:##
//                                                                                                                                     #.  :##
//                                                                                                                                     ######
//                                                                                                                                     :####:)";
//     cout << BLUE R"(
                                                                                                                                            
//                                     H U S N A   K E B O   N D A K   P E R N A H   M A N D I
// )" RESET ;
// }

// int main() {
//     logo();
//     return 0;
// }



// ==================================================================
//  BUILD IN SRAND & RAND
// ==================================================================

// #include <iostream>
// using namespace std;

// int main() {
//     while(true){
//         srand(time(0));

//         int jumlah = 5;
//         for (int i = 0; i < jumlah; i++) {
//             int dadu = rand() % 6 + 1; // hasil: 1 sampai 6
//             cout << "Dadu ke-" << i + 1 << ": " << dadu << endl;
//         }
        
//         system("pause");
//         system("cls");
//     }
//     return 0;
// }


// ==================================================================
//  Latihan SRAND & RAND
// ==================================================================

// #include <iostream>
// #include <iomanip>
// using namespace std;

// const int MAKS         = 7;
// const int MAKS_JURUSAN = 4;

// struct Mahasiswa {
//     string nama[MAKS] = {"Misel Ga Cebok", "Jo 144P", "Husna Stending", "Cayla Ingusan",  "Diki Ngerokok",  "Caca Berkumis", "Widya Mber"};
//     int nim[MAKS] = {1001, 1002, 1003, 1004, 1005, 1006, 1007};
//     float nilai[MAKS] = {3.85, 3.72, 3.91, 3.60, 3.45, 3.80, 3.90};
//     int idxJurusan[MAKS] = {0, 1, 2, 3, 0, 1, 2};
//     string daftarJurusan[MAKS_JURUSAN] = { "Teknik Informatika", "Sistem Informasi", "Teknik Komputer", "Ilmu Komputer"};

//     int jumlah = MAKS;

//     // ── FUNCTION: status nilai ────────────────────────────
//     string statusNilai(int i) {
//         if (nilai[i] >= 3.75f) return "A  — Sangat Memuaskan";
//         if (nilai[i] >= 3.50f) return "B+ — Memuaskan";
//         if (nilai[i] >= 3.00f) return "B  — Cukup Memuaskan";
//         return                        "C  — Cukup";
//     }

//     // ── FUNCTION: tampil satu data berdasarkan indeks ─────
//     void tampilSatu(int i) {
//         cout << "  Nama    : " << nama[i]                      << "\n";
//         cout << "  NIM     : " << nim[i]                       << "\n";
//         cout << "  Jurusan : " << daftarJurusan[idxJurusan[i]] << "\n";
//         cout << "  Nilai   : " << fixed << setprecision(2)     << nilai[i]                     << "\n";
//         cout << "  Status  : " << statusNilai(i)               << "\n";
//         cout << string(50, '-') << "\n";
//     }

//     // ── FUNCTION: tampil satu data acak ──────────────────
//     void tampilAcak() {
//         int i = rand() % jumlah;

//         cout << "\n" << string(50, '=') << "\n";
//         cout << "        MAHASISWA TERPILIH SECARA ACAK\n";
//         cout << string(50, '=') << "\n";
//         cout << "\nIndex terpilih : " << i << " (Mahasiswa ke-" << i + 1 << ")\n\n";
//         tampilSatu(i);
//     }
// };

// // ── MAIN ──────────────────────────────────────────────────
// int main() {
//     while(true) {
//         srand(time(0));

//         Mahasiswa data;
//         data.tampilAcak();
//         system("pause");
//         system("cls");
//     }
//     return 0;
// }