#include <iostream>
#include <cstdio>

using namespace std;

void solve(int t) {
    int a[4][4];
    int ans;
    int b[16];
    for (int i = 0; i < 16; ++i) {
        b[i] = 0;
    }
    for (int k = 0; k < 2; ++k) {
        cin >> ans;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 4; ++i) {
            b[a[ans - 1][i] - 1]++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 16; ++i) {
        if (b[i] == 2) {
            ++cnt;
        }
    }
    cout << "Case #" << t << ": ";
    if (cnt > 1) {
        cout << "Bad magician!" << endl;
        return;
    }
    if (cnt == 0) {
        cout << "Volunteer cheated!" << endl;
        return;
    }
    for (int i = 0; i < 16; ++i) {
        if (b[i] == 2) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }
    return 0;
}
