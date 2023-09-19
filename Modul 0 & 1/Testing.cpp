#include <bits/stdc++.h>
using namespace std;

struct Query {
    string s;
    int ans;
};

int main()
{
    int q;
    cin >> q;

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].s;
        queries[i].ans = 0;
    }

    for (int i = 0; i < q; i++) {
        string s = queries[i].s;
        int len = s.length();
        stack<int> st;
        st.push(-1);

        for (int j = 0; j < len; j++) {
            if (s[j] == 'F') {
                st.push(j);
            }
            else if (s[j] == 'B') {
                if (!st.empty())
                    st.pop();
                if (!st.empty())
                    queries[i].ans = max(queries[i].ans, j - st.top());
                else
                    st.push(j);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << queries[i].ans << "\n";
    }

    return 0;
}
