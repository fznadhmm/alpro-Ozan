#include <iostream>
using namespace std;

struct Tanggal{
    int tanggal;
    int bulan;
    int tahun;
};

void tampilTanggal (Tanggal t){
    cout << "Tanggal " << t.tanggal << "/" << t.bulan << "/" << t.tahun;
}

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
    int nik;
    string nama;
    TglLahir tgl;
    char jenisKelamin;
    char goldar;
    int noTelp;
    Alamat almt;
    char pesertaBPJS;
    int jmlAlergi;
    Alergi alrg;
};

void pendaftaranPasien(PasienBaru p){
    cout << "==================================================" << endl;
    cout << "               PENDAFTARAN PASIEN BARU            " << endl;
    cout << "==================================================" << endl;
    cout << "NIK (16 Digit) : " << p.nik << endl;
    cout << "Nama           : " << p.nama << endl;
    cout << "Tgl Lahir " << endl;
    cout << "   Tanggal : " << p.tgl.tanggal_lahir << endl;
    cout << "   Bulan   : " << p.tgl.bulan << endl;
    cout << "   Tahun   : " << p.tgl.tahun << endl;
}

void bannerGazacare (){
    int pilihanPasien;
    do{
    cout << "==================================================" << endl;
    cout << "       SISTEM MANAJEMEN RS GAZACARE PLUS          " << endl;
    cout << "==================================================" << endl;
    cout << "                          Tanggal " 
         << 
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
    }
    if (pilihanPasien == 1){
    }
    else if (pilihanPasien == 2){

    }
    else if (pilihanPasien == 3){

    }
    else if (pilihanPasien == 4){

    }
    else{

    }
    }while(pilihanPasien !=0);
    
}










int main(){
    bannerGazacare();

    return 0;
}