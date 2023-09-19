#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3; //Menginput jumlah kitab di tiga tumpukan

    stack<int> a1, a2, a3; //Membuat tiga stack untuk tiga tumpukan

    int q1=0, q2=0, q3=0; //Inisialisasi variabel untuk total ketinggian tiap tumpukan
    int n1, n2, n3, i;

    // Membaca tinggi masing-masing kitab dalam tumpukan dari atas ke bawah dan menyimpannya ke dalam stack
    for(i=0; i<t1; i++){
        cin >> n1;
        q1 += n1;
        a1.push(n1);
    }
    for(i=0; i<t2; i++){
        cin >> n2;
        q2 += n2;
        a2.push(n2);
    }
    for(i=0; i<t3; i++){
        cin >> n3;
        q3 += n3;
        a3.push(n3);
    }

    // Memproses tiga tumpukan hingga ketinggian tumpukan sama
    while (true) {
        // Jika ada salah satu tumpukan kosong, output 0 dan selesai
        if (a1.empty() || a2.empty() || a3.empty()) {
            cout << 0;
            return 0;
        }
        // Jika ketiga tumpukan sama tingginya, outputkan tinggi tumpukan tersebut dan selesai
        if (q1 == q2 && q2 == q3){
            cout << q1 << endl;
            return 0;
        }
        // Menghapus elemen dari tumpukan yang memiliki ketinggian paling besar
        if (q1 > q2 || q1 > q3){
            q1 -= a1.top();
            a1.pop();
        }
        else if (q2 > q1 || q2 > q3){
            q2 -= a2.top();
            a2.pop();
        }
        else if (q3 > q1 || q3 > q2){
            q3 -= a3.top();
            a3.pop();
        }
    }
    return 0;
}

/*
4 2 3
1 1 1 1
2 2
1 3 1
*/
