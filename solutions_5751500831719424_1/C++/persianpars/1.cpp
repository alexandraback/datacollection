// written by Amirmohsen Ahanchi //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
#include <complex>
#include <cassert>

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Size(n) ((int)(n).size())
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define dbg(x) "#" << #x << ": " << x 
#define spc << " " <<

using namespace std;

//#define cin fin
//#define cout fout

typedef long long LL;
typedef pair <int, int> PII; 

const int maxN = 100 + 5;

string uq[maxN], s[maxN];
int a[maxN][maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i], uq[i] = s[i]; 
		for (int i = 0; i < n; i++)
			uq[i].resize(unique(all(uq[i])) - uq[i].begin());
		bool flag = false;
		for (int i = 0; i < n-1; i++)
			if (uq[i] != uq[i+1])
			{
				flag = true;
				break;
			}
		cout << "Case #" << t+1 << ": ";
		if (flag)
		{
			cout << "Fegla Won" << endl;
			continue;
		}
		int m = Size(uq[0]);
		for (int i = 0; i < n; i++)
		{
			int cnt = 0, ind = 0;
			for (int j = 0; j < Size(s[i]); j++)
			{
				cnt++;
				if (s[i][j] != s[i][j+1] || j == Size(s[i]))  
				{
					a[ind++][i] = cnt;
					cnt = 0;
				}
			}
		}
		int ans = 0;
		for (int j = 0; j < m; j++)
		{
			sort(a[j], a[j] + n);
			for (int i = 0; i < n; i++)
				ans += abs(a[j][i] - a[j][n/2]);
		}
		cout << ans << endl;
	}
	return 0;
}

