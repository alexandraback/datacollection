#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define fi first
#define sc second
#define MP make_pair
#define pb push_back
#define PI acos(-1.0)
#define vi vector<int>
#define vii vector<pii>
#define ALL(c) (c).begin(), (c).end()
#define RESET( c,a ) memset( (c), a, sizeof(c) )
#define REP( a,b,c ) for ( int a=b, _c=c; a<_c; ++a )
#define RED( a,b,c ) for ( int a=b, _c=c; a>=_c; --a )
#define REPI( it, c ) for ( __typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )

const int big = 1000000000;
const double INF = 1e9;
const double EPS = 1e-9;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

int main() {
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {
		int N;
		scanf("%d",&N);
		int plate[N+5];
		int maxi = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d",&plate[i]);
			if (i > 0)
				maxi = max(maxi,plate[i-1]-plate[i]);
		}

		int max1 = 0;
		for (int i = 0; i < N-1; i++)
			max1 += max(plate[i]-plate[i+1],0);

		int max2 = 0;
		for (int i = 0; i < N-1; i++)
			max2 += min(plate[i],maxi);
		printf("Case #%d: %d %d\n",tc,max1,max2);
	}
	return 0;
}