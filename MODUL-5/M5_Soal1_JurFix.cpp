#include <iostream>
using namespace std;

struct Tanggal{
    int tanggal;
    int bulan;
    int tahun;
};

struct Alamat{
    string jalan;
    string kelurahan;
    string kota;
    string provinsi;
    int kodePos;
};

struct TglLahir {
    int tanggal_lahir;
    int bulan;
    int tahun;
};

struct Alergi {
    string alergen;
    string reaksi;
};

struct PasienBaru {
    int id;
    string nik;
    string nama;
    TglLahir tgl; 
    char jenisKelamin;
    char goldar;
    string noTelp;
    Alamat almt;
    char pesertaBPJS;
    int jmlAlergi;
    Alergi alrg[5];
    Tanggal tglMasuk;
};

const int MAX = 100;
PasienBaru daftarPasien [MAX];
int totalPasien = 0;
Tanggal tanggalHariIni = {21, 5, 2026};


TglLahir inputTanggalLahir (){
TglLahir lahir;
do {
        cout << "      Tanggal : ";
        cin >> lahir.tanggal_lahir;
        if (lahir.tanggal_lahir < 1 || lahir.tanggal_lahir > 31)
            cout << "      [!] Tanggal harus 1-31\n";
    } while (lahir.tanggal_lahir < 1 || lahir.tanggal_lahir > 31);

    do {
        cout << "      Bulan   : ";
        cin >> lahir.bulan;
        if (lahir.bulan < 1 || lahir.bulan > 12)
            cout << "      [!] Bulan harus 1-12\n";
    } while (lahir.bulan < 1 || lahir.bulan > 12);

    do {
        cout << "      Tahun   : ";
        cin >> lahir.tahun;
        if (lahir.tahun < 1900 || lahir.tahun > 2100)
            cout << "      [!] Tahun tidak valid\n";
    } while (lahir.tahun < 1900 || lahir.tahun > 2100);

    return lahir;
}


void detailPendaftaran(PasienBaru p){
    cout << "--------------------------------------------------" << endl;
    cout << "ID   : " << p.id
         << "\t\t\tTgl Masuk: "
         << p.tglMasuk.tanggal << "/" << p.tglMasuk.bulan << "/" << p.tglMasuk.tahun << endl;
    cout << "NIK (16 Digit)      : " << p.nik << endl;
    cout << "Nama                : " << p.nama << endl;
    cout << "Tgl Lahir " << endl;
    cout << "    Tanggal    : " << p.tgl.tanggal_lahir << endl;
    cout << "    Bulan      : " << p.tgl.bulan << endl;
    cout << "    Tahun      : " << p.tgl.tahun << endl;
    cout << "Jenis Kelamin (L/P) : " << p.jenisKelamin << endl;
    cout << "Gol. Darah          : " << p.goldar << endl;
    cout << "No. Telp            : " << p.noTelp << endl;
    cout << "Alamat " << endl;
    cout << "    Jalan      : " << p.almt.jalan << endl;
    cout << "    Kelurahan  : " << p.almt.kelurahan << endl;
    cout << "    Kota       : " << p.almt.kota << endl;
    cout << "    Provinsi   : " << p.almt.provinsi << endl;
    cout << "    Kode Pos   : " << p.almt.kodePos << endl;
    cout << "Peserta BPJS (y/n)  : " << p.pesertaBPJS << endl;
    cout << "Jumlah Alergi (0-5) : " << endl;
    if (p.jmlAlergi == 0){
        cout <<  "Tidak ada alergi." << endl;
    } else {
        for (int i = 0; i < p.jmlAlergi; i++) {
            cout << "[Alergi " << i + 1 << "]" << endl;
        cout << "  Alergen : " << p.alrg[i].alergen << endl;
        cout << "  Reaksi  : " << p.alrg[i].reaksi << endl;
        }
    }
    cout << "--------------------------------------------------" << endl;
}

