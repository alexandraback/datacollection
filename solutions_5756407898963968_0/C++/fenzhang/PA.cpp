#include<stdio.h>
#include<algorithm>
int a[100][100],ca;
int b[100][100],cb;
void sol(int uuu){
	scanf("%d",&ca);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%d",a[i]+j);
		}
	}
	scanf("%d",&cb);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%d",b[i]+j);
		}
	}
	ca--;cb--;
	int cnt=0,ans=-1;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a[ca][i]==b[cb][j]){
				cnt++;
				ans=a[ca][i];
			}
		}
	}
	printf("Case #%d: ",uuu);
	if(cnt==0){
		puts("Volunteer cheated!");
	}
	else if(cnt!=1){
		puts("Bad magician!");
	}
	else{
		printf("%d\n",ans);
	}
}
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("Aout.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=0;ti<t;ti++){
		sol(ti+1);
	}
	return 0;
}
