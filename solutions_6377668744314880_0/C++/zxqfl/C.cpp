#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


template<typename T>
struct pt
{
	T x, y;

	pt() {}
	pt(const T& a, const T& b) : x(a), y(b) {}

	pt operator + (const pt& P) const
	{
		return {x + P.x, y + P.y};
	}
	pt operator - (const pt& P) const
	{
		return {x - P.x, y - P.y};
	}
	pt operator * (const T& s) const
	{
		return {x * s, y * s};
	}
	T operator * (const pt& P) const
	{
		return x * P.x + y * P.y;
	}
	T operator ^ (const pt& P) const
	{
		return x * P.y - y * P.x;
	}
	T dot(const pt& P) const
	{
		return (*this) * P;
	}
	T cross(const pt& P) const
	{
		return (*this) ^ P;
	}
	T norm2() const
	{
		return x * x + y * y;
	}
};
typedef pt<ll> lpt;

int N;
lpt pts[3000];

int main()
{
	nrint(T);
	for (int test = 1; test <= T; test++)
	{
		rint(N);
		ji(N)
		{
			rlong(pts[i].x);
			rlong(pts[i].y);
		}
		int ans[N];
		ji(N) ans[i] = INF;
		if (N == 1) ans[0] = 0;
		jij(N, N) if (i != j)
		{
			lpt A = pts[j] - pts[i];
			vector<int> V;
			int cnt = 0;
			jk(N)
			{
				lpt B = pts[k] - pts[i];
				ll cross = A ^ B;
				if (cross < 0)
					cnt++;
				if (cross <= 0)
					V.pb(k);
			}
			foreach(x, V)
				ans[x] = min(ans[x], cnt);
		}
		printf("Case #%d:\n", test);
		ji(N) printf("%d\n", ans[i]);
	}
}
