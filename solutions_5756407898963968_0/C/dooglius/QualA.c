#include <stdio.h>

int go(void){
	int r;
	int i;
	int info = 0;
	int ans=-1;
	scanf("%d",&r);
	for(i=1; i<=4; i++){
		int j;
		for(j=1; j<=4; j++){
			int x;
			scanf("%d",&x);
			if(i==r){
				info |= (1 << x);
			}
		}
	}
	scanf("%d",&r);
	for(i=1; i<=4; i++){
		int j;
		for(j=1; j<=4; j++){
			int x;
			scanf("%d",&x);
			if(i==r){
				if(info & (1 << x)){
					if(ans == -1) ans = x;
					else ans = -2;
				}
			}
		}
	}
	return ans;
}

int main(int argc, char** argv){
	int t;
	scanf("%d",&t);
	int i;
	for(i=1; i<=t; i++){
		int ans = go();
		printf("Case #%d: ",i);
		switch(ans){
		case -2:
			printf("Bad magician!\n");
			break;
		case -1:
			printf("Volunteer cheated!\n");
			break;
		default:
			printf("%d\n",ans);
			break;
		}
	}
	return 0;
}
