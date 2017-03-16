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

int solve0(vi& v)
{
	int ans = 0;
	int n = v.size();
	for (int i = 1; i < n; i++) {
		ans += max(0, v[i-1] - v[i]);
	}
	return ans;
}

int solve1(vi &v)
{
	int m = 0;
	int n = v.size();
	for (int i = 1; i < n; i++) {
		if (v[i-1] > v[i])
			m = max(m, v[i-1] - v[i]);
	}
	// cout << "m " << m << endl;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int d = v[i-1];
		ans += min(d, m);
		// cout << "i " << i << " ans " << ans << endl;
	}
	return ans;
}

int main()
{
	int T, casn = 0;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vi v(n);
		for (auto &a: v)
			cin >> a;
		// cout << "v " << v << endl;
		int ans0 = solve0(v);
		int ans1 = solve1(v);
		
		cout << "Case #" << ++casn << ": " << ans0 << " " << ans1 << endl;
	}
	return 0;
}
