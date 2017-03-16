#include <bits/stdc++.h>

using namespace std;

int N, B;
int M[1000];

int solve() {
	scanf("%d%d", &B, &N);
	int mul = 1;
	for (int i = 0; i < B; i++) {
		scanf("%d", &M[i]);
		mul *= M[i];
	}
	int cycle = 0;
	for (int i = 0; i < B; i++)
		cycle += mul / M[i];
	N--;
	N %= cycle;
	priority_queue<pair<long long, int> > pq;
	for (int i = 0; i < B; i++)
		pq.push(make_pair(0, -i));
	while (N > 0) {
		pair<long long, int> p = pq.top();
		pq.pop();
		pq.push(make_pair(p.first - M[-p.second], p.second));
		N--;
	}
	//printf("%lld\n", pq.top().first);
	return -pq.top().second + 1;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}
