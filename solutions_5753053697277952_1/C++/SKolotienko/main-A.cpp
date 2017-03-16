#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <queue>

using namespace std;

void test()
{
	int N;
	cin >> N;

	//vector<int> P(N, 0);
	//for (int i = 0; i < N; ) {
	//	cin >> P[i];
	//}

	priority_queue<pair<int, char>> pq;
	for (int i = 0; i < N; i++) {
		int p = 0;
		cin >> p;
		pq.push({ p, 'A' + i });
	}

	while (pq.size() > 2) {
		auto x = pq.top();
		pq.pop();
		cout << x.second << " ";
		if (x.first > 1) {
			pq.push({ x.first - 1, x.second });
		}
	}

	assert(pq.size() == 2);
	auto x = pq.top();
	pq.pop();
	auto y = pq.top();
	pq.pop();
	assert(x.first == y.first);
	for (int i = 0; i < x.first; i++) {
		cout << x.second << y.second << " ";
	}

}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";
		test();
		cout << endl;
	}
	return 0;
}
