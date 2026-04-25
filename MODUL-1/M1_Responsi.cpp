#include <iostream>
using namespace std;

int main(){
    int nim;
    int uts, uas, tugas;
    uts = uts * 30/100;
    uas = uas * 40/100;
    tugas = tugas * 30/100;

     cout << "|=========== SISTEM NILAI AKADEMIK =========|" << endl;
     cout << "Masukkan NIM : "; cin >> nim;
     cout << "Nilai UTS    : " ; cin >> uts;
     cout << "Nilai UAS    : " ; cin >> uas; 
     cout << "Nilai Tugas  : "; cin >> tugas; 
     cout << "---------------------------------------------" << endl;
     
    float nilai_akhir = ((float)uts + (float)uas + (float)tugas)/3;
    int nilai_bulatbawah = (int) nilai_akhir;
    int nilai_bulatatas = ((float) nilai_akhir + (int)nilai_akhir/100);

    cout.precision(2);
    cout << fixed;
    cout << "Nilai Akhir : " << nilai_akhir << endl;
    cout << "Nilai Bulat Bawah : " << nilai_bulatbawah << endl;
    cout << "Nilai Bulat Atas : " << nilai_bulatatas << endl;
    cout << "---------------------------------------------" << endl;

    int sks_tempuh;
    int sisa_sks = sks_tempuh/144 ;
    sisa_sks = sisa_sks%144;
    
    cout << "SKS Ditempuh  : "; cin >> sks_tempuh;
    cout << "Sisa SKS      : " << sisa_sks << endl;
    cout << "Semester Penuh: ";

 



    




     































    return 0;
}