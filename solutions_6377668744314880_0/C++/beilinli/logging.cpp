#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define LL long long
#define PII pair <int, int>

LL cross(PII a, PII b, PII c) {
	return 1LL * (a.first - c.first) * (b.second - c.second) - 1LL * (a.second - c.second) * (b.first - c.first);
}

/* from Wikibook\Andrew's Algorithm */
vector <PII> convexHull(vector <PII> p) {
	int n = p.size();
	int cur = 0;

	vector <PII> hull(n + 1);
	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		while (cur >= 2 && cross(hull[cur - 1], p[i], hull[cur - 2]) <= 0) cur--;
		hull[cur++] = p[i];
	}

	int orig = cur + 1;
	for (int i = n - 2; i >= 0; i--) {
		while (cur >= orig && cross(hull[cur - 1], p[i], hull[cur - 2]) <= 0) cur--;
		hull[cur++] = p[i];
	}
	hull.resize(cur);
	return hull;
}

void print(vector <PII> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i].first << ' ' << v[i].second << '\n';
}

bool btw(int c, int a, int b) {
	if (a > b) {
		int tmp = a;
		a = b, b = tmp;
	}
	return (a <= c && c <= b);
}

bool onLine(PII m, PII a, PII b) {
	return (btw(m.first, a.first, b.first) && btw(m.second, a.second, b.second)) && (cross(a, b, m) == 0);
}

int main(void) {
	freopen("C-small-attempt0.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, N;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		int tx, ty;
		vector <PII> p;
		for (int i = 0; i < N; i++) {
			cin >> tx >> ty;
			p.push_back(make_pair(tx, ty));
		}

		printf("Case #%d:\n", t);
		for (int i = 0; i < N; i++) {
			int maxs = 0;

			for (int mask = 1; mask < (1 << N); mask++) {
				vector <PII> ptmp;
				for (int j = 0; j < N; j++) {
					if (mask & (1 << j))
						ptmp.push_back(p[j]);
				}

				vector <PII> c = convexHull(ptmp);
				//if (mask == (1 << N) - 1) print(c);
				bool ol = false;
				for (int j = 0; j + 1 < c.size(); j++) {
					if (onLine(p[i], c[j], c[j + 1])) {
						ol = true;
					}
				}
				
				int s = ptmp.size();
				if (ol && s > maxs) maxs = s;
			}			

			printf("%d\n", N - maxs);
		}
	}

	/*
	vector <PII> p;
	int sz, tx, ty;
	cin >> sz;
	for (int i = 0; i < sz; i++) { cin >> tx >> ty; p.push_back(make_pair(tx, ty)); }
	print(convexHull(p));*/

	return 0;
}
