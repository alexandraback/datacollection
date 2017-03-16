#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <tuple>
#include <queue>
#include <utility>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <limits>
#include <new>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

int main(void) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int j = 1; j <= T; j++) {
		int N;
		int t = 0;
		cin >> N;
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < N; i++) {
			int P;
			cin >> P;
			t += P;
			pq.push(make_pair(P, i));
		}
		string output = "";
		while (!pq.empty()) {
			auto x = pq.top();
			pq.pop();
			auto y = pq.top();
			pq.pop();
			if (t == 3 && pq.size() == 1) {
				output += (char)('A' + x.second);
				output += ' ';
				pq.push(y);
				t--;
			}
			else if (x.first == y.first) {
				output += (char)('A' + x.second);
				output += (char)('A' + y.second);
				output += ' ';
				t -= 2;
				x.first--;
				y.first--;
				if (x.first > 0) pq.push(x);
				if (y.first > 0) pq.push(y);
			}
			else {
				output += (char)('A' + x.second);
				output += ' ';
				t--;
				x.first--;
				pq.push(y);
				if (x.first > 0) pq.push(x);
			}
		}
		output.pop_back();
		cout << "Case #" << j << ": " << output << endl;
	}

	return 0;
}