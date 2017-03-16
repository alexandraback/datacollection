#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXT=1000000000000000LL;
//const ll MAXT=100;
int TC,N,B,M[1010];
int main(){
	scanf("%d\n",&TC);
	for (int tc=1; tc<=TC; tc++){
		scanf("%d%d",&B,&N);
		for (int i=0; i<B; i++) scanf("%d",&M[i]);
		if (N<=B){
			printf("Case #%d: %d\n",tc,N);
			continue;
		}
		ll s=0,e=MAXT,m;
		while (e-s>1){
			m=(s+e)/2;
//			printf("%lld %lld %lld\n",s,e,m);
			ll n=0;
			for (int i=0; i<B; i++){
				n+=m/M[i]+1;
			}
			if (n>=N) e=m;
			else s=m;
		}
		int prev=0,ans;
		for (int i=0; i<B; i++){
			prev+=(e-1)/M[i]+1;
		}
		for (int i=0; i<B; i++){
			if (e%M[i] == 0) {
				prev++;
				if (prev==N){
					ans = i+1;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",tc,ans);
	}
}
