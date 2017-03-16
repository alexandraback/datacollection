#include <stdio.h>
#include <string.h>
int map[2][4][4],cnt[20];
int main(){
	int test,testt,i,j,row[2],a,count;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		memset(cnt,0,sizeof(cnt));
		for(a=0;a<2;a++){
			scanf("%d",&row[a]);
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					scanf("%d",&map[a][i][j]);
					if(row[a]==i+1)
						cnt[map[a][i][j]]+=1<<a;
				}
			}
		}
		count=0;
		for(i=1;i<=16;i++){
			if(cnt[i]==3){
				count++;
				a=i;
			}
		}
		printf("Case #%d: ",test);
		if(count>=2)
			printf("Bad magician!\n");
		else if(count==1)
			printf("%d\n",a);
		else
			printf("Volunteer cheated!\n");
	}
	return 0;
}
