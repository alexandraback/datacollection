#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int t; cin >> t;

    for (int i = 1; i <= t; i++) {

        cout << "Case #" << i << ": ";

        int n; cin >> n;
        multiset <pair <int, char> > s;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(make_pair(-x, 'A' + i));
        }

        while (!s.empty()) {
            if (s.begin()->first == -1 && s.size() % 2 == 1) {
                cout << s.begin()->second << " ";
                s.erase(s.begin());
            }
            if (s.size() == 1) {
                pair <int, char> cur = *s.begin();
                s.erase(s.begin());
                cout << cur.second << " ";
                cur.first++;
                if (cur.first < 0) s.insert(cur);
                continue;
            }
            pair <int, char> cur1 = *s.begin(), cur2;
            s.erase(s.begin());
            cur2 = *s.begin();
            s.erase(s.begin());
            if (cur1.first != -1 && cur2.first == -1) {
                s.insert(cur2);
                cout << cur1.second << " ";
                cur1.first++;
                s.insert(cur1);
            } else {
                cout << cur1.second << cur2.second << " ";
                cur1.first++;
                cur2.first++;
                if (cur1.first < 0) s.insert(cur1);
                if (cur2.first < 0) s.insert(cur2);
            }
        }
        cout << "\n";
    }

    return 0;
}
