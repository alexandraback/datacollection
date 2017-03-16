#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <valarray>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cassert>
#include <bitset>

#define show(x) cerr << "# " << #x << " = " << (x) << endl

#define FR(i, a, b) for(__typeof(a) i = a; i != b; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOREACH(i, t) FR(i, t.begin(), t.end())
#define SZ(x) ((int) (x).size())
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef complex<double> point;

template<class T> ostream& operator << (ostream &o, const vector<T> &t)	
{
	o << "[" << SZ(t);
	int f = 0;
	FOREACH(i, t)
		o << (f++ ? ", " : ": ") << (*i);
	return o << "]";
}

template<class T1, class T2> ostream& operator << (ostream &o, const pair<T1, T2> &p)
{
	return o << "(" << p.F << ", " << p.S << ")";
}

#define ABS(x) (((x)>0)?(x):(-(x)))

vector<vector<int> > ps;
vector<string> us;

void parse(string w)
{
	string u = "$";
	vector<int> v;
	FOR(i, SZ(w))
	{
		if(w[i] != u[SZ(u) - 1])
		{
			u += w[i];
			v.PB(1);
		}
		else
			v.back()++;
	}
	ps.PB(v);
	us.PB(u);
}

int main()
{
	parse("hellooo");
	int TC;
	cin >> TC;
	FOR(T, TC)
	{
		cout << "Case #" << T + 1 << ": ";

		ps.clear();
		us.clear();
		int n;
		cin >> n;
		FOR(i, n)
		{
			string w;
			cin >> w;
			parse(w);
		}
		us.erase(unique(us.begin(), us.end()), us.end());

		if(SZ(us) != 1)
		{
			cout << "Fegla Won" << endl;
			continue ;
		}
		
		int ans = 0;
		FOR(i, SZ(ps[0]))
		{
			vector<int> v;
			FOR(j, SZ(ps))
				v.PB(ps[j][i]);
			sort(v.begin(), v.end());
			int q = v[SZ(v) / 2];
			FOR(j, SZ(v))
				ans += ABS(v[j] - q);
		}
		cout << ans << endl;
	}
	return 0;
}
