#include <iostream>
using namespace std;

int main(){
    int key;
    char teks [100];
    cout << "[TASK 1/3] DECODE SIGNAL - Communication Room" << endl;
    cout << ">> Kirim sinyal terenkripsi dan deskripsi balasan dari Bumi!." << endl;
    cout << " [ENKRIPSI]" << endl;

    do{
        cout << "Masukkan key: "; cin >> key;
        if (cin.fail()){
            cin.clear();
            }

        if (key <= 0){
            cout << "[!] Key harus bilangan bulat positif. Coba lagi" << endl;
        }
    }while (key <= 0);
        do{
            cin.ignore (1000, '\n');
            cout << "Masukkan teks: " << endl;
            cin.getline (teks, 100);

            if (teks [0] == '\n'){
                cout << "[!] Input tidak boleh kosong. Coba lagi" << endl;
            }
        }while(teks [0] == '\n');

        
        


    
    
    






    return 0;
}