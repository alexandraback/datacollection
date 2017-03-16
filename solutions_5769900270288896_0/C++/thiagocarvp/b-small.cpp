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

int t,r,c,n,ans;
int pd[1<<16][16];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int qtd(int mask, int a, int b)
{
	int v[r][c], x, y, ans = 0;
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			x = i*c + j;
			v[i][j] = (1<<x)&mask;
		}
	}
	for(int i = 0; i < 4; ++i)
	{
		x = a+dx[i];
		y = b+dy[i];
		if(x >= 0 && x < r && y >= 0 && y < c && v[x][y]) ans++;
	}
	return ans;
}

int f(int mask, int rest)
{
	if(rest==0) return 0;

	int &p = pd[mask][rest];
	if(p == inf)
	{
		for(int i = 0; i < r*c; ++i)
		{
			if(((1<<i)&(mask)) == 0)
			{
				p = min(p, qtd(mask, i/c, i%c)+f((1<<i)|mask, rest-1));
			}
		}
	}
	return p;
}

int main()
{
	int teste = 1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &r, &c, &n);
		ans = 0;

		memset(pd, inf, sizeof pd);
		ans = f(0, n);

		printf("Case #%d: %d\n", teste++, ans);
	}

	return 0;
}