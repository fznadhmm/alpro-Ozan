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
            Commit* commit_hapus = repo->daftar_branch[b].commitTerbaru;
            while (commit_hapus != NULL) {
                Commit* sementara = commit_hapus->commitSebelum;
                delete commit_hapus;
                commit_hapus = sementara;
            }
        }
        delete[] repo->daftar_branch;
        delete repo;
    }
    delete[] daftar_repo;
}
//end of commit or push pertama

//start
void gitCommit(){
    bersihkanLayar();
    Branch* branch_aktif = &active_repo->daftar_branch[active_repo->indeks_Activebranch];

    cout << CYAN << "GITSIM - Git Simulator\n" << ABU << "Author: " << nama_penulis << RESET << "\n";
    cout << "--------------------------------------------------------\n";
    cout << "git commit [" << HIJAU << branch_aktif->nama << RESET << "]\n";
    cout << "--------------------------------------------------------\n";
    
    cout << CYAN << "Message : " << RESET;
    string pesan_commit;
    getline (cin, pesan_commit);

    char konfirmasi;
    while (true){
        cout << CYAN << "\nPush commit? (y/n): " << RESET;
        cin >> konfirmasi;
        cin.ignore(1000, '\n');

        if (konfirmasi == 'y' || konfirmasi == 'Y'){
            id_commit_global++;

            Commit* commit_baru = new Commit ();
            commit_baru->id_hash = buatHashPendek(id_commit_global);
            commit_baru->pesan = pesan_commit;
            commit_baru->penulis = nama_penulis;
            commit_baru->pesan = ambilWaktuSekarang();

            commit_baru->commitSebelum = branch_aktif->commitTerbaru;
            branch_aktif->commitTerbaru = commit_baru;
            branch_aktif->total_commit++;

            cout << "\n[" << HIJAU << branch_aktif->nama << " " << commit_baru->id_hash << RESET << "] " << pesan_commit << "\n";
            cout << "--------------------------------------------------------\n";
            cout << branch_aktif->nama << " -> origin/" << branch_aktif->nama << "\n";
            cout << "$ git push origin " << HIJAU << branch_aktif->nama << RESET << "\n";
            break;
        }else if (konfirmasi == 'n' || konfirmasi == 'N'){
            cout << MERAH << "Commit dibatalkan.\n" << RESET;
            break;
        }else{
            cout << MERAH << "[!] Input tidak valid.\n" << RESET;
        }
            
    }
    jedaLayar();
}

void gitLog(){
    bersihkanLayar();
    Branch* branch_aktif = &active_repo->daftar_branch[active_repo->indeks_Activebranch];
    cout << CYAN << "GITSIM - Git Simulator\n" << ABU << "Author: " << nama_penulis << RESET << "\n";
    cout << "--------------------------------------------------------\n";
    cout << "git log [" << HIJAU << branch_aktif->nama << RESET << "]\n";
    cout << "--------------------------------------------------------\n";
    
    if (branch_aktif->commitTerbaru == NULL) {
        cout << ABU << "(No commits on this branch)\n" << RESET;
    } else {
        Commit* saat_ini = branch_aktif->commitTerbaru;
        while (saat_ini != NULL) {
            cout << KUNING << "commit " << saat_ini->id_hash << RESET << "\n";
            cout << ABU << "Author : " << PUTIH << saat_ini->penulis << "\n";
            cout << ABU << "Date   : " << PUTIH << saat_ini->waktu << "\n";
            cout << "         " << saat_ini->pesan << "\n\n";
            
            saat_ini = saat_ini->commitSebelum; 
        }
    }
    jedaLayar();
}

void gitBranch(){
    bersihkanLayar();
    cout << CYAN << "GITSIM - Git Simulator\n" << ABU << "Author: " << nama_penulis << RESET << "\n";
    cout << "--------------------------------------------------------\n";
    cout << "git branch\n";
    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < active_repo->jumlah_branch; i++){
        if (i == active_repo->indeks_Activebranch){
            cout << HIJAU << "* " << active_repo->daftar_branch[i].nama;
            cout << ABU << " (" << active_repo->daftar_branch[i].total_commit << " commits)" << RESET << "\n";
        }
        else {
            cout << "  " << active_repo->daftar_branch[i].nama; 
            cout << ABU << " (" << active_repo->daftar_branch[i].total_commit << " commits)" << RESET << "\n";
        }
    }
     cout << "\n" << CYAN << "New branch name: " << RESET;
    string nama_baru;
    getline(cin, nama_baru);

    if (nama_baru == " "){
        cout << MERAH << "\n[ERROR] Branch name cannot be empty!\n" << RESET;
        jedaLayar();
        return;
    }

    for (int i = 0; i < active_repo->jumlah_branch; i++){
        if (active_repo->daftar_branch[i].nama == nama_baru){
            cout << MERAH << "\n[ERROR] Branch '" << nama_baru << "' already exists!\n" << RESET;
            jedaLayar();
            return;
        }
    }

    if (active_repo->jumlah_branch >= active_repo->kapasitas_branch){
        active_repo->kapasitas_branch *= 2;
        Branch* array_baru = new Branch[active_repo->kapasitas_branch];
        
        for (int i = 0; i < active_repo->jumlah_branch; i++) {
            array_baru[i] = active_repo->daftar_branch[i];
        }
        
        delete[] active_repo->daftar_branch;
        active_repo->daftar_branch = array_baru;
    }

    Branch& branch_baru = active_repo->daftar_branch[active_repo->jumlah_branch];
    branch_baru.nama = nama_baru;
    
    Branch& branch_aktif = active_repo->daftar_branch[active_repo->indeks_Activebranch];
    branch_baru.commitTerbaru = branch_aktif.commitTerbaru;
    branch_baru.total_commit = branch_aktif.total_commit;
    
    active_repo->jumlah_branch++;

    cout << HIJAU << "\n[OK] " << RESET << "Branch '" << nama_baru << "' created from '" << branch_aktif.nama << "'\n";
    cout << ABU << branch_baru.total_commit << " commit(s) inherited\n" << RESET;
    jedaLayar();
}

void gitCheckOut(){

}

void newRepository(){

}

void switchRepository(){
    
}









int main(int argc, char **argv){
    if (argc < 2){
        cout << MERAH << "Error: Requires an Operator name (username)." << RESET << "\n";
        cout << "Usage: ./gitsim <username>\n";
        return 1;
    }
    nama_penulis = argv[1];
    bersihkanLayar();

 return 0;   
}