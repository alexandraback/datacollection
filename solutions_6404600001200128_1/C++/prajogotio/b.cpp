#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int m[10000];
int N;
int main(){
	int TC;
	scanf("%d",&TC);
	for(int tt=1;tt<=TC;++tt){
		printf("Case #%d: ", tt);
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%d",&m[i]);
		}
		int ans = 0;
		int maxdiff = 0;
		for(int i=1;i<N;++i){
			int c = m[i] - m[i-1];
			if (c < 0) ans -= c;
			maxdiff = max(maxdiff, -c);
		}
		printf("%d", ans);
		ans = 0;
		for(int i=0;i<N-1;++i){
			ans += min(maxdiff, m[i]);
		}
		printf(" %d\n",ans);
	}
	return 0;
}