void dataDummyDummy (){

    daftarPasien[0].id = 1;
    daftarPasien[0].nik = "5261020xxx34567";
    daftarPasien[0].nama = "Hatta Perkasa";
    daftarPasien[0].tgl = {11, 1, 2000};
    daftarPasien[0].jenisKelamin = 'L';
    daftarPasien[0].goldar = 'A';
    daftarPasien[0].noTelp = "08144421xxxx";
    daftarPasien[0].almt = {"Jl. Pisang No. 67", "Rabangodu", "Bima", "NTB", 67670};
    daftarPasien[0].pesertaBPJS = 'y';
    daftarPasien[0].jmlAlergi = 2;
    daftarPasien[0].alrg[0] = {"Debu", "Sesak napas"};
    daftarPasien[0].alrg[1] = {"Kacang", "Muncul ruam merah"};
    daftarPasien[0].tglMasuk = {01, 5, 2026};

    
    daftarPasien[1].id = 2;
    daftarPasien[1].nik = "5261030xxx45678";
    daftarPasien[1].nama = "Ahsanul Fuad";
    daftarPasien[1].tgl = {4, 5, 2007};
    daftarPasien[1].jenisKelamin = 'L';
    daftarPasien[1].goldar = 'B';
    daftarPasien[1].noTelp = "08533095xxxx";
    daftarPasien[1].almt = {"Jl. Menuju Surga No. 99", "Gunung Sari", "Mataran", "NTB", 6667};
    daftarPasien[1].pesertaBPJS = 'n';
    daftarPasien[1].jmlAlergi = 0;
    daftarPasien[1].tglMasuk = {17, 5, 2026};

    totalPasien = 2;
}

void pendaftaranPasienBaru (){
    if (totalPasien >= MAX){
        cout << "[!] Data Sudah Penuh! ";
        return;
    }
    PasienBaru p;
    p.id = totalPasien + 1;
    p.tglMasuk = tanggalHariIni; 
    cout << "==================================================" << endl;
    cout << "               PENDAFTARAN PASIEN BARU            " << endl;
    cout << "==================================================" << endl;
    cin.ignore();
    cout << "NIK (16 digit)      : "; getline(cin, p.nik);
    cout << "Nama                : "; getline(cin, p.nama);

    cout << "Tgl Lahir           :" << endl;
    p.tgl = inputTanggalLahir();

    cout << "Jenis Kelamin (L/P) : "; cin >> p.jenisKelamin;
    cout << "Gol. Darah          : "; cin >> p.goldar;

    cin.ignore();
    cout << "No. Telp            : "; getline(cin, p.noTelp);

    cout << "Alamat              :" << endl;
    cout << "   Jalan     : "; getline(cin, p.almt.jalan);
    cout << "   Kelurahan : "; getline(cin, p.almt.kelurahan);
    cout << "   Kota      : "; getline(cin, p.almt.kota);
    cout << "   Provinsi  : "; getline(cin, p.almt.provinsi);
    cout << "   Kode Pos  : "; cin >> p.almt.kodePos;

    cout << "Peserta BPJS (y/n)  : "; cin >> p.pesertaBPJS;

    do {
        cout << "Jumlah alergi (0-5) : "; cin >> p.jmlAlergi;
        if (p.jmlAlergi < 0 || p.jmlAlergi > 5)
            cout << "[!] Masukkan angka 0-5\n";
    } while (p.jmlAlergi < 0 || p.jmlAlergi > 5);

    cin.ignore();
    for (int i = 0; i < p.jmlAlergi; i++) {
        cout << "[Alergi " << i + 1 << "]" << endl;
        cout << "   Alergen : "; getline(cin, p.alrg[i].alergen);
        cout << "   Reaksi  : "; getline(cin, p.alrg[i].reaksi);
    }

    daftarPasien[totalPasien] = p;
    totalPasien++;

    cout << "\n[OK] Pasien ID-" << p.id << " berhasil didaftarkan!\n";
}

void lihatSemuaPasien (){
    cout << "==================================================" << endl;
    cout << "                   DAFTAR PASIEN                  " << endl;
    cout << "==================================================" << endl;

    if (totalPasien == 0) {
        cout << "Belum ada pasien terdaftar.\n";
        return;
    }

    for (int i = 0; i < totalPasien; i++) {
        detailPendaftaran(daftarPasien[i]);
    }

}

void cariPasien (){
    string cariNama;
    cout << "==================================================" << endl;
    cout << "                   CARI PASIEN                    " << endl;
    cout << "==================================================" << endl;

    cin.ignore();
    cout << "Masukkan nama pasien: "; getline (cin, cariNama);

    bool adaketemu = false;
    for (int i = 0; i < totalPasien; i++) {
        if (daftarPasien[i].nama == cariNama) {
            detailPendaftaran(daftarPasien[i]);
            adaketemu = true;
            break;
        }
    }
    if (!adaketemu) cout << "Pasien tidak ditemukan.\n";


}

