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

int T, N, B, M[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
    	cin >> B >> N;
    	for (int i = 0; i < B; ++i)
    	    cin >> M[i];
    	ll lo = 0, hi = 100000000000000;
    	while (lo < hi)
    	{
    	    ll t = (lo + hi)/2, done = 0;
    	    for (int i = 0; i < B; ++i)
    	        done += 1 + t/M[i];
    	    if (done < N)
    	        lo = t+1;
    	    else
    	        hi = t;
    	}
    	vector<int> barbers;
    	for (int i = 0; i < B; ++i)
    	{
    	    N -= (M[i]+lo-1)/M[i];
    	    if (lo % M[i] == 0)
    	        barbers.push_back(i);
    	}
    	cout << "Case #" << z << ": " << (barbers[N-1]+1) << endl;
    }
}
