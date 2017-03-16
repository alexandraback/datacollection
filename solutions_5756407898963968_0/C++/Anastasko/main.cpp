//#pragma comment(linker, "/STACK:134217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define MOD 1000000009
#define INF 1000000007
#define y1 agaga
#define ll long long
#define ull unsigned long long

int is[16];
int n, r;
int a[4][4];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	n = 4;

	int t;
	cin >> t;

	FOR(T,0,t)
	{

		cin >> r;

		FOR(i, 0, n)
			FOR(j, 0, n)
			{
				cin >> a[i][j];
				is[i*n + j] = 0;
			}

		FOR(j, 0, n)
			is[a[r - 1][j]-1]++;

		cin >> r;

		FOR(i, 0, n)
			FOR(j, 0, n)
			{
				cin >> a[i][j];
			}

		FOR(j, 0, n)
			is[a[r - 1][j]-1]++;

		int k = 0;
		int sol;

		FOR(i, 0, 16)
		if (is[i]==2)
		{
			sol = i + 1;
			k++;
		}

		cout << "Case #" << T+1 << ": ";

		if (k == 0)
			cout << "Volunteer cheated!" << endl;
		if (k > 1)
			cout << "Bad magician!" << endl;
		if (k == 1)
			cout << sol << endl;
	}

	return 0;
}
