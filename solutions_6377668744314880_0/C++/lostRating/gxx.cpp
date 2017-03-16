#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <assert.h>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

#define x first
#define y second

const double eps = 1e-10;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

const int N = 100005;

struct node
{
    int x, y;
    double z;
    bool operator <(const node &b) const
    {
        return z + eps < b.z;
    }
};

node a[N], b[N];

int ne(int i, int n)
{
    ++i;
    if (i >= n) i = 1;
    return i;
}

long long cj(node a, node b)
{
    return 1LL * a.x * b.y - 1LL * b.x * a.y;
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt)
	{
		cout << "Case #" << tt << ":" << endl;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
            cin >> a[i].x >> a[i].y;
        for (int i = 0; i < n; ++i)
        {
            node tmp = a[i];
            a[i] = a[0];
            a[0] = tmp;

            int ans = 1;
            for (int j = 1; j < n; ++j)
            {
                b[j] = a[j];
                a[j].y -= a[0].y;
                a[j].x -= a[0].x;
                a[j].z = atan2(a[j].y, a[j].x);
            }
            sort(a + 1, a + n);
            for (int j = 1, k = 1, cnt = 2; j < n; ++j, --cnt)
            {
                while (ne(k, n) != j && cj(a[j], a[ne(k, n)]) >= 0)
                    ++cnt, k = ne(k, n);
                ans = max(ans, cnt);
                if (k == j) ++k, ++cnt;
            }
            cout << n - ans << endl;
            for (int j = 1; j < n; ++j)
                a[j] = b[j];

            tmp = a[i];
            a[i] = a[0];
            a[0] = tmp;
        }
	}
    return 0;
}

