#include <iostream>
#include <climits>

using namespace std;

struct NeuralCore {
    size_t kapasitas = 128;
    unsigned char* buffer = new unsigned char[kapasitas]; 
    size_t cursor = 0; 

    NeuralCore() {
        delete[] buffer;
    }
};
struct NeuralEntry {
    char type;         
    size_t offset;    
    size_t size;     
    int int_data;
    bool terhapus = false; 
};
NeuralCore neural;
const size_t MAX_ENTRY = 256; 
NeuralEntry* entry[MAX_ENTRY]; 
size_t jumlah = 0;
int xelisa_cycle = 0;
char operator_id[4] = {0}; 

int get_stability() {
    return static_cast<int>(100 - (100 * neural.cursor / neural.kapasitas));
}

void banner() {
    cout << "\n===========================================\n";
    cout << "CYRON TERMINAL: DIVINE SUPPRESSION\n";
    cout << "===========================================\n";
    
    switch (xelisa_cycle % 4) {
        case 0: cout << "Xelisa: \"Sinkronisasi selesai. Menunggu perintah, Operator.\"\n";
        break;

        case 1: cout << "Xelisa: \"Aliran data memori terpantau stabil. Lanjutkan enkripsi.\"\n";
        break;

        case 2: cout << "Xelisa: \"Hati-hati, fragmen memori yang kosong bisa memicu anomali.\"\n";
        break;

        case 3: cout << "Xelisa: \"Batas willpower subjek hampir mencapai ambang kritis.\"\n";
        break;
    }
    xelisa_cycle++; 

    cout << "-------------------------------------------\n";
    cout << "1. Lihat Neural Map (Status)\n";
    cout << "2. Suntik Neural Thread (Tambah)\n";
    cout << "3. Bersihkan Link Rusak (Hapus)\n";
    cout << "4. Perluas Kapasitas Memori (Resize)\n";
    cout << "0. Putuskan Koneksi (Keluar)\n";
    cout << "-------------------------------------------\n";
    cout << "Pilih operasi terminal: ";
}

void view_map() {
    system("cls"); 
    int stabilitas = get_stability(); 

    cout << "=========================================================================\n";
    cout << "NEURAL MAP: HISTORIA KOURA [STABILITY: " << stabilitas << "%]\n";
    cout << "=========================================================================\n";
    
    if (jumlah == 0) {
        cout << " (Buffer kosong. Xelisa sedang mengumpulkan kekuatan...)\n";
    }
    for (size_t i = 0; i < jumlah; i++) {
        if (entry[i]->terhapus) continue; 
        
        void* address = (void*)(neural.buffer + entry[i]->offset);
        
        cout << "[" << i << "]"
             << " TIPE: " << (entry[i]->type == '0' ? "Willpower Pulse" : "Thunder Discharge")
             << " | OFFSET: " << entry[i]->offset 
             << " | ALAMAT: " << address
             //<< " | SIZE: " << entry[i]->size << " bytes"
             << " | DATA: ";
             
        if (entry[i]->type == '1') {
            cout << entry[i]->int_data << "\n";
        } 
        else if (entry[i]->type == '0') {
            cout << "\"";
            for(size_t j = 0; j < entry[i]->size - 1; j++) {
                cout << (char)neural.buffer[entry[i]->offset + j];
            }
            cout << "\"\n";
        }
    }
    cout << "=========================================================================\n";
    cout << "Kursor : " << neural.cursor << " / " << neural.kapasitas << " Byte terpakai." << "\n";
}
void add() {
    if (jumlah >= MAX_ENTRY) {
        cout << "!! ERROR OPTIMALISASI !! Burnout neural terdeteksi!.\n";
        return;
    }
    int tipe;
    cout << "Pilih tipe injeksi: 0 = Willpower (Teks), 1 = Thunder (Energi): ";
    cin >> tipe;
    
    if (cin.fail() || (tipe != 0 && tipe != 1)) {
        cout << "[!] INPUT TIDAK VALID.\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n'); 
        return;
    }
    cin.ignore(INT_MAX, '\n'); 
    
    if (tipe == 0) {
        char temp_teks[256];
        cout << "Masukkan Input Willpower: "; 
        
        char c;
        size_t panjang = 0;
        while (cin.get(c) && c != '\n' && panjang < 255) {
            temp_teks[panjang++] = c;
        }
        temp_teks[panjang] = '\0';
        panjang++; 

        if (neural.cursor + panjang > neural.kapasitas) {
            cout << "!! ERROR OPTIMALISASI !! Ego vessel menolak thread!\n";
            return;
        }
        entry[jumlah] = new NeuralEntry;
        entry[jumlah]->type = '0';
        entry[jumlah]->offset = neural.cursor;
        entry[jumlah]->size = panjang;
        entry[jumlah]->terhapus = false;
        
        for (size_t i = 0; i < panjang; i++) {
            neural.buffer[neural.cursor + i] = static_cast<unsigned char>(temp_teks[i]);
        }
        neural.cursor += panjang;
        jumlah++;
        cout << "Perintah CyroN: \"Resistansi subjek terdeteksi. Mengesampingkan umpan balik.\"\n";
    } 
    else if (tipe == 1) {
        int thunder;
        cout << "Masukkan Tingkat Energi Thunder (int): "; 
        cin >> thunder;

        if (cin.fail()) {
            cout << "[!] INPUT TIDAK VALID.\n";
            cin.clear(); 
            cin.ignore(INT_MAX, '\n'); 
            return;
        }
        cin.ignore(INT_MAX, '\n'); 

        if (neural.cursor + sizeof(int) > neural.kapasitas) {
            cout << "!! ERROR OPTIMALISASI !! Burnout neural terdeteksi!\n";
            return;
        }
        entry[jumlah] = new NeuralEntry;
        entry[jumlah]->type = '1';
        entry[jumlah]->offset = neural.cursor;
        entry[jumlah]->size = sizeof(int);
        entry[jumlah]->int_data = thunder;
        entry[jumlah]->terhapus = false;

        unsigned char* ptr_byte = (unsigned char*)&thunder;
        for (size_t i = 0; i < sizeof(int); i++) {
            neural.buffer[neural.cursor + i] = ptr_byte[i];
        }
        neural.cursor += sizeof(int);
        jumlah++;
        cout << "Daiki: \"(Keheningan. Angin telah dijinakkan.)\"\n";
    }
}
void hapus() {
    if (jumlah == 0) {
        cout << "[!] Tidak ada Link yang aktif untuk dihapus.\n";
        return;
    }
    int target;
    cout << "Masukkan Index Link untuk dihapus: ";
    cin >> target;

    if (cin.fail() || target < 0 || static_cast<size_t>(target) >= jumlah) {
        cout << "Indeks link tidak valid atau sudah dihapus sebelumnya.\n";
        cin.clear(); cin.ignore(INT_MAX, '\n');
        return;
    }
    cin.ignore(INT_MAX, '\n'); 

    if (entry[target]->terhapus) {
        cout << "Fragmentasi terdeteksi. Memori belum dapat dikembalikan saat ini!\n";
        return;
    }
    entry[target]->terhapus = true;

    if (entry[target]->offset + entry[target]->size == neural.cursor) {
        neural.cursor -= entry[target]->size; 
        
        int cek_idx = target - 1;
        while (cek_idx >= 0) {
            if (entry[cek_idx]->terhapus && 
               (entry[cek_idx]->offset + entry[cek_idx]->size == neural.cursor)) {
                neural.cursor -= entry[cek_idx]->size;
            }
            cek_idx--;
        }
        cout << "Neural Core berhasil mengembalikan ruang memori. Ujung (Tail) saat ini di: " << neural.cursor << "\n";
    } else {
        cout << "Neural Core berhasil mengembalikan ruang memori. Ujung (Tail) saat ini di: " << neural.cursor << "\n";
    }
}

