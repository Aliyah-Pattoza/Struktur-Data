#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> hitungpalingsedikit(vector<vector<int>>& rute, int awal) {
    int x;
	x = rute.size();
    vector<int> langkah(x, 0);
    langkah[awal] = 0;

    queue<int> queue;
    queue.push(awal);

    while (!queue.empty()) {
        int terhubung = queue.front();
        queue.pop();
          for (int temp : rute[terhubung]) {
            if (langkah[temp] == 0) {
                langkah[temp] = langkah[terhubung] + 1;
                queue.push(temp);
            }
        }
    }
    return langkah;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> rute(n);

    while(1) {
        int dungeon1, dungeon2;
        cin >> dungeon1 >> dungeon2;
        if (dungeon1 == -1 && dungeon2 == -1){
            break;
        }
        rute[dungeon1].push_back(dungeon2);
    }

    for(int i = 0; i < n; i++) {
        vector<int> langkahtercepat = hitungpalingsedikit(rute, i);
        if(langkahtercepat[i] != 0) {
            cout << langkahtercepat[i] << "\n";
        }
		else{
            cout << "gak bisa pulang mamah\n";
        }
    }
    return 0;
}
