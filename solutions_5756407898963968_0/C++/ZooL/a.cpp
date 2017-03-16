#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"


int main()
{
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin);  freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	int a[4][4], b[4][4];

	for (int q = 0; q < T; q++)
	{
		int pos;
		scanf("%d", &pos);
		pos--;
		set<int> card;
		for (int i = 0; i < 4; i++)
			for (int k = 0; k < 4; k++)
			{
				scanf("%d", &a[i][k]);
				if (i == pos)
				{
					card.insert(a[i][k]);
				}
			}

		scanf("%d", &pos);
		pos--;
		set<int> ans;
		for (int i = 0; i < 4; i++)
			for (int k = 0; k < 4; k++)
			{
				scanf("%d", &b[i][k]);
				if (i == pos && card.count(b[i][k]))
				{
					ans.insert(b[i][k]);
				}
			}

		cout << "Case #" << q + 1 << ": ";
		if (ans.size() == 1)
		{
			cout << *ans.begin() << endl;
		}
		if (ans.size() == 0)
		{
			cout << "Volunteer cheated!" << endl;
		}
		if (ans.size() > 1)
		{
			cout << "Bad magician!" << endl;
		}
	}
    return 0;
}
/*******************************************
*******************************************/
