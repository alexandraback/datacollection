#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;
int N, R, C;
int main(){
	int TC;
	scanf("%d",&TC);
	for (int tt=1;tt<=TC;++tt){
		printf("Case #%d:", tt);
		scanf("%d%d%d",&R,&C,&N);
		int sz = R*C;
		int ans = 500;
		for(int i=0;i<(1<<sz);++i){
			int cur = 0;
			if(__builtin_popcount(i) != N)continue;
			for(int j=0;j<sz;++j){
				if(i&(1<<j)){
					for(int k=j+1;k<sz;++k){
						if(i&(1<<k)){
							if((j+1==k && j/C==k/C) || j+C==k)++cur;
						}
					}
				}
			}
			ans = min(ans,cur);
		}
		printf(" %d\n", ans);
	}
	return 0;
}