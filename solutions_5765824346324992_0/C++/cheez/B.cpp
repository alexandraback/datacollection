#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi > vvi; 
typedef pair<int,int> ii; 
typedef vector<ii > vii;
typedef vector<vii > vvii;
typedef set<ii > sii;

#define pb(x) push_back(x)
#define all(c) (c).begin(),(c).end()
#define ins(c) inserter((c),(c).begin())
#define mp(x,y) make_pair((x),(y))
#define mt(x,y,z) make_tuple((x),(y),(z))
#define INF (1e9)

ostream& operator<<(ostream& out, vi v)
{
    for (auto a: v)
        out << a << " ";
    return out;
}

ostream& operator<<(ostream& out, ii d)
{
    out << d.first << ", " << d.second << " ";

    return out;
}

ostream& operator<<(ostream& out, set<ii> S)
{
	for (auto a: S)
		out << "(" << a.first << ", " << a.second << ") ";
	return out;
}

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int solve(vi &v, int m)
{
	int n = v.size();
	set<ii> S;
	set<ii> S1;
	for (int i = 0; i < n; i++) {
		S.insert(mp(0, i));
	}
	// cout << "S " << S << endl;
	int count = 0;

	while (!S.empty()) {
		int last = 0;
		int min_v = S.begin()->first;
		for (auto a: S)
			S1.insert(mp(a.first - min_v, a.second));
		S.clear();
		for (auto a: S1) {
			S.insert(a);
		}
		S1.clear();

		// cout << "S++" << S << endl;
		auto top = *S.begin();
		S.erase(S.begin());
		int x = top.second;
		S.insert(mp(v[x],x));
		// cout << "S--" << S << endl;
		if (++count == m)
			return x + 1;
		last = x;
	}

	return 0;
}

int get_count(vi &v)
{
	int d = 1;
	for (auto a: v)
		d = lcm(a, d);
	int ans = 0;
	for (auto a: v)
		ans += d / a;
	return ans;
}


int main()
{
	int T, casn = 0;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vi v(n);
		for (auto &a: v) {
			cin >> a;
		}
		int cnt = get_count(v);
		m = m % cnt;
		if (!m)
			m = cnt;
		int ans = solve(v, m);
		cout << "Case #" << ++casn << ": " << ans << endl;
	}
	return 0;
}
