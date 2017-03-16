#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define oo 1e9
#define pi 3.1415926536
#define all(x) x.begin(),x.end()
#define sorta(x) sort(all(x))
#define sortam(x,comp) sort(all(x),comp)
#define sortd(x) sort(x.rbegin(),x.rend())
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
#define sfd(x) scanf("%f", &x)

typedef long long ll;
using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	sf(t);
	for(int tc = 1; tc <= t; tc++) {
		int n;
		sf(n);
		int sum = 0;
		priority_queue<pair<int,char> >q;
		for(int i = 0; i < n; i++) {
			int tmp;
			sf(tmp);
			q.push({tmp, i + 'A'});
			sum += tmp;
		}
		printf("Case #%d: ", tc);
		while(q.size()) {
			pair<int, char>cur = q.top();
			q.pop();
			string res;
			res += cur.second;
			cur.first--;
			sum--;
			if(cur.first>0)
				q.push(cur);
			if(q.top().first > sum / 2)  {
				cur = q.top();
				q.pop();
				res += cur.second;
				cur.first--;
				sum--;
				if(cur.first>0)
					q.push(cur);
			}

			cout << res << ' ';
		}
		cout << endl;
	}
	return 0;
}
