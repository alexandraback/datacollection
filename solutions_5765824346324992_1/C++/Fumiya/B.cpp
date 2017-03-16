#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int B, N; cin >> B >> N;
		vector<int> M(B);
		for (int i = 0; i < B; i++) cin >> M[i];
		long long L = -1, R = 1000000000000000000LL;
		while (R - L > 1){
			long long mid = (L + R) / 2;
			long long end = 0;
			for (int i = 0; i < B; i++){
				end += mid / M[i] + 1;
			}
			if (end >= N) R = mid;
			else          L = mid;
		}
		long long cnt = 0;
		for (int i = 0; i < B; i++){
			cnt += (R - 1) / M[i] + 1;
		}
		int res = 0;
		if (N <= B){
			res = N-1;
		} else {
			for (int i = 0; i < B; i++){
				if (R%M[i] == 0){
					cnt++;
					if (cnt == N){
						res = i;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n", t, res+1);
	}
}
