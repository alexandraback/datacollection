#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long i64;
const int MAXB = 1200;
int B, N;
int M[MAXB], mxM;

void init()
{
	scanf("%d%d", &B, &N);
	mxM = 0;
	for (int i = 1; i <= B; ++i) {
		scanf("%d", &M[i]);
		mxM = max(mxM, M[i]);
	}
}

i64 f(i64 x)
{
	i64 s = 0;
	for (int i = 1; i <= B; ++i) s += x / M[i] + 1;
	return s;
}

i64 find()
{
	i64 l = 0, r = (i64)N * mxM, ans = r;
	while (l <= r) {
		i64 mid = (l + r) / 2;
		if (f(mid) >= N) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	return ans;
}

int solve()
{
	i64 x = find();
	if (x > 0) N -= f(x - 1);
	for (int i = 1; i <= B; ++i) {
		if (x % M[i] == 0) --N;
		if (N == 0) return i;
	}
	return -1;
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int cas = 1; cas <= dat; ++cas) {
		init();
		printf("Case #%d: %d\n", cas, solve());
	}
}
