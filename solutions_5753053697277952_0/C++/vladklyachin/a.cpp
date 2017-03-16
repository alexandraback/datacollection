#include <algorithm>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <strstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
typedef int64_t i64;
typedef double dbl;

#define NN 30

int t;
int N;
int a[NN];
int total;

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d", &N);
		priority_queue<pair<int, char>> q;
		total = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &a[i]);
			q.push(make_pair(a[i], 'A'+i));
			total += a[i];
		}
		vector<string> ans;
		while (!q.empty()) {
			auto p1 = q.top();
			q.pop();
			if (q.size() == 2 && total == 3) {
				ans.push_back(string(1, p1.second));
				p1.first -= 1;
				if (p1.first != 0) {
					q.push(p1);
				}
				total -= 1;
				continue;
			}
			auto p2 = q.top();
			q.pop();
			if (p1.first - p2.first >= 1) {
				ans.push_back(string(2, p1.second));
				p1.first -= 2;
				if (p1.first != 0) {
					q.push(p1);
				}
				q.push(p2);
				total -= 2;
				continue;
			}
			ans.push_back(string(1, p1.second) + p2.second);
			p1.first -= 1;
			p2.first -= 1;
			if (p1.first != 0) {
				q.push(p1);
			}
			if (p2.first != 0) {
				q.push(p2);
			}
			total -= 2;
		}
		printf("Case #%d:", ti+1);
		for (auto& s : ans) {
			printf(" %s", s.data());
		}
		printf("\n");
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
