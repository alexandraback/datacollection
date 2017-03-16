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

#define MAXN (3004)

int T, N;
LL X[MAXN];
LL Y[MAXN];
int sol[MAXN];

PLL P[MAXN*2];

inline int quad(PLL &p)
{
	if(p._2 == 0)
	{
		if(p._1 < 0) return 0;
		else return 2;
	}
	else if(p._2 < 0) return 1;
	else return 3;
}

inline LL cross(PLL u, PLL v)
{
	return u._1*v._2 - u._2*v._1;
}

bool cmpf(PLL p, PLL q)
{
	if(p != q)
	{
		int a = quad(p);
		int b = quad(q);
		if(a != b) return a < b;

		return cross(p, q) > 0;
	}
	else return 0;
}

int main()
{
	cin >> T;
	FOR(tt,1,T+1)
	{
		cin >> N;
		FOR(i,0,N) cin >> X[i] >> Y[i];

		FOR(i,0,N)
		{
			int n = 0;
			FOR(j,0,N) if(j != i)
			{
				int d = __gcd(abs(X[j]-X[i]), abs(Y[j]-Y[i]));
				P[n++] = PLL((X[j]-X[i])/d, (Y[j]-Y[i])/d);
			}

			sort(P, P+n, cmpf);
//			printf("\n%d - %d %d\n", i, int(X[i]), int(Y[i]));
//			FOR(j,0,n) printf("%d : %d %d\n", j, int(P[j]._1), int(P[j]._2));
			FOR(j,0,n) P[j+n] = P[j];

			int res = 0;
			int k = 0;
			FOR(j,0,n*2)
			{
				maxa(k, j-n+1);
				while(cross(P[j], P[k]) > 0) ++k;
				maxa(res, j-k+1);
			}
			mina(res, N-1);
			sol[i] = N-1 - res;
		}

		printf("Case #%d:\n", tt);
		FOR(i,0,N) printf("%d\n", sol[i]);
	}

	return 0;
}
