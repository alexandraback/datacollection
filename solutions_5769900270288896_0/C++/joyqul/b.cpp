#include <bits/stdc++.h>

using namespace std;

int R, C, N;
bool mymap[1000][1000];

int packet(int myi, int myj, int last) {
    if (last == 0) {
        int ans = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C-1; ++j) {
                if (mymap[i][j] && mymap[i][j+1]) ++ans;
            }
        }
        for (int i = 0; i < R-1; ++i) {
            for (int j = 0; j < C; ++j) {
                if (mymap[i][j] && mymap[i+1][j]) ++ ans;
            }
        }
        return ans;
    }

    //cout << R*C - myi*C - myj - 1 << endl;
    if (R*C - myi*C - myj - 1 < last) return 0x7fffffff;
    int nexti = myi, nextj = myj;
    if (nextj == C-1) {
        ++nexti;
        nextj = 0;
    }
    else ++nextj;

    mymap[nexti][nextj] = true;
    int first = packet(nexti, nextj, last-1);
    mymap[nexti][nextj] = false;
    int second = packet(nexti, nextj, last);
    return min(first, second);
}

int solve() {
    if ((R*C+1)/2 >= N) return 0;
    memset(mymap, false, sizeof(mymap));
    if (R == 1 && C == 1 && N == 1) return 1;
    mymap[0][0] = true;
    return packet(0, 0, N-1);
}

int main () {
    int tcase;
    scanf("%d", &tcase);
    for (int i = 1; i <= tcase; ++i) {
        
        int row, col;
        cin >> row >> col >> N;
        R = min(row, col);
        C = max(row, col);
        printf("Case #%d: ", i);
        cout << solve() << endl;
    }
    return 0;
}
