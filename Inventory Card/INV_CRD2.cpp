#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct Barang {
    string Nama_Barang;
    int Jumlah, Harga;
};

Barang barang[100]; 
int jumlah_barang = 0;

void Menu(){
    cout << "\n===== INVENTORY CARD =====" << endl;
    cout << "1. Tampilkan Daftar Barang " << endl;
    cout << "2. Tambah Barang " << endl;
    cout << "3. Simpan dan keluar" << endl;
    cout << "Masukkan pilihan dalam format angka : ";

}

void TampilkanFile(){
   ifstream BacaFile("inventory.txt");
    string line;

    cout << left << setw(20) << "Nama" << setw(10) << "Stok" << setw(10) << "Harga" << endl;
    while (getline(BacaFile, line)) {
        stringstream ss(line);
        Barang b;
        getline(ss, b.Nama_Barang, ','); // read until comma
        ss >> b.Jumlah >> b.Harga;
        cout << left << setw(20) << b.Nama_Barang << setw(10) << b.Jumlah << setw(10) << b.Harga << endl;
    }
    BacaFile.close();
}

void TampilkanBrg (){
    cout << "\nDaftar Barang:\n";
   
    if (jumlah_barang == 0) {
        cout << "Tidak ada barang yang terdaftar." << endl;
        return;
    }
    cout << left << setw(10) << "Kode" << setw(20) << "Nama" << setw(10) << "Stok" << setw(10) << "Harga" << endl;
    for (int i = 0; i < jumlah_barang; i++){
        cout << left << setw(20) << barang[i].Nama_Barang 
             << barang[i].Jumlah << setw(8) << "pcs"
             << "Rp. " << barang[i].Harga << endl;
    }
}

void TambahBrg (){ 
    int jumlah;

    cout << "Berapa jenis barang yang mau ditambahkan? ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++ ){
        cout << "\nMasukkan nama barang ke - " << i + 1 << " : ";
        cin >> barang[jumlah_barang].Nama_Barang;
        cout << "Masukkan jumlah barang ke - " << i + 1 << " : ";
        cin >> barang[jumlah_barang].Jumlah;
        cout << "Masukkan harga barang ke - " << i + 1 << " : ";
        cin >> barang[jumlah_barang].Harga;

        jumlah_barang++;
    }
}    

void simpan_file(){
     ofstream TulisFile("inventory.txt", ios::app);
    for (int i = 0; i < jumlah_barang; i++) {
        TulisFile << barang[i].Nama_Barang << "," << barang[i].Jumlah << " " << barang[i].Harga << endl;
    }
    TulisFile.close();
    cout << "Barang sudah tersimpan!" << endl;
}


void Baca_file(){
 ifstream BacaFile("inventory.txt");
    string line;

    cout << left << setw(20) << "Nama" << setw(10) << "Stok" << setw(10) << "Harga" << endl;
    while (getline(BacaFile, line)) {
        stringstream ss(line);
        Barang b;
        getline(ss, b.Nama_Barang, ','); // read until comma
        ss >> b.Jumlah >> b.Harga;
        cout << left << setw(20) << b.Nama_Barang << setw(10) << b.Jumlah << setw(10) << b.Harga << endl;
    }
    BacaFile.close();
}

int main (){
    int pilihan;
    
do {
        Menu();  
        cin >> pilihan;

        if (pilihan < 1 || pilihan > 3) {
            cout << "Pilihan Invalid, coba lagi!" << endl;
            continue;
        }
    
    switch (pilihan){
        case 1:
        if (jumlah_barang > 0) {
                    TampilkanBrg(); 
                } 
                else {
                    TampilkanFile(); 
                }
        break;

        case 2:
        TambahBrg();
        break;

        case 3:
        simpan_file();
        exit(0);

        }
    }
while (pilihan != 3);

return 0;
}