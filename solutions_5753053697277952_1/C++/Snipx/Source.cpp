#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>
#include <memory.h>
#include <sstream>
#include <array>

using namespace std;



int main() {
	//ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");
	ofstream cout("output.txt");


	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		int n;
		cin >> n;
		int sum = 0;
		vector<int> p(n);
		priority_queue<pair<int, int> > q;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			sum += p[i];
			q.push(make_pair(p[i], i));
		}

		while (!q.empty()) {
			int topC = q.top().first;
			int topId = q.top().second;
			q.pop();
			int first = topId;
			if (topC == 1) {
				if (q.size() == 1) {
					cout << char('A' + first) << char('A' + q.top().second) << " ";
					q.pop();
					sum -= 2;
					break;
				}
				else {
					cout << char('A' + first) << " ";
					sum--;
					continue;
				}
			}
			else {
				topC--;
				sum--;
				q.push(make_pair(topC, topId));
				if (q.top().first > sum - q.top().first) {
					int second = q.top().second;
					int num = q.top().first;
					q.pop();
					sum--;
					q.push(make_pair(num - 1, second));
					cout << char('A' + first) << char('A' + second) << " ";
				} else {
					cout << char('A' + first) << " ";
				}
			}
		}
		cout << endl;
		
	}


	//system("pause");
	return 0;
}