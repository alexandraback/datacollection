#include <bits/stdc++.h>

#define maxn 101000
#define inf 0x3F3F3F3F
#define linf 0x3F3F3F3F3F3F3F3FLL
#define eps 1e-9
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef priority_queue<pii, vii, greater<pii> > pq;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

int n, t, teste = 1;
ll v[maxn];
ll pos, lo, hi, mid, aux, ans;
int x;

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %lld", &n, &pos);
		for(int i = 0; i < n; ++i)
		{
			scanf("%lld", &v[i]);
		}
		if(pos <= n)
		{
			printf("Case #%d: %d\n", teste++, (int)pos);
			continue;
		}
		lo = 0;
		hi = 1000000000000000000LL;
		x = -1;
		while(lo < hi-1)
		{
			mid = (lo+hi)/2;
			aux = 0;
			for(int i = 0; i < n; ++i)
			{
				aux += (mid-1)/v[i]+1;
			}
			if(aux >= pos)
			{
				hi = mid;
				continue;
			}
			for(int i = 0; i < n; ++i)
			{
				if(mid%v[i] == 0) aux++;
				if(aux == pos)
				{
					x = i+1;
					break;
				}
			}
			if(x != -1) break;
			lo = mid;
		}

		printf("Case #%d: %d\n", teste++, x);
	}

	return 0;
}