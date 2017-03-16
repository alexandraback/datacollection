#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#define eps 1e-6

using namespace std;
typedef long long ll;

int x[3011], y[3011], ans[3011];
double ang[6010];
int n;

const double pi = acos(-1);
int dcmp(double x) {
	if(x < -eps) return -1;
	else if(x > eps) return 1;
	return 0;
}
bool cmp(const double &a, const double &b) {
	return dcmp(a - b) < 0;
}
int Solve(int K) {
	int ret = 0;
	for(int i = 0; i < n; ++i) {
		if(i != K) {
			ang[ret++] = atan2(y[i] - y[K], x[i] - x[K]);
		}
	}
	for(int i = ret; i < ret * 2; ++i) {
		ang[i] = ang[i - ret] + pi * 2;
	}
	ret *= 2;
	sort(ang, ang + ret, cmp);
	int L = 0, R = 0;
	while(R < ret && dcmp(ang[L] + pi - ang[R]) >= 0) {
		R++;
	}
	int ans = n;
	for(; L < n - 1; ++L) {
		double cita = ang[L] + pi;
		while(R < ret && dcmp(cita - ang[R]) >= 0) {
			R++;
		}
		ans = min(ans, n - 1 - (R - L));
	}
	return ans;
}

int main() {
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int cs = 1; cs <= _; ++cs) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
		}
		printf("Case #%d:\n", cs);
		if(n ==  1) {
			puts("0");
			continue;
		}
		for(int i = 0; i < n; ++i) {
			printf("%d\n", Solve(i));
		}
	}
	return 0;
}