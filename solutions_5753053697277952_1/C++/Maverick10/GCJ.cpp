#include<bits/stdc++.h>
#include<ext/numeric>
using namespace std;
using namespace __gnu_cxx;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)  (ll)v.size()
#define UNVISITED -1
#define CLR(a,v) memset(a,v,sizeof a)
#define PC(x) __builtin_popcount(x)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
#ifndef ONLINE_JUDGE
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c) {
		int n;
		scanf("%d", &n);
		priority_queue<ii> pq;
		int total = 0;
		for (int i = 0; i < n; ++i) {
			int p;
			scanf("%d", &p);
			pq.push(ii(p, i));
			total += p;
		}
//		cout << pq.top().first;
		string s;
		while (!pq.empty()) {
			ii x = pq.top();
			pq.pop();
			--total;
			string add;
			add += (x.second + 'A');
			--x.first;
			if (x.first)
				pq.push(x);
			if (!pq.empty()) {
				ii y = pq.top();
				if (y.first * 2 > total) {
					pq.pop();
					--y.first;
					--total;
					add += (y.second + 'A');
					if (y.first)
						pq.push(y);
				}
			}
			s += add;
			s += ' ';
		}
		if (!s.empty() && s.back() == ' ')
			s.erase(sz(s) - 1, 1);
		cout << "Case #" << c << ": " << s << endl;
	}
}
