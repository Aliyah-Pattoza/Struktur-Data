#include <stdio.h>

int main() {
    int n;
    while (1) { // looping tak terhingga
        scanf("%d", &n); // membaca input dari user untuk n
        if (n == 0){ // jika n = 0
            break; // keluar dari loop
        }else if (n < 0) { // jika n < 0
            printf("Mana ada kartu minus!\n"); // mencetak pesan kesalahan
            break; // keluar dari loop
        }

        int discarded[100], cards[100], i, j, num_discarded = 0; // deklarasi variabel-variabel yang dibutuhkan
        for (i = 0; i < n; i++) { // looping untuk mengisi array cards dengan nilai 1, 2, ..., n
            cards[i] = i+1;
        }

        i = 0; // inisialisasi variabel i
        while (n > 1) { // looping selama n > 1
            discarded[num_discarded++] = cards[i]; // menyimpan nilai cards[i] ke dalam array discarded dan menambah nilai num_discarded
            for (j = i; j < n-1; j++) { // shifting nilai cards sebanyak 1 ke kiri
                cards[j] = cards[j+1];
            }
            n--; // mengurangi n
            i = (i+1) % n; // update nilai i menggunakan modulo n
        }

        printf("Urutan kartu yang dibuang:\n"); // mencetak pesan
        for (i = 0; i < num_discarded; i++) { // looping untuk mencetak nilai dalam array discarded
            printf("%d ", discarded[i]);
        }
        printf("\nKartu terakhir yang tersisa: %d\n", cards[0]); // mencetak nilai cards[0]
    }

    return 0; // mengembalikan nilai 0 sebagai tanda program berakhir dengan sukses
}
