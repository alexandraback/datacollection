#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

void solve(vector<int> &p) {
	/*
	priority_queue<pii> pq;
	int n = (int) p.size();
	for(int i=0 ; i<n ; i++) {
		pq.push(pii(p[i], i));
	}

	while(!pq.empty()) {

	}
	*/

	int n = (int) p.size();
	int sum = 0;
	for(int i=0 ; i<n ; i++) sum += p[i];

	bool valid = true;

	while (sum > 0) {
		int index = max_element(p.begin(), p.end()) - p.begin();
		
		p[index]--;
		printf("%c", 'A' + index);
		sum--;

		for(int i=0 ; i<n ; i++) {
			if (2 * p[i] > sum) {
				p[i]--;
				printf("%c", 'A' + i);
				sum--;
				break;
			}
		}

		printf(" ");

		for(int i=0 ; i<n ; i++) {
			if (2 * p[i] > sum) {
				valid = false;
			}
		}
	}

	if (!valid) printf("\nINVALID");
	printf("\n");
}

int main() {

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int n;
		scanf("%d", &n);

		vector<int> p(n);
		for(int i=0 ; i<n ; i++) 
			scanf("%d", &p[i]);

		printf("Case #%d: ", tc);
		solve(p);
	}

	return 0;
}