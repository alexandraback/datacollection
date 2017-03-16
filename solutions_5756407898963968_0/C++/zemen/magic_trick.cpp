#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "magic_trick"

int a[4][4];
int b[4][4];
char ok[17];

void solve(int test) {
	int i1, i2;
	cin >> i1;
	memset(ok, 0, sizeof(ok));
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			cin >> a[i][j];
			if (i + 1 == i1)
				ok[a[i][j]] = 1;
		}
	cin >> i2;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			cin >> b[i][j];
			if (i + 1 != i2)
				ok[b[i][j]] = 0;
		}
	int res = -1, sum = 0;
	for (int i = 1; i <= 16; ++i) {
		sum += ok[i];
		if (ok[i])
			res = i;
	}
	cout << "Case #" << test << ": ";
	if (sum == 0)
		cout << "Volunteer cheated!\n";
	else if (sum >= 2)
		cout << "Bad magician!\n";
	else
		cout << res << '\n';
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int tn;
	cin >> tn;
	for (int i = 0; i < tn; ++i)
		solve(i + 1);
}
