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
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
            cin >> a[i];
        if (m <= n)
        {
            cout << m << endl;
            continue;
        }
        long long l = 1, r = 200000000000000LL;
        while (l < r)
        {
            long long mid = (l + r) / 2;
            long long tmp = 0;
            for (int i = 0; i < n; ++i)
                tmp += mid / a[i] + 1;
            if (tmp < m)
                l = mid + 1;
            else
                r = mid;
        }
        for (int i = 0; i < n; ++i)
            m -= (l - 1) / a[i] + 1;
        bool gxx = false;
        for (int i = 0; i < n; ++i)
            if (l % a[i] == 0)
            {
                --m;
                if (m == 0)
                {
                    gxx = true;
                    cout << i + 1 << endl;
                    break;
                }
            }
        assert(gxx);
	}
    return 0;
}

