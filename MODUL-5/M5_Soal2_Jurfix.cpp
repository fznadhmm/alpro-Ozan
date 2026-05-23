#include <iostream>
#include <cstdlib>
using namespace std;

void banner()
{
  cout << "+=======================================================================+" << endl;
  cout << "|                                                                       |" << endl;
  cout << "|      _    _                         _   ____            _             |" << endl;
  cout << "|     / \\  | |__  _   _ ___ ___  __ _| | |  _ \\ ___  __ _| |_ __ ___    |" << endl;
  cout << "|    / _ \\ | '_ \\| | | / __/ __|/ _` | | | |_) / _ \\/ _` | | '_ ` _ \\   |" << endl;
  cout << "|   / ___ \\| |_) | |_| \\__ \\__ \\ (_| | | |  _ <  __/ (_| | | | | | | |  |" << endl;
  cout << "|  /_/   \\_\\_.__/ \\__, |___/___/\\__,_|_| |_| \\_\\___|\\__,_|_|_| |_| |_|  |" << endl;
  cout << "|                 |___/                                                 |" << endl;
  cout << "|                                                                       |" << endl;
  cout << "+=======================================================================+" << endl;
};

struct Musuh {
    string nama;
    int hp, maxHp;
    int atk, agi;
    int expDrop;
    bool isBoss;
};

struct Stage {
    string nama;
    Musuh musuh[4];
    bool bossKalah;
};

struct Player {
    string nama;
    int level;
    int hp, maxHp;
    int mp, maxMp;
    int atk, def, agi;
    int exp, maxExp;
    int atkAwal, defAwal, agiAwal;
    int maxHpAwal, maxMpAwal;
};

Stage stages[7];
Player pemain;

void inisialisasiPlayer() {
    pemain.level = 1;
    pemain.maxHp = 1500; pemain.hp  = 1500;
    pemain.maxMp    = 100; pemain.mp  = 100;
    pemain.atk      = 150;
    pemain.def     = 50;
    pemain.agi      = 15;
    pemain.exp      = 0;
    pemain.maxExp   = 150;
    pemain.atkAwal   = 150;
    pemain.defAwal   = 50;
    pemain.agiAwal   = 15;
    pemain.maxHpAwal = 1500;
    pemain.maxMpAwal = 100;
}

