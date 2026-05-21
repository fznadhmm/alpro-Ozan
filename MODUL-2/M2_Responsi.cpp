#include <iostream>
using namespace std;

int main () {
int pesananGwe;
    cout << "=== TOKO AYAM GEPREK ==="<< endl;
    cout << "Mas geprek: Mau pesen apa mas? coba sebutin." << endl;
    cout << "1. Ayam Geprek Original - Rp10.000" << endl;
    cout << "2. Ayam Geprek Jumbo     - Rp15.000" << endl;
    cout << "3. Ayam Geprek Super Jumbo - Rp18.000" << endl;
    cout << "4. Ayam Geprek Super Duper Jumbo - Rp20.000" << endl;
    cout << "Pilih menu (1-4) (pilih 1 ajah, biar ga boncos): "; cin >> pesananGwe;
    
    switch (pesananGwe){
        case 1:
        cout << "Gwe: Ayam Geprek Ori nya satu yeah mazzeh."<< endl;
        cout << "Mas geprek: Yoai, siap abangkuh." << endl;
        break;

        case 2:
        cout << "Gwe: Ayam Geprek Jumbo nya satu yeah mazzeh."<< endl;
        cout << "Mas geprek: Yoai, aman banget aman banget."<< endl;
        break;

        case 3:
        cout << "Gwe: Ayam Geprek Super Jumbo nya satu browdi."<< endl;
        cout << "Mas geprek: Yoai, ashiapp." << endl;
        break;

        case 4:
        cout << "Gwe: Ayam Geprek Super Duper Jumbo nya satu yeah mazzeh." << endl;
        cout << "Mas geprek: Yoai!!! kaya bingitzz nieh, awal bulan ya???."<< endl;
        break;
    }
    cout << "Mas geprek: Tunggu bentar ya Azril";

    return 0;
}
    