void resize() {
    int baru_input;
    cout << "Masukkan batas buffer baru: "; 
    cin >> baru_input;
    
    if (cin.fail() || baru_input <= 0) {
        cout << "[!] INPUT TIDAK VALID.\n";
        cin.clear(); cin.ignore(INT_MAX, '\n'); 
        return;
    }
    cin.ignore(INT_MAX, '\n'); 
    
    size_t baru = static_cast<size_t>(baru_input);

    if (baru > neural.kapasitas) {
        unsigned char* buffer_baru = new unsigned char[baru];
        
        for (size_t i = 0; i < neural.cursor; i++) {
            buffer_baru[i] = neural.buffer[i];
        }
        delete[] neural.buffer; 
        neural.buffer = buffer_baru;
        neural.kapasitas = baru;
        
        cout << "Perintah CyroN: \"Stabilitas meningkat. Vessel sekarang 100% patuh.\"\n";
    } else {
        cout << "Ekspansi harus lebih besar dari batas saat ini!\n";
    }
}
int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Neural Link membutuhkan ID Operator (NIM).\n";
        return 0;
    }
    else if (argc > 2) {
        cout << "Terlalu banyak parameter. Koneksi tidak stabil.\n";
        return 0;
    }

    int len = 0;
    while (argv[1][len] != '\0') {
        len++;
    }

    if (len < 11) {
        cout << "NIM harus tepat 11 karakter.\n";
        return 0;
    } else if (len > 11) {
        cout << "NIM harus tepat 11 karakter.\n"; 
        return 0;
    }

    char target_prefix[5] = {'F', '1', 'D', '0', '2'};
    bool prefix_valid = true;
    for (int i = 0; i < 5; i++) {
        if (argv[1][i] != target_prefix[i]) {
            prefix_valid = false;
            break;
        }
    }

    if (!prefix_valid) {
        cout << "NIM harus diawali dengan 'F1D02'.";
        return 0;
    }

    operator_id[0] = argv[1][8];
    operator_id[1] = argv[1][9];
    operator_id[2] = argv[1][10];
    operator_id[3] = '\0';

    cout << "Access Granted. Operator ID: " << argv[1] << "\n";
    system("pause"); 
    system("cls");   

    while (true) {
        banner();
        
        char input_menu[256];
        cin.getline(input_menu, 256); 
        
        if (input_menu[0] == '\0' || input_menu[1] != '\0' || input_menu[0] < '0' || input_menu[0] > '4') {
            system("pause");
            system("cls");
            continue;
        }

        int pilihan = input_menu[0] - '0'; 

        if (pilihan == 0) {
            cout << "Realitas mulai tidak stabil...\n";
            break; 
        }
        else if (pilihan == 1) { 
            view_map(); 
            system("pause");
            system("cls");
        } 
        else if (pilihan == 2) { 
            add(); 
            system("pause");
            system("cls");
        }
        else if (pilihan == 3) { 
            hapus(); 
            system("pause");
            system("cls");
        }
        else if (pilihan == 4) { 
            resize(); 
            system("pause");
            system("cls");
        } 
    }
    for(size_t i = 0; i < jumlah; i++) {
        delete entry[i];
    }
    cout << "Koneksi terputus. Selamat tinggal, Operator " << operator_id << ".\n";
    return 0;
}