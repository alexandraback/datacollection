#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()

template<class P, class Q> inline void mmin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void mmax(P &a, Q b) { if (a < b) a = b; }

typedef long long LL;
typedef pair<int, int> pii;

const int MAXn = 100 + 5;
int n;
string s[MAXn], ss;
int ar[MAXn][MAXn];

inline bool solve(int &ret)
{
	for(int i=0; i<n; ++i) {
		string t = s[i];
		t.resize(unique(t.begin(), t.end())-t.begin());
		if(t != ss)
			return false;
		int ind = 0;
//		cerr << "HER " << ss << endl;
		rep(j, Size(ss)) {
			ar[j][i] = 0;
			while(s[i][ind]==ss[j]) {
				++ind;
				++ar[j][i];
			}
//			cerr << j << ' ' << i << ' ' << ar[j][i] << endl;
		}
	}

	ret = 0;
	rep(i, Size(ss)) {
		sort(ar[i], ar[i]+n);
		int sum = 0;
		rep(j, n)
			sum += ar[i][j];
/*		cerr << "SALAM : ";
		rep(j, n)
			cerr << ar[i][j] << ' ';
		cerr << endl;*/
		int cur = sum-ar[i][0]*n;
		int mn = cur;
	//	cerr << cur << endl;
		for(int j=1; j<n; ++j) {
			cur += (2*j-n)*(ar[i][j]-ar[i][j-1]);
//			cerr << "HP " << i << ' ' << j << ' ' << cur << endl;
			mmin(mn, cur);
		}
//		cerr << "PL " << cur << endl;
		ret += mn;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int nt;
	cin >> nt;
//	nt = 1;
	for(int ii=1; ii<=nt; ++ii) {
		cin >> n;
		rep(i, n)
			cin >> s[i];
		ss = s[0];
		
		ss.resize(unique(ss.begin(), ss.end())-ss.begin());

		for(int i=0; i<=n; ++i) {
			string t = s[i];
			t.resize(unique(t.begin(), t.end())-t.begin());

		}
		cout << "Case " << "#" << ii << ": ";
		int ans;
		if(solve(ans))
			cout << ans << endl;
		else
			cout << "Fegla Won" << endl;
	}

	return 0;
}
