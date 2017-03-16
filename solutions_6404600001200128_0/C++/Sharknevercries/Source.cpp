#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		int n, w[10005];
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", w + i);
		int ans1 = 0, ans2 = 0, rate = 0, amount = w[0];
		for (int i = 1; i < n; i++)
			if (w[i] < w[i - 1])
				ans1 += w[i - 1] - w[i];
		for (int i = 1; i < n; i++)
			rate = max(w[i - 1] - w[i], rate);
		for (int i = 1; i < n; i++)
			ans2 += min(w[i - 1], rate);
		printf("Case #%d: %d %d\n",c++, ans1, ans2);
		
	}
	return 0;
}