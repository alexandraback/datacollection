#include <iostream>
#include <fstream>

using namespace std;

bool A[20][20];
int r, c, n;
int ans;

void gen(int k, int cnt) {
    int i, j;
    i = k / c;
    j = k % c;
    if (i == r) {
        int cur = 0;
        for (i = 0; i + 1 < r; ++i) {
            for (j = 0; j < c; ++j) {
                cur += (A[i][j] && A[i + 1][j]);
            }
        }
        for (i = 0; i < r; ++i) {
            for (j = 0; j + 1 < c; ++j) {
                cur += (A[i][j] && A[i][j + 1]);
            }
        }
        ans = min(ans, cur);
    }
    if (r * c - k + cnt > n) {
        A[i][j] = 0;
        gen(k + 1, cnt);
    }
    if (cnt < n) {
        A[i][j] = 1;
        gen(k + 1, cnt + 1);
    }
}

void slow() {
    cin >> r >> c >> n;
    ans = (c - 1) * r + c * (r - 1);
    gen(0, 0);
    cout << ans << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int _T, T;
    scanf("%d", &T);
    for (_T = 1; _T <= T; ++_T) {
        printf("Case #%d: ", _T);
        slow();
    }
    return 0;
}