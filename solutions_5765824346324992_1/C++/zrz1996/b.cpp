#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef long long LL;
#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Cor(i,a,b) for (int i = (a); i >= (b); i--)
#define Fill(a,b) memset(a,b,sizeof(a))
const int maxn = 1010;
int a[maxn], n, m;
bool check(LL x)
{
	LL res = 0;
	For(i, 0, n - 1)
	{
		res += x / a[i];
		if (x % a[i] != 0)
			res++;
	}
	if (res >= m - 1)
		return 1;
	else
		return 0;
}
struct node
{
	int t, id;
}V[maxn];
bool cmp(const node &a, const node &b)
{
	return a.t < b.t || (a.t == b.t && a.id > b.id); 
}
void solve(LL x)
{
	for (int i = 0; i < n; i++)
	{
		m -= x / a[i];
		if (x % a[i] != 0)
			m--;
	}
	if (m > 0)
	{
		int mint = 1e9, pos = 0;
		for (int i = 0; i < n; i++)
		{
			a[i] = (a[i] - (x % a[i])) % a[i];
			if (a[i] < mint)
			{
				mint = a[i];
				pos = i + 1;
			}
		}
		cout << pos << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			V[i].t = x % a[i], V[i].id = i + 1;
			if (V[i].t == 0)
				V[i].t = a[i];
		}
		sort(V, V + n, cmp);
		for (int i = 0; i < n; i++)
		{
			m++;
			if (m > 0)
			{
				cout << V[i].id << endl;
				return;
			}
		}
		cout << V[n - 1].id << endl;
	}
}
void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	LL L = 0, R = m;
	R = R * 100000;
	while (L < R)
	{
		LL  mid = (L + R) >> 1;
		if (check(mid))
			R = mid;
		else
			L = mid + 1;
	}
	solve(L);
}
int main()
{
	freopen("t.in", "r", stdin);
	freopen("t.out", "w", stdout);
	int t;
	cin >> t;
	For(i, 1, t)
	{
		printf("Case #%d: ", i);
		init();
	}
	return 0;
}
