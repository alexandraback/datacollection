#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int t,n,m[10010],ans1,ans2,rate;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for(int k = 1; k <= t; k++){
		ans1 = ans2 = rate = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%d",&m[i]);
		for(int i = 0; i < n-1; i++){
			if(m[i]-m[i+1] > 0){
				ans1 += m[i]-m[i+1];
				rate = max(rate,m[i]-m[i+1]);
			}
		}
		for(int i = 0; i < n-1; i++) ans2 += rate > m[i] ? m[i] : rate;
		printf("Case #%d: %d %d\n",k,ans1,ans2);
	}
}