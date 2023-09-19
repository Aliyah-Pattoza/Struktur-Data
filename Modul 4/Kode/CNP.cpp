#include <bits/stdc++.h>

using namespace std;

bool vis[10];
vector<int> x[10];

void dfs(int node)
{
    vis[node] = 1;
    for (auto c : x[node])
    {
        if (!vis[c])
            dfs(c);
    }
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        string a, b, dum;
        cin >> a >> dum >> b;
        pair<int, int> posA = {a[0] - 'A' + 1, a[1] - '0'};
        pair<int, int> posB = {b[0] - 'A' + 1, b[1] - '0'};
        x[(posA.second - 1) * 3 + posA.first].push_back((posB.second - 1) * 3 + posB.first);
        x[(posB.second - 1) * 3 + posB.first].push_back((posA.second - 1) * 3 + posA.first);
    }
    int res = 36;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = i + 1; j <= 9; j++)
        {
            memset(vis, 0, sizeof(vis));
            dfs(i);
            res -= (vis[i] && vis[j]);
        }
    }
    cout << res << endl;
}
