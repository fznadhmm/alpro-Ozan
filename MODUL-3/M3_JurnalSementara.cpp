#include <iostream>
using namespace std;

int main(){
    int key;
    char teks [100];
    cout << "[TASK 1/3] DECODE SIGNAL - Communication Room" << endl;
    cout << ">> Kirim sinyal terenkripsi dan deskripsi balasan dari Bumi!." << endl << endl;
    cout << "[ENKRIPSI]" << endl;

    do{
        if (cin.fail()){
        cin.clear();
        }
        cout << "Masukkan key: "; cin >> key;
        if (key <= 0){
            cout << "[!] Key harus bilangan bulat positif. Coba lagi" << endl;
        }
    }while (key <= 0);
        do{
            cin.ignore (1000, '\n');
            cout << "Masukkan teks: ";
            cin.getline (teks, 100);
            cout << endl;

            if (teks [0] == '\0'){
                cout << "[!] Input tidak boleh kosong. Coba lagi" << endl;
            }
        }while(teks [0] == '\0');

    //Matriks enkripsi
    int panjang = 0;
    int baris = (panjang + key - 1) / key; //buat itung jumlah barisnya
    char matriks [50][50];

    while (teks [panjang] != '\0'){
        panjang++;
    }
    for (int i = 0 ; i < baris ; i++){
        for (int j = 0 ; j < key ; j++){
             if (i * key + j < panjang){
            matriks [i][j] = teks [i + key + j];
            }
            else {
                matriks [i][j] = '_';
            }
        }
    }
    cout << "[MATRIKS ENKRIPSI]" << endl;
    for (int i = 0 ; i < baris ; i++){
        for (int j = 0 ; j < key ; j++){
            cout << matriks [i][j] << " ";
        }
        cout << endl;
    }

        
        


    
    
    






    return 0;
}