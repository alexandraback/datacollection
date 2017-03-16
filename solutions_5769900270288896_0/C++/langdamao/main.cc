#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
bool have[10005];
int r,c,n;
int test(int x,int y){
	int ret=0;
	if(x>0&&have[(x-1)*c+y]) ret++;
	if(y>0&&have[x*c+y-1]) ret++;
	if(y<c-1&&have[x*c+y+1]) ret++;
	if(x<r-1&&have[(x+1)*c+y]) ret++;
	return ret;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&r,&c,&n);
		memset(have,0,sizeof(have));
		int ans=r*c*4;
		int wei=r*c;
		for (int i=0;i<(1<<wei);i++){
			int x=i;
			int j=0;
			int num=0;
			int ret=0;
			while(x){
				have[j++]=x&1;
				if(x&1) num++;
				x/=2;
			}
			if(num!=n) continue;
			for (int j=0;j<r-1;j++){
				for (int k=0;k<c;k++){
					if(have[j*c+k]&&have[j*c+c+k]) {
						ret++;
					}
				}
			}
			for (int j=0;j<r;j++){
				for (int k=0;k<c-1;k++){
					if(have[j*c+k]&&have[j*c+k+1]) ret++;
				}
			}
			ans=min(ret,ans);
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}
