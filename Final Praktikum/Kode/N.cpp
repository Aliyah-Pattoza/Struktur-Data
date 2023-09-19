#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    stack<bool> GC;
    for (int x = 0; x < N; x++) {
        int gerakan;
        cin >> gerakan;
        if (GC.empty()) {
            if (gerakan == 1) { // swap
                GC.push(1);
                GC.push(0);
            } else if (gerakan == 0) { // rotasi
                GC.push(0);
            }
        } else if (GC.size() == 1) {
            if (GC.top()) {
                if (gerakan == 1) { // swap
                    GC.pop();
                } else if (gerakan == 0) { // rotasi
                    GC.push(0);
                }
            } else {
                if (gerakan == 0) { // rotasi
                    GC.pop();
                }
            }
        } else if (GC.size() > 1) {
            if (GC.top()) {
                if (gerakan == 1) { // swap
                    GC.pop();
                } else if (gerakan == 0) { // rotasi
                    GC.push(0);
                }
            } else {
                if (gerakan == 1) { // swap
                    GC.pop();
                    GC.push(1);
                    GC.push(0);
                    GC.push(1);
                    GC.push(0);
                } else if (gerakan == 0) { // rotasi
                    GC.pop();
                }
            }
        }
    }
    int MinMoves = GC.size();
    cout << MinMoves << endl;

    return 0;
}
