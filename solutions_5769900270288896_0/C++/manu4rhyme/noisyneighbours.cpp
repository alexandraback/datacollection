#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ABS(x) ((x) < 0 ? -1*(x) : (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define mp make_pair
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int countbits(int n)
{
	int c = 0;
	while(n)
	{
		if(n & 1) ++c;
		n >>= 1;
	}

	return c;
}

int grid[20][20];
int counted[20][20];

int main()
{
	int T,R,C,N,i,z,tot,n,j,k,tj,tk,count,ans;
	scanf("%d",&T);
	for(z = 1; z <= T; ++z)
	{
		scanf("%d", &R);
		scanf("%d", &C);
		scanf("%d", &N);

		tot = 1 << (R*C);
		//printf("%d\n", tot);

		ans = 1000000;
		for(i = 0; i < tot; ++i)
		{
			if(countbits(i) != N) continue;
			//printf("Entered at %d\n", i);
			n = i;
			k = 0;

			for(j = 0; j <= R; ++j)
				for(k = 0; k <= C; ++k)
				{
					grid[j][k] = 0;
					counted[j][k] = 0;
				}

			k = 0;
			while(n)
			{
				if(n & 1)
					grid[k/C][k%C] = 1;

				++k;
				n >>= 1;
			}

			/*for(j = 0; j < R; ++j)
			{
				for(k = 0; k < C; ++k)
					printf("%d ", grid[j][k]);

				printf("\n");
			}*/

			count = 0;

			for(j = 0; j < R; ++j)
			{
				for(k = 0; k < C; ++k)
				{
					if(!grid[j][k]) continue;

					tj = j-1;
					tk = k;
					if(tj >= 0 && !counted[tj][tk])
						if(grid[tj][tk]) ++count;
					tj = j+1;
					tk = k;
					if(tj < R && !counted[tj][tk])
						if(grid[tj][tk]) ++count;
					tj = j;
					tk = k+1;
					if(tk < C && !counted[tj][tk])
						if(grid[tj][tk]) ++count;
					tj = j;
					tk = k-1;
					if(tk >= 0 && !counted[tj][tk])
						if(grid[tj][tk]) ++count;

					counted[j][k] = 1;
				}
			}
			//printf("%d\n", count);
			if(count < ans) ans = count;
		}

		printf("Case #%d: %d\n",z, ans);
	}

	return 0;
}