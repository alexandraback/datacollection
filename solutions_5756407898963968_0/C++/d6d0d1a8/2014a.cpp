#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++){
		int r1,r2;
		int a[4][4],b[4][4];
		scanf("%d",&r1);
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)scanf("%d",&a[i][j]);
		scanf("%d",&r2);
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)scanf("%d",&b[i][j]);

		int f[16];
		for(int i=0;i<16;i++)f[i]=-1;
		for(int i=0;i<4;i++)f[a[r1-1][i]-1]++;
		for(int i=0;i<4;i++)f[b[r2-1][i]-1]++;
		int ans=-1;
		int count=0;
		for(int i=0;i<16;i++){
			if(f[i]>0){
				ans=i+1;
				count++;
			}
		}
		printf("Case #%d: ",tt+1);
		if(count>1)printf("Bad magician!\n");
		else if(count>0)printf("%d\n",ans);
		else printf("Volunteer cheated!\n");
	}
	return 0;
}