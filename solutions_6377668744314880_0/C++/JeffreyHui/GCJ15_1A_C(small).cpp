#include <algorithm>
#include <cstdio>
using namespace std;
int T, N;
long long X[3000], Y[3000];
long long x_coef, y_coef, constant;
int main (){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		printf("Case #%d:\n", i);
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%I64d %I64d", &X[j], &Y[j]);
		for (int j = 0; j < N; j++){
			int high = 0;
			for (int k = 0; k < N; k++){
				if (j != k){
					x_coef = Y[k] - Y[j];
					y_coef = X[j] - X[k];
					constant = X[k] * Y[j] - X[j] * Y[k];
					int A = 0, B = 0;
					for (int l = 0; l < N; l++){
						if (x_coef * X[l] + y_coef * Y[l] + constant <= 0)
							A++;
						if (x_coef * X[l] + y_coef * Y[l] + constant >= 0)
							B++;
					}
					high = max(high, A);
					high = max(high, B);
				}
			}
			printf("%d\n", N - high);
		}
	}
	return 0;
}
