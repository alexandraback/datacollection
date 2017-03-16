#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000006

lld A[MAXN];
lld ans, ans2;

int main(){
	int T;
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		printf("Case #%d: ", caso);
		int N;
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> A[i];
		ans = 0;
		for(int i = 1; i < N; i++)
			if(A[i - 1] - A[i] > 0)
				ans += A[i - 1] - A[i];
		ans2 = (1ll << 60);
		for(lld i = 0; i < 100000; i++){
			bool can = true;
			lld now = 0;
			for(int j = 0; j < N - 1; j++){
				if(max(A[j] - i, 0ll) > A[j + 1]){
					can = false;
					break;
				}
				now += min(i, A[j]);
			}
			if(can)
				ans2 = min(ans2, now);
			
		}
		cout << ans << " " << ans2 << endl;
	}
	return 0;
}