#include <iostream>
#include <stack>

using namespace std;

struct Stack{
    //berisi indeks teratas dan data array
    int top;
    int data[100001];
};

int main()
{
    int L;
    cin >> L; //Menginputkan banyak data uji

    while (L--){ //Melakukan perulangan sebanyak data uji
        string T;
        cin >> T; //inputkan substring data

        int x = T.length(), game = 0;

        Stack Due; //Mendeklrasikan Stack
        Due.top = -1; //Inisialisasi indeks teratas stack

        Due.data[++Due.top] = -1; //Memasukkan nilai -1 pada indeks teratas stack
        for (int i = 0; i < x; i++){ //Melakukan perulangan sebanyak string T
            if (T[i] == 'F')
            {
                Due.data[++Due.top] = i; //Push indeks i pada stack
            }
            else if (T[i] == 'B')
            {
                if (Due.top != -1)
                    Due.top--; //pop indeks teratas pada stack
                if(Due.top != -1)
                    //hitung selisih antara i dan indeks teratas stack, dan simpan nilai maksimumnya pada variabel game
                    game = max(game, i - Due.data[Due.top]);
                else
                    Due.data[++Due.top] = i; //Push indeks i pada stack
            }
        }
        cout << game << endl; //Menampilkan Nilai Perintah game
    }
}

/*
2
BBFFFBFFBFBB
FFBFBFF
*/
