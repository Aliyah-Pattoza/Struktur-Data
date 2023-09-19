#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> adjList(1000);

void bellmanFord(vector<int>& res, int begin, int peakCount) {
    res = vector<int>(peakCount, INT_MAX);
    res[begin] = 0;

    for (int i = 0; i < peakCount - 1; i++) {
        for (int j = 0; j < peakCount; j++) {
            for (auto peak : adjList[j]) {
                int k = peak.first;
                int balance = peak.second;

                if (res[j] != INT_MAX && res[j] + balance < res[k]) {
                    res[k] = res[j] + balance;
                }
            }
        }
    }
}

int main() {
    int V;
    cin >> V;
    string S;
    int P;
    map<int, string> priceRestaurant;
    map<int, int> priceGuide;

    for (int n = 1; n <= V; n++) {
        cin >> S >> P;
        priceRestaurant[P] = S;
        priceGuide[n] = P;
    }

    int E;
    cin >> E;
    int V1, V2, W;

    for (int n = 0; n < E; n++) {
        cin >> V1 >> V2 >> W;
        adjList[V1].push_back({V2, W});
        adjList[V2].push_back({V1, W});
    }

    int D;
    cin >> D;
    vector<int> res;
    bellmanFord(res, 0, V + 5);
    int minPrice = INT_MAX;
    string RestoMurah;

    for (int n = 1; n <= V; n++) {
        if (priceGuide[n] < minPrice && res[n] <= D) {
            minPrice = priceGuide[n];
            RestoMurah = priceRestaurant[minPrice];
        }
    }
    cout << "Hari ini makan di " << RestoMurah << endl;
    return 0;
}
