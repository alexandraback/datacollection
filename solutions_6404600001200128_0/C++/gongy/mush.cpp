#include<bits/stdc++.h>
using namespace std;

int T, n, m[1005], ans1, ans2;

int main(){
	freopen("min.in","r",stdin);
	freopen("mout.txt","w",stdout);
	scanf("%d\n",&T);
	for(int j = 1; j <= T; j++){
		ans1 = ans2 = 0;
		int maxdif = 0;
		scanf("%d ",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&m[i]);
		for(int i = 0; i < n - 1; i++){
			if(m[i] > m[i+1])
				ans1 += m[i] - m[i+1];
			maxdif = max(maxdif, m[i] - m[i+1]);
		}
		//she eats maxdif every ten secnods
		for(int i = 0; i < n - 1; i++){
			if(m[i] >= maxdif){
				ans2 += maxdif;
				continue;
			}
			ans2 += m[i];
		}
		printf("Case #%d: %d %d\n",j, ans1, ans2);
	}
	return 0;
}
