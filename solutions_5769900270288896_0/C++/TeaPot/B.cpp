#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXN = 20;

int n, m, ans = inf;
bool a[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool in_field (int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int cur_bad = 0;
void go(int x, int y, int num_to_put) {
    if (num_to_put == 0) {
        ans = min(ans, cur_bad);
        return;
    }

    if (x >= n) {
        return;
    }

    int cur = 0;
    for (int i = 0; i < 4; ++i) {
        if (in_field(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]]) {
            cur++;
        }
    }

    int new_x = x;
    int new_y = y + 1;
    if (new_y >= m) {
        new_y = 0;
        new_x++;
    }

    a[x][y] = true;
    cur_bad += cur;
    go(new_x, new_y, num_to_put - 1);
    cur_bad -= cur;
    a[x][y] = false;

    go(new_x, new_y, num_to_put);
}

int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tc;
    cin >> tc;

    for (int ti = 0; ti < tc; ++ti) {
        int num;
        cin >> n >> m >> num;

        cur_bad = 0;
        ans = inf;
        go (0, 0, num);
        cout << "Case #" << ti + 1 << ": " << ans << "\n";
    }

	return 0;
}
