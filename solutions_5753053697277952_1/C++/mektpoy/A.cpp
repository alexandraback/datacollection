#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair
#define sc second
#define ft first

#define FOR(i,N) for (int i=1; i<=N; i++)
#define REP(i,l,r) for (int i=l; i<=r; i++)

#define INF ~0U>>1
#define eps 1e-9

int T;
int a[3000];
vector <string> ans;

int main ()
{
#ifndef ONLINE_JUDGE
#ifndef MEKTPOY
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
#else
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
#endif
	cin >> T;
	for (int test = 1; test <= T; test ++)
	{
		int n;
		cin >> n;
		vector <string> ans;
		for (int i = 1; i <= n; i ++)
			scanf ("%d", &a[i]);
		while (true)
		{
			int MAX = a[1], cnt = 0, j = 1, k = -1;
			for (int i = 1; i <= n; i ++)
			{
				if (a[i] == 1) cnt ++;
				if (a[i] >= MAX) MAX = a[i], k = j, j = i;
			}
			if (MAX == 0) break;
			else if (k == -1 || MAX == 1 && cnt == 3)
			{
				a[j] --;
				string s;
				s += 'A' + j - 1;
				ans.pb (s);
			}
			else if (MAX > 1 || MAX == 1 && cnt != 3)
			{
				string s;
				s += 'A' + j - 1;
				s += 'A' + k - 1;
				a[j] --;
				a[k] --;
				ans.pb (s);
			}
		}
		printf ("Case #%d: ", test);
		for (auto k : ans)
		{
			cout << k << " ";
		}
		puts("");
	}
	return 0;
}

