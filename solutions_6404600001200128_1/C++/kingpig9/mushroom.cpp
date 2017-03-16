#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1010;

int N, A[MAXN];

void go (int tt) {
	printf("Case #%d: ", tt);
	//any # of mushrooms
	scanf("%d", &N);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if (i != 1) {
			if (A[i] < A[i - 1]) {
				ans += A[i - 1] - A[i];
			}
		}
	}
	printf("%d ", ans);
	ans = 0;
	//get the maximum rate down goddamnit
	int rate = 0;
	for (int i = 2; i <= N; i++) {
		rate = max(rate, A[i - 1] - A[i]);
	}
	//this is the max rate down
	for (int i = 1; i < N; i++) {
		ans += min(A[i], rate);
	}
	printf("%d\n", ans);
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int tt;
	scanf("%d", &tt);
	for (int i = 1; i <= tt; i++) {
		go(i);
	}
}



