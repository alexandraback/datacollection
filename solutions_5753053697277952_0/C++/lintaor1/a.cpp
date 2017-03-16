/**********************
 #  By lintao [Hudi]  #
 **********************/

#include <bits/stdc++.h>
using namespace std;

#define INIT(c,v) memset(c,v,sizeof(c))
#define REP(a,b,c) for (int a=b, _c=c; a<_c; ++a)
#define RED(a,b,c) for (int a=b, _c=c; a>=_c; --a)

#define PB push_back
#define MP make_pair
#define fi first
#define sc second

typedef long long ll;
typedef pair<ll,ll> puu;
typedef pair<int,int> pii;
typedef pair<int,char> pic;

#define _MULTI_TC_
// =========================================== //
void solve(int);
int main()
{
#ifdef _MULTI_TC_
	int TC;
	scanf("%d", &TC);
	REP(tc,1,TC+1) solve(tc);
#else
	solve(0);
#endif
	return 0;
}
// =========================================== //

void solve(int tc) {
	int N;
	int sum=0;
	int tmp;
	priority_queue< pic > pq;
	scanf("%d", &N);
	REP(x,'a','a'+N) {
		scanf("%d", &tmp);
		pq.push( MP( tmp, x ) );
		sum += tmp;
	}

	printf("Case #%d:", tc);

	while (!pq.empty()) {
		pic a = pq.top(); pq.pop();
		pic b = pq.top(); pq.pop();
		if (!pq.empty())
		{
			pic c = pq.top(); pq.pop();
			if ((a.fi > b.fi) || (a.fi == b.fi && a.fi == c.fi)) {
				printf(" %c", a.sc); --a.fi;
			}
			else if (a.fi == b.fi) {
				printf(" %c%c", a.sc, b.sc); --a.fi, --b.fi;
			}

			if (a.fi>0) pq.push(a);
			if (b.fi>0) pq.push(b);
			if (c.fi>0) pq.push(c);
		}
		else
		{
			if (a.fi == b.fi) {
				printf(" %c%c", a.sc, b.sc); --a.fi, --b.fi;
			} else {
				printf(" %c", a.sc); --a.fi;
			}
			if (a.fi>0) pq.push(a);
			if (b.fi>0) pq.push(b);
		}
	}
	printf("\n");
}