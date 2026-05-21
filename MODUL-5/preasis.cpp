#include <iostream>
using namespace std;
#define BLUE "\033[31m"
#define PURPLE "\033[32m"
#define RESET "\033[0m"

const int MAX = 100;
//Deklarasi
struct Mahasiswa {
    string nama;
    string nim;
    int umur;
    char kelas;
    string asal;

    Mahasiswa(string nama, string nim, int umur, char kelas, string asal, string hee){
        this->nama = nama;
        this->kelas = kelas;
        this->asal = asal;
        this->nim = nim;
        this->umur = umur;
        this->sayHello(hee);
    }

    void sayHello(string hee){
        cout << "Hello there! "<< hee << endl;
    }
};

struct Mahesa {
    string nama;
    int kelompok;

    struct Praktikan {
        string nama;
    };
};

struct Prodi {
    string nama_prodi;
    int jumlah_stakeholder;
    char akreditasi;
    Mahasiswa mahasiswa;
};

struct Fakultas {
    Prodi prodi;
    char akreditas;
    int jumlah_stakeholder;
    string nama_fakultas;
};

void tampilkanMahasiswa(Mahasiswa mhs){
    cout << BLUE << mhs.nama << RESET << endl;
    cout << PURPLE << mhs.kelas << RESET << endl;
    cout << "\033[30m" << mhs.asal << "\033[0m" << endl;
    cout << mhs.nim << endl;
    cout << mhs.umur << endl;
}



int main(){
    //Deklarasi variable struct
    string nama = "Mahesa2";
    Mahasiswa mahesa(nama, "52", 19, 'A', "Mars", "Helloooo");
    // Mahasiswa kanaya;
    // Mahasiswa saufan;
    //Cara 3:
    //Mahasiswa ara = {"Samara Wardasadiya", "F1D02410023", 19, 'A', "Kekalik"};

    // int umur1 = 10;
    // int umur2;
    // umur2 = 20;



    // //Cara 1:
    // // mahesa = {
    // //     "I Kadek Mahesa Permana Putra",
    // //     "F1D02410052",
    // //     19,
    // //     'A',
    // //     "Bali"
    // // };

    // //Cara 2:
    // //kanaya = {"Kanaya Salsabila Humaira", "F1D02410061", 25, 'A', "Belakang RSUP"};

    // //Cara 4:
    // //saufan.nama = "Saufan Ridho";
    // //saufan.asal = "Sayang Sayang";
    // saufan.kelas = 'A';
    // saufan.nim = "F1D02310091";
    // saufan.umur = 30;

    // cout << mahesa.umur;

    // //Array of Struct (Array dari struct)
    // // Mahasiswa mhs[30];
    // // Fakultas fkl;

    // // for(int i = 0; i < 30; i++){
    // //     cout << mhs[i].nama;
    // // }
    // //Struct of Array (Struct isinya Array)

    // // Fakultas fakultas;
    // // Prodi prodi;
    // // Mahasiswa mahasiswa;

    // // string asal2 = mahasiswa.asal;
    // // Prodi prodi2 = prodi;

    // //Cara 1:
    // // mahasiswa.nama = "Intan";

    // // //Cara 2:
    // // prodi.mahasiswa.nama = "Samara";

    // //Cara 3:
    // //fakultas.prodi.mahasiswa.nama = "Satria";

    // string fpnm = fakultas.prodi.mahasiswa.nama;

    // Mahasiswa shortcut = fakultas.prodi.mahasiswa;
    // Prodi shortcut2 = fakultas.prodi;

    // shortcut2.mahasiswa.nama;
    // shortcut2.nama_prodi = "Informatika";

    // shortcut.nama;
    // shortcut.asal;
    // shortcut.nim;
    // shortcut.kelas;
    // shortcut.umur;

    // //cout << fpnm;
    // //cout << fakultas.prodi.mahasiswa.nama;

    tampilkanMahasiswa(mahesa);
    //shortcut.sayHello();

    return 0;
}