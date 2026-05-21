#include <iostream>
using namespace std;

int main(){
    char teks [MAX];

    cout << "Masukkan kalimat: ";
    cin.getline (teks, MAX);

    int panjang = 0

while (teks[panjang] != '\0') {
        panjang++;
    }
    cout << "Panjang kalimat: " << panjang << endl;
    
    return 0;
}