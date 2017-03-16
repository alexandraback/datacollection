#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

const int MAX_N = 33;

int n;
int p[MAX_N];

void sub() {
	priority_queue<pair<int, int>> pq;

	int total = 0;

	for (int i = 0; i < n; i++) {
		pq.push(make_pair(p[i], i));

		total += p[i];
	}

	while (!pq.empty()) {
		string out = "";

		pair<int, int> senator1 = pq.top(); pq.pop();
		pair<int, int> senator2 = pq.top(); pq.pop();

		//sub 1
		if ((total - 1) >= (senator1.first - 1) * 2
			&& (total - 1) >= senator2.first * 2) {
			senator1.first--;
			total--;
			out += senator1.second + 'a';
		}
		//sub 1 1
		else if ((total - 2) >= (senator1.first - 2) * 2
			&& (total - 2) >= senator2.first * 2) {
			senator1.first--;
			senator1.first--;
			total--;
			total--;
			out += senator1.second + 'a';
			out += senator1.second + 'a';
		}
		//sub 1, 2
		else {
			senator1.first--;
			total--;
			out += senator1.second + 'a';
			senator2.first--;
			total--;
			out += senator2.second + 'a';
		}

		if (senator1.first > 0) pq.push(senator1);
		if (senator2.first > 0) pq.push(senator2);

		cout << out << " ";
	}
}

void solve(int tc) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	printf("Case #%d: ", tc);

	sub();

	puts("");
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t;tc++) {
		solve(tc);
	}


	return 0;
}