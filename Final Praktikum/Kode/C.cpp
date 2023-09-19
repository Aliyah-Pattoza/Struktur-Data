#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
using namespace std;

const int mod = 1000000007;
const int INF = 1e9;

int n;

void tackle() {
   cin >> n;
   multiset <int> v;
   for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      v.insert(p);
   }

   multiset<int>::iterator its;
   int oft = 0;
   while (!v.empty()) {
      int x = v.count(*v.begin());
      oft = max(oft, x);
      v.erase(*v.begin());
   }
   if (n - oft >= oft) {
      if (n % 2 == 1)
         cout << 1 << endl;
      else
         cout << 0 << endl;
      return;
   }
   if (n - oft >= oft)
      cout << 0 << endl;
   else
      cout << oft - (n - oft) << endl;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   t = 1;
   cin >> t;

   while (t--)
      tackle();
   return 0;
}
