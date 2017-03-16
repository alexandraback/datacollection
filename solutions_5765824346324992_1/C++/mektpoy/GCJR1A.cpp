#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

const int maxn = 100100;
int a[maxn], T, n, m;

bool solve (long long t)
{
	long long now = 0;
	for (int i=1; i<=n; i++) now += t/a[i]+1;
	if (now < m) return false;
	return true;
}

struct node
{
	int t, id;
	bool operator < (const node &a) const { return t < a.t || t == a.t && id > a.id; }
}A[maxn];

int main()
{
  freopen("text.in","r",stdin);
  freopen("text.out","w",stdout);
  cin >> T;
  for (int t=1; t<=T; t++)
  	{
			scanf ("%d%d", &n, &m);
			for (int i=1; i<=n; i++)
				scanf ("%d", &a[i]);
			long long L = 0, R = 100000000000000LL;
			while (R-L > 1)	
				{
					long long mid = (L+R)/2;
					if (solve (mid)) R = mid; else L = mid+1;
				}
			if (!solve (L) && solve (R)) L = R;
			long long now = 0, tot = 0;
			for (int i=1; i<=n; i++)
				{
					now += L/a[i]+1;
					A[++tot].t = L%a[i], A[tot].id = i;
				}
			sort (A+1, A+tot+1);
			printf ("Case #%d: %d\n", t, A[now-m+1].id);
		}
	return 0;
}

