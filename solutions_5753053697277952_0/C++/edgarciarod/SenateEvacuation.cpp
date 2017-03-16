#include <bits/stdc++.h>
using namespace std;
//look at my code my code is amazing
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FOREACH(it, a) for (typeof(a.begin()) it = (a).begin(); it != (a).end(); it++)
#define ROF(i, a, b) for (int i = int(a); i >= int(b); i--)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define ALL(x) x.begin(), x.end()
#define MP(a, b) make_pair((a), (b))
#define X first
#define Y second
#define EPS 1e-9
#define DEBUG(x)   cerr << #x << ": " << x << " "
#define DEBUGLN(x) cerr << #x << ": " << x << " \n"
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<bool> vb;
//ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
//cin.tie(NULL); cout.tie(NULL);

ii v[30];

void solve()
{
	static int caso = 0;
	int n;

	cin >> n;

	REP(i, n)
	{
		cin >> v[i].X;
		v[i].Y = i;
	}

	sort(v, v+n);

	cout << "Case #" << ++caso << ":";

	int delta_last = v[n-1].X - v[n-2].X;
	v[n-1].X = v[n-2].X;
	REP(i, delta_last)
	{
		cout << " " << (char)(v[n-1].Y + 'A');
	}

	REP(i, n-2)
	{
		REP(j, v[i].X)
		{
			cout << " " << (char)('A'+v[i].Y);
		}
	}

	REP(i, v[n-1].X)
	{
		cout << " " << (char)(v[n-1].Y + 'A') << (char)(v[n-2].Y + 'A');
	}

	cout << '\n';
}

int main()
{
	int T;

	cin >> T;

	REP(i, T)
		solve();

	return 0;
}