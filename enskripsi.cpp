#include <iostream>
#include <string>
using namespace std;

// User-Defined Function
char enkripsiHuruf(char hurufSekarang, char hurufSebelumnya) {

    // Mengubah huruf menjadi nilai alfabet
    // A = 1, B = 2, ..., Z = 26
    int nilaiSekarang = hurufSekarang - 'A' + 1;

    int nilaiSebelumnya = 0;

    // Jika bukan huruf pertama
    if (hurufSebelumnya != '\0') {
        nilaiSebelumnya = hurufSebelumnya - 'A' + 1;
    }

    // Menjumlahkan kedua nilai
    int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

    // Jika lebih dari 26, kembali ke awal alfabet
    if (nilaiBaru > 26) {
        nilaiBaru = nilaiBaru - 26;
    }

    // Mengubah nilai kembali menjadi huruf
    return 'A' + nilaiBaru - 1;
}

int main() {
    string pesan;
    string hasil = "";

    cout << "Masukkan pesan: ";
    cin >> pesan;

    // Proses enkripsi
    for (int i = 0; i < pesan.length(); i++) {

        char hurufSebelumnya;

        if (i == 0) {
            hurufSebelumnya = '\0';
        } else {
            hurufSebelumnya = pesan[i - 1];
        }

        char hurufBaru = enkripsiHuruf(
            pesan[i],
            hurufSebelumnya
        );

        hasil += hurufBaru;
    }

    cout << "Pesan terenkripsi: "
         << hasil << endl;

    return 0;
}