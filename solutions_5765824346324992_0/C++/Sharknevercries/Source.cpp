#include<bits\stdc++.h>
using namespace std;
long long  b, n, ti[1005];
long long solve(long long t){
	long long cnt = 0;
	for (int i = 0; i < b; i++)
		cnt += ceil((double)t / ti[i]);
	return cnt;
}
int getHarber(long long t){
	long long count = solve(t);
	for (int i = 0; i < b; i++){
		if (t % ti[i] == 0)
			count++;
		if (count >= n)
			return i + 1;
	}
}
int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld", &b, &n);
		for (int i = 0; i < b; i++)
			scanf("%lld", ti + i);
		long long L = 1, R = 2e15, mid;
		while (L <= R){
			mid = (L + R) / 2;
			long long res = solve(mid);
			//if (res == n)
			//	break;
			if (res < n)
				L = mid + 1;
			else
				R = mid - 1;
		}
		//mid = min(mid, L - 1);
		//printf("%d\n", L);
		printf("Case #%d: %d\n", c++, getHarber(L - 1));
	}
	return 0;
}