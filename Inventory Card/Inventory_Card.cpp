#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Barang {
    string kode;
    string nama;
    int jumlah;
    double harga;
};

Barang Gudang[100];
int JumlahBrg = 0;

void Menu(){
    cout << "\n===== INVENTORY CARD =====" << endl;
    cout << "1. Tampilkan Daftar Barang " << endl;
    cout << "2. Tambah Barang " << endl;
    cout << "3. Hapus Barang " << endl;
    cout << "4. Simpan dan keluar" << endl;
    cout << "Masukkan pilihan dalam format angka : ";
}

void TampilkanFile (){
    ifstream BacaFile("inventory.txt");
    if (!BacaFile){
        cout << "File tidak ditemukan!" << endl;
        return;
    }

    JumlahBrg = 0;
    string line;
    while (getline(BacaFile, line)) {
        if (line == "----------------------") {
            break;
        }

        stringstream ss(line);
        Barang barangBaru;
            getline(ss, barangBaru.kode, ',');
            getline(ss, barangBaru.nama, ',');
                
            string jumlah;
            getline(ss, jumlah, ',');
            barangBaru.jumlah = stoi(jumlah); 

            string harga;
            getline(ss, harga, ',');
            barangBaru.harga = stod(harga);

        Gudang[JumlahBrg++] = barangBaru;
    }
    BacaFile.close();
}

void TampilkanData(){
    if (JumlahBrg == 0){
        cout << "\nGudang Kosong." << endl;
        return;
    }

    cout << "\nDaftar Barang di Gudang : " << endl;
    cout << left << setw(10) << "Kode"
         << setw(20) << "Nama"
         << setw(10) << "Jumlah"
         << setw(10) << "Harga" << endl;
    cout << string(50,'-') << endl;

    for(int i = 0; i < JumlahBrg; i++){
        cout << left << setw(10) << Gudang[i].kode
             << setw(20) << Gudang[i].nama
             << setw(10) << Gudang[i].jumlah 
             << setw(10) << Gudang[i].harga
             << endl;
    }
}

void TambahBrg(){
Barang BarangBaru;
int JumlahBrgBaru;

cout << "Berapa jenis barang yang ingin ditambahkan : ";
cin >> JumlahBrgBaru;

cin.ignore();

for (int i = 0; i < JumlahBrgBaru; i++){ 
    cout << "\nMasukkan kode barang ke - " << i+1 << ": ";
    getline(cin, BarangBaru.kode);
    
    cout << "Masukkan nama barang ke - " << i+1 << ": ";
    getline(cin, BarangBaru.nama);

    cout << "Masukkan jumlah barang ke - " << i+1 << ": ";
    cin >> BarangBaru.jumlah;

    cin.ignore();

    cout << "Masukkan harga barang ke - " << i+1 << ": ";
    cin >> BarangBaru.harga;

    cin.ignore();

    Gudang[JumlahBrg++] = BarangBaru;
    cout << "Barang Berhasil ditambahkan!" << endl;

    }
   TampilkanData();
}

void HapusBrg(){
string Kode;
    cout << "\nMasukkan kode barang yang ingin dihapus : ";
    cin >> Kode;

    cin.ignore();

    bool ditemukan = false;
    for(int i = 0; i < JumlahBrg; i++){
        if (Gudang[i].kode == Kode){
            for (int j = i; j < JumlahBrg - 1; j++){
                Gudang[j] = Gudang[j + 1];
            }
            JumlahBrg--;
            cout << "Barang dengan Kode - " << Kode << " Berhasil dihapus." << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Barang dengan kode " << Kode << "tidak ditemukan." << endl;
    }
}

void SimpanData(){
    ofstream TulisFile("inventory.txt", ios::trunc);

    for (int i = 0; i < JumlahBrg; i++){
        TulisFile << left << setw(10) << Gudang[i].kode << " , "
             << setw(20) << Gudang[i].nama << " , "
             << setw(10) << Gudang[i].jumlah << " , "
             << setw(10) << Gudang[i].harga << " , "
             << endl;
    }
    TulisFile << "----------------------" << endl;

    TulisFile.close();
    cout << "Data Tersimpan! Terimakasih Sudah menggunakan.";
}

int main(){
TampilkanFile();
    int pilihan;

    do{
        Menu();
        cin >> pilihan;
        switch (pilihan){
            case 1:
            TampilkanData();
            break;

            case 2:
            TambahBrg();
            break;

            case 3:
            HapusBrg();
            break;

            case 4:
            SimpanData();
            exit (0);
            break;

            default:
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    } while (pilihan!= 4);
    return 0;
}