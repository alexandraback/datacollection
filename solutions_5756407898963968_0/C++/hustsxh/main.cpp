#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void solve() {
    int a[5][5], b[5][5], r1, r2, cnt[17] = {0};
    cin >> r1;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= 4; ++j) {
        ++ cnt[a[r1][j]];
    }
    cin >> r2;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cin >> b[i][j];
        }
    }
    for (int j = 1; j <= 4; ++j) {
        ++ cnt[b[r2][j]];
    }
    set<int> res;
    for (int i = 1; i <= 16; ++i) {
        if (cnt[i] == 2) {
            res.insert(i);
        }
    }
    if (res.size() == 1) {
        cout << *res.begin() << endl;
    } else if (res.size() == 0){
        cout << "Volunteer cheated!" << endl;
    } else {
        cout << "Bad magician!" << endl;
    }
}
int main() {
    int testcase;
    freopen("/Users/xhSong/Downloads/A-small-attempt0.in", "r", stdin);
    freopen("/Users/xhSong/out.txt", "w", stdout);
    cin >> testcase;
    for (int test = 1; test <= testcase; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
