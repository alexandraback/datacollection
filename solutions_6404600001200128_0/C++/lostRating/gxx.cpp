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

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

const int N = 100005;

int a[N];

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt)
	{
		cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        int ans1 = 0, gxx = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i) ans1 += max(0, a[i - 1] - a[i]);
            if (i) gxx = max(gxx, a[i - 1] - a[i]);
        }
        int ans2 = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            ans2 += min(a[i], gxx);
        }
        cout << ans1 << ' ' << ans2 << endl;
	}
    return 0;
}

