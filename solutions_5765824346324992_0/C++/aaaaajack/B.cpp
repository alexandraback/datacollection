#include<cstdio>
#define N 1010
using namespace std;
int main(){
	int T,cs,n,m,i,a[N],cnt;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++){
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++){
			scanf("%d",&a[i]);
		}
		if(n<=m){
			printf("Case #%d: %d\n",cs,n);
		}
		else{
			long long l=0,r=1LL<<50,x,y;
			while(l+1<r){
				x=(l+r)/2;
				y=0;
				for(i=0;i<m;i++){
					y+=x/a[i]+1;
				}
				if(y<n) l=x;
				else r=x;
			}
			y=0;
			for(i=0;i<m;i++){
				y+=l/a[i]+1;
			}
			cnt=n-y;
			for(i=0;i<m;i++){
				if(r%a[i]==0) cnt--;
				if(cnt==0){
					printf("Case #%d: %d\n",cs,i+1);
					break;
				}
			}
		}
	}
	return 0;
}