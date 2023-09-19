#include <iostream>
#include <vector>

using namespace std;

void Treasure(vector<vector<int>>& YutaMap, int X, int Y, int sign) {
    int N = YutaMap.size();

    if (X < 0 || X >= N || Y < 0 || Y >= N)
        return;

    if (YutaMap[X][Y] != 0 && YutaMap[X][Y] <= sign)
        return;

    if (YutaMap[X][Y] == 0 || YutaMap[X][Y] > sign)
        YutaMap[X][Y] = sign;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int u = 0; u < 4; u++) {
        int _x = X + dx[u];
        int _y = Y + dy[u];

        Treasure(YutaMap, _x, _y, sign + 1);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> YutaMap(N, vector<int>(N, 0));

    while(M--){
        int X, Y;
        cin >> Y >> X;
        Treasure(YutaMap, X-1, Y-1, 1);
    }

    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (YutaMap[u][v] < 1 || YutaMap[u][v] > 4)
                YutaMap[u][v] = 0;
        }
    }

    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            cout << YutaMap[u][v] << " ";
        }
        cout << endl;
    }

    return 0;
}
