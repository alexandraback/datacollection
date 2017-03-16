#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>


using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<VVPI> VVVPI;
typedef vector<VVI> VVVI;


#define LOGSZ 17

int t, n, cnt;
string s[128], m[128];
VI v[128], w;

void minify(string s, string &m, VI &v) {
	m = "";
	v.clear();
	char prev = '#';
	int t = 0;
	for (int i = 0; i < sz(s); ++i)
	{
		if(s[i] != prev) {
			v.pb(1);
			m += s[i];
			prev = s[i];
			t++;
		} else {
			v[t-1]++;
		}
	}
}

int main (int argc, char const* argv[])
{
	// ios::sync_with_stdio(false);

	
	cin >> t;
	for (int cs = 1; cs <= t; ++cs)
	{
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
			minify(s[i], m[i], v[i]);
			if(m[i] != m[0]) {
				cnt = -1;
			}
		}

		if(cnt == -1) {
			printf("Case #%d: Fegla Won\n", cs);
		} else {
			int l = sz(m[0]);
			for (int i = 0; i < l; ++i)
			{
				w.clear();
				for (int j = 0; j < n; ++j)
					w.pb(v[j][i]);
				sort(all(w));
				for (int i = 0; i < n; ++i)
					cnt += abs(w[i]-w[n/2]);
			}
			printf("Case #%d: %d\n", cs, cnt);
		}

	}
	
	return 0;
}
