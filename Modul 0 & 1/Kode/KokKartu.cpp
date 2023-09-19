#include <iostream>
#include <deque> // library untuk menggunakan deque

using namespace std;

int main() {
    int n;
    while (true) { // lakukan looping
        cin >> n; // inputkan nilai n

        if (n == 0) { // jika n = 0, maka hentikan program
            break;
        } else if (n < 0) { // jika n < 0, keluarkan pesan dan hentikan program
            cout << "Mana ada kartu minus!\n";
            break;
        }

        deque<int> cards, discarded; // inisialisasi deque untuk kartu dan kartu yang dibuang

        // inisialisasi deque cards dengan nilai dari 1 hingga n
        for (int i = 1; i <= n; i++) {
            cards.push_back(i);
        }

        int i = 0; // inisialisasi int i dengan nilai 0

        // lakukan proses penghapusan kartu sampai hanya tersisa 1 kartu
        while (n > 1) {
            discarded.push_back(cards[i]); // tambahkan nilai kartu ke dalam deque discarded
            cards.erase(cards.begin() + i); // hapus nilai kartu pada i dari deque cards
            n--; // kurangi jumlah kartu
            i = (i+1) % n; // atur nilai i agar selalu berada pada indeks yang valid
        }

        // cetak urutan kartu yang dibuang
        cout << "Discarded cards: ";
        for (auto it = discarded.begin(); it != discarded.end(); it++) {
            if (it != discarded.begin()) {
                cout << ",";
            }
            cout << " " << *it;
        }

        // cetak kartu terakhir yang tersisa
        cout << "\nRemaining card: " << cards.front() << "\n";
    }

    return 0;
}
