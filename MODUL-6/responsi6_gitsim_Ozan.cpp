#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#define RESET   "\033[0m"
#define HIJAU   "\033[1;32m"
#define KUNING  "\033[1;33m"
#define MERAH   "\033[1;31m"
#define CYAN    "\033[1;36m"
#define ABU     "\033[0;90m"
#define PUTIH   "\033[1;37m"

struct Commit {
    string id_hash;
    string pesan;
    string penulis;
    string waktu;
    Commit* commitSebelum;
};

struct Branch {
    string nama;
    Commit* commitTerbaru;
    int total_commit;
};

struct Repository{
    string nama;
    Branch* daftar_branch;
    int kapasitas_branch;
    int jumlah_branch;
    int indeks_Activebranch;
};

string nama_penulis;
Repository** daftar_repo = NULL;
int jumlah_repo = 0;
int indeks_Activerepo = 0;
Repository* active_repo = NULL;

int id_commit_global = 0;

void jedaLayar (){
    cout << ABU << "\nPress Enter..." << RESET;
    cin.ignore();
}

void bersihkanLayar (){
    cout << "\033[2J\033[H";
}

string ambilWaktuSekarang() {
    time_t sekarang = time(NULL);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", localtime(&sekarang));
    return string(buffer);
}

string buatHashPendek (int id_commit){
    const char karakter_hex[] = "0123456789abcdef";
    string hash_hasil = " ";
    unsigned int nilai = id_commit * 987654321u;

    for (int i = 0; i < 7; i++){
        int indeks = nilai % 16;
        hash_hasil = karakter_hex[indeks] + hash_hasil;
        nilai = nilai / 16;
    };
    return hash_hasil;
}

void initialize_mainbranch (Repository* repo){
    repo -> kapasitas_branch = 4;
    repo -> jumlah_branch = 1;
    repo -> indeks_Activebranch = 0;

    repo ->daftar_branch = new Branch[repo->kapasitas_branch];
    repo ->daftar_branch[0].nama = "main"; 
    repo ->daftar_branch[0].commitTerbaru = NULL;
    repo ->daftar_branch[0].total_commit = 0;
}

void bersihkanSemuaMemori() {
    for (int r = 0; r < jumlah_repo; r++) {
        Repository* repo = daftar_repo[r];
        for (int b = 0; b < repo->jumlah_branch; b++) {
            Commit* komit_hapus = repo->daftar_branch[b].commitTerbaru;
            while (komit_hapus != NULL) {
                Commit* sementara = komit_hapus->commitSebelum;
                delete komit_hapus;
                komit_hapus = sementara;
            }
        }
        delete[] repo->daftar_branch;
        delete repo;
    }
    delete[] daftar_repo;
}









int main(int argc, char **argv){

 return 0;   
}