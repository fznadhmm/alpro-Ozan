#include <iostream>
using namespace std;

int main() {
    int umurUser;

    cout << "===== GOBLET OF FIRE: TURNAMEN TRIWIZARD =====" << endl;
    cout << "Masukkan umur anda: "; cin >> umurUser; 

    if (umurUser >=17){
         cout << "Piala api menyala! Anda terpilih sebagai Triwizard Champions." << endl;
    } else {
        cout << "Piala api menolak anda! Umur terlalu kecil" << endl;
    }
    
    
    int perlindunganSihir = 3;
    char pilihanStrategi;
    cout << "--- TUGAS 1: NAGA HUNGARIAN HORNTAIL ---" << endl;
    cout << "Sisa perlindungan sihir : " << perlindunganSihir << " kali.";
    cout << "Pilih strategi (a: Sembunyi, b: Panggil Sapu): "; cin >> pilihanStrategi;

    switch (pilihanStrategi){
        case ('a'):
            cout << "Naga menyemburkan api! Anda terluka." << endl;
            cout << "Sisa perlindungan sihir: " << perlindunganSihir << " kali.";
            perlindunganSihir--;
            break;
        case ('b'):
            cout << "Berhasil! Anda mengambil Telur Emas!" << endl;
            break;
        deafult:
            cout << "Pilihan tidak valid! Ulangi pilihan." << endl;
    }
    if (perlindunganSihir == 0){
        cout << ">> KESEMPATAN HABIS! Anda ditarik keluar arena oleh pawang naga." << endl;
        cout << ">> MENGULANG TUGAS 1 DARI AWAL....";
        system ("pause");
        system ("cls");
    }

    int pilihanStrategi2;
    int menit;
    cout << "--- TUGAS 2: DANAU HITAM ---" << endl;
    
    

// MAAF BANG SAYA SKILL ISSUE WKWKWKWKWK
























    return 0;
}