void pulangkanPasien (){
    cout << "==================================================" << endl;
    cout << "                 PULANGKAN PASIEN                 " << endl;
    cout << "==================================================" << endl;

        if (totalPasien == 0) {
        cout << "Tidak ada pasien terdaftar.\n";
        return;
    }

    cout << "Daftar Pasien:" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < totalPasien; i++) {
        cout << "  ID-" << daftarPasien[i].id
             << " | " << daftarPasien[i].nama << endl;
    }
    cout << "--------------------------------------------------" << endl;

    int idInput;
    cout << "Masukkan ID pasien yang ingin dipulangkan: ";
    cin >> idInput;

    int idx = -1;
    for (int i = 0; i < totalPasien; i++) {
        if (daftarPasien[i].id == idInput) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "[!] Pasien tidak ditemukan.\n";
        return;
    }

    PasienBaru p = daftarPasien[idx];

    int hariMasuk  = p.tglMasuk.tahun * 365 + p.tglMasuk.bulan * 30 + p.tglMasuk.tanggal;
    int hariKeluar = tanggalHariIni.tahun * 365 + tanggalHariIni.bulan * 30 + tanggalHariIni.tanggal;
    int lamaRawat  = hariKeluar - hariMasuk;
    if (lamaRawat < 1) lamaRawat = 1;

    bool bpjs = (p.pesertaBPJS == 'y' || p.pesertaBPJS == 'Y');
    int tagihan = bpjs ? 0 : lamaRawat * 75000;

    cout << "==================================================" << endl;
    cout << "              RINCIAN TAGIHAN                     " << endl;
    cout << "==================================================" << endl;
    cout << "Nama  : " << p.nama << endl;
    cout << "NIK   : " << p.nik << endl;
    cout << "BPJS  : " << (bpjs ? "Ya" : "Tidak") << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Tgl Masuk  : " << p.tglMasuk.tanggal << "/" << p.tglMasuk.bulan << "/" << p.tglMasuk.tahun << endl;
    cout << "Tgl Keluar : " << tanggalHariIni.tanggal << "/" << tanggalHariIni.bulan << "/" << tanggalHariIni.tahun << endl;
    cout << "Lama Rawat : " << lamaRawat << " hari" << endl;
    cout << "Tarif/Hari : Rp 75000" << endl;
    cout << "--------------------------------------------------" << endl;
    if (bpjs) {
        cout << "Total Tagihan : Rp 0 (Ditanggung BPJS)" << endl;
    } else {
        cout << "Total Tagihan : Rp " << tagihan << endl;
        cout << "\nPasien wajib melunasi tagihan sebelum dipulangkan." << endl;
    }
    cout << "==================================================" << endl;

    char konfirmasi;
    cout << "Yakin ingin memulangkan pasien ini? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        for (int i = idx; i < totalPasien - 1; i++) {
            daftarPasien[i] = daftarPasien[i + 1];
        }
        totalPasien--;
        cout << "[OK] Pasien ID-" << p.id << " berhasil dipulangkan.\n";
        cout << "Sisa pasien terdaftar: " << totalPasien << "\n";
    } else {
        cout << "Dibatalkan.\n";
    }
    
}

void bannerGazacare (){
    dataDummyDummy ();
    int pilihanPasien;
    do{
        cout << "==================================================" << endl;
        cout << "       SISTEM MANAJEMEN RS GAZACARE PLUS          " << endl;
        cout << "==================================================" << endl;
        cout << "                          Tanggal " 
            << tanggalHariIni.tanggal << "/"
            << tanggalHariIni.bulan << "/"
            << tanggalHariIni.tahun << endl;
        cout << "[1] Daftarkan Pasien Baru" << endl;
        cout << "[2] Lihat Semua Pasien" << endl;
        cout << "[3] Cari Pasien" << endl;
        cout << "[4] Pulangkan Pasien" << endl;
        cout << "[0] Keluar" << endl;
        cout << "==================================================" << endl;
        cout << "Pilihan: "; cin >> pilihanPasien;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka!\n";
            pilihanPasien = -1;
            system ("pause");
            system ("cls");
            continue;
        }  
        system ("pause");
        system ("cls");

        if (pilihanPasien == 1){
            pendaftaranPasienBaru();
            system ("pause");
            system ("cls");
        }else if (pilihanPasien == 2){
            lihatSemuaPasien ();
            system ("pause");
            system ("cls");
        }else if (pilihanPasien == 3){
            cariPasien ();
            system ("pause");
            system ("cls");
        } else if (pilihanPasien == 4){
            pulangkanPasien ();
            system ("pause");
            system ("cls");
        } else if (pilihanPasien == 0){
            cout << "Terimakasih! Sistem ditutup.";
            system ("pause");
            system ("cls");
        } else{
            cout << "[!] Pilihan tidak valid!";
            system ("pause");
            system ("cls");
        }
        
    }while(pilihanPasien !=0);
}

int main (){

bannerGazacare ();
    return 0;
}





//menyerah, kayaknya masih banyak yang salah bang :)
//masih saah di tarif nya :)
//(#lessAI, cuma di menu 4 kok...maaf bang)  
       
       