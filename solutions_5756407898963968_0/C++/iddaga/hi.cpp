#include <stdio.h>
#include <memory.h>
int d[16];
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, r, i, j, k;
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("%d / %d\n",t,T);
		fprintf(out,"Case #%d: ",t);
		memset(d,0,sizeof(d));
		fscanf(in,"%d",&r); r--;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				fscanf(in,"%d",&k); k--;
				if (i == r) d[k]++;
			}
		}
		fscanf(in,"%d",&r); r--;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				fscanf(in,"%d",&k); k--;
				if (i == r) d[k]++;
			}
		}
		r = 0;
		for (i = 0; i < 16; i++) {
			if (d[i] == 2) r++;
		}
		
		if (r == 1) {
			for (i = 0; i < 16; i++) {
				if (d[i] == 2)
					fprintf(out,"%d\n",i+1);
			}
		}
		else if (r == 0)
			fprintf(out,"Volunteer cheated!\n");
		else fprintf(out,"Bad magician!\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}