/*
 mohamed magdi
 moh_magdi@acm.org
 */

#include <bits/stdc++.h>

#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif

#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<(int)m;i++)
#define REP(i,k,m)      for(int i=k;i<(int)m;i++)
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define X real()
#define Y imag()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef complex<long double> point;

int diri[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dirj[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int compare(double d1, double d2) {
	if (fabs(d1 - d2) < 1e-9)
		return 0;
	if (d1 < d2)
		return -1;
	return 1;
}
#define OO ((int)1e9)
#define MAX 1000001
#define MOD 1000000009

#define SMALL
//#define LARGE

int _N;

string get(string a) {
	a += "-";
	string res = "";
	for (int i = 1; i < (int) a.length(); i++) {
		if (a[i] != a[i - 1])
			res += a[i - 1];
	}
	return res;
}

int solve(string unit, vector<vector<int> > ss) {
//	cerr << unit.size() << " " << ss[0].size() << endl ;
	int ans = 0;
	for (int i = 0; i < (int) unit.size(); i++) {
		int mn = OO;
		for(int l = 1 ; l <= 100 ; l++){
			int c = 0 ;
			for (int word = 0; word < ss.size() ; ++word) {
				c += abs(l - ss[word][i]) ;
			}
			mn = min(mn , c);
		}
		ans += mn ;
	}
	return ans;
}

vector<vector<int> > getS(vector<string> inp) {
	vector<vector<int> > res;
	for (int i = 0; i < (int) inp.size(); ++i) {
		vector<int> in;
		string l = inp[i] + "-";
		int c = 0;
		for (int i = 1; i < l.size(); ++i) {
			c++;
			if (l[i] != l[i - 1]) {
				in.push_back(c);
				c = 0;
			}
		}
		res.pb(in);
	}
//	rep(i,res.size()){
//		rep(j,res[i].size()){
//			cout << res[i][j] << " " ;
//		}
//		cout << endl;
//	}
	return res;
}

int main() {
//	std::ios_base::sync_with_stdio(false);
	freopen("1.in", "rt", stdin);
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
//	scanf("%d", &_N);
	cin >> _N;
	for (int _n = 1; _n <= _N; _n++) {
		cerr << _n << endl ;
		printf("Case #%d: ", _n);
		int n;
		cin >> n;
		vector<string> inp(n);
		set<string> s;
		rep(i,n)
		{
			cin >> inp[i];
			s.insert(get(inp[i]));
		}
		if (s.size() != 1) {
			printf("Fegla Won\n");
		} else {
//			cout << get(inp[0]) << endl ;
			int ans = solve(get(inp[0]), getS(inp));
			printf("%d\n", ans);
		}
	}
	return 0;
}
//end

