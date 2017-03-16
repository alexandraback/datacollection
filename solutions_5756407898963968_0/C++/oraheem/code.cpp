#include<stdio.h>
#include<string.h>

int rows[17];

void readgrid(int targetrow){
	for(int i = 1; i <= 4;i++){
		for(int j = 1; j <= 4;j++){
			int cell;
			scanf("%d",&cell);
			if (i == targetrow){
				rows[cell] ++;
			}
		}
	}
}

int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int c = 1; c <= n; c++){
		memset(rows,0,sizeof(rows));
		int r1,r2;
		scanf("%d",&r1);
		readgrid(r1);
		scanf("%d",&r2);
		readgrid(r2);
		int repcount = 0;
		int rep = 0;
		for(int i = 0; i < 17;i++){
			if (rows[i] == 2) {
				repcount ++;
				rep = i;
			}
		}
		printf("Case #%d: ", c);
		if (repcount == 0) printf("Volunteer cheated!\n");
		else if (repcount == 1) printf("%d\n", rep);
		else printf("Bad magician!\n");
	}
	//while(true);
}


