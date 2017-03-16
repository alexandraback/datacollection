#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 110

vector<int> p[MAXN];
vector<pair<char, int> > v[MAXN];
string s[MAXN];
int t, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> n;
		cout << "Case #" << tt << ": ";
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
			cin >> s[i];
			s[i] += '#';
		}
		long long ans = (long long)INF * (long long)1000;
		for (int i = 1; i <= n; i++)
		{
			int last = -1;
			for (int j = 0; j <= SZ(s[i]) - 2; j++)
				if (s[i][j] != s[i][j + 1])
				{
					v[i].pb({s[i][j], j - last});
					last = j;
				}
		}
		for (int i = 1; i <= n; i++)
		{
			if (SZ(v[i]) != SZ(v[1]))
			{
				ans = -1;
				break;
			}
			for (int j = 0; j < SZ(v[i]); j++)
				if (v[i][j].first != v[1][j].first)
				{
					ans = -1;
					i = n + 1;
				}
		}
		if (ans == -1)
			cout << "Fegla Won" << endl;
		else
		{
			for (int i = 0; i < SZ(v[1]) + 1; i++)
				p[i].clear();
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < SZ(v[i]); j++)
					p[j].pb(v[i][j].second);
			for (int i = 0; i < SZ(v[1]) + 1; i++)
				sort(ALL(p[i]));
			ans = 0;
			for (int j = 0; j < SZ(v[1]); j++)
				for (int i = 1; i <= n; i++)
					ans += (long long)abs(v[i][j].second - p[j][n / 2]);
			cout << ans << endl;
		}
	}
	return 0;
}