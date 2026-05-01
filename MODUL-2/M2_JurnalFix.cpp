#include <iostream>
using namespace std;

int main () {
    int umurUser;
    cout << "===== GOBLET OF FIRE: TURNAMEN TRIWIZARD =====" << endl;
    cout << "Masukkan umur anda: "; cin >> umurUser; 
    if (!(umurUser >=17)){
        cout << "Piala api menolak anda! Umur terlalu kecil" << endl;
        return 0;
    }
    while (true){
        cout << "Piala api menyala! Anda terpilih sebagai Triwizard Champions." << endl;
        system ("cls");

        //TUGAS 1
        bool tugasSelesai = false;
        while (!tugasSelesai){
            int perlindunganSihir = 3;
            char pilihanStrategi;
            cout << "--- TUGAS 1: NAGA HUNGARIAN HORNTAIL ---" << endl;

            while (perlindunganSihir > 0){
                cout << "Sisa perlindungan sihir : " << perlindunganSihir << " kali." << endl;
                cout << "Pilih strategi (a: Sembunyi, b: Panggil Sapu): "; cin >> pilihanStrategi;

                if (pilihanStrategi == 'a'){
                    cout << "Naga menyemburkan api! Anda terluka." << endl;
                    perlindunganSihir--;
                }else if (pilihanStrategi == 'b'){
                    cout << "Berhasil! Anda mengambil Telur Emas!" << endl;
                    tugasSelesai = true;
                    system ("pause");
                    system ("cls");
                    break;
                }else {
                    cout << "Pilihan tidak valid! Ulangi pilihan." << endl;
                    system ("pause");
                }
            }
                if (perlindunganSihir == 0){
                    cout << ">> KESEMPATAN HABIS! Anda ditarik keluar arena oleh pawang naga." << endl;
                    cout << ">> MENGULANG TUGAS 1 DARI AWAL..." << endl;
                    system("pause");
                    system("cls");
                }
        }
        
        //TUGAS 2
        bool tugas2Selesai = false;
        while (!tugas2Selesai) {
            int waktu = 10;
            char pilihanStrategi2;

            cout << "--- TUGAS 2: DANAU HITAM ---" << endl;

            while (waktu <= 60) {
                cout << "Menit " << waktu << "...Ada Grindylow! (l: Lawan, h: Hindari): ";
                cin >> pilihanStrategi2;

                if (pilihanStrategi2 == 'h'){
                    cout << "Lolos dari Gryndilow." << endl;
                    waktu +=10;
                    if (waktu > 60){
                        cout << "Tepat 60 menit! Anda menyelamatkan sandera." << endl;
                        tugas2Selesai = true;
                        system ("pause");
                        system ("cls");
                        break;
                    }
                }else if (pilihanStrategi2 == 'l'){
                    cout << "Oksigen Anda habis karena kelelahan bertarung!" << endl;
                    cout << ">> WAKTU/OKSIGEN HABIS! Putri duyung membawa Anda ke permukaan." << endl;
                    cout << ">> MENGULANG TUGAS 2 DARI AWAL..." << endl;
                    system ("pause");
                    system ("cls");
                    break;
                }else {
                    cout << "Pilihan tidak valid! Ulangi pilihan." << endl;
                    system ("pause");
                }
            }

        }

        //TUGAS 3
        bool tugas3Selesai = false;
        while (!tugas3Selesai){
            int toleransi = 2;
            int langkah = 0;
            int pilihArah;

            cout << "--- TUGAS 3: LABIRIN ---" << endl;

            while (toleransi > 0 && langkah < 3) {
                cout << "Sisa toleransi kesalahan: " << toleransi << endl;
                cout << "Langkah ditempuh: " << langkah << endl;
                cout << "Pilih arah (1: Kiri, 2: Kanan, 3: Lurus): ";
                cin >> pilihArah;

                if (pilihArah == 1){
                    toleransi--;
                    cout << "Terkena Akar Berbisa! Sisa toleransi kesalahan: " << toleransi << endl;
                }else if (pilihArah == 2){
                    langkah++;
                    cout << "Jalan aman, Anda semakin dalam." << endl;
                }else if (pilihArah == 3){
                    langkah = 3;
                    cout << "Anda melihat cahaya...Oh tunggu, apa itu..." << endl;
                }else {
                    cout <<"Anda tidak berada di jalur pilihan! Ulangi pilihan!" << endl;
                }
                system ("pause");
                system ("cls");
            }
            if (toleransi == 0){
                cout << ">> KESEMPATAN HABIS! Labirin berubah bentuk dan menendang Anda ke pintu masuk." << endl;
                cout << ">> MENGULANG TUGAS 3 DARI AWAL..." << endl;
                system ("pause");
                system ("cls");
            }else {
                tugas3Selesai = true;
            }
            //JALAN KELUAR
            int angka;
            cout << "--- JALAN KELUAR ---" << endl;
            cout << "Anda melihat sesuatu yang bersinar di tengah arena..." << endl;
            cout << "Terdapat sebuah cahaya terkurung di dalamnya, dan terdapat mesin yang meminta Anda untuk memasukkan sebuah angka..." << endl;
            cout << "Masukkan angka (minimal 5): "; cin >> angka;

            //buat diamond
            int n = angka;

            //atas
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n-i; j++) cout << " ";
                for (int j = 1; j <= 2*i-1; j++) cout << "*";
                cout << endl;
            }
            //bawah
            for (int i = n-1; i >= 1; i--){
                for (int j = 1; j <= n-i; j++) cout << " ";
                for (int j = 1; j <= 2*i-1; j++) cout << "*";
                cout << endl;

            }
        }
        cout << "*** SELAMAT! ANDA ADALAH PEMENANG TURNAMEN TRIWIZARD! ***" << endl;
        system ("pause");
        system ("cls");
        break;
    }
    return 0;
}