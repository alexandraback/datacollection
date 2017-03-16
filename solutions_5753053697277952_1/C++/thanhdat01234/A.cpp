#include <bits/stdc++.h>

using namespace std;

int T, N, cnt[30];
priority_queue < pair <int, int> > heap;

int isValid() {
	int a = 0, b = 0;
	for (int i = 0; i < N; ++i) {
		a += cnt[i];
		b = max(b, cnt[i]);
	}
	return 2 * b <= a;
}

void solve() {
	scanf("%d", &N);
	heap = priority_queue < pair <int, int> > ();
	for (int i = 0; i < N; ++i) {
		scanf("%d", cnt + i);
		heap.push(make_pair(cnt[i], i));
	}

	pair <int, int> a, b;
	int k;
	while (!heap.empty()) {
		k = 1;
		a = heap.top(); heap.pop();
		if (!heap.empty())
			b = heap.top(), heap.pop(), k = 2;

		if (a.first == 1) {
			cnt[a.second] -= 1;
			cnt[b.second] -= 1;			
			printf(" %c", 'A' + a.second);
			if (k == 2) printf("%c", 'A' + b.second);
			continue;
			// return;
		}

		cnt[a.second] -= 2;
		if (isValid()) {
			printf(" %c%c", 'A' + a.second, 'A' + a.second);
			heap.push(b);
			if (cnt[a.second]) heap.push(make_pair(cnt[a.second], a.second));
			continue;
		}
		cnt[a.second] += 2;

		cnt[a.second] -= 1;
		cnt[b.second] -= 1;

		printf(" %c%c", 'A' + a.second, 'A' + b.second);
		
		if (cnt[a.second]) heap.push(make_pair(cnt[a.second], a.second));		
		if (cnt[b.second]) heap.push(make_pair(cnt[b.second], b.second));


	}
}

int main() {
	freopen("in.inp", "r", stdin);
	freopen("ou.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d:", i + 1);
		solve();
		printf("\n");
	}
}