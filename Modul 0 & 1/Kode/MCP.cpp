#include <iostream>
#include <queue>

#define wibu pair<pair<int, int>, string> //definisi alias untuk tipe data pair


using namespace std;

int main() {
    //deklarasi priority queue dengan nama "miko" menggunakan tipe data "wibu" dan diurutkan dari nilai terkecil ke terbesar
    priority_queue<wibu, vector<wibu>, greater <wibu>> miko;
    int x, y;
    cin >> x >> y; //menginputkan nilai x dan y

    // perulangan untuk memasukkan data ke priority queue "miko"
    for (int i = 0; i < x; i++) {
        string name;
        int date, month;
        cin >> name >> date >> month; //menginputkan nama, tanggal, dan bulan
            miko.push({{month, date}, name}); //memasukkan data ke priority queue "miko"
    }
    // perulangan untuk mengeluarkan data dari priority queue "miko" sebanyak y kali
    for (int i = 0; i < y; i++) {
        miko.pop(); //mengeluarkan data teratas dari priority queue "miko"
        if (miko.empty()) { //jika priority queue "miko" kosong, maka program berhenti
            cout << "Miko TOP G" << endl;
            return 0;
        }
    }
    //mendapatkan data nama waifu yang tersisa di priority queue "miko"
    string name = miko.top().second;
    //mencetak output hasil pemrosesan data dari priority queue "miko"
    cout << "Waifu selanjutnya adalah " << name << " chan" << endl;

    return 0;
}

/*
5 3
Hikarunara 04 12
Ayumi 01 11
Sonoko 08 12
Miku 31 12
Robbin 30 12
*/
