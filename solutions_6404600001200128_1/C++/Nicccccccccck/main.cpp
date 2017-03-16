#include <cstdio>
const int maxn = 10000 + 10;
int M[maxn];
//int inter[maxn];
int method1(int *M, int N) {
	int sum = 0;
	for(int i = N-1; i > 0; i--) {
		if(M[i-1]-M[i] > 0) sum += M[i-1]-M[i];
	}
	return sum;
}
int method2(int *M, int N) {
	int sum = 0, rate = 0, inter;
	for(int i = N-1; i > 0; i--) { // find rate
		inter = M[i-1]-M[i];
		if(inter > 0 && inter > rate) rate = inter;
	}
	for(int i = 0; i < N-1; i++) {
		if(M[i] <= rate) sum += M[i];
		else sum += rate;
	}
	return sum;
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T, cnt = 0;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &M[i]);
		printf("Case #%d: %d %d\n", ++cnt, method1(M, N), method2(M, N));
	}
	return 0;
}