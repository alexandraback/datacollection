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

int B,N;
int barber[1005];

LL count(int chosen, LL n) {
	LL temp = (LL)barber[chosen] * n;
	LL sum = 0;
	for (int i = 0; i < B; i++) {
		sum += (LL)ceil(1.0*temp/barber[i]);

		LL temp1 = (LL)ceil(1.0*temp/barber[i]);
		LL temp2 = (LL)floor(1.0*temp/barber[i]);

		if (i < chosen && temp1==temp2)
			sum += 1LL;
	}
	return sum;
}

bool solve(int chosen) {

	LL a = 0ll, b = (LL)big;
	LL target = (LL)N - 1ll;

	while ((b-a) > 1) {
		LL mid = (a+b)/2ll;

		LL sum = count(chosen,mid);

		if (sum < target)
			a = mid;
		else if (sum > target)
			b = mid;
		else
			return true;
	}

	if (count(chosen,a) == target)
		return true;
	if (count(chosen,b) == target)
		return true;

	return false;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d%d",&B,&N);
		for (int i = 0; i < B; i++)
			scanf("%d",&barber[i]);

		int chosen = 0;
		for (int i = 0; i < B; i++) {
			if (solve(i)) {
				chosen = i+1;
				break;
			}
		}
		printf("Case #%d: %d\n",tc,chosen);
	}
	return 0;
}