#include <iostream>
#define ll unsigned long long int

using namespace std;
ll star(ll a, ll b, ll s)
{
    if (b == 0)
        return 1;

    ll res = star(a, b / 2, s) % s;
    res = (res * res) % s;

    if (b % 2 == 1)
        res = (res * a) % s;

    return res;
}

int main (){
    ll a = 2;
    ll n = 1000000009;
    int m;
    cin >> m;
    ll mi;
 for (int i = 0; i < m; i++) {
        cin >> mi;
            ll s = (mi*(mi-1))/2;
            s %= n-1;
            cout << "Zodiak found: " << (star(a, s, n)) << " signs" << endl;
    }
    return 0;
}
