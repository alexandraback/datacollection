#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char **argv){
	int t,i,j,k;
	int T,n,type,ans;
	int arr[4][4],tmp[4];
	FILE *fin,*fout;
	fin=fopen("A-small-attempt0.in","rt");
	fout=fopen("A-small-attempt0.out","wt");

	fscanf(fin,"%d",&T);
	for(t=1;t<=T;t++){
		type=0;
		fscanf(fin,"%d",&n);
		//for(j=0;j<16;j++)
		//	fscanf(fin,"%d",&(arr[j]));
		for(i=0;i<4;i++){
			fscanf(fin,"%d %d %d %d",&(arr[i][0]),&(arr[i][1]),&(arr[i][2]),&(arr[i][3]));
			if(i==(n-1)){
				tmp[0]=arr[i][0];	tmp[1]=arr[i][1];	tmp[2]=arr[i][2];	tmp[3]=arr[i][3];
			}
		}

		fscanf(fin,"%d",&n);
		for(i=0;i<4;i++){
			fscanf(fin,"%d %d %d %d",&(arr[i][0]),&(arr[i][1]),&(arr[i][2]),&(arr[i][3]));
			if(i==(n-1)){
				for(j=0;j<4;j++){
					for(k=0;k<4;k++){
						if(tmp[j]==arr[i][k]){
							ans=tmp[j];
							type++;
						}
					}
				}
			}
		}
		if(type>1) type=2;
		if(type==0) type=3;

		switch(type){
		case 1:
			fprintf(fout,"Case #%d: %d\n",t,ans);
			break;
		case 2:
			fprintf(fout,"Case #%d: Bad magician!\n",t);
			break;
		case 3:
			fprintf(fout,"Case #%d: Volunteer cheated!\n",t);
			break;
		}
	}
	fclose(fout);
	fclose(fin);

	return 0;
}