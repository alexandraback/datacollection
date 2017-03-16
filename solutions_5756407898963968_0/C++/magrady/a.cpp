#include<stdio.h>
int map[2][4][4];
int ans[2];
void input(int id){
	int i,j,k;
	scanf("%d",&ans[id]);
	ans[id]--;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d",&map[id][i][j]);
		}
	}
}
void solve(){
	int i,j1,j2,k=0,sol;
	for(j1=0;j1<4;j1++){
		for(j2=0;j2<4;j2++){
			if(map[0][ans[0]][j1]==map[1][ans[1]][j2]){
				sol=map[0][ans[0]][j1];
				k++;
				break;
			}
		}
	}
	if(k==1){
		printf("%d\n",sol);
	} else if(k==0){
		puts("Volunteer cheated!");
	} else {
		puts("Bad magician!");
	}
}
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		input(0);
		input(1);
		printf("Case #%d: ",T);
		solve();
	}
}
