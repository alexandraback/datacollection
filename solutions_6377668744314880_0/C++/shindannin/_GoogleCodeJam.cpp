// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include "assert.h"

using namespace std;
static const double EPS = 1e-9;
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
template<class T> void amin(T &a,T v){if(a>v) a=v;}
template<class T> void amax(T &a,T v){if(a<v) a=v;}
#define PI	(3.14159265358979323846)
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG (987654321)
#define SZ(a) ((int)a.size())
typedef long long ll;

#define FOR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
// BEGIN CUT HERE
#undef FOR
#define FOR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
// END CUT HERE

#define PRINTF(fmt,...) fprintf(stderr,fmt,__VA_ARGS__); printf(fmt,__VA_ARGS__);



#if 1

double add(double a, double b)
{
	if (abs(a+b)< EPS * (abs(a)+abs(b))) return 0;
	return a+b;
}

struct P
{
	double x,y;
	P() {}
	P(double x, double y) : x(x), y(y) {};
	P operator + (P p)
	{
		return P(add(x,p.x), add(y,p.y));
	}
	P operator - (P p)
	{
		return P(add(x,-p.x), add(y,-p.y));
	}
	P operator * (double d)
	{
		return P(x*d, y*d);
	}
	double dot(P p)
	{
		return add(x*p.x, y*p.y);
	}
	double det(P p)
	{
		return add(x*p.y, -y*p.x);
	}
};

bool cmp_x(const P& p, const P& q)
{
	if(p.x != q.x) return p.x < q.x;
	return p.y < q.y;
}

// 凸包
vector <P> convex_hull(P* ps, int n)
{
	sort(ps, ps+n, cmp_x);
	int k = 0;
	vector <P> qs(n*2);
	for (int i = 0; i < n; ++i)
	{
		while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1]) <= 0) k--;
		qs[k++] = ps[i];
	}

	for (int i = n-2, t=k; i>=0; i--)
	{
		while(k>t && (qs[k-1] - qs[k-2]).det(ps[i]-qs[k-1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}

bool on_seg(P p1, P p2, P q)
{
	return (p1-q).det(p2-q)==0 && (p1-q).dot(p2-q)<=0;
}

int main()
{

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d",&T);

	for (int testcase = 0; testcase < T; testcase++)
	{
		int N;
		cin >> N;

		P base[5000];
		for (int i = 0; i < N; ++i)
		{
			cin >> base[i].x >> base[i].y;
		}


		vector <int> ans(N, N);
		if(N==1)
		{
			ans[0] = 0;
		}
		else
		{

			P tmp[5000];
			for (int i = 1; i < 1<<N; ++i)
			{
				int numVertices = 0;
				int numTmp = 0;
				for(int b=0; b<N;++b)
				{
					if(i>>b & 1)
					{
						numVertices++;
						tmp[numTmp] = base[b];
						numTmp++;
					}
				}

				vector <P> ret = convex_hull(tmp, numTmp);

				for(int b=0; b<N;++b)
				{
					if(i>>b & 1)
					{
						for(int s=0;s<SZ(ret);++s)
						{
							if(on_seg(ret[s], ret[(s+1)%SZ(ret)], base[b]))
							{
								amin(ans[b], N-numTmp);
							}
						}

					}
				}



				// 			for (int t = 0; t < SZ(ret); ++t)
				// 			{
				// 				fprintf(stderr,"%f %f\n",ret[t].x, ret[t].y);
				// 			}
			}
		}








		PRINTF("Case #%d:\n",testcase+1);
		for (int i = 0; i < N; ++i)
		{
			PRINTF("%d\n",ans[i]);
		}
	}

	return 0;
}


#elif 1

int main()
{

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d",&T);

	for (int testcase = 0; testcase < T; testcase++)
	{
		ll B,N;
		cin >> B >> N;
		vector <ll> m(B);
		for (int i = 0; i < B; ++i)
		{
			cin >> m[i];
		}

		ll lo = 0;
		ll hi = (ll)1e15;

		while(lo<hi)
		{
			ll mid = lo+(hi-lo)/2LL;

			ll num = 0;
			for (int i = 0; i < B; ++i)
			{
				num += mid/m[i];
//				if(mid%m[i]==0LL)
				{
					num++;
				}

			}

			if(num>=N)
			{
				hi=mid;
			}
			else
			{
				lo=mid+1;
			}
		}

		int ans = 0;

//		fprintf(stderr,"lo=%lld\n",lo);

		for (int i = 0; i < B; ++i)
		{
			N -= (lo+m[i]-1)/m[i];
//			fprintf(stderr,"N=%lld\n",N);
		}
		for (int i = 0; i < B; ++i)
		{
			if(lo%m[i]==0LL)
			{
				if(N==1)
				{
					ans = i+1;
					break;
				}
				else
				{
					N--;
				}
			}
		}

		PRINTF("Case #%d: %d\n",testcase+1, ans);
	}

	return 0;
}



#else

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d",&T);

	for (int testcase = 0; testcase < T; testcase++)
	{
		int N;
		cin >> N;
		vector <ll> m(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> m[i];
		}

		ll ret1 = 0, ret2 = 0;
		{
			for (int i = 0; i < N-1; ++i)
			{
				ret1 += max(0LL,m[i]-m[i+1]);
			}
		}

		{
			ll waste = 0;
			for (int i = 0; i < N-1; ++i)
			{
				amax(waste,max(0LL,m[i]-m[i+1]));
			}

			for (int i = 0; i < N-1; ++i)
			{
				ret2 += min(waste,m[i]);
			}
		}


		



		PRINTF("Case #%d: %lld %lld\n",testcase+1, ret1, ret2);
	}

	return 0;
}

#endif