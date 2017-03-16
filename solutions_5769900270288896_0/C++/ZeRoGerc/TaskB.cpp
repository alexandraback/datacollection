#include<iostream>

using namespace std;

const int INF = 1000111222;

int T, r, c, n;
int map[20][20];

bool next() {
    map[0][0]++;
    int i = 0, j = 0;
    while (map[i][j] > 1) {
        map[i][j] = 0;
        j++;
        if (j >= c) j = 0, i++;
        if (i >= r) return false;
        map[i][j]++;
    }
    
    return true;
}

int check() {
    int result = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] != 1) continue;
            if (i > 0) result += map[i - 1][j];
            if (j > 0) result += map[i][j - 1];
        }
    }
    return result;
}

bool count() {
    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            k += map[i][j];
        }
    }
    return (k == n);
}

int main() {
    freopen("B-small-attempt0.in-2.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    for (int I = 0; I < T; I++) {
        int ans = INF;
        cin >> r >> c >> n;
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) map[i][j] = 0;
        
        while (true) {
            if (count()) ans = min(ans, check());
            if (!next()) break;
        }
        
        printf("Case #%d: %d\n", I + 1, ans);
    }
}