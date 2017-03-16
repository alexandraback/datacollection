#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define MINF 0xc0c0c0c0
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

int T, N, m[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
    	cin >> N;
    	for (int i = 0; i < N; ++i)
    	    cin >> m[i];
    	int ans1 = 0, ans2 = 0, rate = 0;
    	for (int i = 0; i < N-1; ++i)
    	{
    	    ans1 += max(0, m[i] - m[i+1]);
    	    rate = max(rate, m[i] - m[i+1]);
    	}
    	for (int i = 0; i < N-1; ++i)
    	    ans2 += min(rate, m[i]);
    	cout << "Case #" << z << ": " << ans1 << ' ' << ans2 << endl;
    }
}
