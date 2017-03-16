// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

#define MAXM (1004)

int T, N, M;
int A[MAXM];

int main()
{
	cin >> T;
	FOR(tt,1,T+1)
	{
		cin >> M >> N;
		FOR(i,0,M) cin >> A[i];

		LL lo = 0;
		LL hi = 1LL << 50;
		LL res = 0;
		while(lo <= hi)
		{
			LL mid = (lo + hi) / 2;
			LL s = 0;
			FOR(i,0,M) s += (mid + A[i]-1) / A[i];
//			printf("mid  %I64d  s %I64d\n", mid, s);
			if(s >= N) res = hi = mid - 1;
			else lo = mid + 1;
		}

//		printf("res %I64d\n", res);

		LL f = 0;
		FOR(i,0,M) f += (res + A[i]-1) / A[i];
		int sol = 0;
		FOR(i,0,M) if(res % A[i] == 0)
		{
			++f;
			if(f == N)
			{
				sol = i+1;
				break;
			}
		}

		printf("Case #%d: %d\n", tt, sol);
	}

	return 0;
}
