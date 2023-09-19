#include <bits/stdc++.h>

using namespace std;

vector<int> addTwoLists(const vector<int>& list1, const vector<int>& list2) {
    vector<int> hasil;
    int ces = 0;
    int a = list1.size() - 1;
    int b = list2.size() - 1;

    while (a >= 0 || b >= 0 || ces > 0) {
        int sum = ces;
        if (a >= 0) {
            sum += list1[a];
            a--;
        }
        if (b >= 0) {
            sum += list2[b];
            b--;
        }
        hasil.push_back(sum % 10);
        ces = sum / 10;
    }

    reverse(hasil.begin(), hasil.end());

    return hasil;
}

void printList(const vector<int>& list) {
    for (int digit : list) {
        cout << digit;
    }
    cout << endl;
}

int main() {
    int M, N;
    cout << "";
    cin >> M >> N;

    vector<int> list1(M);

    cout << "";
    for (int i = 0; i < M; i++) {
        cin >> list1[i];
    }
    vector<int> list2(N);
    cout << "";
    for (int i = 0; i < N; i++) {
        cin >> list2[i];
    }

    vector<int> sum = addTwoLists(list1, list2);

    cout << "";
    printList(sum);

    return 0;
}
