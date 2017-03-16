// LUCIFER <3 SLS <3

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

int a[20][20][20];

int x[20][20];

void recur(int r, int c, int i, int j)
{
    if (i == r) {
        int cnt = 0, cnt2 = 0;
        for (int p = 0; p < r; p++) {
            for (int q = 0; q < c; q++) {
                if (x[p][q] == 1) {
                    cnt++;
                    if (q < (c-1) && x[p][q+1] == 1) {
                        cnt2++;
                    }
                    if (p < (r-1) && x[p+1][q] == 1) {
                        cnt2++;
                    }
                }
            }
        }
        /*if (r == 2 && c == 3) {
            for (int p = 0; p < r; p++) {
                for (int q = 0; q < c; q++)
                    cout << x[p][q] << " ";
                cout << endl;
            }
            cout << endl;
        }*/
        a[r][c][cnt] = min(a[r][c][cnt], cnt2);
    }
    else {
        if (j == c) {
            j = 0;
            i++;
        }
        recur(r, c, i, j+1);
        x[i][j] = 1;
        recur(r, c, i, j+1);
        x[i][j] = 0;
    }
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int i, j, k;
    for (i = 1; i <= 16; i++) {
        for (j = 1; j <= (16/i); j++) {
            for (k = 0; k <= i*j; k++)
                a[i][j][k] = INT_MAX;
            memset(x, 0, sizeof(x));
            recur(i, j, 0, 0);
        }
    }
    int t, u = 0;
    cin >> t;
    while (t--) {
        cin >> i >> j >> k;
        cout << "Case #" << ++u << ": " << a[i][j][k] << endl;
    }
}
