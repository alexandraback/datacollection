#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		int n;
		cin >> n;

		vector<int> p(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			sum += p[i];
		}

		priority_queue<pair<int, int> > pmax;
		for (int i = 0; i < p.size(); i++) {
			pmax.emplace(p[i], i);
		}

		while (pmax.top().first != 0) {
			auto first = pmax.top();
			first.first--;
			pmax.pop();

			cout << (char)(first.second + 'A');

			auto second = pmax.top();			
			pmax.pop();
			second.first--;

			int news = sum - 2;

			if (second.first == 0 && first.first == 0 && pmax.size() == 1 && pmax.top().first > 0) {
				sum = news + 1;
				second.first++;
			} else if ((first.first) * 2 <= news) {
				cout << (char)(second.second + 'A');
				sum = news;
			}
			else {
				second.first++;
				sum = news + 1;
			}

			cout << " ";
			pmax.push(first);
			pmax.push(second);
		}

		cout << endl;
	}
}