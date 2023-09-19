#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Memastikan N berada dalam batas yang valid (3 sampai 1000)
    if (N < 3 || N > 1000) {
        return 0;
    }

    // Membuat vektor dua dimensi untuk merepresentasikan graf
    vector<vector<int>> graph(N + 1);

    // Membuat map untuk menyimpan jumlah tetangga setiap anggota
    map<int, int> neighbors;

    // Membaca persekutuan-persekutuan antar anggota
    int a, b;
    string input;
    while (true) {
        cin >> input;
        if (input == "Yee!")
            break;
        a = stoi(input);
        cin >> b;

        // Menambahkan tetangga ke graf (hubungan dua arah)
        graph[a].push_back(b);
        graph[b].push_back(a);

        // Menghitung jumlah tetangga untuk setiap anggota
        neighbors[a]++;
        neighbors[b]++;
    }

    // Mencari anggota dengan neighbor paling sedikit
    int minNeighbor = numeric_limits<int>::max();
    int targetNode = -1;
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        int node = it->first;
        int numNeighbors = it->second;

        if (numNeighbors < minNeighbor) {
            minNeighbor = numNeighbors;
            targetNode = node;
        } else if (numNeighbors == minNeighbor && node > targetNode) {
            targetNode = node;
        }
    }

    // Mencari anggota dengan neighbor paling banyak
    int maxNeighbor = -1;
    int dangerousNode = -1;
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        int node = it->first;
        int numNeighbors = it->second;

        if (numNeighbors > maxNeighbor) {
            maxNeighbor = numNeighbors;
            dangerousNode = node;
        } else if (numNeighbors == maxNeighbor && node < dangerousNode) {
            dangerousNode = node;
        }
    }

    // Output hasil
    cout << targetNode << " Targetnya" << endl;
    cout << dangerousNode << " Paling Bahaya" << endl;

    return 0;
}
