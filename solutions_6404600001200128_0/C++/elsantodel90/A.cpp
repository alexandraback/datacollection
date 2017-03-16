#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define all(c) (c).begin(),(c).end()

#define esta(x,c) ((c).find(x) != (c).end())
#define zMem(c) memset((c),0,sizeof(c))

typedef long long tint;
typedef long double tdbl;

typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;

const int MAXN = 100000;

tint v[MAXN];

int main()
{
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
        int n; cin >> n;
        forn(i,n) cin >> v[i];
        tint min1 = 0, min2 = 0;
        tint maxDecrease = 0;
        forn(i,n-1)
        {
            tint decrease = max(0LL, v[i] - v[i+1]);
            min1 += decrease;
            maxDecrease = max(maxDecrease, decrease);
        }
        // maxDecrease / 10 = mushrate
        forn(i, n-1)
        {
            tint remaining = max(0LL, v[i] - maxDecrease);
            min2 += v[i] - remaining;
        }
		cout << "Case #" << caso + 1 << ": " << min1 << " " << min2 << endl;
	}
	return 0;
}
