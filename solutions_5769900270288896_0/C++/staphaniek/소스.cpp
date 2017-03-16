#include<stdio.h>
#define min(a,b) a<b?a:b

int N, T, M, P, unhappy, K,U;

int main(){
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		scanf("%d %d %d", &N, &M, &P);
		unhappy = 0;
		if (P > ((N*M+1) / 2)){
			P -= ((N*M) / 2);
			int L = P;
			if (N == 1){
				if (M & 1){
					unhappy = P * 2;
				}
				else{
					unhappy = 1 + (P - 1) * 2;
				}
			}
			else if (M == 1){
				if (N & 1){
					unhappy = P * 2;
				}
				else{
					unhappy = 1 + (P - 1) * 2;
				}
			}
			else if (((N*M) & 1)){
				if (P <= 4){
					unhappy = (P * 2);
				}
				else{
					unhappy = 8;
					P -= 4;
					K = N - 3 + M - 3;
					if (P <= K){
						unhappy += (P * 3);
					}
					else{
						unhappy += (K * 3);
						P -= K;
						unhappy += (P * 4);
					}
				}
				P = L;
				P--;
				U = 0;
				K = (N / 2) * 2 + (M / 2) * 2;
				if (P <= K)U = (P * 3);
				else{
					U += (K * 3);
					P -= K;
					U += (P * 4);
				}
				unhappy = min(unhappy, U);
			}
			else{
				if (P <= 2){
					unhappy = (P * 2);
				}
				else{
					unhappy = 4;
					P -= 2;
					K = (N - 2) + (M - 2);
					if (P <= K){
						unhappy += (P * 3);
					}
					else{
						unhappy += (K * 3);
						P -= K;
						unhappy += (P * 4);
					}
				}
			}
		}
		printf("Case #%d: %d\n", t, unhappy);
	}
	return 0;
}