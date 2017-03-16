#include<cstdio>

int T;
int n=4,fa,sa;
int first[4][4];
int second[4][4];

int process(){
	bool chk[17] = {false,};
	int i;
	int flag = 0; // -1: Bad magician, 0: Volunteer cheated, else: answer
	for(i=0;i<n;i++){
		chk[first[fa][i]] = true;
	}
	for(i=0;i<n;i++){
		if(chk[second[sa][i]] == true){
			if(flag == 0) flag = second[sa][i];
			else{
				flag = -1;
				break;
			}
		}
	}
	return flag;
}

int main(void){
	int i,j,t;
	int ans;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&fa);
		--fa;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&first[i][j]);
			}
		}
		scanf("%d",&sa);
		--sa;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&second[i][j]);
			}
		}
		ans = process();
		printf("Case #%d: ", t);
		if(ans == 0) printf("Volunteer cheated!\n");
		else if(ans == -1) printf("Bad magician!\n");
		else printf("%d\n", ans);
	}
}