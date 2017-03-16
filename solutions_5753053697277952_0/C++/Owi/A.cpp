#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

typedef long long LL;



int main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int caseID = 1; caseID <= T; ++caseID) {
		priority_queue<pair<int, char> > senators; 
		printf("Case #%d:", caseID);
		int N;
		cin >> N;
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			int C;
			cin >> C;
			sum += C;
			pair<int, char> p(C, (char)(i + 'A'));
			senators.push(p);
		}
		while (!senators.empty()) {
			pair<int, char> p1 = senators.top();
			senators.pop();
			--p1.first;
			--sum;
			if (p1.first > 0) senators.push(p1);
			if (!senators.empty()) {
				pair<int, char> p2 = senators.top();
				if (p2.first == 1 && senators.size() == 2) {

				}
				else {
					senators.pop();
					--p2.first;
					--sum;
					if (p2.first > 0) senators.push(p2);
					printf(" %c%c", p1.second, p2.second);
					continue;
				}
			}
			printf(" %c", p1.second);
		}
		puts("");
	}
}