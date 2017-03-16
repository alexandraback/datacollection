#include <iostream>
#include <cstring>
using namespace std;

int T;
int r, c, n;
int a[32][32];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cal() {
    int ret = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (a[i][j] == 1)
            for (int k = 0; k < 4; k++)
                if (a[i + dx[k]][j + dy[k]] == 1)
                    ret += 1;
    return ret / 2;
}

int gao() {
    int s = r * c;
    int ans = 4 * r * c;
    for (int m = 0; m < (1 << s); m++) {
        int k = 0;
        for (int i = 0; i < s; i++)
            if ((m >> i) & 1) k += 1;
        if (k != n) continue;
//        cout << m << endl;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < s; i++) {
            if ((m >> i) & 1) {
                int x = i / c + 1;
                int y = i % c + 1;
//                cout << x << ' ' << y << endl;
                a[x][y] = 1;
            }
        }
        ans = min(ans, cal());
    }
    return ans;
}

int main() {
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
        cin >> r >> c >> n;
        cout << "Case #" << ca << ": " << gao() << endl;
    }
    return 0;
}