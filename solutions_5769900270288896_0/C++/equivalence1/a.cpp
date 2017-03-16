#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define what_is(x) cerr << #x << ": " << x << endl;

#define file "f"

typedef long long ll;

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

using namespace std;

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int T, r, c, n;
int a[1000][1000];

int get_ans(int r, int c, int mask) {
    forn(i, r + 2)
        forn(j, c + 2)
            a[i][j] = 0;

    int top = 0;
    forn(i, r) {
        forn(j, c) {
            a[1 + i][1 + j] = (mask & (1 << top));
            top++;
        }
    }

    int ans = 0;
    forn(i, r) {
        forn(j, c) {
            forn(k, 2) {
                if (a[i + 1][j + 1] > 0 && a[i + 1 + dy[k]][j + 1 + dx[k]] > 0) {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int solve(int r, int c, int n) {
    int ans = r * c + 100000;
    forn(mask, 1 << (r * c)) {
        if (__builtin_popcount(mask) == n) {
            int z = get_ans(r, c, mask);
            ans = min(ans, z);
        }
    }

    return ans;
}

int main() {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);

    scanf("%d", &T);
    forn(_t, T) {
        scanf("%d%d%d", &r, &c, &n);
        printf("Case #%d: %d\n", _t + 1, solve(r, c, n));
    }
}
