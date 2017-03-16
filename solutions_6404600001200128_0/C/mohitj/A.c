#include <stdio.h>

void exec(int case_num) {
	int N;
	int z = 1;
	int m[1000];
	int i;
	int ans1 = 0, ans2 = 0, rate = 0;
	scanf("%d", &N);
	for(i = 0; i < N; ++i) scanf("%d", &m[i]);
	for(i = 1; i < N; ++i) {
		int diff = m[i - 1] - m[i];
		if(m[i - 1] == 0) ++z;
		if(diff > 0) {
			ans1 += diff;
		}
	}
	for(i = 1; i < N; ++i) {
		if(m[i] < m[i-1]) {
			const int nm = m[i-1] - m[i];
			if(nm > rate) rate = nm;
		}
	}
	for(i = 1; i < N; ++i) {
		if(rate > m[i-1]) ans2 += m[i-1];
		else ans2 += rate;
	}
	printf("Case #%d: %d %d\n", case_num, ans1, ans2);
}

int main()
{
	int T, i;
	scanf("%d", &T);

	for(i = 1; i <= T; ++i) exec(i);
	return 0;
}

