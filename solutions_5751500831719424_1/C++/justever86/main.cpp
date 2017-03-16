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
#include <cstring>
#include <ctime>
#include <queue>

using namespace std;

#define	sqr(a)		((a)*(a))
#define	rep(i,a,b)	for(int i=(a);i<(int)(b);i++)
#define	per(i,a,b)	for(int i=((a)-1);i>=(int)(b);i--)
#define	PER(i,n)	per(i,n,0)
#define	REP(i,n)	rep(i,0,n)
#define	clr(a)		memset((a),0,sizeof (a))
#define	SZ(a)		((int)((a).size()))
#define	ALL(x)		x.begin(),x.end()
#define	mabs(a)		((a)>0?(a):(-(a)))
#define	inf			(0x7fffffff)
#define	eps			1e-6

#define	MAXN		
#define MODN		(1000000007)

typedef long long ll;

int len[105];
int d[105][105];
char e[105][105];

int f(int n)
{
	REP(i,n)
	{
		if (len[i] != len[0])
		{
			return -1;
		}
	}

	int m = len[0];

	REP(i,m)
	{
		REP(j,n)
		{
			if (e[j][i] != e[0][i])
			{
				return -1;
			}
		}
	}
	int res = 0;
	REP(i,m)
	{
		vector<int> v;

		REP(j,n)
		{
			v.push_back(d[j][i]);
		}

		sort(v.begin(),v.end());
		
		int x = v[n / 2];
		REP(j,n)
		{
			res += mabs(d[j][i] - x);
		}
	}

	return res;
}

int main()
{
#if 1
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif

	int CASE;
	scanf("%d",&CASE);

	for (int K = 1;K <= CASE;K++)
	{
		int n;
		scanf("%d",&n);

		REP(i,n)
		{
			char s[105];
			scanf("%s",s);

			int l = strlen(s);
			int temp = 0;
			REP(j,l)
			{
				if (j == 0 || s[j] != s[j - 1])
				{
					d[i][temp] = 1;
					e[i][temp] = s[j];
					temp++;
				}
				else
				{
					d[i][temp - 1]++;
				}
			}

			len[i] = temp;
		}

		int res = f(n);

		printf("Case #%d: ",K);
		if (res == -1)
		{
			puts("Fegla Won");
		}
		else
		{
			printf("%d\n",res);
		}
	}

	return 0;
}
