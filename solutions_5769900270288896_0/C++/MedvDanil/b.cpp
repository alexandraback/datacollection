#include<bits/stdc++.h>
using namespace std;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int solve_old(int r, int c, int N) {
    int a[16];
    int mres = 10000000;
    for(int i = 0;i<r*c;i++)
        a[i] = (r*c - i <= N);
    do {
        int res = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(a[i*c+j])
                    for(int k = 0; k < 4; k++)
                        res += (i + dr[k] < r && i + dr[k] >= 0 &&
                                j + dc[k] < c && j + dc[k] >= 0 && a[(i+dr[k])*c+j+dc[k]]);
        if(res < mres)
            mres = res;
    }while(next_permutation(a, a+r*c));
    return mres / 2;
}
char a[1024*1024];
int fill_other(int r, int c, int n) {
    int nb = 0;
    int res = 0;
    while(n > 0) {
        int ch = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(a[i*c+j] == 0) {
                    int neib = 0;
                    for(int k = 0; k < 4; k++)
                        neib += (i + dr[k] < r && i + dr[k] >= 0 &&
                                 j + dc[k] < c && j + dc[k] >= 0 && a[(i+dr[k])*c+j+dc[k]]);
                    if(neib == nb)
                        n--, a[i*c+j] = 1, ch = 1, res += neib;
                }
        if(ch == 0)
            nb++;
    }
    return res;
}
int solve(int r, int c, int N) {
    int n = N;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if((i+j)&1)
                a[i*c+j] = 1, n--;
            else
                a[i*c+j] = 0;
    int v1 = fill_other(r, c, n);
    n = N;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if((i+j)&1)
                a[i*c+j] = 0;
            else
                a[i*c+j] = 1, n--;
    int v2 = fill_other(r, c, n);
    return min(v1, v2);
}
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    int r, c, n;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> r >> c >> n;
        printf("Case #%d: %d\n", t, solve_old(r, c, n));
    }
}