void inisialisasiStage() {
    //Pride
    stages[0].nama = "Pride";
    stages[0].bossKalah = false;
    stages[0].musuh[0].nama = "Arrogant Soldier";
    stages[0].musuh[0].hp = 80;   stages[0].musuh[0].maxHp = 80;
    stages[0].musuh[0].atk = 40;  stages[0].musuh[0].agi = 8;
    stages[0].musuh[0].expDrop = 10; stages[0].musuh[0].isBoss = false;

    stages[0].musuh[1].nama = "Noble Knight";
    stages[0].musuh[1].hp = 120;  stages[0].musuh[1].maxHp = 120;
    stages[0].musuh[1].atk = 55;  stages[0].musuh[1].agi = 10;
    stages[0].musuh[1].expDrop = 20; stages[0].musuh[1].isBoss = false;

    stages[0].musuh[2].nama = "Fallen Champion";
    stages[0].musuh[2].hp = 150;  stages[0].musuh[2].maxHp = 150;
    stages[0].musuh[2].atk = 65;  stages[0].musuh[2].agi = 12;
    stages[0].musuh[2].expDrop = 30; stages[0].musuh[2].isBoss = false;


    stages[0].musuh[3].nama = "King of Pride (Boss)";
    stages[0].musuh[3].hp = 400;  stages[0].musuh[3].maxHp = 400;
    stages[0].musuh[3].atk = 90;  stages[0].musuh[3].agi = 15;
    stages[0].musuh[3].expDrop = 80; stages[0].musuh[3].isBoss = true;

    //Greed
    stages[1].nama = "Greed";
    stages[1].bossKalah = false;
    stages[1].musuh[0].nama = "Gold Hoarder";
    stages[1].musuh[0].hp = 180;  stages[1].musuh[0].maxHp = 180;
    stages[1].musuh[0].atk = 50;  stages[1].musuh[0].agi = 13;
    stages[1].musuh[0].expDrop = 35; stages[1].musuh[0].isBoss = false;

    stages[1].musuh[1].nama = "Corrupt Merchant";
    stages[1].musuh[1].hp = 220;  stages[1].musuh[1].maxHp = 220;
    stages[1].musuh[1].atk = 65;  stages[1].musuh[1].agi = 15;
    stages[1].musuh[1].expDrop = 45; stages[1].musuh[1].isBoss = false;

    stages[1].musuh[2].nama = "Living Treasure";
    stages[1].musuh[2].hp = 280;  stages[1].musuh[2].maxHp = 280;
    stages[1].musuh[2].atk = 75;  stages[1].musuh[2].agi = 17;
    stages[1].musuh[2].expDrop = 55; stages[1].musuh[2].isBoss = false;

    stages[1].musuh[3].nama = "Dragon of Greed (Boss)";
    stages[1].musuh[3].hp = 600;  stages[1].musuh[3].maxHp = 600;
    stages[1].musuh[3].atk = 120; stages[1].musuh[3].agi = 20;
    stages[1].musuh[3].expDrop = 120; stages[1].musuh[3].isBoss = true;

    //Wrath
    stages[2].nama = "Wrath";
    stages[2].bossKalah = false;
    stages[2].musuh[0].nama = "Furious Beast";
    stages[2].musuh[0].hp = 250;  stages[2].musuh[0].maxHp = 250;
    stages[2].musuh[0].atk = 80;  stages[2].musuh[0].agi = 18;
    stages[2].musuh[0].expDrop = 50; stages[2].musuh[0].isBoss = false;

    stages[2].musuh[1].nama = "Berserker";
    stages[2].musuh[1].hp = 300;  stages[2].musuh[1].maxHp = 300;
    stages[2].musuh[1].atk = 100; stages[2].musuh[1].agi = 20;
    stages[2].musuh[1].expDrop = 60; stages[2].musuh[1].isBoss = false;

    stages[2].musuh[2].nama = "Flame Demon";
    stages[2].musuh[2].hp = 350;  stages[2].musuh[2].maxHp = 350;
    stages[2].musuh[2].atk = 115; stages[2].musuh[2].agi = 22;
    stages[2].musuh[2].expDrop = 70; stages[2].musuh[2].isBoss = false;

    stages[2].musuh[3].nama = "Avatar of Wrath (Boss)";
    stages[2].musuh[3].hp = 800;  stages[2].musuh[3].maxHp = 800;
    stages[2].musuh[3].atk = 160; stages[2].musuh[3].agi = 28;
    stages[2].musuh[3].expDrop = 160; stages[2].musuh[3].isBoss = true;

    //Sloth
    stages[3].nama = "Sloth";
    stages[3].bossKalah = false;
    stages[3].musuh[0].nama = "Lazy Undead";
    stages[3].musuh[0].hp = 300;  stages[3].musuh[0].maxHp = 300;
    stages[3].musuh[0].atk = 70;  stages[3].musuh[0].agi = 10;
    stages[3].musuh[0].expDrop = 60; stages[3].musuh[0].isBoss = false;

    stages[3].musuh[1].nama = "Sleeping Giant";
    stages[3].musuh[1].hp = 400;  stages[3].musuh[1].maxHp = 400;
    stages[3].musuh[1].atk = 90;  stages[3].musuh[1].agi = 12;
    stages[3].musuh[1].expDrop = 70; stages[3].musuh[1].isBoss = false;

    stages[3].musuh[2].nama = "Dream Spirit";
    stages[3].musuh[2].hp = 350;  stages[3].musuh[2].maxHp = 350;
    stages[3].musuh[2].atk = 110; stages[3].musuh[2].agi = 15;
    stages[3].musuh[2].expDrop = 75; stages[3].musuh[2].isBoss = false;

    stages[3].musuh[3].nama = "Lord of Sloth (Boss)";
    stages[3].musuh[3].hp = 900;  stages[3].musuh[3].maxHp = 900;
    stages[3].musuh[3].atk = 140; stages[3].musuh[3].agi = 18;
    stages[3].musuh[3].expDrop = 180; stages[3].musuh[3].isBoss = true;

    //Gluttony
    stages[4].nama = "Gluttony";
    stages[4].bossKalah = false;
    stages[4].musuh[0].nama = "Hungry Slime";
    stages[4].musuh[0].hp = 350;  stages[4].musuh[0].maxHp = 350;
    stages[4].musuh[0].atk = 90;  stages[4].musuh[0].agi = 15;
    stages[4].musuh[0].expDrop = 70; stages[4].musuh[0].isBoss = false;

    stages[4].musuh[1].nama = "Devourer Beast";
    stages[4].musuh[1].hp = 450;  stages[4].musuh[1].maxHp = 450;
    stages[4].musuh[1].atk = 115; stages[4].musuh[1].agi = 18;
    stages[4].musuh[1].expDrop = 85; stages[4].musuh[1].isBoss = false;

    stages[4].musuh[2].nama = "Endless Maw";
    stages[4].musuh[2].hp = 500;  stages[4].musuh[2].maxHp = 500;
    stages[4].musuh[2].atk = 130; stages[4].musuh[2].agi = 20;
    stages[4].musuh[2].expDrop = 95; stages[4].musuh[2].isBoss = false;

    stages[4].musuh[3].nama = "Lord of Gluttony (Boss)";
    stages[4].musuh[3].hp = 1000; stages[4].musuh[3].maxHp = 1000;
    stages[4].musuh[3].atk = 200; stages[4].musuh[3].agi = 28;
    stages[4].musuh[3].expDrop = 200; stages[4].musuh[3].isBoss = true;

    //Envy
    stages[5].nama = "Envy";
    stages[5].bossKalah = false;
    stages[5].musuh[0].nama = "Shadow Copy";
    stages[5].musuh[0].hp = 400;  stages[5].musuh[0].maxHp = 400;
    stages[5].musuh[0].atk = 100; stages[5].musuh[0].agi = 20;
    stages[5].musuh[0].expDrop = 80; stages[5].musuh[0].isBoss = false;

    stages[5].musuh[1].nama = "Mirror Spirit";
    stages[5].musuh[1].hp = 480;  stages[5].musuh[1].maxHp = 480;
    stages[5].musuh[1].atk = 120; stages[5].musuh[1].agi = 23;
    stages[5].musuh[1].expDrop = 95; stages[5].musuh[1].isBoss = false;

    stages[5].musuh[2].nama = "Shapeshifter";
    stages[5].musuh[2].hp = 550;  stages[5].musuh[2].maxHp = 550;
    stages[5].musuh[2].atk = 140; stages[5].musuh[2].agi = 26;
    stages[5].musuh[2].expDrop = 110; stages[5].musuh[2].isBoss = false;

    stages[5].musuh[3].nama = "Embodiment of Envy (Boss)";
    stages[5].musuh[3].hp = 1300; stages[5].musuh[3].maxHp = 1300;
    stages[5].musuh[3].atk = 250; stages[5].musuh[3].agi = 35;
    stages[5].musuh[3].expDrop = 220; stages[5].musuh[3].isBoss = true;

    //Lust
    stages[6].nama = "Lust";
    stages[6].bossKalah = false;
    stages[6].musuh[0].nama = "Charming Spirit";
    stages[6].musuh[0].hp = 500;  stages[6].musuh[0].maxHp = 500;
    stages[6].musuh[0].atk = 120; stages[6].musuh[0].agi = 25;
    stages[6].musuh[0].expDrop = 100; stages[6].musuh[0].isBoss = false;

    stages[6].musuh[1].nama = "Siren";
    stages[6].musuh[1].hp = 600;  stages[6].musuh[1].maxHp = 600;
    stages[6].musuh[1].atk = 150; stages[6].musuh[1].agi = 30;
    stages[6].musuh[1].expDrop = 120; stages[6].musuh[1].isBoss = false;

    stages[6].musuh[2].nama = "Succubus";
    stages[6].musuh[2].hp = 700;  stages[6].musuh[2].maxHp = 700;
    stages[6].musuh[2].atk = 170; stages[6].musuh[2].agi = 32;
    stages[6].musuh[2].expDrop = 140; stages[6].musuh[2].isBoss = false;

    stages[6].musuh[3].nama = "Queen of Lust (Boss)";
    stages[6].musuh[3].hp = 1500; stages[6].musuh[3].maxHp = 1500;
    stages[6].musuh[3].atk = 300; stages[6].musuh[3].agi = 40;
    stages[6].musuh[3].expDrop = 260; stages[6].musuh[3].isBoss = true;
}

