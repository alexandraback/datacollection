#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 110001
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

int used[MAXN], d[MAXN];
int uc = 0;
char buf[20];


inline int get(int x) {
	_itoa(x, buf, 10);
	string s = buf;
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;
	forn(ttt, tc) {
		
		int n, m, k;
		int u[55][59];
		cin >> n >> m >> k;
		if (n > m) swap(n, m);
		int cmin = 1000000000;
		
		forn(mask, (1 << (n * m))) {
			int bits = 0;
			forn(y, 55)
			memset(u[y], 0, sizeof u[y]);
			forn(i, n * m) {
				if (mask & (1 << i)) {
					++bits, u[i / m][i % m] = 1;
					//if (i / m == 1)
					//cout << i << " = " << (i / m) << endl;
				}
			}
			if (bits != k)
				continue;
			//cout << (ttt+1) << ": " << mask << " ";
			int cc = 0;
			forn(i, n)
				forn(j, m) {
					if (u[i][j] && u[i + 1][j]){
						++cc;
					//	cout << i << ", " << j << endl;
					}
					if (u[i][j] && u[i][j + 1]) {
						++cc;
					//	cout << i << ", " << j << endl;
					}
				}
			//cout << cc << endl;
			cmin = min(cmin, cc);
		}
		printf("Case #%d: ", ttt + 1);
		printf("%d\n", cmin == 1000000000 ? 0 : cmin);
	}

	/* Solution for A-small
	memset(buf, 0, sizeof buf);
	int tc;
	cin >> tc;
	++uc;
	used[1] = uc;
		d[1] = 1;
		int n = MAXN - 1;
		queue<int> q;
		q.push(1);
		while(used[n] != uc && !q.empty()) {
			int v = q.front();
			q.pop();
			if (v+1 < MAXN && used[v+1] < uc) {
				used[v + 1] = uc;
				q.push(v + 1);
				d[v + 1] = d[v] + 1;
			}
			int u = get(v);
			if (u < MAXN && used[u] < uc) {
				used[u] = uc;
				q.push(u);
				d[u] = d[v] + 1;
			}
		}
	forn(ttt, tc) {
		printf("Case #%d: ", ttt + 1);
		
		cin >> n;
		printf("%d\n", d[n]);
	}
	*/
}