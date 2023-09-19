#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 100) {
        return 0;
    }

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] < 1 || x[i] > 10000) {
            return 0;
        }
    }

    int c;
    cin >> c;
    if (c < 1 || c > 10000) {
        return 0;
    }

    unordered_map<int, int> parent;
    unordered_map<int, vector<int>> group;

    for (int num : x) {
        parent[num] = num;
        group[num].push_back(num);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int xorRes = x[i] ^ x[j];
            if (xorRes % c == 0) {
                int parentX = parent[x[i]];
                int parentY = parent[x[j]];
                if (parentX != parentY) {
                    for (int num : group[parentY]) {
                        parent[num] = parentX;
                        group[parentX].push_back(num);
                    }
                    group[parentY].clear();
                }
            }
        }
    }

    int Kelompok = 0;
    for (auto it = group.begin(); it != group.end(); ++it) {
        if (!it->second.empty())
            Kelompok++;
    }
    cout << Kelompok << endl;

    return 0;
}