bool cekDodge(int agi) {

    int peluang = agi * 100 / (agi + 50);

    return (rand() % 100) < peluang;
}

void cekLevelUp() {
    while (pemain.exp >= pemain.maxExp) {
        pemain.exp -= pemain.maxExp;
       pemain.level ++;
        int bonusAtk = pemain.atkAwal   * 0.3;
        int bonusDef = pemain.defAwal   * 0.3;
        int bonusAgi = pemain.agiAwal   * 0.3;
        int bonusHp  = pemain.maxHpAwal * 0.5;
        int bonusMp  = pemain.maxMpAwal * 0.5;

        pemain.atk   += bonusAtk;
        pemain.def   += bonusDef;
        pemain.agi   += bonusAgi;
        pemain.maxHp += bonusHp;
        pemain.maxMp += bonusMp;
        pemain.hp     = pemain.maxHp;
        pemain.mp     = pemain.maxMp;
        pemain.maxExp += 50;

        cout << "+----------------------------------------------------------------+" << endl;
        cout << "|                    *** LEVEL UP! ***                          |" << endl;
        cout << "| You reached Level " << pemain.level << endl;
        cout << "| ATK +" << bonusAtk
             << "  DEF +" << bonusDef
             << "  AGI +" << bonusAgi
             << "  MaxHP +" << bonusHp
             << "  MaxMP +" << bonusMp
             << "  (HP/MP restored)" << endl;
        cout << "+----------------------------------------------------------------+" << endl;
    }
}
void pertarungan(Musuh& m) {
    cout << "+----------------------------------------------------------------+" << endl;
    cout << "| [" << m.nama << "]: Welcome, adventurer. Show me what you are made of!" << endl;
    cout << "+----------------------------------------------------------------+" << endl;
    cout << "Press ENTER to continue...";
    cin.ignore(); cin.get();

    int turn = 1;
    while (pemain.hp > 0 && m.hp > 0) {
        system("cls");
        cout << "================================================================" << endl;
        cout << "| ABYSSAL REALM                                   TURN " << turn << "      |" << endl;
        cout << "================================================================" << endl;
        cout << "| [" << pemain.nama << "]" << "                              Level " << pemain.level << endl;
        cout << "|   HP  : " << pemain.hp  << " / " << pemain.maxHp << endl;
        cout << "|   MP  : " << pemain.mp  << " / " << pemain.maxMp << endl;
        cout << "|   AGI : " << pemain.agi << endl;
        cout << "|   EXP : " << pemain.exp << " / " << pemain.maxExp << endl;
        cout << "+----------------------------------------------------------------" << endl;
        cout << "| [" << m.nama << "]" << endl;
        cout << "|   HP  : " << m.hp << " / " << m.maxHp << endl;
        cout << "|   AGI : " << m.agi << endl;
        cout << "================================================================" << endl;
        cout << "| 1. Basic Attack   (No MP  | 100% ATK)" << endl;
        cout << "| 2. Heavy Attack   (30 MP  | 160% ATK | lower accuracy)" << endl;
        cout << "| 3. Heal           (20 MP  | Restore 200 HP)" << endl;
        cout << "| 4. Run Away       (Exit game)" << endl;
        cout << "================================================================" << endl;
        cout << "[Choose action]: ";

        int aksi;
        cin >> aksi;
        cout << endl;

        if (aksi == 1) {
            if (cekDodge(m.agi)) {
                cout << "[" << m.nama << "] dodged the attack!" << endl;
            } else {
                int dmg = pemain.atk;
                m.hp -= dmg;
                if (m.hp < 0) m.hp = 0;
                cout << "[Basic Attack] " << pemain.nama << " hits " << m.nama << " for " << dmg << " damage!" << endl;
            }
        } else if (aksi == 2) {
            if (pemain.mp < 30) {
                cout << "Not enough MP for Heavy Attack. Turn wasted." << endl;
            } else {
                pemain.mp -= 30;
                bool kena = (rand() % 100) < 70;
                if (!kena || cekDodge(m.agi)) {
                    cout << "[Heavy Attack] " << pemain.nama << " missed!" << endl;
                } else {
                    int dmg = pemain.atk * 1.6;
                    m.hp -= dmg;
                    if (m.hp < 0) m.hp = 0;
                    cout << "[Heavy Attack] " << pemain.nama << " lands a crushing blow on " << m.nama << " for " << dmg << " damage!" << endl;
                }
            }
        } else if (aksi == 3) {
            if (pemain.mp < 20) {
                cout << "Not enough MP for Heal. Turn wasted." << endl;
            } else {
                pemain.mp -= 20;
                pemain.hp += 200;
                if (pemain.hp > pemain.maxHp) pemain.hp = pemain.maxExp;
                cout << "[Heal] " << pemain.nama << " restored 200 HP. HP: " << pemain.hp << "/" << pemain.maxHp << endl;
            }
        } else if (aksi == 4) {
            cout << pemain.nama << " runs away from the battle..." << endl;
            cout << "Game over." << endl;
            cout << "Press ENTER to continue...";
            cin.ignore(); cin.get();
            exit(0);
        } else {
            cout << "[!] Invalid action. Turn wasted." << endl;
        }

        if (m.hp <= 0) {
            cout << endl;
            cout << "+----------------------------------------------------------------+" << endl;
            cout << "| " << m.nama << " has been defeated!" << endl;
            cout << "| EXP gained: " << m.expDrop << endl;
            cout << "+----------------------------------------------------------------+" << endl;
            pemain.exp += m.expDrop;
            cekLevelUp();
            cout << "Press ENTER to continue...";
            cin.ignore(); cin.get();
            break;
        }

        cout << endl;
        if (cekDodge(pemain.agi)) {
            cout << "[" << m.nama << "] attacked, but " << pemain.nama << " dodges!" << endl;
        } else {
            int dmgMusuh = m.atk - pemain.def / 2;
            if (dmgMusuh < 1) dmgMusuh = 1;
            pemain.hp -= dmgMusuh;
            if (pemain.hp < 0) pemain.hp = 0;
            cout << "[" << m.nama << "] attacks " << pemain.nama << " for " << dmgMusuh << " damage." << endl;
        }

        if (pemain.hp <= 0) {
            cout << endl;
            cout << "================================================================" << endl;
            cout << pemain.nama << " has been defeated..." << endl;
            cout << "GAME OVER" << endl;
            cout << "================================================================" << endl;
            cout << "Press ENTER to continue...";
            cin.ignore(); cin.get();
            exit(0);
        }

        cout << "Press ENTER to continue...";
        cin.ignore(); cin.get();
        turn++;
    }
}
void jalankanStage(int idxStage) {
    Stage& s = stages[idxStage];

    system("cls");
    cout << "================================================================" << endl;
    
    // Gunakan switch untuk membedakan dialog berdasarkan index stage
    switch(idxStage) {
        case 0: // Pride
            cout << "| [???]   : Fufufu, human. Are you strong enough to fight me?  |" << endl;
            cout << "| [???]   : I am Pride, and you dare to challenge me?          |" << endl;
            cout << "| [Pride] : But first, prove your worth.                       |" << endl;
            break;
        case 1: // Greed
            cout << "| [???]   : Ohoho, another mortal blinded by the glint of gold?|" << endl;
            cout << "| [???]   : I am Greed, and your treasures belong to me!       |" << endl;
            cout << "| [Greed] : But first, show me if your life is worth taking.   |" << endl;
            break;
        case 2: // Wrath
            cout << "| [???]   : GRAAAHH! Your presence angers me, puny human!      |" << endl;
            cout << "| [???]   : I am Wrath, and I will burn you to ashes!          |" << endl;
            cout << "| [Wrath] : But first, survive my raging vanguard!             |" << endl;
            break;
        case 3: // Sloth
            cout << "| [???]   : *Yawn*... Why do you disturb my eternal slumber?   |" << endl;
            cout << "| [???]   : I am Sloth... fighting you sounds so exhausting... |" << endl;
            cout << "| [Sloth] : Let my servants deal with you first... zzz...      |" << endl;
            break;
        case 4: // Gluttony
            cout << "| [???]   : *Drools*... You look incredibly delicious, human...|" << endl;
            cout << "| [???]   : I am Gluttony, and I shall devour your soul!       |" << endl;
            cout << "| [Gluttony]: But first, let my pets take a bite out of you.   |" << endl;
            break;
        case 5: // Envy
            cout << "| [???]   : Such courage... Such strength... I WANT IT ALL!    |" << endl;
            cout << "| [???]   : I am Envy, and I will steal everything you have!   |" << endl;
            cout << "| [Envy]  : But first, let's see if you can defeat your own shadows.|" << endl;
            break;
        case 6: // Lust
            cout << "| [???]   : Ah~ Such a handsome adventurer... Why fight?       |" << endl;
            cout << "| [???]   : I am Lust, surrender yourself to eternal pleasure..|" << endl;
            cout << "| [Lust]  : But first, let my charming guards test your willpower.|" << endl;
            break;
    }
    
    cout << "================================================================" << endl;
    cout << "Press ENTER to continue...";
    cin.ignore(); cin.get();

    int pilih;
    do {
        system("cls");
        cout << "================================================================" << endl;
        cout << "| Stage: " << s.nama << endl;
        cout << "================================================================" << endl;
        for (int i = 0; i < 4; i++) {
            string status = "";
            if (s.musuh[i].hp <= 0) status = " [DEFEATED]";
            cout << "| " << i+1 << ". " << s.musuh[i].nama << status << endl;
        }
        cout << "| 5. Retreat" << endl;
        cout << "================================================================" << endl;
        cout << "[Which path will you take?]: ";
        cin >> pilih;

        if (pilih == 5) {
            cout << pemain.nama << " retreats from " << s.nama << "..." << endl;
            cout << "Press ENTER to continue...";
            cin.ignore(); cin.get();
            return;
        }

        if (pilih < 1 || pilih > 4) {
            cout << "[!] Invalid choice.\n";
            cout << "Press ENTER to continue...";
            cin.ignore(); cin.get();
            continue;
        }

        Musuh& m = s.musuh[pilih - 1];

        if (m.hp <= 0) {
            cout << "[!] " << m.nama << " sudah dikalahkan!\n";
            cout << "Press ENTER to continue...";
            cin.ignore(); cin.get();
            continue;
        }

        pertarungan(m);

        if (s.musuh[3].hp <= 0) {
            s.bossKalah = true;
        }

        bool semua = true;
        for (int i = 0; i < 4; i++) {
            if (s.musuh[i].hp > 0) { semua = false; break; }
        }
        if (semua) {
            system("cls");
            cout << "================================================================" << endl;
            cout << "| All enemies in " << s.nama << " have been defeated!" << endl;
            cout << "================================================================" << endl;
            cout << "Press ENTER to continue...";
            cin.ignore(); cin.get();
            return;
        }

    } while (pilih != 5);
}
bool cekSemuaBossKalah() {
    for (int i = 0; i < 7; i++) {
        if (!stages[i].bossKalah) return false;
    }
    return true;
}

