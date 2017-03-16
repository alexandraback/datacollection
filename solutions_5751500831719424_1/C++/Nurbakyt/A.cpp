#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#define _USE_MATH_DEFINES
#define ll long long 
#define ull unsigned long long  
#define fname ""
const int N = 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;

using namespace std;

int tt, n;
string a[N], b[N];
int d[N][N], ans, t[N];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> tt;
	for (int test = 1;test <= tt;test ++)
	{
		cin >> n;
		memset(d, 0, sizeof d);
		ans = 0;
		for (int i = 1;i <= n;i ++)
		{
			cin >> a[i];
			b[i] = "";
			for (int j = 0;j < sz(a[i]);j ++)
			{
				if (b[i] == "" || a[i][j] != b[i][sz(b[i]) - 1])
					b[i] += a[i][j],
					d[i][sz(b[i]) - 1] = 1;
				else
					d[i][sz(b[i]) - 1] ++;
			}	
			if (i > 1 && b[i] != b[i - 1])
			{
				cout << "Case #" << test << ": Fegla Won\n";
				goto qwe;
			}
		}
		for (int i = 0;i < sz(b[1]);i ++)
		{
			t[0] = 0;
			for (int j = 1;j <= n;j ++)	
				t[++ t[0]] = d[j][i];
			int mini = inf;
			for (int j = 1;j <= t[0];j ++)
			{
			    int cur = 0;
				for (int k = 1;k <= t[0];k ++)
					cur += abs(t[k] - t[j]);
				mini = min(cur, mini);
			}
			ans += mini;		
		}
		cout << "Case #" << test << ": " << ans << endl;
		qwe:;
	}
	return 0;
}
