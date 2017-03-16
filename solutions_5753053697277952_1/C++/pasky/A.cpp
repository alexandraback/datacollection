#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <string>
#include <cassert>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long LL;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }


void Go() {
	int N;
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	priority_queue<pair<int, int>> q;
	int total = 0;
	for (int i = 0; i < N; i++) {
		q.push(make_pair(P[i], i));
		total += P[i];
	}
	auto evacuate = [&]() {
		auto p = q.top();
		cout << (char)(p.second + 'A');
		q.pop();
		p.first -= 1;
		total -= 1;
		if (p.first > 0) {
			q.push(p);
		}
	};
	while (!q.empty()) {
		cout << ' ';
		evacuate();
		if (!q.empty() && q.top().first * 2 > total) {
			evacuate();
		}
		if (!q.empty() && q.top().first * 2 > total) {
			throw 1;
		}
	}
	cout << endl;
}

int main() {
	const string task = "A";
	const string folder = "gcj/2016/1C";
	const int attempt = -1;
	const bool dbg = false;

	if (dbg) {
		freopen("inp.txt", "r", stdin);
	}
	else {
		stringstream ss;
		ss << folder << '/' << task;
		if (attempt < 0)
			ss << "-large";
		else
			ss << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%d:", i + 1);
		Go();
	}
	return 0;
}
