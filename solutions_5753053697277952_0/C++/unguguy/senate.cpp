#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int t, n;
int arr[30];
priority_queue<pii> pq;
pii p;

int main() {
	scanf("%d",&t);
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			pq.push(make_pair(arr[i], i));
		}

		bool first = true;
		vector<string> ans;

		while (!pq.empty()) {
			string s = "";
			for (int i = 0; i < 2; i++) {
				if (pq.empty())
					break;

				p = pq.top(); pq.pop();
				--p.first;
				s.push_back((char)(p.second + 'A' - 1));
				if (p.first > 0)
					pq.push(p);
			}
			ans.push_back(s);
		}

		if (ans.size() > 1 && ans.back().length() == 1)
			swap(ans[ans.size()-1], ans[ans.size()-2]);

		printf("Case #%d: ", tc);
		for (int i = 0; i < (int)ans.size(); i++) {
			if (i) cout << " ";
			cout << ans[i];
		}
		printf("\n");
	}	
	return 0;
}