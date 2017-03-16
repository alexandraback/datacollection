
#include <iostream>
#include <set>

using namespace std;

set <int> s[2];

void solve() {
    for (int k = 0; k < 2; k++) {
        s[k].clear();

        int row;
        cin >> row;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int a;
                cin >> a;
                if (i + 1 == row)
                    s[k].insert(a);
            }
        }
    }

    int cnt = 0;
    int last = -1;
    for (auto x : s[0])
        if (s[1].count(x))
            cnt++, last = x;

    if (cnt == 0)
        cout << "Volunteer cheated!" << endl;
    else if (cnt == 1)
        cout << last << endl;
    else
        cout << "Bad magician!" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

