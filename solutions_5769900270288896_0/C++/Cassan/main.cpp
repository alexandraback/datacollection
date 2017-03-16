#include <bits/stdc++.h>

using namespace std;

int r,c, n;

int val(vector<vector<bool> > &room) {
    int res = 0;
    bool uh = false;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            uh = false;
            if (room[i][j]) {
                if ((j - 1) >= 0 && room[i][j - 1]) res++;//uh = (uh || room[i][j - 1]);
                if ((j + 1) < c && room[i][j + 1]) res++;//uh = (uh || room[i][j + 1]);

                if ((i - 1) >= 0 && room[i - 1][j]) res++;//uh = (uh || room[i - 1][j]);
                if ((i + 1) < r && room[i + 1][j]) res++;//uh = (uh || room[i + 1][j]);

                //if (uh) res++;
            }
        }
    }

    return res;
}

int compute(vector<vector<bool> > &room, int x, int y, int left) {

    if (left == 0) return val(room);
    if (x == c) x = 0, y++;
    if (y == r) return numeric_limits<int>::max();
    int res = 0;

    room[y][x] = true;
    res = compute(room, x+1, y, left-1);
    room[y][x] = false;
    res = min(compute(room,x+1,y,left),res);

    return res;
}

int solve() {

    int left;
    cin >> r >> c >> left;
    vector<vector<bool> > room(r);
    for (int i = 0; i < r; ++i) {
        room[i].resize(c);
    }
    int res = compute(room, 0,0,left);
    return (res / 2);
}

int main() {

    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int res = solve();
        if (res >= 0) cout << "Case #" << (i+1) << ": " << res << endl;
        else cout << "Fegla Won" << endl;
    }
    
}