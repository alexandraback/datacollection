#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;

int N, R, C;

int solve(){
	int r = 1000;
	int map[20][20];
	for(int i=0;i<(1<<(R*C));++i){
		int cnt = 0;
		for(int j=1;j<=i;j<<=1){
			if(j&(i)){
				++cnt;
			}
		}
		if(cnt != N)
			continue;
		for(int j=0;j<20;++j)
			for(int k=0;k<20;++k)
				map[j][k] = 0;
		int pans = 0;
		for(int j=0;j<R;++j){
			for(int k=0;k<C;++k){
				if(i&(1<<(C*j + k))){
					map[j][k] = 1;
				}
			}
		}

		for(int j=0;j<R;++j){
			for(int k=0;k<C;++k){
				if(map[j][k] && map[j][k+1])
					++pans;
				if(map[j][k] && map[j+1][k])
					++pans;
			}
		}
		r = min(r, pans);
	}
	return r;
}

int main(){

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);

	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;++t){
		scanf("%d%d%d",&R,&C,&N);
		printf("Case #%d: %d\n",t,solve());
	}

	return 0;
}