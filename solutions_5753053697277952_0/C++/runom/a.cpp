#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		priority_queue<pair<int, int>> que;
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			int p;
			cin >> p;
			sum += p;
			que.emplace(p, i);
		}
		bool f = false;
		while(!que.empty()) {
			if(f) cout << ' ';
			f = true;
			auto p = que.top(); que.pop();
			//auto q = que.top(); que.pop();
			cout << (char)('A' + p.second);
			--sum;
			if(p.first != 1) {
				que.emplace(p.first - 1, p.second);
			}
			if(que.empty()) break;

			auto q = que.top(); que.pop();
			if(2 * q.first > sum) {
				cout << (char)('A' + q.second);
				--sum;
				if(q.first != 1) {
					que.emplace(q.first - 1, q.second);
				}
			} else {
				que.push(q);
			}
		}
		cout << endl;
	}
}
