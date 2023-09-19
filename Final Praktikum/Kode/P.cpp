#include <stdio.h>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

struct dayat
{
    int visited = 0;
    int status = 0;
};

dayat d[100][100];

int visit = 0;

bool cek(int x, int y) // cek posisi
{
    d[x][y].visited = visit;

    if (d[x + 1][y].status == 2 || d[x - 1][y].status == 2 || d[x][y + 1].status == 2 || d[x][y - 1].status == 2)
    {
        d[x][y].status = 2; // kalau sekitarnya status = 2, dia nya ikut 2
        return true;
    }

    if (d[x + 1][y].status == 1 && visit != d[x + 1][y].visited)
        if (cek(x + 1, y))
            return true;
    if (d[x][y + 1].status == 1 && visit != d[x][y + 1].visited)
        if (cek(x, y + 1))
            return true;
    if (d[x - 1][y].status == 1 && visit != d[x - 1][y].visited)
        if (cek(x - 1, y))
            return true;
    if (d[x][y - 1].status == 1 && visit != d[x][y - 1].visited)
        if (cek(x, y - 1))
            return true;

    return false;
}

int main()
{

    vector<pair<int, int>> map; // map ukuran M X N

    int M, N, m, n;
    char input;

    scanf("%d %d", &M, &N);
    char dayat[M + 1][N + 1]; // array buat map

    for (m = 1; m <= M; m++)
        for (int n = 1; n <= N; n++)
        {
            cin >> input;
            // input simpen ke array berupa mapping
            dayat[m][n] = input;

            if (input == 'X') // x laut kabut bahaya beracun
                continue;
            d[m][n].status = 1; // diset 1
            // cari harta karun dan di push ke map

            if (m > 1 && n > 1 && m < M && n < N && input == 'O') // o harta karun
                map.push_back(make_pair(m, n));

            if (m == 1 || n == 1 || m == M || n == N || input == '^') // ^ gunung
                d[m][n].status = 2;                                   // diset 2
        }

    int size = map.size();

    for (int i = 0; i < size; i++)
    {
        visit++;
        if (!cek(map[i].first, map[i].second)) // gabisa dijangkau
            dayat[map[i].first][map[i].second] = 'X';
    }
    for (m = 1; m <= M; m++)
    {
        for (n = 1; n <= N; n++)

            cout << dayat[m][n];
        cout << endl;
    }
}
