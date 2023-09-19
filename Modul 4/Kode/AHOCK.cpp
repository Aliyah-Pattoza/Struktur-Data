#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N < 3 || N > 1000) {
        return 0;
    }

    vector<vector<int>> graf(N + 1);
    map<int, int> sekutu;

    int a, b;
    string input;
    while (true) {
        cin >> input;
        if (input == "Yee!")
            break;
        a = stoi(input);
        cin >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        sekutu[a]++;
        sekutu[b]++;
    }

    int target = -1;
    int bahaya = -1;
    int minNeighbor = N + 1;
    int maxNeighbor = -1;

    for (int node = 1; node <= N; ++node) {
        int sekutu_n = sekutu[node];

        if (sekutu_n < minNeighbor) {
            minNeighbor = sekutu_n;
            target = node;
        } else if (sekutu_n == minNeighbor && node > target) {
            target = node;
        }

        if (sekutu_n > maxNeighbor) {
            maxNeighbor = sekutu_n;
            bahaya = node;
        } else if (sekutu_n == maxNeighbor && node < bahaya) {
            bahaya = node;
        }
    }

    cout << target << " Targetnya" << endl;
    cout << bahaya << " Paling Bahaya" << endl;

    return 0;
}
