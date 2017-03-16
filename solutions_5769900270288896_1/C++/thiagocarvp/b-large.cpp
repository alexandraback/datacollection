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

int t,r,c,n,ans,ans2;
int v[10010], tam;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void pre()
{
	tam = 0;
	int aux, x, y;
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			if((i&1) == 0 && (j&1) == 0)
			{
				n--;
				continue;
			}
			else if((i&1) != 0 && (j&1) != 0)
			{
				n--;
				continue;
			}
			aux = 0;
			for(int k = 0; k < 4; ++k)
			{
				x = i+dx[k];
				y = j+dy[k];
				if(x >= 0 && x < r && y >= 0 && y < c)
				{
					aux++;
				}
			}
			v[tam++] = aux;
		}
	}
	sort(v, v+tam);
}

void pre2()
{
	tam = 0;
	int aux, x, y;
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			if((i&1) == 0 && (j&1) != 0)
			{
				n--;
				continue;
			}
			else if((i&1) != 0 && (j&1) == 0)
			{
				n--;
				continue;
			}
			aux = 0;
			for(int k = 0; k < 4; ++k)
			{
				x = i+dx[k];
				y = j+dy[k];
				if(x >= 0 && x < r && y >= 0 && y < c)
				{
					aux++;
				}
			}
			v[tam++] = aux;
		}
	}
	sort(v, v+tam);
}

int main()
{
	int teste = 1, aux;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &r, &c, &n);
		ans = ans2 = 0;
		aux = n;
		pre();
		for(int i = 0; i < tam && n > 0; i++, n--)
		{
			ans += v[i];
		}

		n = aux;
		pre2();
		for(int i = 0; i < tam && n > 0; i++, n--)
		{
			ans2 += v[i];
		}
		printf("Case #%d: %d\n", teste++, min(ans, ans2));
	}

	return 0;
}