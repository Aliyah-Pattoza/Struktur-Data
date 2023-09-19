#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> rute(N);

    while(true) {
        int dungeon1, dungeon2;
        cin >> dungeon1 >> dungeon2;
        if (dungeon1 == -1 && dungeon2 == -1){
            break;
        }
        rute[dungeon1].push_back(dungeon2);
    }

    for(int x = 0; x < N; x++) {
        int start = x;
        int P = rute.size();
        vector<int> langkah(P, 0);
        langkah[x] = 0;

        queue<int> queue;
        queue.push(start);

        while (!queue.empty()) {
            int connect = queue.front();
            queue.pop();
            for (int ans : rute[connect]) {
                if (langkah[ans] == 0) {
                    langkah[ans] = langkah[connect] + 1;
                    queue.push(ans);
                }
            }
        }

        if (langkah[x] != 0) {
            cout << langkah[x] << endl;
        } else {
            cout << "gak bisa pulang mamah" << endl;
        }
    }
    return 0;
}
