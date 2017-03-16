#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ull = unsigned long long;

string SolveA(vector<pair<int,char>>& P) {
	ostringstream oss;
	if (P.size() == 2) {
		for (int i = 0;i < P[0].first;++i)
			oss << "AB ";
		return oss.str();
	}
	priority_queue<pair<int, char>> Q(P.begin(), P.end());
	int N = 0;
	for (const auto& p : P) {
		N += p.first;
	}
	while (N > 2) {
		--N;
		auto p = Q.top();
		oss << p.second << ' ';
		if (p.first > 0) {
			--p.first;
			Q.pop();
			Q.push(p);
		}
	}
	auto p = Q.top();
	oss << p.second;
	Q.pop();
	p = Q.top();
	oss << p.second;
	return oss.str();
}

void main() {

	int T;
	cin >> T;
	for (int i = 0;i < T;++i) {
		int N;
		cin >> N;
		vector<pair<int,char>> P;
		int j;
		char c;
		for (j = 0, c='A';j < N;++j, ++c) {
			int p;
			cin >> p;
			P.push_back(make_pair(p,c));
		}

		cout << "Case #" << i + 1 << ": " << SolveA(P) << endl;
	}
}