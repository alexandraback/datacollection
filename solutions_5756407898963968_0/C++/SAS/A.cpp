#include<stdio.h>
#include<stdlib.h>
int main(){
	int T;
	int set[2][4],r;
	scanf("%d",&T);
	for(int ca = 1; ca <= T ;ca++){
		for(int k=0;k<2;k++){
			scanf("%d",&r); r--;
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(i != r)
						scanf("%*d");
					else
						scanf("%d",&set[k][j]);
				}
			}
		}

		int count = 0;
		int ans = -1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(set[0][i] == set[1][j]){
					count += 1;
					ans = set[0][i];
					break;
				}
			}
		}
		if(count == 0){
			printf("Case #%d: Volunteer cheated!\n", ca);
		}else if(count == 1){
			printf("Case #%d: %d\n", ca, ans);
		}else{
			printf("Case #%d: Bad magician!\n",ca);
		}
	}
	return 0;
}
