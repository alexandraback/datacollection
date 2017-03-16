#include <stdio.h>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int t;
int ch[20] = {0,};
int main(){
	fscanf(input, "%d", &t);
	int tt;
	int i, j;
	for(tt = 1; tt <= t; tt++){
		int a, x;
		fscanf(input, "%d", &a);
		for(i = 1; i <= 4; i++){
			for(j = 1; j <= 4; j++){
				fscanf(input, "%d", &x);
				if(i == a) ch[x]++;
			}
		}
		fscanf(input, "%d", &a);
		for(i = 1; i <= 4; i++){
			for(j = 1; j <= 4; j++){
				fscanf(input, "%d", &x);
				if(i == a) ch[x]++;
			}
		}
		int c = 0, ans = 0;
		for(i = 1; i <= 16; i++){
			if(ch[i] == 2){
				c++;
				ans = i;
			}
		}
		fprintf(output, "Case #%d: ", tt);
		if(c == 1) fprintf(output, "%d\n", ans);
		if(c == 0) fprintf(output, "Volunteer cheated!\n");
		if(c > 1) fprintf(output, "Bad magician!\n");
		for(i = 1; i <= 16; i++) ch[i] = 0;
	}
	return 0;
}