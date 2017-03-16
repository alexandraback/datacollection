#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>

//#define Cpp11
#ifdef Cpp11
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>
using namespace std::chrono;
#endif
using namespace std;

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int mx[4] = { 1, 0, -1, 0 };
const int my[4] = { 0, 1, 0, -1 };

const int Inf = 1000000000;
const int MOD = 1000000007;
const int N = 1005;
const int K = 30;
const ld eps = 10e-8;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

unsigned rand16() { return rand() % (1 << 16); }
unsigned rand32() { return (rand16() << 16) + rand16(); }
ull rand64() { return (((ull)rand32()) << 32) + rand32(); }
int rand(int L, int R) { if (L > R) return R; return rand32() % (R - L + 1) + L; }
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

ll Abs(ll a) { return a < 0 ? -a : a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

string toStr(int n) {
	char s[100];
	sprintf(s, "%d", n);
	return string(s);
}

struct point {
	ll x, y;
	int id;
};

bool cw(point a, point b, point c) {
	return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) < 0;
}

bool anticw(point a, point b, point c) {
	return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) > 0;
}

vector<point> convex_hull(vector<point> a) {
	if (a.size() == 1) return a;
	sort(a.begin(), a.end(), [](point a, point b) {
		return a.x < b.x || a.x == b.x && a.y < b.y;
	});
	point p1 = a[0], p2 = a.back();
	vector<point> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (int i = 1; i < a.size(); ++i) {
		if (i == a.size() - 1 || cw(p1, a[i], p2)) {
			while (up.size() > 1 && !cw(up[up.size() - 2], up.back(), a[i]))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || anticw(p1, a[i], p2)) {
			while (down.size() > 1 && !anticw(down[down.size() - 2], down.back(), a[i]))
				down.pop_back();
			down.push_back(a[i]);
		}
	}
	vector<point> res = up;
	for (int i = down.size() - 2; i > 0; --i)
		res.push_back(down[i]);
	return res;
}

vector<point> a, b, c;
int n;

//#define ONLINE_JUDGE
int main() {
	std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		printf("Case #%d:\n", t + 1);

		scanf("%d", &n);
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i].x = x;
			a[i].y = y;
			a[i].id = i;
		}
		
		cerr << t << endl;
		for (int i = 0; i < n; ++i) {
			int ans = n - 1;
			for (int mask = 0; mask < (1 << n); ++mask) if ((mask >> i) & 1) {
				b.clear();
				for (int j = 0; j < n; ++j)
					if ((mask >> j) & 1) b.push_back(a[j]);

				c = convex_hull(b);
				bool good = false;
				for (int j = 0; j < c.size(); ++j) {
					int k = (j + 1) % c.size();
					good |= (!cw(c[j], c[k], a[i]) && !anticw(c[j], c[k], a[i]));
				}

				if (good) ans = min(ans, (int)(a.size() - b.size()));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}