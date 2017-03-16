#define DEBUG 0

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long long int uLint;
typedef long long int Lint;
typedef short int sint;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<PII,int> PPI;
typedef vector<int> VI;
typedef vector<ld> VD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef queue<int> QI;
typedef queue<PII> QPII;

const int PRIME = 1000 * 1000 * 1000 + 7;
const int MULTIPLIER = 523;
const int INFI = (1 << 30) - 1;
const ld INF = 2 * 1e9 + 1;
const ld EPS = 1e-9;
const ld PI = M_PI;
const int DIM = 2;

#define X coord[0]
#define Y coord[1]

#define VAR(v, n) __typeof(n) v = (n)
#define REP(a, b) for(int a = 0;a < (b);++a)
#define FOR(a, b, c) for(int a = (b);a <= (c);++a)
#define FORD(a, b, c) for(int a = (b);a >= (c);--a)
#define FOREACH(it, s) for(VAR(it, (s).begin());it != (s).end();++it)
#define SIZE(x) (int)(x).size()
#define PB push_back
#define PF push_front
#define MP make_pair
#define NEWLINE cout << "\n";

const Lint MAXN = 1000 * 1000 * 1000;
const Lint MAXM = 100 * 1000;
const int MAXB = 1000;
const Lint RIGHT = MAXN * MAXM;

int tab[MAXB];

void solve(int caseNumber) {
	int b, n;
	cin >> b >> n;

	REP(i, b) {
		cin >> tab[i];
	}

	// cerr << b << " " << n << endl;
	// REP(i, b) {
	// 	cerr << tab[i] << " ";
	// }
	// cerr << endl;

	if (n <= b) {
		cout << n;
		return;
	}

	Lint result;
	bool isRef;
	int order;

	// LONG LONG INT
	Lint left = 1;
	Lint right = RIGHT;

	while (true) {
		Lint mid = (left + right) / 2;
		Lint ref = mid - 1;

		Lint midClient = 0;
		Lint refClient = 0;

		REP(i, b) {
			if (tab[i]) {
				midClient += mid / tab[i] + 1;
				if (ref >= 0) {
					refClient += ref / tab[i] + 1;
				}
			}
		}

		// cout << "mid " << mid << endl;
		// cout << "refClient " << refClient << endl;
		// cout << "midClient " << midClient << endl;

		if (refClient < n && midClient >= n) {
			if (refClient == n) {
				result = ref;
				isRef = true;
			} else {
				result = mid;
				isRef = false;
				order = n - refClient;
			}
			break;
		} else if (midClient < n) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	// cerr << "result " << result << endl;
	// cerr << "isRef " << isRef << endl;
	// cerr << "order " << order << endl;

	VPII barbers;
	REP(i, b) {
		barbers.PB(MP(i + 1, tab[i]));
	}
	sort(barbers.begin(), barbers.end());

	if (isRef) {
		FORD(i, b - 1, 0) {
			int barber = barbers[i].first;
			int btime = barbers[i].second;

			if (result % btime == 0) {
				cout << barber;
				return;
			}
		}
	}

	int number = 0;
	REP(i, b) {
		int barber = barbers[i].first;
		int btime = barbers[i].second;

		if (result % btime == 0) {
			++number;
			if (number >= order) {
				cout << barber;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);

	int numberOfTests;
	cin >> numberOfTests;

	for (int test = 1; test <= numberOfTests; ++test) {
		cout << "Case #" << test << ": ";
		solve(test);
		cout << "\n";
	}

	return 0;
}
