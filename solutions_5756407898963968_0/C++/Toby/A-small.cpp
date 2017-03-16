#include <iostream>
#include <cstring>

using namespace std;

int valid[17];

void solve() {
    int line;
    memset(valid, 0, sizeof(valid));
    cin >> line;
    for (int i = 0; i < 4; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (i == line - 1) {
            valid[a]++;
            valid[b]++;
            valid[c]++;
            valid[d]++;
        }
    }
    cin >> line;
    for (int i = 0; i < 4; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (i == line - 1) {
            valid[a]++;
            valid[b]++;
            valid[c]++;
            valid[d]++;
        }
    }

    int ans = -1;
    for (int i = 1; i < 17; i++) {
        if (valid[i] != 2)
            continue;
        if (ans == -1)
            ans = i;
        else {
            cout << "Bad magician!" << endl;
            return;
        }
    }
    if (ans == -1)
        cout << "Volunteer cheated!" << endl;
    else
        cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }

    return 0;
}
