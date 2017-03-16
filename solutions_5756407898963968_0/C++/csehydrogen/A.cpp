#include <cstdio>

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,ti,i,j;
	int ans,card[5][5],cnt;
	bool check[17];

	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		for(i=1;i<=16;i++)
			check[i]=0;
		scanf("%d",&ans);
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				scanf("%d",&card[i][j]);
		for(i=1;i<=4;i++)
			check[card[ans][i]]=1;
		scanf("%d",&ans);
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				scanf("%d",&card[i][j]);
		cnt=0;
		for(i=1;i<=4;i++)
			if(check[card[ans][i]])
				cnt++;
		printf("Case #%d: ",ti);
		if(cnt==0){
			printf("Volunteer cheated!");
		}else if(cnt>1){
			printf("Bad magician!");
		}else{
			for(i=1;i<=4;i++)
				if(check[card[ans][i]])
					break;
			printf("%d",card[ans][i]);
		}
		printf("\n");
	}
}