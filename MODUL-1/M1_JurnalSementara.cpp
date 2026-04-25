#include <iostream>
using namespace std;

int main(){

 int beras, telur, minyakGoreng;
 
 cout << "==================================================" << endl;
 cout << "|             TOKO SEMBAKO JAYA ABADI            |" << endl;
 cout << "==================================================" << endl;

 cout << "[Bina]: Than, masukin harga barangnya Rendy di program ini!" << endl;

 cout << "Harga Beras (Rp)         : "; cin >> beras;
 cout << "Harga Telur (Rp)         : "; cin >> telur;
 cout << "Harga Minyak Goreng (Rp) : "; cin >> minyakGoreng;
 
 //Hitung Total Belanja
 int totalBelanja = (beras + telur + minyakGoreng );
 int ppnBelanja = (25/100 * totalBelanja);
 int totalSemua = totalBelanja + ppnBelanja;
 int uangRendy;

 cout << "Total Belanja (+ PPN 25%) : " << totalSemua << endl;

 cout << "[Fathan]:Ren, totalnya segitu. Uang lu berapa?" << endl;
 cout << "[Rendy]:Hmmmmmm, pajaknya gede juga ya." << endl;
 cout << "        Nih than, my uang gweh segini" << endl;

 cout << "Nominal Uang Rendy (Rp) : "; cin >> uangRendy;

 //Hitung Uang Kembalian
 int uangKembalian;

 cout << "==================================================" << endl;
 cout << "|                 STRUK KEMBALIAN                |" << endl;
 cout << "==================================================" << endl;

 cout << "[Bina]: Nih, than. Rincian kembaliannya: " << endl;
 cout << "Total Kembalian: Rp " << uangKembalian << endl;

 cout << "--------------------------------------------------" << endl;
 cout << "- Rp 100.000 : 0 lembar" << endl;
 cout << "- Rp 50.000  : 1 lembar" << endl;
 cout << "- Rp 20.000  : 1 lembar" << endl;
 cout << "- Rp 10.000  : 0 lembar" << endl;
 cout << "- Rp 5.000   : 1 lembar" << endl;
 cout << "- Rp 1.000   : 0 lembar" << endl;
 cout << "- Rp 1.000   : 0 lembar" << endl;
 cout << "- Rp 500     : 0 koin" << endl;
 cout << "- Rp 200     : 0 koin" << endl;
 cout << "- Rp 100     : 0 koin" << endl;
  cout << "--------------------------------------------------" << endl;
  cout << "[Fathan]: Aman! Sisa receh tak terpecahnya:  " << endl;
  cout << "          Ini mau di Donasikan ga Ren? " << endl;
  cout << "[Rendy] : GAS" << endl;
  cout << "==================================================" << endl;





    return 0;
}