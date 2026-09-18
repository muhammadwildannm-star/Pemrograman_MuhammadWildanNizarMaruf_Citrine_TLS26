#include <iostream>
#include <vector>
using namespace std;

// User-Defined Function
int eliminasiAstronot(vector<int>& astronot, int& posisi, int K) {
    
    // Menentukan posisi astronot yang dieliminasi
    posisi = (posisi + K - 1) % astronot.size();

    // Menyimpan nomor astronot
    int tereliminasi = astronot[posisi];

    // Menghapus astronot
    astronot.erase(astronot.begin() + posisi);

    // Mengubah posisi ke astronot berikutnya
    if (posisi >= astronot.size()) {
        posisi = 0;
    }

    return tereliminasi;
}

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;

    cout << "Masukkan nilai K awal: ";
    cin >> K;

    vector<int> astronot;

    // Membuat daftar astronot
    for (int i = 1; i <= N; i++) {
        astronot.push_back(i);
    }

    vector<int> urutanEliminasi;

    int posisi = 0;

    // Proses eliminasi
    while (astronot.size() > 1) {

        int tereliminasi = eliminasiAstronot(
            astronot, posisi, K
        );

        urutanEliminasi.push_back(tereliminasi);

        // Mengubah K berdasarkan nomor astronot
        if (tereliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        // K minimum adalah 2
        if (K < 2) {
            K = 2;
        }
    }

    // Output
    cout << "\nUrutan eliminasi: ";

    for (int x : urutanEliminasi) {
        cout << x << " ";
    }

    cout << "\nAstronot terakhir yang bertahan: "
         << astronot[0] << endl;

    return 0;
}