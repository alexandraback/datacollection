#include<stdio.h>
int f[2][20];
int T,tot;
void readRow(int num){
	int i,j,x,p;
	scanf("%d",&x);
	for(i=1;i<=16;i++)f[num][i] = 0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d",&p);
			if(x==i+1)f[num][p] = 1;
		}
	}
}
int main(){
	int i,ans,out;
	freopen("sample.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(tot=1;tot<=T;tot++){
		readRow(0);
		readRow(1);
		ans = 0;
		for(i=1;i<=16;i++)
			if(f[0][i]+f[1][i] == 2){
				ans++;
				out = i;
			}
		printf("Case #%d: ",tot);
		if(ans > 1) printf("Bad magician!\n");else
		if(ans == 1) printf("%d\n",out);else
		if(ans == 0) printf("Volunteer cheated!\n");
	}
}
