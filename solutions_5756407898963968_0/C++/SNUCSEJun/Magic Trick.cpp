#include<stdio.h>
#include<algorithm>

int grid[2][5][5];
int idx[2];
int ans;

void getData(){
	int i,j;
	scanf("%d",&idx[0]);
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			scanf("%d",&grid[0][i][j]);
	
	scanf("%d",&idx[1]);
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			scanf("%d",&grid[1][i][j]);
}

bool isthere(int target){
	int i;
	for(i=1;i,i<=4;i++){
		if(grid[0][idx[0]][i] == target){
			ans = target;
			return true;
		}
	}
	return false;
}

int solveTrick(){
	int i;
	int cnt = 0;
	for(i=1;i<=4;i++)
		if(isthere(grid[1][idx[1]][i]))
			cnt++;
	return cnt;
}

void printCase(int caseNum, int caseType){
	printf("Case #%d: ", caseNum);
	switch(caseType){
	case 0:
		printf("Volunteer cheated!\n");
		break;
	case 1:
		printf("%d\n",ans);
		break;
	default :
		printf("Bad magician!\n");
	}

}

int main(){

	int T, i, CaseType;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		getData();
		CaseType = solveTrick();
		printCase(i, CaseType);
	}


	return 0;
}