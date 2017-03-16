#include <stdio.h>
#include <string.h>

int count[20];

void read();

int main(void){
	int i, j, flag, ans, tot;
	scanf("%d", &tot);
	for(i = 1; i <= tot; i++){
		memset(count, 0, 20 * sizeof(int));
		read();
		read();
		flag = 0;
		ans = 0;
		for(j = 1; j <= 16; j++){
			if(count[j]>1){
				flag++;
				ans = j;
			}
		}
		if(0 == flag){
			printf("Case #%d: Volunteer cheated!\n", i);
		}
		else if(flag > 1){
			printf("Case #%d: Bad magician!\n", i);
		}
		else{
			printf("Case #%d: %d\n", i, ans);
		}
	}
	return 0;
}
void read(){
	int i, j, ans, x;
	scanf("%d", &ans);
	for(i = 1; i <= 4; i++){
		for(j = 1; j <= 4; j++){
			scanf("%d", &x);
			if(i == ans)count[x]++;
		}
	}
}
