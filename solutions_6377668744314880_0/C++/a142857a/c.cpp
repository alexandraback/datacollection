#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 3005;
const double PI = 3.1415926535897932394626;
//const double eps = 1e-10;
int n;
#define cin fin
#define cout fout
ifstream fin("a.in");
ofstream fout("a.out");

long long x[MAXN], y[MAXN];
struct DATA
{
	double ang;
	int i;
}a[MAXN * 4];

inline int cmp(const DATA &a, const DATA &b)
{
	return a.ang < b.ang;
}

int solve(int p)
{
	for(int i = 1; i <= n; i++)
	if(i != p)
	{
		int t = i;
		if(i > p) t--;
		a[t].ang = atan2(y[i] - y[p], x[i] - x[p]);
		a[t].i = i;
	}
	sort(a + 1, a + n, cmp);
	for(int i = n; i <= 2 * n - 2; i++)
	a[i] = a[i - n + 1];
	int ans = 100000;
	int cur = 1;
	for(int i = 1; i < n; i++)
	{
		if(cur < i)
			cur = i;
		while(cur + 1 < i + n - 1)
		{
			if((x[p] - x[a[i].i]) * (y[p] - y[a[cur + 1].i]) - (y[p] - y[a[i].i]) * (x[p] - x[a[cur + 1].i]) > 0)
				cur++;
			else
				break;
		}
		if(cur - i < ans) ans = cur - i;
	}
	if(n == 1)
		return 0;
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> x[i] >> y[i];
		cout << "Case #" << test << ": " <<endl;
		for(int i = 1; i <= n; i++)
		{
			cout << solve(i) << endl;
		}
	}
	
	return 0;
}
/*
2
5
0 0
10 0
10 10
0 10
5 5
9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10
*/

