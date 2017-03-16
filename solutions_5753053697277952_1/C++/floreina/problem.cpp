#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T; cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		/**/
		int N;
		map <char, int> P;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> P['A' + i];
		}
		while (P.size() != 2) {
			char maxC, maxV = -1;
			for (auto i : P) {
				if (i.second > maxV) {
					maxV = i.second;
					maxC = i.first;
				}
			}
			P[maxC] -= 1;
			if (P[maxC] == 0) {
				P.erase(maxC);
			}
			cout << maxC << ' ';
		}
		auto it = P.begin();
		char fC = it->first;
		it++;
		char sC = it->first;
		if (P[sC] > P[fC]) {
			swap(sC, fC);
		}
		while (P[fC] != P[sC]) {
			P[fC]--;
			cout << fC << ' ';
		}
		while (P[fC] != 0) {
			P[fC]--;
			cout << fC << sC << ' ';
		}
		/**/
		cout << endl;
	}
}