#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vs;

#define SIZE(x) ((int)(x.size()))
#define LET(var, val) auto var = (val)
#define FOR(k, a, b) for(auto k = (a); k < (b); ++k)
#define FORR(k, a, b) for(auto k = (a); k >= (b); --k)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(LET(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PF push_front

const int INF = 1000000001;
const double EPS = 10e-9;
const double PI = acos(-1.0);

ostringstream out;

string str[105];


struct Letter
{
	char letter;
	int count;
};

vector<Letter> v[105];

void A()
{
	int n;
	cin >> n;
	REP(i, n)
	{
		cin >> str[i];
		v[i].clear();
	}
	REP(i, n)
	{
		int c = 1;
		FOR(j, 1, str[i].length() + 1)
		{
			if (j != str[i].length() && str[i][j] == str[i][j - 1])
				c++;
			else
			{
				Letter l;
				l.count = c;
				l.letter = str[i][j - 1];
				v[i].push_back(l);
				c = 1;
			}
		}
	}
	bool f = false;
	int am = 0;
	REP(i, n - 1)
	{
		if (SIZE(v[i]) != SIZE(v[i + 1]))
		{
			f = true;
			break;
		}
	}
	if (f == true)
	{
		out << "Fegla Won\n";
		return;
	}
	REP(i, SIZE(v[0]))
	{
		int avg = v[0][i].count;
		REP(j, n - 1)
		{
			if (v[j][i].letter != v[j + 1][i].letter)
			{
				f = true;
				break;
			}
			avg += v[j + 1][i].count;
		}
		if (f == true)
		{
			out << "Fegla Won\n";
			return;
		}
		avg = (int) (((float) avg / (float) n) + 0.5);
		REP(j, n)
		{
			am += abs(v[j][i].count - avg);
		}
	}
	out << am << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	REP(i, t)
	{
		out << "Case #" << i + 1 << ": ";
		A();
	}

	cout << out.str();
	return 0;
}