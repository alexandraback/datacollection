#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;

int T;
int B;
const int MAX_B = 1000;
ll N;
int m[MAX_B];

bool ltpll(const pll& a, const pll& b) {
	if (a.first < b.first) {
		return true;
	} else if (a.first == b.first && a.second < b.second) {
		return true;
	}
	return false;
}

ll gcd(ll a, ll b)
{
     if (b == 0) return a;
     return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
     ll g = gcd(a, b);
     return a * b / g;
}

void solve()
{
	ll lcmnum = 1;
	for (int i = 0; i < B; ++i) {
		lcmnum = lcm(lcmnum, m[i]);
	}
	ll tot = 0;
	for (int i = 0; i < B; ++i) {
		tot += lcmnum / m[i];
	}
	//cout << lcmnum << " "<< tot << endl;
	N = N % tot;

	if (N == 0) {
		N = tot;
	} else if (N <= B) {
		cout << N;
		return;
	}

	deque<pll> que;
	for (int i = 0; i < B; ++i) {
		if (i == N - 1) {
			cout << i + 1;
			return;
		}
		pll item = make_pair(m[i], i);
		deque<pll>::iterator it = lower_bound(que.begin(), que.end(), item, ltpll);
		que.insert(it, item);
	}
	for (int i = B; i < N-1; ++i) {
		// for (int j = 0;j < que.size(); ++j) {
		// 	cout << que[j].first << "," << que[j].second << " ";
		// }
		// cout << endl;
		pll item = que[0];
		que.erase(que.begin());
		ll idx = item.second;
		item.first += m[idx];
		deque<pll>::iterator it = lower_bound(que.begin(), que.end(), item, ltpll);
		que.insert(it, item);
	}
	pll ans = que[0];
	cout << ans.second + 1;
}

int main()
{
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %lld", &B, &N);
		for (int i = 0; i < B; ++i) {
			scanf("%d", &m[i]);
		}
		printf("Case #%d: ", t);
		solve();
		printf("\n");
	}
	return 0;
}