void tampilKemenangan() {
    system("cls");
    cout << "================================================================" << endl;
    cout << "|     *** CONGRATULATIONS, CHAMPION OF THE ABYSS! ***         |" << endl;
    cout << "|                                                              |" << endl;
    cout << "|       You have defeated all Seven Deadly Sins!              |" << endl;
    cout << "|                                                              |" << endl;
    cout << "|   Pride      - DEFEATED                                     |" << endl;
    cout << "|   Greed      - DEFEATED                                     |" << endl;
    cout << "|   Wrath      - DEFEATED                                     |" << endl;
    cout << "|   Sloth      - DEFEATED                                     |" << endl;
    cout << "|   Gluttony   - DEFEATED                                     |" << endl;
    cout << "|   Envy       - DEFEATED                                     |" << endl;
    cout << "|   Lust       - DEFEATED                                     |" << endl;
    cout << "|                                                              |" << endl;
    cout << "|   The Abyssal Realm trembles before your name, " << pemain.nama << "!" << endl;
    cout << "|        You are the true master of the Abyss!                |" << endl;
    cout << "================================================================" << endl;
    cout << "Press ENTER to continue...";
    cin.ignore(); cin.get();
}

void menuUtama() {
    int pilihan;
    do {
        system("cls");
        cout << "================================================================" << endl;
        cout << "|         THE 7 DEADLY SINS ARE WAITING FOR YOU               |" << endl;
        cout << "================================================================" << endl;
        for (int i = 0; i < 7; i++) {
            string status = stages[i].bossKalah ? " [BOSS DEFEATED]" : "";
            cout << "|   " << i+1 << ". " << stages[i].nama << status << endl;
        }
        cout << "|   8. EXIT" << endl;
        cout << "================================================================" << endl;
        cout << "|   The deeper you go, the stronger they are                  |" << endl;
        cout << "================================================================" << endl;
        cout << "[Choose your desired stage]: ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[!] Input harus angka!\n";
            system("pause");
            continue;
        }

        if (pilihan >= 1 && pilihan <= 7) {
            jalankanStage(pilihan - 1);
            if (cekSemuaBossKalah()) {
                tampilKemenangan();
                break;
            }
        } else if (pilihan == 8) {
            cout << "Leaving Abyssal Realm..." << endl;
            system("pause");
        } else {
            cout << "[!] Pilihan tidak valid!\n";
            system("pause");
        }

    } while (pilihan != 8);
}


int main (){
  banner();
  cout << "+=======================================================================+" << endl;
  cout << "|                  Welcome to Abyssal Realm, adventurer.                |" << endl;
  cout << "|               The seven deadly sins await your challenge.             |" << endl;
  cout << "+=======================================================================+" << endl;
  cout << "[Enter your name]: ";
  string nama;
  //cin.ignore();
  getline(cin, nama);
  pemain.nama = nama;

  inisialisasiPlayer();
  inisialisasiStage();

  cout << "Press ENTER to continue...";
  cin.get();

  menuUtama();
  return 0;
}

//jujur nyerah....
//gakuat....