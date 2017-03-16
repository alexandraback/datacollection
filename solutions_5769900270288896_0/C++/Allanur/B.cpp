#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define sz(c) (int)c.size()
#define ln(c) (int)c.length()
#define all(c) (c).begin(), (c).end()
#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

using namespace std;
typedef long long lld;
const int MAXN = 200009;
typedef pair<int,int> pii;

int t, r, c, n, m, ans;
bool v[19][19], f[19];

void rec(int x, int y)
{
	if (x==m)
	{
		if (y!=n)
			return;
		
		int tmp = 0, hness = 0;
		
		for (int i=0; i<r; i++)
			for (int h=0; h<c; h++)
				v[i][h] = f[tmp++];
		
		for (int i=0; i<r; i++)
			for (int h=0; h<c; h++) {
				if (v[i][h] && i+1<r)	hness += v[i+1][h];
				if (v[i][h] && h+1<c)	hness += v[i][h+1];
			}
		
		ans = min(ans, hness);
		
		return;
	}
	
	for (int i=0; i<2; i++)
		f[x] = i, rec(x+1, y+i);
}

int main ()
{	
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	
	scanf("%d" ,&t);
	
	for (int q=1; q<=t; q++)
	{
		ans = INT_MAX;
		
		scanf("%d %d %d" ,&r ,&c ,&n);
		
		m = r*c;
		rec(0,0);
		
		printf("Case #%d: %d\n" ,q ,ans);
	}
}
