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
typedef complex<ld> pt;

int T, N;
ld x, y;
pt tree[3000];

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
    	cin >> N;
    	for (int i = 0; i < N; ++i)
    	    cin >> x >> y, tree[i] = pt(x, y);
    	cout << "Case #" << z << ":" << endl;
    	for (int i = 0; i < N; ++i)
    	{
    	    vector<ld> angles;
    	    for (int j = 0; j < N; ++j)
    	    if (i != j)
    	        angles.push_back(arg(tree[j]-tree[i]));
    	    sort(angles.begin(), angles.end());
    	    for (int j = 0; j < N-1; ++j)
    	        angles.push_back(angles[j] + 2*M_PI);
    	    
    	    int ans = N-1, lo = 0, hi = 0;
    	    while (hi < 2*(N-1))
    	    {
    	        if (angles[hi]-angles[lo] < M_PI - 1e-14)
    	            ++hi;
    	        else
    	            ans = min(ans, hi-lo-1), ++lo;
    	    }
    	    cout << ans << endl;
    	}
    }
}
