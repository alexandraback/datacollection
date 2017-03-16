#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

#define INF 0x3f3f3f3f

int a[1010];

int main(){
	int T;
	scanf("%d",&T);
	for(int cas = 1;cas <= T;++cas){
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		int m1 = 0,m2 = 0;
		int gap = 0;
		for(int i = 2;i <= n;++i){
			gap = max(gap,a[i - 1] - a[i]);
			if(a[i] < a[i - 1])
				m1 += a[i - 1] - a[i];
		}
		for(int i = 1;i < n;++i){
			int t = a[i];
			if(t > gap)
				t = gap;
			m2 += t;
		}
		printf("Case #%d: %d %d\n",cas,m1,m2);
	}
	return 0;
}

