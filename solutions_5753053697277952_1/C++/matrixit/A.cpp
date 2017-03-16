#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi = acos(-1.0);
const double eps = 1e-11;
template<class T> inline void checkmin(T &a, T b) { if (b<a) a = b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a = b; }
template<class T> inline T sqr(T x) { return x*x; }
typedef pair<int, int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

#define MAX 30
int N;
int P[MAX];

int maxidx(bool &onlyone) {
	int pos = 0;
	onlyone = true;
	for (int i = 1; i < N; ++i) {
		if (P[i] > P[pos]) {
			pos = i;
			onlyone = true;
		}
		else if (P[i] == P[pos]) {
			pos = i;
			onlyone = false;
		}
	}
	return pos;
}

int main() {
	std::ios::sync_with_stdio(false);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		memset(P, 0, sizeof(P));
		for (int i = 0; i < N; ++i) {
			cin >> P[i];
		}
		cout << "Case #" << t << ":";
		bool onlyone;
		int n = N;
		for (; n; ) {
			int idx = maxidx(onlyone);
			if (onlyone) {
				cout << ' ' << (char)('A' + idx);
				if (--P[idx] == 0) {
					n--;
				}
			}
			else {
				if (n == 2) {
					int a[2];
					int aidx = 0;
					for (int i = 0; i < N; ++i) {
						if (P[i]) {
							a[aidx++] = i;
						}
					}
					P[a[0]]--;
					P[a[1]]--;
					if (P[a[0]] == 0) n--;
					if (P[a[1]] == 0) n--;

					cout << ' ' << (char)('A' + a[0]) << (char)('A' + a[1]);
				}
				else {
					int cnt = 2;
					for (int i = 0; i < N; ++i) {
						if (P[i] == 0 || P[i] == P[idx] && cnt--) continue;
						for (; P[i]; --P[i]) {
							cout << ' ' << (char)('A' + i);
						}
						n--;
					}
				}
			}
		}
		cout << endl;
		
	}
	return 0;
}

