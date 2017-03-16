#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

#define MEM(v,i) memset(v,i,sizeof(v))

typedef long long int LL;

int main(){
	int test = 0, initial_row = 0, final_row = 0;
	int initial_array[5][5], final_array[5][5];
	int i = 0, j = 0, count = 0, card = 0;
	scanf("%d",&test);
	for(int x_test = 1;x_test<=test; x_test++){
		scanf("%d",&initial_row);
		for(i = 0; i<4; i++){
			for(j = 0; j<4; j++){
				scanf("%d",&initial_array[i][j]);
			}
		}
		scanf("%d",&final_row);
		for(i = 0; i<4; i++){
			for(j = 0; j<4; j++){
				scanf("%d",&final_array[i][j]);
			}
		}
		count = 0;
		card = 0;
		for(i = 0; i<4; i++){
			for(j = 0; j<4; j++){
				if(initial_array[initial_row-1][i]==final_array[final_row-1][j]){
				count++;
				card = initial_array[initial_row-1][i];
				}
			}
		}
		if(count==1){
			printf("Case #%d: %d\n",x_test,card);
		}
		else if(count >1){
			printf("Case #%d: Bad magician!\n",x_test);
		}else if(count ==0){
			printf("Case #%d: Volunteer cheated!\n",x_test);
		}
	}
	return(0);
}
