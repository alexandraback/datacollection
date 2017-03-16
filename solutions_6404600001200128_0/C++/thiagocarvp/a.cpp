#include <bits/stdc++.h>

#define maxn 1010
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

int t, n, v[maxn], ans1, ans2, last, teste = 1, qtd, aux;
bool ok;

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		ans1 = last = 0;
		ans2 = inf;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i]);
			if(last > v[i])
			{
				ans1 += last-v[i];
			}
			last = v[i];
		}

		for(int i = 0; i <= 10000; i++)
		{
			aux = min(i, v[0]);
			qtd = v[0]-i;
			ok = true;
			for(int j = 1; j < n; ++j)
			{
				qtd = max(qtd, 0);
				if(v[j] < qtd)
				{
					ok = false;
					break;
				}
				if(j == n-1) break;
				qtd = v[j]-i;
				aux += min(i, v[j]);
			}
			if(ok)
			{
				ans2 = min(aux, ans2);
				break;
			}
		}

		printf("Case #%d: %d %d\n", teste++, ans1, ans2);
	}

	return 0;
}