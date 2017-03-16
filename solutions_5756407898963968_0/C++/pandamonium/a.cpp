#include <cstdio>
#include <cstring>
int t,r,m,cnt[20],ans;
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		memset(cnt,0,sizeof(cnt));
		ans=0;
		scanf("%d",&r);
		for(int x=0;x<4;x++){
			for(int y=0;y<4;y++){
				scanf("%d",&m);
				if(x+1==r) cnt[m]=1;
			}
		}
		scanf("%d",&r);
		for(int x=0;x<4;x++){
			for(int y=0;y<4;y++){
				scanf("%d",&m);
				if(x+1==r){
					if(cnt[m]==1){
						if(ans==0) ans=m;
						else ans=-1;
					}
				}
			}
		}
		printf("Case #%d: ",i);
		if(ans==0) printf("Volunteer cheated!\n");
		else if(ans==-1) printf("Bad magician!\n");
		else printf("%d\n",ans);
	}
	return 0;
}
