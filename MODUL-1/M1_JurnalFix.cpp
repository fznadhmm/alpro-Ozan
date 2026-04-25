#include <iostream>
using namespace std;

int main(){

 int beras, telur, minyakGoreng; //Deklarasi beras, telut, minyak
 
 cout << "==================================================" << endl;
 cout << "|             TOKO SEMBAKO JAYA ABADI            |" << endl;
 cout << "==================================================" << endl << endl;

 cout << "[Bina]: Than, masukin harga barangnya Rendy di program ini!" << endl << endl;
 cout << "Harga Beras (Rp)         : "; cin >> beras;
 cout << "Harga Telur (Rp)         : "; cin >> telur;
 cout << "Harga Minyak Goreng (Rp) : "; cin >> minyakGoreng;
 
 //Hitung Total Belanja
 int totalBelanja = beras + telur + minyakGoreng; // Deklarasi Total dari beras, telur, minyak
     totalBelanja = totalBelanja + (totalBelanja * 25/100); //Deklarasi dan menghitung PPN
 int uangRendy; 

 cout << "Total Belanja (+ PPN 25%) : " << totalBelanja << endl << endl;
 cout << "[Fathan]: Ren, totalnya segitu. Uang lu berapa?" << endl;
 cout << "[Rendy] : Hmmmmmm, pajaknya gede juga ya." << endl;
 cout << "          Nih than, my uang gweh segini" << endl <<endl;
 cout << "Nominal Uang Rendy (Rp) : "; cin >> uangRendy;
 cout<< endl;

 //Hitung Uang Kembalian
 int uangKembalian = uangRendy - totalBelanja; //Deklarasi dan menghitung uang kembalian

 cout << "==================================================" << endl;
 cout << "|                 STRUK KEMBALIAN                |" << endl;
 cout << "==================================================" << endl;

 cout << "[Bina]: Nih, than. Rincian kembaliannya: " << endl;
 cout << "Total Kembalian: Rp " << uangKembalian << endl;

 cout << "--------------------------------------------------" << endl;
 int lembarKoin = uangKembalian/100000; //Deklarasi  dengan tipe data integer karena kita mencari hasil pembagian bulatnya untuk tau berapa banyaknya lembar atau koin
     uangKembalian = uangKembalian % 100000; //Mencari sisa bagi untuk tau berapa sisa uang yang belum terpecah dengan menggunakan modulo
 cout << "- Rp 100.000 : " << lembarKoin << " lembar" << endl;

 lembarKoin = uangKembalian/50000; //Karena sudah dideklarasikan di awal, maka di sini hingga seterusnya bisa langsung saja seperti di atas
 uangKembalian = uangKembalian % 50000;
 cout << "- Rp 50.000  : " << lembarKoin << " lembar" << endl;

 lembarKoin = uangKembalian/20000;
 uangKembalian = uangKembalian % 20000;
 cout << "- Rp 20.000  : " << lembarKoin << " lembar" << endl;

 lembarKoin = uangKembalian/10000;
 uangKembalian = uangKembalian % 10000;
 cout << "- Rp 10.000  : " << lembarKoin << " lembar" << endl;
 
 lembarKoin = uangKembalian/5000;
 uangKembalian = uangKembalian % 5000;
 cout << "- Rp 5.000   : " << lembarKoin << " lembar" << endl;

 lembarKoin = uangKembalian/1000;
 uangKembalian = uangKembalian % 1000;
 cout << "- Rp 1.000   : " << lembarKoin << " lembar" << endl;

 lembarKoin = uangKembalian/1000;
 uangKembalian = uangKembalian % 1000;
 cout << "- Rp 1.000   : " << lembarKoin << " koin" << endl;

 lembarKoin = uangKembalian/500;
 uangKembalian = uangKembalian % 500;
 cout << "- Rp 500     : " << lembarKoin << " koin" << endl;
 
 lembarKoin = uangKembalian/200;
 uangKembalian = uangKembalian % 200;
 cout << "- Rp 200     : " << lembarKoin << " koin" << endl;

 lembarKoin = uangKembalian/100;
 uangKembalian = uangKembalian % 100;
 cout << "- Rp 100     : " << lembarKoin << " koin" << endl;
 cout << "--------------------------------------------------" << endl;
 cout << "[Fathan]: Aman! Sisa receh tak terpecahnya: Rp " << uangKembalian << endl;
 cout << "          Ini mau di Donasikan ga Ren? " << endl;
 cout << "[Rendy] : GAS" << endl;
 cout << "==================================================" << endl;

    return 0;
}