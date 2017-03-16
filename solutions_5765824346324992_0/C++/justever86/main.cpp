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

#define TEST_LOCAL 1

long long a[1005];

int main()
{
	freopen("data.in","r",stdin);
#if TEST_LOCAL
	freopen("data.out","w",stdout);
#endif

	int T;
	scanf("%d",&T);

	for (int K = 1;K <= T;K++)
	{
		long long n,m;
		scanf("%I64d %I64d",&n,&m);
		long long temp = 0;
		REP(i,n)
		{
			scanf("%I64d",&a[i]);
			temp = max(temp,a[i]);
		}

		long long res = -1;
		long long t = temp;
		long long left = 0;
		long long right = temp * (m);
		while(left <= right)
		{
			long long mid = (left + right) / 2;
			long long t0 = 0;
			long long t1 = 0;
			REP(i,n)
			{
				t0 += mid / a[i];
				t1 += mid / a[i];
				if (mid % a[i] == 0)
				{
					t1 += 1;
				}
				else
				{
					t0++;
					t1++;
				}
			}

			if (t0 >= m)
			{
				right = mid - 1;
			}
			else if (t1 < m)
			{
				left = mid + 1;
			}
			else
			{
				long long cnt = m - t0;
				REP(i,n)
				{
					if (mid % a[i] == 0)
					{
						cnt--;
						if (cnt == 0)
						{
							res = i;
							break;
						}
					}
				}
				break;
			}
		}

		printf("Case #%d: ",K);
		printf("%d\n",res + 1);
	}


	return 0;
}
