#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int T,N;
int a[10101];

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(int re=1;re<=T;++re){
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",a+i);
		int ans1 = 0 , ans2 = 0 , MAX = -10000000;
		for(int i=1;i<N;++i){
			if(a[i] > a[i+1])
				ans1 += a[i] - a[i+1];
			int t = a[i] - a[i+1];
			if(t > MAX) MAX = t;
		}
		if(MAX < 0) ans2 = 0;
		else{
			for(int i=1;i<N;++i){
				if(a[i] > MAX) ans2 += MAX;
				else ans2 += a[i];
			}
		}
		printf("Case #%d: %d %d\n",re,ans1,ans2);
	}
	return 0;
}
