#include <algorithm>
#include <cstdio>
using namespace std;
int T, N, m[1000];
int main (){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d", &m[j]);
		int A = 0, B = 0, rate = 0;
		for (int j = 1; j < N; j++){
			if (m[j - 1] > m[j]){
				A += m[j - 1] - m[j];
				rate = max(rate, m[j - 1] - m[j]);
			}
		}
		for (int j = 0; j < N - 1; j++)
			B += min(m[j], rate);
		printf("Case #%d: %d %d\n", i, A, B);
	}
	return 0;
}
