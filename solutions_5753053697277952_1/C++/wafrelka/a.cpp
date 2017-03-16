#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


void try_insert(priority_queue<pair<int,char>>& q, int count, char party)
{
	if(count > 0)
		q.push({count, party});
}

int main()
{
	int testcases;

	scanf("%d", &testcases);

	for(int case_num = 1; case_num <= testcases; ++case_num) {

		int n;
		vector<int> p;

		scanf("%d", &n);
		p.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &p[i]);

		priority_queue<pair<int, char>> q;

		for(int i = 0; i < n; ++i)
			try_insert(q, p[i] - 1, 'A' + i);

		string ans;

		while(!q.empty()) {

			auto p1 = q.top();
			q.pop();

			if(q.size() == 0) {

				ans.push_back(' ');
				ans.push_back(p1.second);

				try_insert(q, p1.first - 1, p1.second);

				continue;
			}

			auto p2 = q.top();
			q.pop();

			bool p2_use = (p1.first == p2.first);

			ans.push_back(' ');
			ans.push_back(p1.second);
			if(p2_use)
				ans.push_back(p2.second);

			try_insert(q, p1.first - 1, p1.second);
			try_insert(q, p2.first - (int)(p2_use), p2.second);
		}

		if(n % 2 == 1)
			ans.append(" A");
		for(int i = (n % 2); i < n; i += 2) {
			char c1 = 'A' + i;
			char c2 = 'A' + i + 1;
			ans.push_back(' ');
			ans.push_back(c1);
			ans.push_back(c2);
		}

		printf("Case #%d:%s\n", case_num, ans.c_str());
	}

	return 0;
}
