#include<iostream>
#include<cstdio>
using namespace std;
int posibles[20];
int grid[4][4];
int main(){
	int t=0,T,a,q,b;
	scanf("%d",&T);
	while(T--){
		t++;
		for(int i=1;i<=16;i++) posibles[i]=2;
		scanf("%d",&a);
		a--;
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) scanf("%d",&grid[i][j]);
		for(int j=0;j<4;j++) posibles[grid[a][j]]--;
		scanf("%d",&a);
		a--;
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) scanf("%d",&grid[i][j]);
                for(int j=0;j<4;j++) posibles[grid[a][j]]--;
		q=0;
		for(int i=1;i<=16;i++) if(!posibles[i]){q++; b=i;};
		printf("Case #%d: ",t);
		if(q==0) printf("Volunteer cheated!\n");
		if(q==1) printf("%d\n",b);
		if(q>1) printf("Bad magician!\n");
	}
}
