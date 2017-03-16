#include <cstdio>
using namespace std;
int t,n,r,c,grid[20][20],minans;
int main(){
	scanf("%d",&t);
	for(int a=1;a<=t;a++){
		scanf("%d %d %d",&r,&c,&n);
		int lim=(1<<(r*c)),minans=10000;
		for(int x=0;x<lim;x++){
			int x2=x,ans=0,cnt=0;
			for(int y=0;y<r;y++){
				for(int z=0;z<c;z++){
					grid[y][z]=x2&1;
					x2>>=1;
					if(grid[y][z]){
						cnt++;
						if(y){
							if(grid[y-1][z]) ans++;
						}
						if(z){
							if(grid[y][z-1]) ans++;	
						}
					}
				}
			}
			if(cnt!=n) continue;
			if(ans<minans) minans=ans;
		}
		printf("Case #%d: %d\n",a,minans);
	}
	return 0;
}
