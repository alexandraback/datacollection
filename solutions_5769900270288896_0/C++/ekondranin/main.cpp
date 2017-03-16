#include <bits/stdc++.h>
#define endl "\n"
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int i = 0; i < (n); ++i) cin >> a[i];
#define GETM(a, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
#define PRINTM(a, n, m) for (int i = 0; i < (n); ++i) { for (int j = 0; j < m; ++j) cout << a[i][j] << " ";  cout << endl; };
#define PRINT(a, n) for (int i = 0; i < (n); ++i) cout << a[i] << " ";
#define IT(a) a.begin(), a.end()
#define CASE(a, s) cout << "Case #" << a << ": " << s << endl;
#define DEB(a) cout << #a << " = " << (a) << endl; cout.flush();
#define DEBA(a) for (auto i: a) cout << i << " "; cout << endl;
#define IFDEB(b, a) if (b) { cout << #a << " = " << a << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <vector <int>> VVI;
typedef pair <int, int> PII;
const int MOD = 1000000007;
template <class T> typename T::value_type arr_sum(const T& v, int n) { typename T::value_type sum = 0; FOR(i, 0, n) sum += v[i]; return sum; }
struct Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

int main()
{
    int t;
    cin >> t;
    FOR (l, 0, t) {
        int r, c, n;
        cin >> r >> c >> n;
        vector <vector <int>> v(r, vector <int> (c));
        int minc = INT_MAX;
        FOR (i, 0, (1 << (r * c))) {
            int x = 0, y = 0;
            int z = i;
            int cnt = 0;
            int tres = 0;
            FOR (j, 0, r * c) {
                v[x][y] = z & 1;
                cnt += z & 1;
                z >>= 1;
                ++y;
                if (y == c) {
                    ++x;
                    y = 0;
                }
            }
            if (cnt != n) {
                continue;
            }
            FOR (j, 0, r) {
                FOR (k, 0, c) {
                    if (v[j][k] != 1) {
                        continue;
                    }
                    if (j + 1 < r && v[j + 1][k] == 1) {
                        ++tres;
                    }
                    if (k + 1 < c && v[j][k + 1] == 1) {
                        ++tres;
                    }
                }
            }
            minc = min(minc, tres);
        }
        CASE(l + 1, minc);
    }
}
