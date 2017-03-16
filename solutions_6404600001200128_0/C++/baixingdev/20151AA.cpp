#include<cstdio>
#include<algorithm>
using namespace std;

int T, _;
int n, v[1111];
int ans1, ans2, rate;

int main() {
	scanf("%d", &T);
	for(int _=1; _<=T; _++) {
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &v[i]);
		ans1 = ans2 = 0;
		rate = 0;
		for(int i=1;i<n;i++) {
			if(v[i] < v[i-1]) ans1 += v[i-1] - v[i];
			
			rate = max(rate, v[i-1] - v[i]);
		}
		for(int i=0;i<n-1;i++){
			ans2 += min(rate, v[i]);
		}
		printf("Case #%d: %d %d\n", _, ans1, ans2);
	}

	return 0;
}