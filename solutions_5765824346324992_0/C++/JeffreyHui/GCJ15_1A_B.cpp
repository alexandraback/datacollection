#include <cstdio>
int T;
long long B, M[1000], N, cnt;
long long bin_search(long long low, long long high){
	if (low == high){
		return low;
	} else {
		long long mid = (low + high) / 2;
		long long cnt = 0;
		for (int i = 0; i < B; i++)
			cnt += mid / M[i];
		if (cnt >= N){
			return bin_search(low, mid);
		} else {
			return bin_search(mid + 1, high);
		}
	}
}
int main (){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%I64d %I64d", &B, &N);
		for (int j = 0; j < B; j++)
			scanf("%I64d", &M[j]);
		if (N <= B){
			printf("Case #%d: %I64d\n", i, B);
		} else {
			N -= B;
			long long time = bin_search(0, 100000 * N);
			cnt = 0;
			for (int j = 0; j < B; j++)
				cnt += (time - 1) / M[j];
			N -= cnt;
			int j = 0;
			while (j < B && N > 0){
				if (!(time % M[j]))
					N--;
				j++;
			}
			printf("Case #%d: %d\n", i, j);
		}
	}
	return 0;
}
